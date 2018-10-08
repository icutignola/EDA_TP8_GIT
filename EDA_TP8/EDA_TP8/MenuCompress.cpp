#include "MenuCompress.h"


MenuCompress::MenuCompress(vector<string>& arrayPath, unsigned int numberPath)
{
	numberImages = numberPath;				// Guardo el numero de archivos encontrados
	arrayImages = new Image[numberImages];	// Genero la cantidad de imagenes que me indica numberPath
	unsigned int i = 0;						// Variable que se utiliza para recorrer el arreglo de imagenes
	char * imagePath = NULL;				// Puntero que se utiliza para guardar el path de una imagen
	numberPage = 0;							// Contador que se utiliza para almacenar la cantidad de paginas 
	exitMenu = false;						// No salir del menu
	display = NULL;
	colaEventos = NULL;


	//**********************  Inicializa Allegro  **********************************
	if (!al_init())
	{
		cout << "Error al inicializar allegro" << endl;
	}

	if (!al_install_keyboard())
	{
		cout << "Error al inicializar el teclado" << endl;
	}

	if (!al_init_image_addon())
	{
		cout << "Error al inicializar los addons de imagenes" << endl;
	}

	colaEventos = al_create_event_queue();
	if (!colaEventos)
	{
		cout << "Error al inicializar la cola de eventos" << endl;
		al_shutdown_image_addon();

	}

	if (!al_init_primitives_addon())
	{
		cout << "Error al inicializar las primitivas" << endl;
		al_shutdown_image_addon();
		al_destroy_event_queue(colaEventos);
	}

	display = al_create_display(WIDE, HEITH);
	if (!display)
	{
		cout << "Error al inicializar el display" << endl;
		al_shutdown_image_addon();
		al_shutdown_primitives_addon();
		al_destroy_event_queue(colaEventos);

	}

	for (vector<string>::iterator iter = arrayPath.begin(); iter != arrayPath.end(); ++iter)
	{
		imagePath = convert(*iter);
		images.push_back(al_load_bitmap(imagePath));
		//arrayImages[i].image = al_load_bitmap(imagePath);
		if (images[i] == NULL)
		{
			cout << "Error al iniciar la imagen numero: " << i << endl;
		}
		i++;
	}

	al_register_event_source(colaEventos, al_get_display_event_source(display));
	al_register_event_source(colaEventos, al_get_keyboard_event_source());

	//********************************************************************************************************

	//******************************  Carga el Path de cada imagen  ******************************************
	if (arrayImages != NULL)
	{
		i = 0;
		for (vector<string>::iterator iter = arrayPath.begin(); iter != arrayPath.end(); ++iter)
		{
			imagePath = convert(*iter);
			arrayImages[i].initImage(imagePath);
			i++;
		}
	}
	//********************************************************************************************************	

	//******************************  Calcula la cantidad de paginas maxima  *********************************
	numberPagesMax = numberImages / IMAGE_PER_SCREEN;
	if (numberImages % IMAGE_PER_SCREEN == 0);	//No hace nada
	else
	{
		numberPagesMax++;
	}
	//********************************************************************************************************	
}

MenuCompress::~MenuCompress(void)
{
	al_destroy_display(display);
	al_shutdown_image_addon();
	al_shutdown_primitives_addon();
	al_destroy_event_queue(colaEventos);
}

