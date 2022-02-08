#include <iostream>
using namespace std;
#include"c_File.h"
int main()
{
    int v;
    setlocale(0, "");
    c_File f;
    cout << "Введите название файла: ";
    string name;
    cin >> name;
    string info;
    string search;
    string rep, zam;
    if (f.Path(name) == 1)
    {
        do
        {
            cout << "\t\tМеню\n";
            cout << "1 - Добавить информацию в файл\n";
            cout << "2 - Поиск заданной строки в файле\n";
            cout << "3 - Отображение файла на экран\n";
            cout << "4 - Переворот содержимого файла\n";
            cout << "5 - Замена строки на новую строку\n";
            cout << "0 - Выход\n";
            cin >> v;
            switch (v)
            {
            case 1:
                system("cls");
                cout << "Введите информацию: ";
                cin.ignore();
                getline(cin, info);
                f.Add(info);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                cout << "Введите строку которую необходимо найти: ";
                cin.ignore();
                getline(cin, search);
                f.String_Search(search);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                f.Show();
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                f.Reverse_Srting();
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                cout << "Введите строку которую хотите заменить: ";
                cin.ignore();
                getline(cin, rep);
                cout << "Введите строку на которую вы хотите заменить: ";
                getline(cin, zam);
                f.String_replacement(rep, zam);
                system("pause");
                system("cls");
                break;
            }

        } while (v != 0);
    }
    else
    {
        cout << "Такого файла в списке нет!\n";
    }
}