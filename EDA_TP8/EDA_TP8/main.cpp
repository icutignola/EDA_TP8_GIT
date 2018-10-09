#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "MenuCompress.h"
#include "MenuDescompress.h"




using namespace std;
using namespace boost::filesystem;



int main(int argc, char * argv[])
{
	unsigned int countPngFiles = 0;
	const char * paths = "./imagenes/";
	const char * pathD = "./imegenes_comprimidas/";

	string pathS(paths);
	char * pathSelected;


	//**************************  COMPRESS  *******************************
	vector<string> filesC;	// Vector para guardar los archivos .png

	//****************  BUSCO LOS ARCHIVOS .PNG  *****************
	path p(paths);
	if (exists(p))
	{
		if (is_directory(p))
		{
			for (directory_iterator itr(p); itr != directory_iterator(); itr++)
			{
				if (itr->path().extension().string() == ".png")
				{
					pathS += itr->path().filename().string();
					filesC.push_back(pathS);
					pathS = (paths);
					countPngFiles++;
				}
			}

		}
	}
	else
	{
		cout << " No existe la ruta" << endl;
	}
	//************************************************************

	if (countPngFiles != 0)
	{
		MenuCompress menuC(filesC, countPngFiles);
		menuC.enterMenu();
		unsigned int numberSelected = menuC.getNumberPathsSelected();
		for (unsigned int i = 0; i < numberSelected; ++i)
		{
			pathSelected = menuC.getPathSelected(i);
			cout << pathSelected << endl;
			//void FuncionParaComprimir (pathSeleted);
		}
		getchar();
		menuC.~MenuCompress();
	}
	else
	{
		cout << "No hay imagenes .png para comprimir" << endl;
		cout << "Presione enter para finalizar el programa" << endl;
		getchar();
	}
	//*********************************************************************

	/*
	//************************  DESCOMPRESS  ******************************
		unsigned int countTxtFiles = 0;
		vector<string> filesD;	// Vector para guardar los archivos .png

		//****************  BUSCO LOS ARCHIVOS .PNG  *****************
		path p2(pathD);
		if (exists(p2))
		{
			if (is_directory(p2))
			{
				for (directory_iterator itr(p2); itr != directory_iterator(); itr++)
				{
					if (itr->path().extension().string() == ".txt")
					{
						filesD.push_back(itr->path().filename().string());
						countTxtFiles++;
					}
				}

			}
		}
		else
		{
			cout << " No existe la ruta" << endl;
		}
		//************************************************************

		if (countTxtFiles != 0)
		{
			MenuDescompress menuD(filesD, countTxtFiles);
			menuD.enterMenu();
			unsigned int numberSelected = menuD.getNumberPathsSelected();
			for (unsigned int i = 0; i < numberSelected; ++i)
			{
				pathSelected = menuD.getPathSelected(i);
				cout << pathSelected << endl;
				//void FuncionParaComprimir (pathSeleted);
			}
			getchar();
			menuD.~MenuDescompress();
		}
		else
		{
			cout << "No hay imagenes .txt para descomprimir" << endl;
			cout << "Presione enter para finalizar el programa" << endl;
			getchar();
		}
		*/
		//*********************************************************************

	return 0;
}
