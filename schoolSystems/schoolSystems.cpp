#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//Braedan M
void heading() {//this removes the hassle
	cout << "School Information System" << endl;
	cout << "-------------------------" << endl << endl;
}
//Anthony S
struct User {
	string email;
	string password;
};
//Anthony S
void bscRegister() {
	User newUser;

	heading();
	cout << "\nRegistration Form" << endl;
	cout << "--------------------" << endl;
	cout << "Enter your Email address: ";	cin >> newUser.email;
	cout << "Enter a Password: "; cin >> newUser.password;

	ofstream file("users.txt", ios::app);
	if (file.is_open()) {
		file << newUser.email << " " << newUser.password << endl;
		file.close();
		cout << "Account created successfully!" << endl;

		system("PAUSE");

		//Needs menu to direct logged in user to
	}
	else {
		cout << "Account creation failed. Please try again." << endl;
		system("PAUSE");
	}
}
//Anthony S
bool bscLogin() {
	string email, password;

	heading();
	cout << "\nEnter your email and password to login.\n" << endl;
	cout << "Email address: "; cin >> email;
	cout << "Password: "; cin >> password;

	ifstream file("users.txt");
	if (file.is_open()) {
		string storedEmail, storedPassword;
		while (file >> storedEmail >> storedPassword) {
			if (storedEmail == email && storedPassword == password) {
				file.close();
				cout << "\nLogin successful!\n" << endl;
				return true;
			}
		}
		file.close();
		cout << "\nInvalid username or password. Please try again.\n" << endl;
	}
	else {
		cout << "\nLogin Error. Please try again.\n" << endl;
		system("PAUSE");
	}
	return false;
}
//Anthony S
void admRegister() {
	User newUser;
	string enteredToken;
	string admToken = "1234ABcd";

	heading();
	cout << "Please enter your Admin Token to proceed: " << endl;
	cin >> enteredToken;

	system("cls");

	if (enteredToken == admToken) {
		heading();
		cout << "\nAdmin Token Verified!\n" << endl;
		cout << "Admin Account Registration Form\n" << endl;
		cout << "Enter your Email address: ";	cin >> newUser.email;
		cout << "Enter a Password: "; cin >> newUser.password;

		ofstream file("users.txt", ios::app);
		if (file.is_open()) {
			file << newUser.email << " " << newUser.password << endl;
			file.close();
			cout << "Account created successfully!" << endl;

			system("PAUSE");

			//Needs menu to direct logged in user to
		}
		else {
			cout << "Account creation failed." << endl;
		}
	}
	else {
		cout << "Invalid admin token. Please try again.\n";
		system("PAUSE");
	}
}
//Anthony S
bool admLogin() {
	string email, password;

	heading();
	cout << "\nEnter your email and password to login.\n" << endl;
	cout << "Email address: "; cin >> email;
	cout << "Password: "; cin >> password;

	ifstream file("users.txt");
	if (file.is_open()) {
		string storedEmail, storedPassword;
		while (file >> storedEmail >> storedPassword) {
			if (storedEmail == email && storedPassword == password) {
				file.close();
				cout << "\nLogin successful!\n" << endl;
				return true;
			}
		}
		file.close();
		cout << "\nInvalid username or password. Please try again.\n" << endl;
	}
	else {
		cout << "\nLogin Error. Please try again.\n" << endl;
		system("PAUSE");
	}
	return false;	
}

int main () {
	ofstream file("account.txt");
	
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
					if (bscLogin()) {
						// if user logs in, this is where it will direct the user to.
					}
					break;

				case 2:
					//create an account
					bscRegister();
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
					admLogin();
					break;

				case 2:
					//Create an account - user to enter a token to access
					admRegister();
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
