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
	double calculatedPrice = 0;
	string arName;
	double totalPrice = 0;


	//에러값을 반환할때 0으로 반환하여 error가 뜨게해야함.
	//에러 값을 반환할때 값으로 반환하는 것을 해야함(돈 계산)
	//계산값을 변경해야함

	/*
	for (i = 0; i < a; i++) {

		getline(cin, attName[i]); 
		
		arName = attName[i];
		if (arName != "") {   //If there is no name in the attName array  
			getline(cin, checkInDay[i]);
			getline(cin, checkOutDay[i]);
			ciD = dayToIndex(checkInDay[i]);
			coD = dayToIndex(checkOutDay[i]);
			calculatedPrice = calculateCostOfRoom(roomRate, ciD, coD);
		
			cout << "Attendee name is : " <<  attName[i] << endl;
			cout << "'" << attName[i] << "'s Check in day is : " << checkInDay[i] << endl;
			cout << "'" << attName[i] << "'s Check out day is : " << checkOutDay[i] << endl;
			cout << "'" << attName[i] << "'s calculated price : " << calculatedPrice << endl;
			cout << endl;
			
		}
		else {
			cout << "Error! Input next Name" << endl;
			error;
		}
	}
	*/


	for (i = 0; i < a; i++) {
		cout << "Insert Attendee's name : ";
		getline(cin, attName[i]);

		arName = attName[i];
		if (arName != "") {   //If there is no name in the attName array  
			cout << "Valid day : sun, mon, tue, wed, thu, fri, sat" << endl;

			cout << "Insert Check-In Day : ";
			getline(cin, checkInDay[i]);
			ciD = dayToIndex(checkInDay[i]);

			if (ciD != -1) {
				cout << "Insert Check-Out Day : ";
				getline(cin, checkOutDay[i]);
				coD = dayToIndex(checkOutDay[i]);
				if (coD != -1) {
					calculatedPrice = calculateCostOfRoom(roomRate, ciD, coD);
					cout << "Attendee name is : " << attName[i] << endl;
					cout << "'" << attName[i] << "'s Check in day is : " << checkInDay[i] << endl;
					cout << "'" << attName[i] << "'s Check out day is : " << checkOutDay[i] << endl;
					cout << "'" << attName[i] << "'s calculated price : " << calculatedPrice << endl;
					cout << endl;
				}
				else {
					cout << "Error!" << endl;
				}
			}
			else {
				cout << "Error : You insert wrong Check-In day" << endl;
			}
		
			//calculatedPrice = calculateCostOfRoom(roomRate, ciD, coD);
			/*
			cout << "Attendee name is : " << attName[i] << endl;
			cout << "'" << attName[i] << "'s Check in day is : " << checkInDay[i] << endl;
			cout << "'" << attName[i] << "'s Check out day is : " << checkOutDay[i] << endl;
			cout << "'" << attName[i] << "'s calculated price : " << calculatedPrice << endl;
			cout << endl;
			*/
		}
		else {
			cout << "Error! Input next Name" << endl;
			error;
		}
	}

	cout << "Total Price : " << totalPrice << endl;

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