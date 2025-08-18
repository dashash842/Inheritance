#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	//1)создание потока:
	std::ofstream fout;
	//2открытие потока:
	//fout.open("File.txt");  //поток открытый таким образом всегда будет перезаписывать файлю
	fout.open("File.txt", std::ios_base::app); //Append-добавить в конец
	//3)запись в поток:
	fout << "hello files" << endl;
	//4)Потоки обязательно нужно закрывать:
	fout.close();

	system("notepad file.txt");
#endif // WRITE_TO_FILE

	//1) Создаем и открываем поток:
	std::ifstream fin("File.txt");

	//2)проверяем, открылся ли поток:
	if (fin.is_open())
	{
		//3)TODO read from file:  чтение из файла:
		while (!fin.eof()) //EndOfFile
		{
			std::string buffer;
			//fin >> buffer;
			std::getline(fin, buffer);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}

	//?) закрываем поток:
	fin.close();

}