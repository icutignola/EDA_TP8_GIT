#include "Menu.h"


Menu::Menu(string arrayPath[], unsigned int numberPath)
{
	numberImages = numberPath;
	arrayImages = new Image[numberImages];	// Genero la cantidad de imagenes que me indica numberPath

	display = NULL;
	colaEventos = NULL;

	initAllegro();

	if (arrayImages != NULL)
	{
		for (int i = 0; i < numberImages; i++)
		{
			arrayImages->initImage(arrayPath[i]);
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

void Menu::enterMenu(void)
{
	ALLEGRO_EVENT evento;
	while (exitMenu == false)
	{
		printImages();
		if (al_get_next_event(colaEventos, &evento))
		{
			if (evento.type == ALLEGRO_KEY_DOWN)
			{
				switch (evento.keyboard.keycode)
				{
					case ALLEGRO_KEY_1:
					{
						if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 0].isSelected() == SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 0].selectImage();
							numberImagesSelected++;
						}
						else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 0].isSelected() == NOT_SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 0].deselectImage();
						}
						break;
					}

					case ALLEGRO_KEY_2:
					{
						if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 1].isSelected() == SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 1].selectImage();
							numberImagesSelected++;
						}
						else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 1].isSelected() == NOT_SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 1].deselectImage();
						}
						break;
					}

					case ALLEGRO_KEY_3:
					{
						if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 2].isSelected() == SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 2].selectImage();
							numberImagesSelected++;
						}
						else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 2].isSelected() == NOT_SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 2].deselectImage();
						}
						break;
					}

					case ALLEGRO_KEY_4:
					{
						if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 3].isSelected() == SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 3].selectImage();
							numberImagesSelected++;
						}
						else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 3].isSelected() == NOT_SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 3].deselectImage();
						}
						break;
					}

					case ALLEGRO_KEY_5:
					{
						if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 4].isSelected() == SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 4].selectImage();
							numberImagesSelected++;
						}
						else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 4].isSelected() == NOT_SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 4].deselectImage();
						}
						break;
					}

					case ALLEGRO_KEY_6:
					{
						if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 5].isSelected() == SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 5].selectImage();
							numberImagesSelected++;
						}
						else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 5].isSelected() == NOT_SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 5].deselectImage();
						}
						break;
					}

					case ALLEGRO_KEY_7:
					{
						if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 6].isSelected() == SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 6].selectImage();
							numberImagesSelected++;
						}
						else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 6].isSelected() == NOT_SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 6].deselectImage();
						}
						break;
					}

					case ALLEGRO_KEY_8:
					{
						if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 7].isSelected() == SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 7].selectImage();
							numberImagesSelected++;
						}
						else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 7].isSelected() == NOT_SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 7].deselectImage();
						}
						break;
					}

					case ALLEGRO_KEY_9:
					{
						if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 8].isSelected() == SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 8].selectImage();
							numberImagesSelected++;
						}
						else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + 8].isSelected() == NOT_SELECTED)
						{
							arrayImages[(numberPage*IMAGE_PER_SCREEN) + 8].deselectImage();
						}
						break;
					}

					case ALLEGRO_KEY_ENTER:
					{
						exitMenu = true;
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

	pathsSelected = new string[numberImagesSelected];

	for (int i = 0; i < numberImages; i++)
	{
		if (arrayImages[i].isSelected() == SELECTED)
		{
			pathsSelected[i] = arrayImages[i].getPath();
		}
	}
}

string * Menu::getPathsSelected(void)
{
	return pathsSelected;
}

bool Menu::initAllegro(void)
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

	colaEventos = al_create_event_queue();
	if (!colaEventos)
	{
		cout << "Error al inicializar la cola de eventos" << endl;
		return false;
	}

	if (!al_init_primitives_addon()) 
	{
		cout << "Error al inicializar las primitivas" << endl;
		al_destroy_event_queue(colaEventos);
		return false;
	}

	display = al_create_display(WIDE, HEITH);
	if (!display)
	{
		cout << "Error al inicializar el display" << endl;
		al_shutdown_primitives_addon();
		al_destroy_event_queue(colaEventos);
		return false;
	}

	al_register_event_source(colaEventos, al_get_display_event_source(display));
	al_register_event_source(colaEventos, al_get_keyboard_event_source());

	return true;
}

void Menu::printImages(void)
{

	ALLEGRO_BITMAP * imageAux;
	unsigned int numberImageAux = 0;
	float x = ((WIDE/IMAGE_PER_LINE)/2);
	float y = ((HEITH/IMAGE_PER_COLUMN)/2);
	float x0Rectangle = 0;
	float y0Rectangle = 0;
	ALLEGRO_COLOR colorRojo = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR colorVerde = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR colorNegro = al_map_rgb(255, 255, 255);

	al_clear_to_color(colorNegro);

	for (int i = 0; (i < IMAGE_PER_LINE) && (numberImageAux < numberImages); i++, x += (WIDE / IMAGE_PER_LINE), x0Rectangle += (WIDE / IMAGE_PER_LINE))
	{
		for (int j = 0; (j < IMAGE_PER_COLUMN) && (numberImageAux < numberImages); j++, y += (HEITH / IMAGE_PER_COLUMN), y0Rectangle += (HEITH / IMAGE_PER_COLUMN))
		{
			if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + numberImageAux].isSelected() == SELECTED)
			{
				al_draw_filled_rectangle(x0Rectangle, y0Rectangle, x0Rectangle + (WIDE / IMAGE_PER_LINE), y0Rectangle + (HEITH / IMAGE_PER_COLUMN), colorVerde);
			}
			else if (arrayImages[(numberPage*IMAGE_PER_SCREEN) + numberImageAux].isSelected() == NOT_SELECTED)
			{
				al_draw_filled_rectangle(x0Rectangle, y0Rectangle, x0Rectangle + (WIDE / IMAGE_PER_LINE), y0Rectangle + (HEITH / IMAGE_PER_COLUMN), colorRojo);
			}
			imageAux = arrayImages[(numberPage*IMAGE_PER_SCREEN) + numberImageAux].getBitmapImage();
			al_draw_scaled_bitmap(imageAux, 0, 0, al_get_bitmap_width(imageAux), al_get_bitmap_height(imageAux), x, y, 150, 150, 0);

			numberImageAux++;
		}
	}
			
	al_flip_display();
	
}