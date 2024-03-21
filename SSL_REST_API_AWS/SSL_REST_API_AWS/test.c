
/* These functions are based on the Arduino test program at
*  https://github.com/adafruit/Adafruit-SSD1351-library/blob/master/examples/test/test.ino
*
*  You can use these high-level routines to implement your
*  test program.
*/

// TODO Configure SPI port and use these libraries to implement
// an OLED test program. See SPI example program.
#include "test.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1351.h"
#include "glcdfont.h"
#include "string.h"
#include "stdio.h"
#include "stdint.h"

float p = 3.1415926;


void gametitle() {
    const char *message = "Welcome to GeoGuessr";
        int length = strlen(message); // Get the length of the message
        int charWidth = 6; // Approximate width of each character in pixels at font size 1
        int totalWidth = length * charWidth; // Total width the message will occupy
        int startX = (128 - totalWidth) / 2; // Calculate starting X to center the message
        int startY = 64; // Center Y position on a 128x128 display
        int x = startX;
        int i;
        for (i = 0; i < length; i++) {
            drawChar(x, startY, message[i], WHITE, BLACK, 1);
            x += charWidth; // Move x to the right for the next character
        }

}

//*****************************************************************************

void drawGrid() {
    // Set the entire background to black
//        fillScreen(BLACK);

        unsigned int x;
        unsigned int y;

        // Draw vertical grid lines
        for (x = 0; x <= 128; x += 16)
        {
            drawFastVLine(x, 0, 128, WHITE);

        }

        // Draw horizontal grid lines
        for (y = 0; y <= 128; y += 16)
        {
            drawFastHLine(0, y, 128, WHITE);
        }
}

//*****************************************************************************
//  function delays 3*ulCount cycles
void delay(unsigned long ulCount){
    int i;

  do{
    ulCount--;
        for (i=0; i< 65535; i++) ;
    }while(ulCount);
}


//*****************************************************************************

void helloworld() {
    drawChar(0, 64, 'H', WHITE, WHITE, 2);
    drawChar(10, 64, 'e', WHITE, WHITE, 2);
    drawChar(20, 64, 'l', WHITE, WHITE, 2);
    drawChar(30, 64, 'l', WHITE, WHITE, 2);
    drawChar(40, 64, 'o', WHITE, WHITE, 2);
    drawChar(60, 64, 'W', WHITE, WHITE, 2);
    drawChar(70, 64, 'o', WHITE, WHITE, 2);
    drawChar(80, 64, 'r', WHITE, WHITE, 2);
    drawChar(90, 64, 'l', WHITE, WHITE, 2);
    drawChar(100, 64, 'd', WHITE, WHITE, 2);
    drawChar(110, 64, '!', WHITE, WHITE, 2);

}

//*****************************************************************************

void characterSet() {
    fillScreen(BLACK);
           int i;
           int x = 0; //x coordinates
           int y = 0;//y coordinates

           for(i = 0; i < 255; ++i){
               drawChar(x, y, i, WHITE, 0x0000, 1);
               if(x < 114) x+=6;
               else{
                   y += 9;
                   x = 1;
               }
    }

}

//*****************************************************************************

void horizontal() {
    fillRect(0, 0, 16, 128, BLACK);
    fillRect(16, 0, 16, 128, BLUE);
    fillRect(32, 0, 16, 128, GREEN);
    fillRect(48, 0, 16, 128, CYAN);
    fillRect(64, 0, 16, 128, RED);
    fillRect(80, 0, 16, 128, MAGENTA);
    fillRect(96, 0, 16, 128, YELLOW);
    fillRect(112, 0, 16, 128, WHITE);
#define BLACK           0x0000
#define BLUE            0x001F
#define GREEN           0x07E0
#define CYAN            0x07FF
#define RED             0xF800
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF
}

//*****************************************************************************

void vertical() {
    fillRect(0, 0, 128, 16, BLACK);
    fillRect(0, 16, 128, 16, BLUE);
    fillRect(0, 32, 128, 16, GREEN);
    fillRect(0, 48, 128, 16, CYAN);
    fillRect(0, 64, 128, 16, RED);
    fillRect(0, 80, 128, 16, MAGENTA);
    fillRect(0, 96, 128, 16, YELLOW);
    fillRect(0, 112, 128, 16, WHITE);
}

//*****************************************************************************

void testfastlines(unsigned int color1, unsigned int color2) {
    unsigned int x;
    unsigned int y;

   fillScreen(BLACK);
   for (y=0; y < height()-1; y+=8) {
     drawFastHLine(0, y, width()-1, color1);
   }
     delay(100);
   for (x=0; x < width()-1; x+=8) {
     drawFastVLine(x, 0, height()-1, color2);
   }
     delay(100);
}

//*****************************************************************************

void testdrawrects(unsigned int color) {
    unsigned int x;

 fillScreen(BLACK);
 for (x=0; x < height()-1; x+=6) {
   drawRect((width()-1)/2 -x/2, (height()-1)/2 -x/2 , x, x, color);
     delay(10);
 }
}

//*****************************************************************************