void MenuCompress::enterMenu(void)
{
	while (!exitMenu)
	{
		printImages();

		if (al_get_next_event(colaEventos, &evento) && exitMenu == false)
		{
			if (evento.type == ALLEGRO_EVENT_KEY_DOWN && exitMenu == false)
			{
				switch (evento.keyboard.keycode)
				{
				case ALLEGRO_KEY_1:
				{
					if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 0].isSelected() == SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 0].deselectImage();
						numberImagesSelected--;
					}
					else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 0].isSelected() == NOT_SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 0].selectImage();
						numberImagesSelected++;
					}
					break;
				}

				case ALLEGRO_KEY_2:
				{
					if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 1].isSelected() == SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 1].deselectImage();
						numberImagesSelected--;
					}
					else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 1].isSelected() == NOT_SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 1].selectImage();
						numberImagesSelected++;
					}
					break;
				}

				case ALLEGRO_KEY_3:
				{
					if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 2].isSelected() == SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 2].deselectImage();
						numberImagesSelected--;
					}
					else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 2].isSelected() == NOT_SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 2].selectImage();
						numberImagesSelected++;
					}
					break;
				}

				case ALLEGRO_KEY_4:
				{
					if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 3].isSelected() == SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 3].deselectImage();
						numberImagesSelected--;
					}
					else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 3].isSelected() == NOT_SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 3].selectImage();
						numberImagesSelected++;
					}
					break;
				}

				case ALLEGRO_KEY_5:
				{
					if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 4].isSelected() == SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 4].deselectImage();
						numberImagesSelected--;
					}
					else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 4].isSelected() == NOT_SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 4].selectImage();
						numberImagesSelected++;
					}
					break;
				}

				case ALLEGRO_KEY_6:
				{
					if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 5].isSelected() == SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 5].deselectImage();
						numberImagesSelected--;
					}
					else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 5].isSelected() == NOT_SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 5].selectImage();
						numberImagesSelected++;
					}
					break;
				}

				case ALLEGRO_KEY_7:
				{
					if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 6].isSelected() == SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 6].deselectImage();
						numberImagesSelected--;
					}
					else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 6].isSelected() == NOT_SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 6].selectImage();
						numberImagesSelected++;
					}
					break;
				}

				case ALLEGRO_KEY_8:
				{
					if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 7].isSelected() == SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 7].deselectImage();
						numberImagesSelected--;
					}
					else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 7].isSelected() == NOT_SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 7].selectImage();
						numberImagesSelected++;
					}
					break;
				}

				case ALLEGRO_KEY_9:
				{
					if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 8].isSelected() == SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 8].deselectImage();
						numberImagesSelected--;
					}
					else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 8].isSelected() == NOT_SELECTED)
					{
						arrayImages[(numberPage*IMAGE_PER_SCREEN) + 8].selectImage();
						numberImagesSelected++;
					}
					break;
				}

				case ALLEGRO_KEY_ENTER:
				{
					exitMenu = true;
					break;
				}

				case ALLEGRO_KEY_A:
				{
					for (unsigned int i = 0; i < numberImages; i++)
					{
						arrayImages[i].selectImage();
					}
					numberImagesSelected = numberImages;
					break;
				}

				case ALLEGRO_KEY_N:
				{
					for (unsigned int i = 0; i < numberImages; i++)
					{
						arrayImages[i].deselectImage();
					}
					numberImagesSelected = 0;
					break;
				}

				case ALLEGRO_KEY_LEFT:
				{
					if (numberPage == 0);	//No hace nada
					else
					{
						numberPage--;
					}
					break;
				}

				case ALLEGRO_KEY_RIGHT:
				{
					if (numberPage == (numberPagesMax - 1));	// No hace nada
					else
					{
						numberPage++;
					}
					break;
				}

				}
			}
		}

	}


	for (unsigned int i = 0; i < numberImages; i++)
	{
		if (arrayImages[i].isSelected() == SELECTED)
		{
			pathsSelected.push_back(arrayImages[i].localPathC);
		}
	}

}




void MenuCompress::printImages(void)
{
	unsigned int numberImageAux = (numberPage*IMAGE_PER_SCREEN);
	float x = 0;
	float y = 0;
	float x0Rectangle = 0;
	float y0Rectangle = 0;
	ALLEGRO_COLOR colorRojo = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR colorVerde = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR colorNegro = al_map_rgb(0, 0, 0);
	bool status = false;

	al_clear_to_color(colorNegro);

	for (int i = 0; (i < IMAGE_PER_LINE) && (numberImageAux < numberImages); i++, x += 333.33, x0Rectangle += 333.33)
	{
		for (int j = 0; (j < IMAGE_PER_COLUMN) && (numberImageAux < numberImages); j++, y += 200, y0Rectangle += 200)
		{
			status = arrayImages[numberImageAux].isSelected();
			if (status)
			{
				al_draw_filled_rectangle(x0Rectangle, y0Rectangle, x0Rectangle + 333.33, y0Rectangle + 200, colorVerde);
			}
			else
			{
				al_draw_filled_rectangle(x0Rectangle, y0Rectangle, x0Rectangle + 333.33, y0Rectangle + 200, colorRojo);
			}

			//al_draw_scaled_bitmap(arrayImages[numberImageAux].image, 0, 0, al_get_bitmap_width(arrayImages[numberImageAux].image), al_get_bitmap_height(arrayImages[numberImageAux].image), x, y, 300, 180, 0);
			al_draw_scaled_bitmap(images[numberImageAux], 0, 0, al_get_bitmap_width(images[numberImageAux]), al_get_bitmap_height(images[numberImageAux]), x, y, 300, 180, 0);
			numberImageAux++;
		}
		y0Rectangle = 0;
		y = 0;
	}

	al_flip_display();

}

char * MenuCompress::getPathSelected(unsigned int number)
{
	if (numberImagesSelected == 0)
	{
		cout << "No hay imagenes seleccionadas" << endl;
		return NULL;
	}
	else
	{
		char * answer;
		answer = convert(pathsSelected[number]);
		return answer;
	}

}

char * MenuCompress::convert(const std::string & s)
{
	char *pc = new char[s.size() + 1];
	strcpy(pc, s.c_str());
	return pc;
}

unsigned int MenuCompress::getNumberPathsSelected(void)
{
	return numberImagesSelected;
}


