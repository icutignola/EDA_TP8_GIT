#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Image.h"

using namespace std;

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
	Menu(string arrayPath[], unsigned int numberPath);
	void enterMenu(void);


private:

	Image * arrayImages;
	bool initAllegro(void);
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *colaEventos;
	unsigned int numberPage;
	unsigned int numberPagesMax;
	bool exitMenu;
	void printImages(void);
	unsigned int numberImages;

};