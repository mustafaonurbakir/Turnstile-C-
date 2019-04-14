#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale.h>
#include "person.h"

using namespace std;

string hourmin(int min);

int main() {
	setlocale(LC_ALL, "Turkish");
	
	cout << "Çalýþýyor..." << endl;

	ifstream input;
	input.open("a.csv");

	vector<string> kayit;							// mevcut tarihler
	vector<string> kayit2;
	vector<person> people;							// insanlarin listesi
	
	if (!input) 	cout << "Dosya bulunamadý!" << endl;
	else {
		string waste, name, surname, day, hour, min, g_c;		//gecici degerler
		bool gc = false, var, first = true;				

		getline(input, waste);						//first line
		while (input) {
			getline(input, waste, ';');
			getline(input, name, ';');
			getline(input, surname, ';');
			getline(input, day, ' ');			
			getline(input, hour, ':');
			getline(input, min, ';');
			getline(input, g_c, ';');
			if (g_c.substr(0,1) == "G") gc = false;
			if (g_c.substr(0,1) == "Ç") gc = true;
			getline(input, waste);
			
			
			if(kayit2.empty())	kayit2.push_back(day.substr(3, 2));						// aylýk kayýt
			else if (day.substr(3, 2) != kayit[kayit.size() - 1].substr(3, 2)) kayit2.push_back(day.substr(3, 2));
			
			if (first){		kayit.push_back(day);	first = false;}						// tam tarih kaydi
			else if (day != kayit[kayit.size() - 1] || first)	kayit.push_back(day);


			var = false;								// eger kisi daha once varsa kisiye ekleme yapiyor
			vector<person>::iterator v = people.begin();
			for (; v != people.end(); v++) {
				if (v->name == name && v->surname == surname) {
					v->kayit(day, day.substr(3, 2), stoi(hour), stoi(min), gc, 0);
					var = true;
				}
			}
			if (!var) {									// eger kisi yoksa yeni kisi yaratiyor ve ekleme yapiyor
				person *newperson = new person(&name[0u], &surname[0u]);
				newperson->kayit(day, day.substr(3, 2), stoi(hour), stoi(min), gc, 0);
				people.push_back(*newperson);
			}
		
		}
		input.close();
	}

	
	/////////////////////////////////////////////////////////////////////////////////////////////output

	

	ofstream output;
	output.open("b.csv");

	output << "isim;soyad;";											// ilk satýrýn yazýlmasý
	for (int i = 0; i < kayit2.size(); i++)		output << "ay: "<< kayit2[i] << ";";
	for (int i = 0; i < kayit.size(); i++) 		output << kayit[i] << ";";
	output << endl;
	

	vector<person>::iterator v = people.begin();			// degerlerin yazýlmasý
	for (; v != people.end(); v++) {
		v->kayit("00.00.0000", "00", 0, 0, true, 1);													//son kayýtlar maplere kayýt edilmesi icin
		output << v->name << ";" << v->surname << ";";												//isimleri yazýyor
		for (int i = 0; i < kayit2.size(); i++)		output << hourmin(v->print_month(kayit2[i])) << ";";		//aylýk deðerleri yazýyor
		for (int i = 0; i < kayit.size(); i++)		output << hourmin(v->print(kayit[i])) << ";";			//gunluk degerleri yazýyor
		output << endl;
	}


	cout << "bitti!";
	output.close();
	getchar();
	return 0;
}

string hourmin(int min) {
	string a;
	a = to_string(min / 60) + ":" + to_string(min - (min / 60)*60);
	return a;
}