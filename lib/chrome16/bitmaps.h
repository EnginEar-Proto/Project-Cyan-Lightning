#ifndef FACE_H

#define FACE_H

// this structre can hold up to a 32x32 pixel RGB bitmap
typedef struct  {
  unsigned int   width;
  unsigned int   height;
  unsigned int   bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */
  unsigned char  pixel_data[128*16*3 + 1];
} Bitmap;

class Emotes {
public:
  static Bitmap basic_e;
  static Bitmap basic_m;
  static Bitmap happy_e;
  static Bitmap happy_m;
  static Bitmap tired_e;
  static Bitmap tired_m;
  static Bitmap eyesclosed_e;
  static Bitmap eyesclosed_m;
  static Bitmap angry_e;
  static Bitmap angry_m;
  static Bitmap furios_e;
  static Bitmap furios_m;
  static Bitmap sad_e;
  static Bitmap sad_m;
  static Bitmap confused_e;
  static Bitmap confused_m;
  static Bitmap love_e;
  static Bitmap love_m;
  static Bitmap emotes[10][2];
};

#endif