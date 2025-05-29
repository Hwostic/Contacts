#include "PhoneBook.h"
#include "Clients.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    bool exit = false;
    char Name[150];
    char filename[256];
    int choice;
    PhoneBook phoneBook;
   
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить нового абонента" << endl;
        cout << "2. Удалить абонента" << endl;
        cout << "3. Найти абонента по ФИО" << endl;
        cout << "4. Посмотреть всех абонентов" << endl;
        cout << "5. Сохранить телефонную книгу в файл" << endl;
        cout << "6. Загрузить телефонную книгу из файла" << endl;
        cout << "7. Выйти из меню" << endl;
        cout << "-> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            phoneBook.addNewClient();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 2:
            cout << "Введите ФИО абонента для удаления: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(Name, 150);
            phoneBook.DeleteClients(Name);
            break;
           
        case 3:
            cout << "Введите ФИО абонента для поиска" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(Name, 150);
            phoneBook.FindClient(Name).Information();
            break;
        case 4:
            phoneBook.ShowAllClients();
            break;
        case 5:
            cout << "Введите имя файла для сохранения: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(filename, 256);
            phoneBook.SaveFile(filename);
            break;
         case 6:
            cout << "Введите имя файла для загрузки: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(filename, 256);
            phoneBook.ReadFile(filename);
            break;
          
        case 7:
            exit = true;
            break;
        default:
            cout << "В меню такого пункта нет" << endl;
            break;
        }
    } while (exit != true);
}
