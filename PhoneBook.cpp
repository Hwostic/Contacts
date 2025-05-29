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
		cout << "����� ���������!" << endl;
		return;
	}

	char FullName[150], HomePhone[150], WorkPhone[150], Phone[150], Info[150];

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //��� ������������� ����� ���������� ������� �� \ n

	cout << "������� ���: ";
	cin.getline(FullName, 150);
	cout << "�������� �������: ";
	cin.getline(HomePhone, 150);
	cout << "������� �������: ";
	cin.getline(WorkPhone, 150);
	cout << "������ �������: ";
	cin.getline(Phone, 150);
	cout << "���. ����������: ";
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
	if (!Name) cout << "������ �������� ��� �������� ����� �� �������! " << endl;
}

Clients PhoneBook::FindClient(const char* Name) {
	for (int i = 0; i < count; i++)
	{
		if (strcmp(Name, clients[i].getFullName()) == 0) {
			return clients[i];
		}
	}
	cout << "����� �������� �� �������! " << endl;
	Clients empty;
	empty.setFullName("Not Found");
	return empty;
}

void PhoneBook::ShowAllClients() {
	cout << "���������� �����: " << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "������� � " << i+1<< endl;
		cout << "���: " << clients[i].getFullName() << endl;
		cout << "�������� �������: " << clients[i].getHomePhone() << endl;
		cout << "������� �������: " << clients[i].getWorkPhone() << endl;
		cout << "������ �������:" << clients[i].getPhone() << endl;
		cout << "�������������� ����������: " << clients[i].getInfo() << endl << endl;

	}
}


void PhoneBook::SaveFile(const char* FileName) {

	 //������� ����������, ������� ������ ���������� �����
	string exp = ".txt";

	ofstream file(FileName+exp); //��������� � ����� ����� ����������

	
	if (!file.is_open())
	{
		cout << "���� �� ��������";
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

	//������� ����������, ������� ������ ���������� �����
	string exp = ".txt";

	ifstream inFile(FileName+exp); 
	if (!inFile.is_open()) {
		cout << "������: �� ������� ������� ����" << endl;
		return;
	}
	count = 0;

	inFile >> count;
	inFile.ignore();								//����� ���������� ��������� (count) ���������� \n, ����� ���������� ��� � �.�
	for (int i = 0; i < count; i++) {
		Clients entry;
		char buffer[256];							//���������� �������������� �������, ���� ������������ ������
		inFile.getline(buffer, sizeof(buffer));		//�������� ������ � �� ������
		entry.setFullName(buffer);					//�������� �������� ����� �������


		inFile.getline(buffer, sizeof(buffer));
		entry.setHomePhone(buffer);


		inFile.getline(buffer, sizeof(buffer));
		entry.setWorkPhone(buffer);


		inFile.getline(buffer, sizeof(buffer));
		entry.setPhone(buffer);


		inFile.getline(buffer, sizeof(buffer));
		entry.setInfo(buffer);

		clients[i] = entry; //����� ������ ������� �������� ��� ��������
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