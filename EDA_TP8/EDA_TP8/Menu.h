#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Image.h"

using namespace std;
using std::vector;
using std::string;


#define WIDE				1000
#define HEITH				600
#define IMAGE_W				300
#define IMAGE_H				300
#define IMAGE_PER_SCREEN	9
#define IMAGE_PER_LINE		3
#define IMAGE_PER_COLUMN	3
#define NOT_SELECTED		false
#define SELECTED			true	

class Menu
{
public:
	Menu(vector<string>& arrayPath, unsigned int numberPath);
	~Menu(void);
	void enterMenu(void);
	string * getPathsSelected(void);
	ALLEGRO_DISPLAY *display;


private:

	Image * arrayImages;
	bool initAllegro(vector<string>& arrayPath);
	ALLEGRO_EVENT_QUEUE *colaEventos;
	unsigned int numberPage;
	unsigned int numberPagesMax;
	bool exitMenu;
	void printImages(void);
	unsigned int numberImages;
	unsigned int numberImagesSelected;
	char *  pathsSelected;
	ALLEGRO_EVENT evento;
	char* Paths[];


};