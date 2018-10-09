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


#define WIDE				1000		// Display wide
#define HEITH				600			// Displat heith
#define IMAGE_W				300			// Image wide
#define IMAGE_H				300			// Image heith
#define IMAGE_PER_SCREEN	9			// Cantidad de imagenes por pagina
#define IMAGE_PER_LINE		3			// Cantidad de imagenes en una fila
#define IMAGE_PER_COLUMN	3			// Cantidad de imagenes en una columna
#define NOT_SELECTED		false
#define SELECTED			true	

class MenuDescompress
{

	//***********************  PUBLIC  ***************************
public:

	//*************  CONSTRUCTOR & DESCONSTRUCTOR  **********
	MenuDescompress(vector<string>& arrayPath, unsigned int numberPath);
	~MenuDescompress(void);
	//*******************************************************

	//**********  ALLEGRO  *****************
	ALLEGRO_DISPLAY *display;
	vector<ALLEGRO_BITMAP *> images;
	//**************************************

	//**************  GET  *******************
	unsigned int getNumberPathsSelected(void);
	char* getPathSelected(unsigned int number);
	//****************************************

	void enterMenu(void);


	vector<string> pathsSelected;

	//************************************************************

	//***********************  PRIVATE  **************************
private:

	//**********  ALLEGRO  *****************
	ALLEGRO_EVENT_QUEUE *colaEventos;
	ALLEGRO_FONT* fuente;
	ALLEGRO_EVENT evento;
	//**************************************

	Image * arrayImages;				// Arreglo de imagenes disponibles en el directorio

	//*********  PAGES  **************
	unsigned int numberPage;			// Variable que almacena la pagina que se esta viendo en pantalla
	unsigned int numberPagesMax;		// Variable que almacena la cantidad maxima de paginas
	//********************************

	bool exitMenu;						// Variable que determina si el usuario quiere salir del menu (true == Salir del menu) (false == No salir del menu)

	char *convert(const std::string & s);// Metodo que se utiliza para convertir un string a un char*

	//**********  IMAGES  ************
	void printImages(void);				// Metodo para imprimir todas las imagenes en la pagina indicada por numberPage
	unsigned int numberImages;			// Variable que almacena la cantidad de imagenes disponibles en el directori
	unsigned int numberImagesSelected;	// Variable que almacena la cantidad de imagenes que estan seleccionadas		
	//********************************

//************************************************************

};