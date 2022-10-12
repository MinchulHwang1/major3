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
	int ciD = 0;
	int coD = 0;
	double z = 0;
	string arName;
	double totalPrice = 0;


	//이름 넣으면 에러가 뜨는것을 진행 -- 완료
	//배열에 마지막 것만 들어가는 것을 해결해야함


	for (i = 0; i < a; i++) {

		getline(cin, attName[i]); 
		
		arName = attName[i];
		if (arName != "") {   //If there is no name in the attName array  
			getline(cin, checkInDay[i]);
			getline(cin, checkOutDay[i]);
			ciD = dayToIndex(checkInDay[i]);
			coD = dayToIndex(checkOutDay[i]);
			z = calculateCostOfRoom(roomRate, ciD, coD);
		}
		else {
			cout << "Error! Input next Name" << endl;
			error;
		}
	}

	//에러 발생 메세지 출력

	for (i = 0; i < a; i++) {

		arName = attName[i];
		ciD = dayToIndex(checkInDay[i]);
		coD = dayToIndex(checkOutDay[i]);

		if (arName != "") {
			if (ciD != -1) {
				if (coD != -1) {
					cout << attName[i] << " attendancd name " << endl;
					cout << "************** " << checkInDay[i] << endl;
					cout << "--/*-/*-/*-/* " << checkOutDay[i] << endl;
					cout << "calculated price : " << z << endl;
					totalPrice += z;
				}
				else {
					cout << "Error!" << endl;
				}
			}
			else {
				cout << "Error!" << endl;
			}
		}
		else {
			cout << "Error!" << endl;
		}
		/*
		cout << attName[i] << " attendancd name " << endl;
		cout << "************** " << checkInDay[i] << endl;
		cout << "--/*-/*-/*-/* " << checkOutDay[i] << endl;
		cout << "calculated price : " << z << endl;
		*/
	}

	cout << "Total Price : " << totalPrice << endl;

	/*
	for (i = 0; i < a; i++) {
		cout << attName[i] << " attendancd name " << endl;
		cout << "************** " << checkInDay[i] << endl;
		cout << "--/*-/*-/*-/* " << checkOutDay[i] << endl;
		cout << "calculated price : " << z << endl;
	}
	*/





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