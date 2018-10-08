#include "Image.h"


Image::Image(void)
{
	selected = false;
}

void Image::initImage(const char  *path)
{

	strcpy(localPathC, path);
	printf("%s", localPathC);
}

bool Image::isSelected(void)
{
	if (selected)
	{
		return true;
	}
	else
	{
		return false;
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
