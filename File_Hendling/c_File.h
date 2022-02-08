#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
class c_File
{
public:
	bool Path(std::string path)
	{
		if (path == "File.txt")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Add(std::string str)
	{
		std::fstream f;
		f.open("File.txt", std::ios::out | std::ios::app);
		if (f.is_open())
		{
		f << str<<"\n";
		}
		else
		{
			std::cout << "Error!\n";
		}
		f.close();
	}
	void String_Search(std::string str)
	{
		std::fstream f;
		std::string str2;
		int a = 0;
		f.open("File.txt", std::ios::in);
		while (!f.eof())
		{
			std::getline(f, str2);
			if (str2.find(str)<= str2.length())
			{
				a++;
			}
		}
		std::cout << "Stat: " << a << "\n";
		f.close();
	}
	void Show()
	{
		std::fstream f;
		f.open("File.txt", std::ios::in);
		std::string str3;
		if (f.is_open())
		{
			while (!f.eof())
			{
				str3 = " ";
				std::getline(f, str3);
				std::cout << str3<<"\n";
			}
		}
		else
		{
			std::cout << "Error!\n";
		}
		f.close();
	}
	void Reverse_Srting()
	{
		std::fstream f;
		std::string str1;
		f.open("File.txt", std::ios::in);
		if (f.is_open())
		{
			while (!f.eof())
			{
				str1 = " ";
				std::getline(f, str1);
				int len = str1.length();
				for (int i = 0; i < len; i++)
				{
					if (str1[i] != ' ' || str1[len - 1] != ' ')
					{
						char zamena = str1[i];
						str1[i] = str1[len - 1];
						str1[len - 1] = zamena;
						len--;
					}
				}
				std::cout << str1 << "\n";
			}
		}
		else
		{
			std::cout << "Error!\n";
		}
		f.close();
	}
	void String_replacement(std::string rep, std::string zam)
	{
		std::fstream f;
		std::fstream f2;
		f2.open("Rep.txt", std::ios::out);
		int a = 0;
		std::string str;
		f.open("File.txt", std::ios::in);
		while (!f.eof())
		{
			str = " ";
			std::getline(f, str);
			if (str.find(rep) <= str.length())
			{
				a++;
				f2 << zam << "\n";
			}
			else
			{
				f2 << str << "\n";
			}
		}
		f.close();
		f2.close();
		f2.open("Rep.txt", std::ios::in);
		f.open("File.txt", std::ios::out);
		f.clear();
		if (f2.is_open())
		{
			while (!f2.eof())
			{
				std::getline(f2, str);
				f << str << "\n";
			}
		}
		else
		{
			std::cout << "Error!\n";
		}
		std::cout << "Stat: " << a << "\n";
		f2.close();
		f.close();
		remove("Rep.txt");
	}
};

