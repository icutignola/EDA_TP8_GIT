#include "infoDecompress.h"
#include "point.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;
infoDecompress::infoDecompress(char * name)
{
	this->pFile = fopen(name, "r"); // asigno el puntero al archivo de donde leo la imagen comprimida
	this->coordinates = Point(0, 0);
	this->treeLevel = 0;
}
