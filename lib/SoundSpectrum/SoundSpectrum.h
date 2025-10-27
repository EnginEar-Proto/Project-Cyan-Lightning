#include <Audio.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <MatrixHardware_Teensy4_ShieldV5.h>        // SmartLED Shield for Teensy 4 (V5)
#include <SmartMatrix.h>
#include <FastLED.h>

class SoundSpectAnalyzer {

    unsigned int adc_input;
    AudioInputAnalog input;
    AudioAnalyzeFFT256 fft;
    AudioConnection audioConnection;
    float scale;
    float level[16];
    int shown[16];
public:
    SoundSpectAnalyzer(unsigned int adc, float scale);
    void AnalyzeSpectrum();
    void ConvertToBars();
};