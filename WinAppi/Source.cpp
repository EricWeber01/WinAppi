#define _CRT_SECURE_NO_WARNINGS
//#define _UNICODE
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include<locale>
#include<codecvt>
#include<vector>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choose;
	do
	{
		cout << "\t" << "Задание №1" << "\n";
		cout << "Ввести строку ANSI. Преобразовать в Unicode и вывести на экран." << "\n";
		cout << "\t" << "Задание №2" << "\n";
		cout << "Ввести строку Unicode. Преобразовать в ANSI и вывести на экран." << "\n";
		cout << "\t" << "Задание №3" << "\n";
		cout << "Считать текст Unicode из файла, используя файловые потоки и вывести на экран." << "\n";
		cout << "\t" << "Задание №4" << "\n";
		cout << "Записать текст Unicode в файла, используя файловые потоки." << "\n";
		cout << "\t" << "Задание №5" << "\n";
		cout << "Дан текстовый файл. В файле содержатся Unicode-символы. Найти длину самой длинной строки, самой короткой строки, среднюю длину строки." << "\n";
		cout << "Выхода ==> 6" << "\n";
		cout << "Введите номер ==> ";
		cin >> choose;
		switch (choose)
		{
		case(1):
		{
			char buffer[] = "Converts ANSI - string to Unicode - string";
			cout << "\n";
			int length = mbstowcs(NULL, buffer, 0);
			wchar_t* ptr = new wchar_t[length];
			mbstowcs(ptr, buffer, length);
			wcout << ptr;
			cout << "\n";
			cout << "Length of Unicode - string ==> " << length << "\n";
			cout << "Size of allocated memory: " << _msize(ptr) << " bytes";
			cout << "\n\n";
			delete[] ptr;
			break;
		}
		case(2):
		{
			cout << "\n";
			wchar_t buffer[128];
			wcout << "Введите строку ==> ";
			wcin >> buffer;
			wcin.ignore();
			int length = WideCharToMultiByte(CP_ACP, 0, buffer, -1, NULL, 0, 0, 0);
			char* ptr = new char[length];
			WideCharToMultiByte(CP_ACP, 0, buffer, -1, ptr, length, 0, 0);
			cout << ptr << "\n";
			cout << "Length of ANSI - string ==> " << strlen(ptr) << "\n";
			cout << "Size of allocated memory ==> " << _msize(ptr) << "\n";
			cout << "\n";
			delete[] ptr;
			break;
		}
		case(3):
		{

			break;
		}
		case(4):
		{
			vector<wstring> vec;
			wifstream file("text.txt");
			wstring buffer;
			while (getline(file, buffer))
			{
				wcout << buffer << "\n";
				vec.push_back(buffer);
			}
			file.close();
			wofstream write("text.txt");
			vec.push_back(L"Hi");
			for (int i = 0; i < vec.size(); i++)
				write << vec[i] << "\n";
			write.close();
			break;
		}
		case(5):
		{
			vector<wstring> vec;
			wifstream file("text2.txt");
			wstring buffer;
			while (getline(file, buffer)) 
			{
				wcout << buffer << "\n";
				vec.push_back(buffer);
			}
			file.close();
			if (vec.size() > 0) 
			{
				int size = vec[0].length();
				int max_i = 0;
				int* sizes = new int[vec.size()];
				for (int i = 0; i < vec.size(); i++) 
				{
					if (size < vec[i].length()) 
					{
						max_i = i;
						size = vec[i].length();
					}
					sizes[i] = vec[i].length();
				}
				wcout << "Large line ==> " << vec[max_i] << "\n";
				int middle = 0;
				for (int i = 0; i < vec.size(); i++)
					middle += sizes[i];
				cout << "Average length ==> " << middle / vec.size();
				cout << "\n";
			}
			break;
		}
		case(6):
		{
			exit(0);
			break;
		}
		}
	} while (choose != 6);
}