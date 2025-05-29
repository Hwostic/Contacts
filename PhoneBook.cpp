#include "PhoneBook.h"
#include "Clients.h"
#include <iostream>
#include <fstream>


using namespace std;



PhoneBook::PhoneBook()
{
	count = 0;
};

void PhoneBook::addNewClient() {
	if (count >= 100) {
		cout << "Книга заполнена!" << endl;
		return;
	}

	char FullName[150], HomePhone[150], WorkPhone[150], Phone[150], Info[150];

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //для игнорирования после введенного символа до \ n

	cout << "Введите ФИО: ";
	cin.getline(FullName, 150);
	cout << "Домашний телефон: ";
	cin.getline(HomePhone, 150);
	cout << "Рабочий телефон: ";
	cin.getline(WorkPhone, 150);
	cout << "Личный телефон: ";
	cin.getline(Phone, 150);
	cout << "Доп. информация: ";
	cin.getline(Info, 150);

	clients[count++] = Clients(FullName, HomePhone, WorkPhone, Phone, Info);
	
}




void PhoneBook::DeleteClients(const char* Name) {
	for (int i = 0; i < count; i++)
	{
		if (strcmp(Name, clients[i].getFullName()) == 0) {
			for (int j = i; j < count - 1; j++) {
				clients[j] = clients[j + 1];
			}
			count--;
			break;
			return;
		}

	}
	if (!Name) cout << "Такого абонента для удаления найти не удалось! " << endl;
}

Clients PhoneBook::FindClient(const char* Name) {
	for (int i = 0; i < count; i++)
	{
		if (strcmp(Name, clients[i].getFullName()) == 0) {
			return clients[i];
		}
	}
	cout << "Найти абонента не удалось! " << endl;
	Clients empty;
	empty.setFullName("Not Found");
	return empty;
}

void PhoneBook::ShowAllClients() {
	cout << "Телефонная книга: " << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Абонент № " << i+1<< endl;
		cout << "ФИО: " << clients[i].getFullName() << endl;
		cout << "Домашний телефон: " << clients[i].getHomePhone() << endl;
		cout << "Рабочий телефон: " << clients[i].getWorkPhone() << endl;
		cout << "Личный телефон:" << clients[i].getPhone() << endl;
		cout << "Дополнительная информация: " << clients[i].getInfo() << endl << endl;

	}
}


void PhoneBook::SaveFile(const char* FileName) {

	 //создаем переменную, которая хранит расширение файла
	string exp = ".txt";

	ofstream file(FileName+exp); //добавляем к имени файла расширение

	
	if (!file.is_open())
	{
		cout << "Файл не открылся";
		return;
	}
	file << count << endl;
	for (int i = 0; i < count; i++)
	{
		file << clients[i].getFullName() << endl;
		file << clients[i].getHomePhone() << endl;
		file << clients[i].getWorkPhone() << endl;
		file << clients[i].getPhone() << endl;
		file << clients[i].getInfo() << endl;
	}
	file.close();

}
void PhoneBook::ReadFile(const char* FileName) {

	//создаем переменную, которая хранит расширение файла
	string exp = ".txt";

	ifstream inFile(FileName+exp); 
	if (!inFile.is_open()) {
		cout << "Ошибка: не удалось открыть файл" << endl;
		return;
	}
	count = 0;

	inFile >> count;
	inFile.ignore();								//после количества абонентов (count) игнорируем \n, чтобы записалось фио и т.д
	for (int i = 0; i < count; i++) {
		Clients entry;
		char buffer[256];							//переменная фиксированного размера, куда записывается строка
		inFile.getline(buffer, sizeof(buffer));		//получаем строку и ее размер
		entry.setFullName(buffer);					//передаем значение через функцию


		inFile.getline(buffer, sizeof(buffer));
		entry.setHomePhone(buffer);


		inFile.getline(buffer, sizeof(buffer));
		entry.setWorkPhone(buffer);


		inFile.getline(buffer, sizeof(buffer));
		entry.setPhone(buffer);


		inFile.getline(buffer, sizeof(buffer));
		entry.setInfo(buffer);

		clients[i] = entry; //здесь объект клиента получает все сведения
	}

	inFile.close();
}

PhoneBook::~PhoneBook() {
	char* arr;
	for (int i = 0; i < count; i++) {
		arr = clients[i].getFullName();
		delete[] arr;
	}
}