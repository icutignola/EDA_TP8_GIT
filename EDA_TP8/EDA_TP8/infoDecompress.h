#pragma once
#include "point.h"
#include <stdio.h>
using namespace std;
class infoDecompress {
public:
	int treeLevel; // en que nivel del arbol estoy
	FILE * pFile;
	Point coordinates = Point(0, 0);
	unsigned int width, height;
	infoDecompress(char * name);
};
