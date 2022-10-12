#include<iostream>
#include<sstream>
#include<string>

//#include<>
using namespace std;


int dayToIndex(string day);
double calculateCostOfRoom(const double rent[], int ciD, int coD);
const int error = -1;

int main() {
	const double roomRate[6] = { 127.50, 128.25, 130.50, 150, 150, 162.50 };
	int i = 0;
	int a = 2;
	string attName[4] = { };
	string checkInDay[4];
	string checkOutDay[4];
	int x = 0;
	int y = 0;
	double z = 0;

	//이름 넣으면 에러가 뜨는것을 진행
	for (i = 0; i < a; i++) {


		getline(cin, attName[i]); //이름에 배열 인자를 넣었다.

		//왜 attname 의 배열안에 들어가는 것이 없을까?


		if (attName[i] != "") {   //If there is no name in the attName array
			getline(cin, checkInDay[i]);
			getline(cin, checkOutDay[i]);
			x = dayToIndex(checkInDay[i]);
			y = dayToIndex(checkOutDay[i]);
			z = calculateCostOfRoom(roomRate, x, y);
		}
		else {
			error;
		}
	}

	for (i = 0; i < a; i++) {
		cout << attName[i] << " attendancd name " << endl;
		cout << "************** " << checkInDay[i] << endl;
		cout << "--/*-/*-/*-/* " << checkOutDay[i] << endl;
		cout << "calculated price : " << z << endl;
	}
	



	//under code is safe. not error without attName[i]
	/*
	
	for (i = 0; i < a; i++) {
		
		
		getline(cin, attName[i]);
		getline(cin, checkInDay[i]);
		getline(cin, checkOutDay[i]);
		x = dayToIndex(checkInDay[i]);
		y = dayToIndex(checkOutDay[i]);
		z = calculateCostOfRoom(roomRate, x, y);

		cout << attName[i] << " attendancd name " << endl;
		cout << "************** " << x << endl;
		cout << "--/*-/*-/*-/* " << y << endl;
		cout << "calculated price : " << z << endl;
	}*/
		return 0;
	
}

int dayToIndex(string day) {
	if (day == "sun") {
		return 0;
	}
	else if (day == "mon") {
		return 1;
	}
	else if (day == "tue") {
		return 2;
	}
	else if (day == "wed") {
		return 3;
	}
	else if (day == "thu") {
		return 4;
	}
	else if (day == "fri") {
		return 5;
	}
	else if (day == "sat") {
		return 6;
	}
	else {
		return error;
	}
}

double calculateCostOfRoom(const double rent[], int ciD, int coD) {
	double total = 0;
	
	if (ciD > 4 || coD < 4) {
		return error;
	}
	else if (ciD == coD) {
		return error;
	}
	else {
		for (ciD; ciD < coD; ciD++) {
			total += rent[ciD];
		}
	}

	return total;
}