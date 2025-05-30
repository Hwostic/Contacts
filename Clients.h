#pragma once

//класс, где хранятся переменные, сеттеры и геттеры

class Clients
{
private:
	char* FullName;
	char HomePhone[15];
	char WorkPhone[15];
	char Phone[15];
	char Info[150];

public:

	Clients();
	Clients(const char* FullName, const char* HomePhone, const char* WorkPhone, const char* Phone, const char* Info);
	
	Clients& operator=(const Clients& other);
	~Clients();

	void setFullName(const char* FullName);
	void setHomePhone(const char* HomePhone);
	void setWorkPhone(const char* WorkPhone);
	void setPhone(const char* Phone);
	void setInfo(const char* Info);


	char* getFullName();
	char* getHomePhone();
	char* getWorkPhone();
	char* getPhone();
	char* getInfo();

	void Information();

};

