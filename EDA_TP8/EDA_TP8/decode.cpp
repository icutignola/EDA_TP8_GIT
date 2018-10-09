#include "decode.h"
#include <stdlib.h>

void freeMatrix(unsigned char ** matrix, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		free(matrix[i]); //free de las columnas de cada fila
	}
	free(matrix); //free de las filas
}


unsigned char ** decodeImage(char * name, unsigned int * sizeo)
{
	infoDecompress info = infoDecompress(name);
	unsigned int size = 0;
	char aux = 0;
	for (int i = 0; i < 8; i++) // para leer los 4 primeros bytes con el tamanio de la matriz
	{
		size <<= 4;
		aux = fgetc(info.pFile);
		switch (aux)
		{
		case 'A': case 'a':
			aux = 10;
		case 'B': case 'b':
			aux = 11;
		case 'C': case 'c':
			aux = 12;
		case 'D': case 'd':
			aux = 13;
		case 'E': case 'e':
			aux = 14;
		case 'F': case 'f':
			aux = 15;
		default:
			aux = aux - '0';
		}
		size += aux;
	}
	info.height = sqrt(size);
	info.width = info.height; // porque es un cuadrado
	unsigned char ** reconstrucedImage = (unsigned char **)malloc(info.height * sizeof(unsigned char *)); // reservo la memoria necesaria para construir la imagen
	for (int i = 0; i < info.height; i++)
	{
		reconstrucedImage[i] = (unsigned char *)malloc(info.width * 4 * sizeof(unsigned char)); //por cada fila reservo memoria de sus columnas
	}

	recursiveDecompress(info, reconstrucedImage); // llamo a la funcion recursiva
	*sizeo = size;
	return reconstrucedImage;

}
//  0    1    0    2    0   3     0    4
// 0000.0001.0000.0010.0000.0011.0000.0100
//0000.0001.0000.0010.0000.0000

void recursiveDecompress(infoDecompress info, unsigned char ** matrix) { // funcion para leer el archivo y descomprimir la imagen
	char c = fgetc(info.pFile);
	if (c == INNER) // Ir un cuadradito mas profundo
	{
		info.treeLevel++; // paso al nivel siguiente
		recursiveDecompress(info, matrix); // superior izquierdo
		info.treeLevel--;

		info.treeLevel++;
		info.coordinates.x += 4 * info.width / pow(2, info.treeLevel);
		recursiveDecompress(info, matrix); //superior derecho
		info.treeLevel--;

		info.treeLevel++;
		info.coordinates.x -= 4 * info.width / pow(2, info.treeLevel);
		info.coordinates.y += info.height / pow(2, info.treeLevel);
		recursiveDecompress(info, matrix); // inferior izquierdo
		info.treeLevel--;

		info.treeLevel++;
		info.coordinates.x += 4 * info.width / pow(2, info.treeLevel);
		recursiveDecompress(info, matrix); //inferior derecho
	}
	else //Es una h
	{
		unsigned char red, green, blue;
		red = fgetc(info.pFile) - '0'; // para que guarde el numero
		for (int i = 0; i < 2; i++)
		{
			red *= 10;
			red += fgetc(info.pFile) - '0';
		}

		green = fgetc(info.pFile) - '0'; // para que guarde el numero
		for (int i = 0; i < 2; i++)
		{
			green *= 10;
			green += fgetc(info.pFile) - '0';
		}
		blue = fgetc(info.pFile) - '0'; // para que guarde el numero
		for (int i = 0; i < 2; i++)
		{
			blue *= 10;
			blue += fgetc(info.pFile) - '0';
		}
		for (int i = info.coordinates.y; i < info.coordinates.y + info.height / pow(2, info.treeLevel); i++)
		{
			for (int j = info.coordinates.x; j < (info.coordinates.x + 4 * info.width / pow(2, info.treeLevel)); j += 4)
			{
				matrix[i][j] = red;
				matrix[i][j + 1] = green;
				matrix[i][j + 2] = blue;
				matrix[i][j + 3] = ALPHA;
			}
		}
	}
}
