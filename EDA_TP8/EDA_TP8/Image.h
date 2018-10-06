#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Image
{
public:
	Image(void);
	void initImage(string path);
	bool isSelected(void);
	bool alInitImage (void);
	void selectImage(void);
	void deselectImage(void);
	ALLEGRO_BITMAP * getBitmapImage(void);
	string getPath(void);

private:

	ALLEGRO_BITMAP *image;
	bool selected;
	string localPath;
};


