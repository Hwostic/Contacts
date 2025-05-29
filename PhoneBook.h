#pragma once
#include "Clients.h"


class PhoneBook
{
private:

	static const int size = 150;
	Clients clients[size];
	int count;
	

public:
	//Наполните класс переменными-членами, функциями-членами, конструкторами, inline-функциями-членами,
	//используйте инициализаторы, реализуйте деструктор.
	//Обязательно необходимо выделять динамически память
	//под ФИО. Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов, искать абонентов по ФИО, показывать всех абонентов, сохранять
	//информацию в файл и загружать из файла.


	PhoneBook();
	void addNewClient();

	void DeleteClients(const char* FullName);
	void ShowAllClients();
	Clients FindClient(const char* Name);
	void SaveFile(const char* FileName);
	void ReadFile(const char* FileName);

	~PhoneBook();

};

