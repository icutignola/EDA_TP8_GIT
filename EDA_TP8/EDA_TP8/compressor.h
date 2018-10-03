#pragma once
#include <iostream>
#include <string>
class compressor
{
public:
	compressor(unsigned char * image, int umbral);
	~compressor();

private:
	/* Funci�n compression:
	Recive una imagen en forma arreglo de pixeles (pixelArray) y la comprime de acuerdo
	al algoritmo de compresi�n Quad Tree, devolviendola en el buffer deseado (compressedImg).
	Recive el umbral de comparasi�n para el algoritmo(threshhold).
	Ademas, devuelve en su nombre si la compresi�n fue o no exitosa.
	*/
	bool compression(int step, unsigned char *inicio);
	std::string filename;
	unsigned char* pixelArray;
	unsigned char* compressedImg;
	int threshhold;
	unsigned int width;
	unsigned int heigth;
};

