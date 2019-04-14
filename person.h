#pragma once

#include <vector>
#include <map>
#include <set>

using std::map;

class person {
private:
	map<std::string, int> yeniduzen;				//gunluk bazda tutuyor
	map<std::string, int> yeniduzen2;				//aylýk bazda tutuyor
	
	std::string tarih, month;
	int hour, min, in_time_day, in_time_month;;
	bool in;

public:
	char *name, *surname;
	
	person();
	person(char*, char*);

	void kayit(std::string, std::string, int, int, bool, bool);
	int print(std::string);
	int print_month(std::string);
};