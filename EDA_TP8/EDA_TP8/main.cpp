#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "Menu.h"


using namespace std;
using namespace boost::filesystem;





int main(void)
{
	unsigned int countPngFiles = 0;
	const char * paths = "./";




	vector<string> filesS;



	path p(paths);

	if (exists(p))
	{
		if (is_directory(p))
		{
			for (directory_iterator itr(p); itr != directory_iterator(); itr++)
			{
				if (itr->path().extension().string() == ".png")
				{
					filesS.push_back(itr->path().filename().string());
					countPngFiles++;
				}
			}

		}
	}
	else
	{
		cout << " No existe la ruta" << endl;
	}

	if (countPngFiles != 0)
	{
		Menu menu(filesS, 12);
		menu.enterMenu();
		menu.~Menu();
		string * pathSelected = menu.getPathsSelected();
		//printf("%s", pathSelected[0]);
		getchar();
	}
	else
	{
		cout << "No hay imagenes .png para comprimir" << endl;
		cout << "Presione enter para finalizar el programa" << endl;
		getchar();
	}

	return 0;
}

