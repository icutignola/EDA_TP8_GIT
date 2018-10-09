#pragma once
#include <stdio.h>
#include <math.h>
//#include "allegro_init.h"
//#include "image.h"
//#include "lodepng.h"
#include "infoDecompress.h"
#include "point.h"

#define INNER 'N'
#define ALPHA 0xff

void recursiveDecompress(infoDecompress info, unsigned char ** matrix);
unsigned char ** decodeImage(char * name, unsigned int * sizeo);// devuelve un puntero a chars con la imagen reconstruida
void freeMatrix(unsigned char ** matrix, int width, int height);
