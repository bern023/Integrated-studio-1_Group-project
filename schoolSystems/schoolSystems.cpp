#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//Braedan M
void heading() {//this removes the hassle
	cout << "School Information System" << endl;
	cout << "-------------------------" << endl << endl;
}

//Braedan M
void basicAccount() {
	int opt;
	heading();//School title is in every main menu
	cout << "Main Menu" << endl;
	cout << "---------" << endl << endl;
	cout << "1. Sign-in/Create Account" << endl;
	cout << "2. Admin Access" << endl;
	cout << "3. Help/About Us" << endl;
	cout << "4. Exit" << endl << endl;
	cout << "Enter your choice" << endl;
	cin >> opt;
}


int main () {
	
//Braedan M
	int opt;
	do {
		heading();//School title is in every main menu
		cout << "Main Menu" << endl;
		cout << "---------" << endl << endl;
		cout << "1. Sign-in/Create Account" << endl;
		cout << "2. Admin Access" << endl;
		cout << "3. Help/About Us" << endl;
		cout << "4. Exit" << endl << endl;
		cout << "Enter your choice" << endl;
		cin >> opt;

		switch (opt) {
		case 1:
			//Sign-in/Create

			break;

		case 2:
			//Admin Access
			break;

		case 3:
			//Help and About Us
			break;

		case 4://exits
			return 0;

		default:
			cout << "Invalid Input";
		}
	}while (opt != 4);
		return 0;
}
