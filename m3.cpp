#include<iostream>
#include<sstream>
#include<string>


using namespace std;


int dayToIndex(string day);
double calculateCostOfRoom(const double rent[], int ciD, int coD);
const int errorValue = -1;

int main() {
	const double roomRate[6] = { 127.50, 128.25, 130.50, 150, 150, 162.50 };     //Declare an array of double as requirements.
	int i = 0;
	int a = 4;
	string attName[4] = { };
	string checkInDay[4];
	string checkOutDay[4];
	int ciD = 0;
	int coD = 0;
	double calculatedPrice = 0;
	string arName;
	double totalPrice = 0;


	
	for (i = 0; i < a; i++) {
		cout << "Insert Attendee's name : ";
		getline(cin, attName[i]);

		arName = attName[i];
		if (arName != "") {   //If there is no name in the attName array  
			cout << "---------------------------------------------" << endl;
			cout << "Valid day : sun, mon, tue, wed, thu, fri, sat" << endl;
			cout << "---------------------------------------------" << endl;

			cout << "Insert Check-In Day : ";
			getline(cin, checkInDay[i]);
			ciD = dayToIndex(checkInDay[i]);



			switch (ciD)
			{
			case errorValue:case 5: case 6:
				cout << "Error : Invalid check-in day" << endl;
				cout << endl;
				break;



			case 4:
				cout << "Insert Check-Out Day : ";
				getline(cin, checkOutDay[i]);
				coD = dayToIndex(checkOutDay[i]);


				switch (coD) {
				case 4:
					cout << "Error : Invalid length of stay" << endl;
					break;


				default:
					calculatedPrice = calculateCostOfRoom(roomRate, ciD, coD);
					cout << "** Attendee name is : " << attName[i] << " **" << endl;
					cout << "'" << attName[i] << "'s calculated price : " << calculatedPrice << endl;
					cout << endl;
					totalPrice += calculatedPrice;
					break;
				}
				break;


			default:
				cout << "Insert Check-Out Day : ";
				getline(cin, checkOutDay[i]);
				coD = dayToIndex(checkOutDay[i]);
				
				switch (coD) {
				case 0: case 1: case 2: case 3: case -1:
					cout << "Error : Invalid check-out day" << endl;
					cout << endl;
					break;



				default :
				
					calculatedPrice = calculateCostOfRoom(roomRate, ciD, coD);

					cout << "** Attendee name is : " << attName[i] << " **" << endl;
					cout << "'" << attName[i] << "'s calculated price : " << calculatedPrice << endl;
					cout << endl;
					totalPrice += calculatedPrice;
				}

				break;
			}
			
		}
		else {
			cout << "Error : Missing name" << endl;
			errorValue;
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
		return errorValue;
	}
}

double calculateCostOfRoom(const double rent[], int ciD, int coD) {
	double total = 0;
	
	if (ciD > 4 || coD < 4) {
		return errorValue;
	}
	else if (ciD == coD) {
		return errorValue;
	}
	else {
		for (ciD; ciD < coD; ciD++) {
			total += rent[ciD];
		}
	}

	return total;
}