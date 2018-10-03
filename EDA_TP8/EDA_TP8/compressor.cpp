#include "compressor.h"



compressor::compressor(unsigned char * image, int umbral)
{
	threshhold = umbral;
	pixelArray = image;
}


compressor::~compressor()
{
}

bool compressor::compression(int step, unsigned char * inicio) 
{
	unsigned char * navigator = inicio;
	unsigned char maxR, minR, maxB, minB, maxG, minG;
	int puntaje;
	step++;
	for (int count = 0; count = 3; count++)
	{
		int incremento = (count % 2) ? ((heigth / step)*width) : (width / step); 
		
		for (int j = 0; j < (width / (step)); j++)
		{
			for (int i = 0; i < (heigth / (step)); i++)
			{
				navigator = pixelArray + (i*width) + j;

				maxR = (maxR > (*navigator)) ? maxR : (*navigator);
				minR = (minR < (*navigator)) ? minR : (*navigator);
				maxB = (maxB > (*(navigator + 1))) ? maxB : (*(navigator + 1));
				minB = (minB < (*(navigator + 1))) ? minB : (*(navigator + 1));
				maxG = (maxG > (*(navigator + 2))) ? maxG : (*(navigator + 2));
				minG = (minG < (*(navigator + 2))) ? minG : (*(navigator + 2));
			}
		}
		navigator += incremento;
	}
}