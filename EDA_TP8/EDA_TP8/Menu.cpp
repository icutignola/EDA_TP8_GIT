#include "Menu.h"


Menu::Menu(vector<string>& arrayPath, unsigned int numberPath)
{
	numberImages = numberPath;
	arrayImages = new Image[numberImages];	// Genero la cantidad de imagenes que me indica numberPath
	display = NULL;
	colaEventos = NULL;

	for (vector<string>::iterator iter = arrayPath.begin(); iter != arrayPath.end(); ++iter)
		cout << *iter << endl;

	//initAllegro(arrayPath);

	if (arrayImages != NULL)
	{
		for (unsigned int i = 0; i < numberImages; i++)
		{
			//cout << arrayPath[i];
			//arrayImages->initImage(arrayPath[i].c_str);
		}
	}



	numberPage = 0;
	numberPagesMax = numberImages / IMAGE_PER_SCREEN;
	if (numberImages % IMAGE_PER_SCREEN == 0);	//No hace nada
	else
	{
		numberPagesMax++;
	}

	exitMenu = false;

}

Menu::~Menu(void)
{
	al_destroy_display(display);
	al_shutdown_image_addon();
	al_shutdown_primitives_addon();
	al_destroy_event_queue(colaEventos);
}

void Menu::enterMenu(void)
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

	//pathsSelected = new char*[0];
	//unsigned int j = 0;

	//cout << arrayImages[0].localPath;

	//pathsSelected[0] = arrayImages[0].localPathC;

	/*
	for (unsigned int i = 0; i < numberImages && j < numberImagesSelected ; i++)
	{
		if (arrayImages[i].isSelected() == SELECTED)
		{
			pathsSelected[j] = arrayImages[i].getPath();
			j++;
		}
	}
	*/
}

string * Menu::getPathsSelected(void)
{
	//return pathsSelected;
	return 0;
}

bool Menu::initAllegro(vector<string>& arrayPath)
{
	if (!al_init())
	{
		cout << "Error al inicializar allegro" << endl;
		return false;
	}

	if (!al_install_keyboard())
	{
		cout << "Error al inicializar el teclado" << endl;
		return false;
	}

	if (!al_init_image_addon())
	{
		cout << "Error al inicializar los addons de imagenes" << endl;
		return false;
	}


	colaEventos = al_create_event_queue();
	if (!colaEventos)
	{
		cout << "Error al inicializar la cola de eventos" << endl;
		al_shutdown_image_addon();
		return false;

	}


	if (!al_init_primitives_addon())
	{
		cout << "Error al inicializar las primitivas" << endl;
		al_shutdown_image_addon();
		al_destroy_event_queue(colaEventos);
		return false;
	}

	display = al_create_display(WIDE, HEITH);
	if (!display)
	{
		cout << "Error al inicializar el display" << endl;
		al_shutdown_image_addon();
		al_shutdown_primitives_addon();
		al_destroy_event_queue(colaEventos);
		return false;
	}



	for (unsigned int i = 0; i < numberImages; i++)
	{
		//arrayImages[i].image = al_load_bitmap(arrayPath[i].c_str);
		if (arrayImages[i].image == NULL)
		{
			cout << "Error" << endl;
		}
	}

	al_register_event_source(colaEventos, al_get_display_event_source(display));
	al_register_event_source(colaEventos, al_get_keyboard_event_source());

	return true;
}

void Menu::printImages(void)
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

			al_draw_scaled_bitmap(arrayImages[numberImageAux].image, 0, 0, al_get_bitmap_width(arrayImages[numberImageAux].image), al_get_bitmap_height(arrayImages[numberImageAux].image), x, y, 300, 180, 0);

			numberImageAux++;
		}
		y0Rectangle = 0;
		y = 0;
	}

	al_flip_display();

}