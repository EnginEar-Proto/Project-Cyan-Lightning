#include "SoundSpectrum.h"

#ifndef SOUNDSPECT

#define SOUNDSPECT 1

SoundSpectAnalyzer::SoundSpectAnalyzer(unsigned int adc, float scale){
    input = AudioInputAnalog(adc);
    audioConnection = AudioConnection(input, 0, fft, 0);
    this->scale = scale;
}

void SoundSpectAnalyzer::Allocate(){
    AudioMemory(12);
}

void SoundSpectAnalyzer::AnalyzeSpectrum(){
    if(fft.available()){
        // I'm skipping the first two bins, as they seem to be unusable
        // they start out at zero, but then climb and don't come back down
        // even after sound input stops
        level[0] = fft.read(2);
        level[1] = fft.read(3);
        level[2] = fft.read(4);
        level[3] = fft.read(5, 6);
        level[4] = fft.read(7, 8);
        level[5] = fft.read(9, 10);
        level[6] = fft.read(11, 14);
        level[7] = fft.read(15, 19);

        // Magic values based on multiple measurements for noise mitigation.
        level[8] = fft.read(20, 25) - 0.2f;

        level[9] = fft.read(26, 32);
        level[10] = fft.read(33, 41);

        // Magic values based on multiple measurements for noise mitigation.
        level[11] = fft.read(42, 52) - 0.1f;

        level[12] = fft.read(53, 65);
        level[13] = fft.read(66, 82);
        level[14] = fft.read(83, 103);
        level[15] = fft.read(104, 127);
    }
}

void SoundSpectAnalyzer::ConvertToBars(SMLayerBackground<rgb24, 0U> *bgLayer, int widht, int height){
    for(int i = 0; i < 16; i++){
         for (int i = 0; i < 16; i++) {
            // TODO: conversion from FFT data to display bars should be
            // exponentially scaled.  But how to keep it a simple example?
            int val = level[i] * scale;

            // trim the bars vertically to fill the matrix height
            if (val >= height) val = height - 1;

            if (val >= shown[i]) {
                shown[i] = val;
            }
            else {
                if (shown[i] > 0) shown[i] = shown[i] - 1;
                val = shown[i];
            }

            // color hue based on band
            auto color = CRGB(CHSV(i * 15, 255, 255));
            rgb24 rgbColor(color.r, color.g, color.b);

            // draw the levels on the matrix
            if (shown[i] >= 0) {
                // scale the bars horizontally to fill the matrix width
                for (int j = 0; j < widht / 32; j++) {
                    bgLayer->drawRectangle(i * 8, (height - 1), i * 8 + j, (height - 1) - val, rgbColor);
                }
            }
        }
    }
    bgLayer->swapBuffers();
}

#endif