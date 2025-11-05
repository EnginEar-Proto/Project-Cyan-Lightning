/*
 * This example shows how to display bitmaps that are exported from GIMP and
 * compiled into the sketch and stored in the Teensy's Flash memory
 * See more details here:
 * http://docs.pixelmatix.com/SmartMatrix/library.html#smartmatrix-library-how-to-use-the-library-drawing-raw-bitmaps
 *
 * This example uses only the SmartMatrix Background layer
 */

#include <MatrixHardware_Teensy4_ShieldV5.h>        // SmartLED Shield for Teensy 4 (V5)
#include <SmartMatrix.h>
#include <Wire.h>

// chrome16 is a 16x16 pixel bitmap, exported from GIMP without modification
#include "bitmaps.h"

#define COLOR_DEPTH 24                  // Choose the color depth used for storing pixels in the layers: 24 or 48 (24 is good for most sketches - If the sketch uses type `rgb24` directly, COLOR_DEPTH must be 24)
const uint16_t kMatrixWidth = 128;       // Set to the width of your display, must be a multiple of 8
const uint16_t kMatrixHeight = 32;      // Set to the height of your display
const uint8_t kRefreshDepth = 36;       // Tradeoff of color quality vs refresh rate, max brightness, and RAM usage.  36 is typically good, drop down to 24 if you need to.  On Teensy, multiples of 3, up to 48: 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48.  On ESP32: 24, 36, 48
const uint8_t kDmaBufferRows = 4;       // known working: 2-4, use 2 to save RAM, more to keep from dropping frames and automatically lowering refresh rate.  (This isn't used on ESP32, leave as default)
const uint8_t kPanelType = SM_PANELTYPE_HUB75_32ROW_MOD16SCAN;   // Choose the configuration that matches your panels.  See more details in MatrixCommonHub75.h and the docs: https://github.com/pixelmatix/SmartMatrix/wiki
const uint32_t kMatrixOptions = (SM_HUB75_OPTIONS_NONE);        // see docs for options: https://github.com/pixelmatix/SmartMatrix/wiki
const uint8_t kBackgroundLayerOptions = (SM_BACKGROUND_OPTIONS_NONE);
const uint8_t kIndexedLayerOptions = (SM_INDEXED_OPTIONS_NONE);

SMARTMATRIX_ALLOCATE_BUFFERS(matrix, kMatrixWidth, kMatrixHeight, kRefreshDepth, kDmaBufferRows, kPanelType, kMatrixOptions);
SMARTMATRIX_ALLOCATE_BACKGROUND_LAYER(background, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kBackgroundLayerOptions);
SMARTMATRIX_ALLOCATE_INDEXED_LAYER(eyelayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kIndexedLayerOptions);
SMARTMATRIX_ALLOCATE_INDEXED_LAYER(mouthlayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kIndexedLayerOptions);

int led = -1;   // Set to -1 to disable LED flash, only needed for debugging purposes
//int led = 13; // builtin LED pin on the Teensy, interferes with refresh on Teensy 4

void drawBitmap(int16_t x, int16_t y, const Bitmap* bitmap, const bool isEye) {
  for(unsigned int i=0; i < bitmap->height; i++) {
    for(unsigned int j=0; j < bitmap->width; j++) {
      SM_RGB pixel = { bitmap->pixel_data[(i*bitmap->width + j)*3 + 0],
                      bitmap->pixel_data[(i*bitmap->width + j)*3 + 1],
                      bitmap->pixel_data[(i*bitmap->width + j)*3 + 2] };
      if(COLOR_DEPTH == 48) {
          pixel.red = pixel.red << 8;
          pixel.green = pixel.green << 8;
          pixel.blue = pixel.blue << 8;
      }

      if(pixel.blue > 0 || pixel.red > 0 || pixel.green > 0){
        if(isEye){
          eyelayer.setIndexedColor(1, pixel);
          eyelayer.drawPixel(x + j, y + i, 1);
        }else{
          mouthlayer.setIndexedColor(1, pixel);
          mouthlayer.drawPixel(x + j, y + i, 1);
        }
      }
    }
  }
}

void select_emotion(int num_bytes){
  int id = 0;
  while(1 < Wire1.available()){
    id = Wire1.read();
  }
  id = Wire1.read();

  Serial.println(id);

  eyelayer.setIndexedColor(0, {0,0,0});
  mouthlayer.setIndexedColor(0, {0,0,0});

  eyelayer.fillScreen(0);
  mouthlayer.fillScreen(0);

  drawBitmap(0,0,(const Bitmap*)&Emotes::emotes[id][0], true);
  drawBitmap(0,16,(const Bitmap*)&Emotes::emotes[id][1], false);
}

void setup() {
  Serial.begin(115200);
  Wire1.begin(0x3c);
  Wire1.onReceive(select_emotion);
  //Wire.begin(60);

  matrix.addLayer(&background);
  matrix.addLayer(&eyelayer); 
  matrix.addLayer(&mouthlayer);
  matrix.begin();

  matrix.setBrightness(212);
  background.fillScreen({0,0,0});

  drawBitmap(0,0,(const Bitmap*)&Emotes::emotes[0][0], true);
  drawBitmap(0,16,(const Bitmap*)&Emotes::emotes[0][1], false);

  if(led >= 0)  pinMode(led, OUTPUT);

  //Wire.onReceive(select_emotion);
}

void loop() {
  eyelayer.swapBuffers();
  mouthlayer.swapBuffers();
  background.swapBuffers();
}