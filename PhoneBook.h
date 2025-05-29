#pragma once
#include "Clients.h"


class PhoneBook
{
private:

	static const int size = 150;
	Clients clients[size];
	int count;
	

public:
	//��������� ����� �����������-�������, ���������-�������, ��������������, inline-���������-�������,
	//����������� ��������������, ���������� ����������.
	//����������� ���������� �������� ����������� ������
	//��� ���. ������������ ������������ ����������� ��������� ����� ���������, ������� ���������, ������ ��������� �� ���, ���������� ���� ���������, ���������
	//���������� � ���� � ��������� �� �����.


	PhoneBook();
	void addNewClient();

	void DeleteClients(const char* FullName);
	void ShowAllClients();
	Clients FindClient(const char* Name);
	void SaveFile(const char* FileName);
	void ReadFile(const char* FileName);

	~PhoneBook();

};

