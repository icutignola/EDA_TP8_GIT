#pragma once
#include <iostream>
#include "Image.h"

using namespace std;

class Menu
{
public:
	Menu(string arrayPath[], unsigned int numberPath);

private:

	Image * arrayImages;
	
};