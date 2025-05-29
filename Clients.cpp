#include "Clients.h"
#include <iostream>
#include <cstring>
using namespace std;


void Clients::setFullName(const char* name) {
	if (FullName) {
		delete[] FullName;
	}
	int len = strlen(name);
	FullName = new char[len + 1];
	strcpy_s(FullName, len + 1, name);
}


void Clients::setHomePhone(const char* HomePhone)
{
	strcpy_s(this->HomePhone, HomePhone);
};

void Clients::setWorkPhone(const char* WorkPhone)
{
	strcpy_s(this->WorkPhone, WorkPhone);
};
void Clients::setPhone(const char* Phone)
{
	strcpy_s(this->Phone, Phone);
};
void Clients::setInfo(const char* Info)
{
	strcpy_s(this->Info, Info);
};


char* Clients::getFullName()
{
	if (FullName == nullptr) {
		return nullptr;
	}
	return FullName;
};
char* Clients::getHomePhone()
{
	return HomePhone;
};
char* Clients::getWorkPhone()
{
	return WorkPhone;
};
char* Clients::getPhone()
{
	return Phone;
};
char* Clients::getInfo()
{
	return Info;
};

void Clients::Information()
{
	cout << "Данные абонента: " << endl;
	cout << "ФИО:" << FullName << endl;
	cout << "Домашний номер: " << HomePhone << endl;
	cout << "Рабочий номер: " << WorkPhone << endl;
	cout << "Личный номер: " << Phone << endl;
	cout << "Дополнительная информация: " << Info << endl;

}


Clients::Clients() {
	FullName = nullptr;           // Инициализируем указатель на nullptr
	HomePhone[0] = '\0';          // Инициализируем строки пустой строкой
	WorkPhone[0] = '\0';
	Phone[0] = '\0';
	Info[0] = '\0';
}

Clients::Clients(const char* FullName, const char* HomePhone, const char* WorkPhone, const char* Phone, const char* Info) {
// раз мы сразу не задаем значение нужно сделать nullptr динамическую память
	this->FullName = nullptr;
	setFullName(FullName);
	strcpy_s(this->HomePhone, HomePhone);
	strcpy_s(this->WorkPhone, WorkPhone);
	strcpy_s(this->Phone, Phone);
	strcpy_s(this->Info, Info);
}


// Оператор присваивания
Clients & Clients::operator=(const Clients & other) {
	if (this != &other) { // проверка на присваивание самому себе
	
		if (other.FullName) {
			int len = strlen(other.FullName);
			FullName = new char[len + 1];
			strcpy_s(FullName, len + 1, other.FullName);
		}
		else {
			FullName = nullptr;
		}
		strcpy_s(HomePhone, other.HomePhone);
		strcpy_s(WorkPhone, other.WorkPhone);
		strcpy_s(Phone, other.Phone);
		strcpy_s(Info, other.Info);
	}
	return *this;
}

Clients::~Clients() {

	delete[] FullName;

}

