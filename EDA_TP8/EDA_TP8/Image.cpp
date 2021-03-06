#include "Image.h"


Image::Image(void)
{
	selected = false;
}

void Image::initImage(const char  *path)
{
	strcpy(localPathC, path);
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


string Image::getPath(void)
{
	return localPath;
}