void testfillrects(unsigned int color1, unsigned int color2) {

    unsigned char x;

 fillScreen(BLACK);
 for (x=height()-1; x > 6; x-=6) {
   fillRect((width()-1)/2 -x/2, (height()-1)/2 -x/2 , x, x, color1);
   drawRect((width()-1)/2 -x/2, (height()-1)/2 -x/2 , x, x, color2);
     delay(10);
 }
}

//*****************************************************************************

void testfillcircles(unsigned char radius, unsigned int color) {
    unsigned char x;
    unsigned char y;

  for (x=radius; x < width()-1; x+=radius*2) {
    for (y=radius; y < height()-1; y+=radius*2) {
      fillCircle(x, y, radius, color);
            delay(10);
    }
  }
}

//*****************************************************************************

void testdrawcircles(unsigned char radius, unsigned int color) {
    unsigned char x;
    unsigned char y;

  for (x=0; x < width()-1+radius; x+=radius*2) {
    for (y=0; y < height()-1+radius; y+=radius*2) {
      drawCircle(x, y, radius, color);
            delay(10);
    }
  }
}

//*****************************************************************************

void testtriangles() {
  int color = 0xF800;
  int t;
  int w = width()/2;
  int x = height()-1;
  int y = 0;
  int z = width()-1;

  fillScreen(BLACK);
  for(t = 0 ; t <= 15; t+=1) {
    drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
        delay(10);
  }
}

//*****************************************************************************

void testroundrects() {
  int color = 100;

    int i;
  int x = 0;
  int y = 0;
  int w = width();
  int h = height();

  fillScreen(BLACK);

  for(i = 0 ; i <= 24; i++) {
    drawRoundRect(x, y, w, h, 5, color);
    x+=2;
    y+=3;
    w-=4;
    h-=6;
    color+=1100;
  }
}

//*****************************************************************************
void testlines(unsigned int color) {
    unsigned int x;
    unsigned int y;

   fillScreen(BLACK);
   for (x=0; x < width()-1; x+=6) {
     drawLine(0, 0, x, height()-1, color);
   }
     delay(10);
   for (y=0; y < height()-1; y+=6) {
     drawLine(0, 0, width()-1, y, color);
   }
     delay(100);

   fillScreen(BLACK);
   for (x=0; x < width()-1; x+=6) {
     drawLine(width()-1, 0, x, height()-1, color);
   }
     delay(100);
   for (y=0; y < height()-1; y+=6) {
     drawLine(width()-1, 0, 0, y, color);
   }
     delay(100);

   fillScreen(BLACK);
   for (x=0; x < width()-1; x+=6) {
     drawLine(0, height()-1, x, 0, color);
   }
     delay(100);
   for (y=0; y < height()-1; y+=6) {
     drawLine(0, height()-1, width()-1, y, color);
   }
     delay(100);

   fillScreen(BLACK);
   for (x=0; x < width()-1; x+=6) {
     drawLine(width()-1, height()-1, x, 0, color);
   }
     delay(100);
   for (y=0; y < height()-1; y+=6) {
     drawLine(width()-1, height()-1, 0, y, color);
   }
     delay(100);

}

//*****************************************************************************

void lcdTestPattern(void)
{
  unsigned int i,j;
  goTo(0, 0);

  for(i=0;i<128;i++)
  {
    for(j=0;j<128;j++)
    {
      if(i<16){writeData(RED>>8); writeData((unsigned char) RED);}
      else if(i<32) {writeData(YELLOW>>8);writeData((unsigned char) YELLOW);}
      else if(i<48){writeData(GREEN>>8);writeData((unsigned char) GREEN);}
      else if(i<64){writeData(CYAN>>8);writeData((unsigned char) CYAN);}
      else if(i<80){writeData(BLUE>>8);writeData((unsigned char) BLUE);}
      else if(i<96){writeData(MAGENTA>>8);writeData((unsigned char) MAGENTA);}
      else if(i<112){writeData(BLACK>>8);writeData((unsigned char) BLACK);}
      else {writeData(WHITE>>8); writeData((unsigned char) WHITE);}
    }
  }
}
/**************************************************************************/
void lcdTestPattern2(void)
{
  unsigned int i,j;
  goTo(0, 0);

  for(i=0;i<128;i++)
  {
    for(j=0;j<128;j++)
    {
      if(j<16){writeData(RED>>8); writeData((unsigned char) RED);}
      else if(j<32) {writeData(YELLOW>>8);writeData((unsigned char) YELLOW);}
      else if(j<48){writeData(GREEN>>8);writeData((unsigned char) GREEN);}
      else if(j<64){writeData(CYAN>>8);writeData((unsigned char) CYAN);}
      else if(j<80){writeData(BLUE>>8);writeData((unsigned char) BLUE);}
      else if(j<96){writeData(MAGENTA>>8);writeData((unsigned char) MAGENTA);}
      else if(j<112){writeData(BLACK>>8);writeData((unsigned char) BLACK);}
      else {writeData(WHITE>>8);writeData((unsigned char) WHITE);}
    }
  }
}

/**************************************************************************/
