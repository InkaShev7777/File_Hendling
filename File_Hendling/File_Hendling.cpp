#include <iostream>
using namespace std;
#include"c_File.h"
int main()
{
    int v;
    setlocale(0, "");
    c_File f;
    cout << "������� �������� �����: ";
    string name;
    cin >> name;
    string info;
    string search;
    string rep, zam;
    if (f.Path(name) == 1)
    {
        do
        {
            cout << "\t\t����\n";
            cout << "1 - �������� ���������� � ����\n";
            cout << "2 - ����� �������� ������ � �����\n";
            cout << "3 - ����������� ����� �� �����\n";
            cout << "4 - ��������� ����������� �����\n";
            cout << "5 - ������ ������ �� ����� ������\n";
            cout << "0 - �����\n";
            cin >> v;
            switch (v)
            {
            case 1:
                system("cls");
                cout << "������� ����������: ";
                cin.ignore();
                getline(cin, info);
                f.Add(info);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                cout << "������� ������ ������� ���������� �����: ";
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
                cout << "������� ������ ������� ������ ��������: ";
                cin.ignore();
                getline(cin, rep);
                cout << "������� ������ �� ������� �� ������ ��������: ";
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
        cout << "������ ����� � ������ ���!\n";
    }
}