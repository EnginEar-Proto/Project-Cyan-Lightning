typedef struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[128 * 16 * 3 + 1];
} Bitmap;

static Bitmap const basic_eye;
static Bitmap const basic_mouth;
static Bitmap const happy_eye;
static Bitmap const happy_mouth;
static Bitmap const emotions[10][2];