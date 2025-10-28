#include <Audio.h>
#include <FastLED.h>
#include <Layer_Background.h>
#include <pixeltypes.h>

class SoundSpectAnalyzer {

    AudioInputAnalog input;
    AudioAnalyzeFFT256 fft;
    AudioConnection audioConnection;

    // The scale sets how much sound is needed in each frequency range to
    // show all 32 bars.  Higher numbers are more sensitive.
    float scale;

    // An array to hold the 16 frequency bands
    float level[16];

    /* 
     * This array holds the on-screen levels.  When the signal drops quickly,
     * these are used to lower the on-screen level 1 bar per update, which
     * looks more pleasing to corresponds to human sound perception.
     */
    int shown[16];
public:
    SoundSpectAnalyzer(unsigned int adc, float scale);
    void Allocate();
    void AnalyzeSpectrum();
    void ConvertToBars(SMLayerBackground<rgb24, 0U> *bgLayer, int widht, int height);
};