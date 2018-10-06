#include "Image.h"

using namespace std;

Image::Image(void)
{

}

void Image::initImage(string path)
{
	deselectImage();
	localPath = path;
	alInitImage();
}

bool Image::isSelected(void)
{
	return selected;
}

bool Image::alInitImage(void)
{
	const char * localPathC = localPath.c_str();

	image = al_load_bitmap(localPathC);
	if (!image) 
	{
		cout << "Error al cargar la imagen (" << localPathC << ")" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

void Image::selectImage(void)
{
	selected = true;
}

void Image::deselectImage(void)
{
	selected = false;
}

ALLEGRO_BITMAP * Image::getBitmapImage(void)
{
	return image;
}

string Image::getPath(void)
{
	return localPath;
}
