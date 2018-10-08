#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


using namespace std;

class Image
{
public:
	Image(void);
	void initImage(const char * path);
	bool isSelected(void);
	void selectImage(void);
	void deselectImage(void);
	ALLEGRO_BITMAP * getBitmapImage(void);
	string getPath(void);
	char localPathC[20];
	ALLEGRO_BITMAP *image;



private:

	string localPath;
	bool selected;
};


