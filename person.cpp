#include "person.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

person::person() {
	in_time_day = in_time_month = min = hour = 0;
	in = false;
	name = surname = NULL;
};

person::person(char *newname, char* newsurname) {
	tarih = "01.01.2017";
	month = "01";
	in_time_day = in_time_month = min = hour = 0;
	in = false;
	name = surname = NULL;
	name = new char[strlen(newname) + 1];
	strcpy(name, newname);
	surname = new char[strlen(newsurname) + 1];
	strcpy(surname, newsurname);
};

void person::kayit(string newtarih, string newmonth, int newhour, int newmin, bool newin, bool finish) {
	if (newin && !finish && in) {
		if (tarih == newtarih && in) {
			in_time_day = in_time_day + (newhour * 60 + newmin) - (hour * 60 + min);
			in = false;

		}
		if (tarih != newtarih && !finish && in) {
			if (stoi(newtarih.substr(0, 2)) < stoi(tarih.substr(0, 2))) {
				if (stoi(newtarih.substr(0, 2)) - stoi(tarih.substr(0, 2)) == 1) {		// çýkýþ kayýp
					in_time_day = in_time_day + (24 * 60 - (hour * 60 + min));

			
					yeniduzen[tarih] = in_time_day;
					in_time_month = in_time_month + in_time_day;
					if (newmonth != month) {
						yeniduzen2[month] = in_time_month;
						in_time_month = 0;
					}
					in_time_day = 0;
					cout << "asdf";
					tarih = newtarih;
					month = newmonth;
					hour = newhour;
					min = newmin;

					in_time_day = in_time_day + (newhour * 60 + newmin);
					in = false;
				}
				else if (stoi(newtarih.substr(0, 2)) - stoi(tarih.substr(0, 2)) > 1) {
					
					in_time_day = in_time_day + (stoi(newtarih.substr(0, 2)) - stoi(tarih.substr(0, 2)) - 1) * 24 * 60;
					in_time_day = in_time_day + (24 * 60 - (hour * 60 + min));


					yeniduzen[tarih] = in_time_day;
					in_time_month = in_time_month + in_time_day;
					if (newmonth != month) {
						yeniduzen2[month] = in_time_month;
						in_time_month = 0;
					}
					in_time_day = 0;

					tarih = newtarih;
					month = newmonth;
					hour = newhour;
					min = newmin;

					in_time_day = in_time_day + (newhour * 60 + newmin);
					in = false;
				}
			}
			else if (stoi(newtarih.substr(0, 2)) < stoi(tarih.substr(0, 2))) {
				if (stoi(tarih.substr(3, 2)) == 1 || stoi(tarih.substr(3, 2)) == 3 || stoi(tarih.substr(3, 2)) == 5 || stoi(tarih.substr(3, 2)) == 7 || stoi(tarih.substr(3, 2)) == 8 || stoi(tarih.substr(3, 2)) == 10 || stoi(tarih.substr(3, 2)) == 12) {
					if (stoi(newtarih.substr(0, 2))+31 - stoi(tarih.substr(0, 2)) > 1) {	
						in_time_day = in_time_day + (stoi(newtarih.substr(0, 2))+31 - stoi(tarih.substr(0, 2)) - 1) * 24 * 60;
						in_time_day = in_time_day + (24 * 60 - (hour * 60 + min));


						yeniduzen[tarih] = in_time_day;
						in_time_month = in_time_month + in_time_day;
						if (newmonth != month) {
							yeniduzen2[month] = in_time_month;
							in_time_month = 0;
						}
						in_time_day = 0;

						tarih = newtarih;
						month = newmonth;
						hour = newhour;
						min = newmin;

						in_time_day = in_time_day + (newhour * 60 + newmin);
						in = false;
					}
				}
				if (stoi(tarih.substr(3, 2)) == 4 || stoi(tarih.substr(3, 2)) == 6 || stoi(tarih.substr(3, 2)) == 9 || stoi(tarih.substr(3, 2)) == 11 ) {
					if (stoi(newtarih.substr(0, 2)) + 30 - stoi(tarih.substr(0, 2)) > 1) {	
						in_time_day = in_time_day + (stoi(newtarih.substr(0, 2))+30 - stoi(tarih.substr(0, 2)) - 1) * 24 * 60;
						in_time_day = in_time_day + (24 * 60 - (hour * 60 + min));


						yeniduzen[tarih] = in_time_day;
						in_time_month = in_time_month + in_time_day;
						if (newmonth != month) {
							yeniduzen2[month] = in_time_month;
							in_time_month = 0;
						}
						in_time_day = 0;

						tarih = newtarih;
						month = newmonth;
						hour = newhour;
						min = newmin;

						in_time_day = in_time_day + (newhour * 60 + newmin);
						in = false;
					}
				}
				if (stoi(tarih.substr(3, 2)) == 2) {
					if (stoi(newtarih.substr(0, 2)) + 28 - stoi(tarih.substr(0, 2)) > 1) {	
						in_time_day = in_time_day + (stoi(newtarih.substr(0, 2))+28 - stoi(tarih.substr(0, 2)) - 1) * 24 * 60;
						in_time_day = in_time_day + (24 * 60 - (hour * 60 + min));


						yeniduzen[tarih] = in_time_day;
						in_time_month = in_time_month + in_time_day;
						if (newmonth != month) {
							yeniduzen2[month] = in_time_month;
							in_time_month = 0;
						}
						in_time_day = 0;

						tarih = newtarih;
						month = newmonth;
						hour = newhour;
						min = newmin;

						in_time_day = in_time_day + (newhour * 60 + newmin);
						in = false;
						
					}
				}
			}

			
		}
	}
	
	if (!newin || finish) {
		if (newtarih != tarih) {
			yeniduzen[tarih] = in_time_day;
			in_time_month = in_time_month + in_time_day;
			if (newmonth != month) {
				yeniduzen2[month] = in_time_month;
				in_time_month = 0;
			}
			in_time_day = 0;
		}
	

		tarih = newtarih;
		month = newmonth;
		hour = newhour;
		min = newmin;
		in = true;
	}
		
}


int person::print(string tarih) {
	map<string, int>::iterator it;
	it = yeniduzen.find(tarih);

	if (it == yeniduzen.end()) 	return 0;
	return yeniduzen[tarih];
}

int person::print_month(string ay) {
	map<string, int>::iterator it;
	it = yeniduzen2.find(ay);

	if (it == yeniduzen2.end()) 	return 0;
	return yeniduzen2[ay];
}
