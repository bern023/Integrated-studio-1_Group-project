#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//Braedan M
void heading() {//this removes the hassle
	cout << "School Information System" << endl;
	cout << "-------------------------" << endl << endl;
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
		system("cls");

		switch (opt) {
		case 1: {

			//Sign-in/Create (basic)
			do {
				//Braedan M
				heading();//School title is in every main menu
				cout << "Student Account" << endl;
				cout << "---------------" << endl << endl;
				cout << "1. Log-in" << endl;
				cout << "2. Create an account" << endl;
				cout << "3. Return to Main Menu" << endl;
				cout << "4. Exit" << endl << endl;
				cout << "Enter your choice" << endl;
				cin >> opt;
				system("cls");

				switch (opt) {
				case 1:
					//Log In
					cout << "test 1\n\n";
					break;

				case 2:
					//create an account
					cout << "test 2\n\n";
					break;

				case 3:
					//return to menu
					break;

				case 4:
					//exit
					return 0;

				default:
					cout << "Invalid Input";
				}
			} while (opt != 3);
		}
			  break;
		case 2:
			//Admin Access
			do {
				//Braedan M
				heading();//School title is in every main menu
				cout << "Admin Access" << endl;
				cout << "---------------" << endl << endl;
				cout << "1. Log-in" << endl;
				cout << "2. Create an account" << endl;
				cout << "3. Return to Main Menu" << endl;
				cout << "4. Exit" << endl << endl;
				cout << "Enter your choice" << endl;
				cin >> opt;
				system("cls");

				switch (opt) {
				case 1:
					//Log In
					cout << "test 1\n\n";
					break;

				case 2:
					//create an account- special code first
					//I assume it'll be an "if else" for this part -BM
					cout << "test 2\n\n";
					break;

				case 3:
					//return to menu
					break;

				case 4:
					//exit
					return 0;

				default:
					cout << "Invalid Input";
				}
			} while (opt != 3);

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
