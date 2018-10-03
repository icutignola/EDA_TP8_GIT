#include "compressor.h"



compressor::compressor(unsigned char * image, int umbral)
{
	threshhold = umbral;
	pixelArray = image;
}


compressor::~compressor()
{
}

bool compressor::compression() 
{

}