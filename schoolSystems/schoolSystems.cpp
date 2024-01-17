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
struct Account {
	string email;
	string password;
};
//Anthony S
void bscRegister() {
	Account newAccount;

	heading();
	cout << "\nRegistration Form\n" << endl;
	cout << "Provide your Email address: "; getline(cin, newAccount.email);
	cout << "\nProvide a Password: "; getline(cin, newAccount.password);

	ofstream outputFile("accounts.txt", ios::app);
	if (outputFile.is_open()) {
		outputFile << newAccount.email << "," << newAccount.password << endl;
		outputFile.close();
		cout << "Account created successfully!" << endl;

		//Needs menu to direct logged in user to
	}
	else {
		cout << "Account creation failed." << endl;
	}
}
//Anthony S
void bscLogin() {
	string email, password;

	heading();
	cout << "Email address: "; getline(cin, email);
	cout << "\nPassword: "; getline(cin, password);

	ifstream file("admaccounts.txt");
	string line;
	while (getline(file, line)) {
		size_t pos = line.find(",");
		string savedEmail = line.substr(0, pos);
		string savedPassword = line.substr(pos + 1);

		if (savedEmail == email && savedPassword == password) {
			cout << "Login successful!" << endl;
			file.close();
			system("PAUSE");

			//Needs menu to direct logged in user to
		}

		cout << "Invalid email or password. Please try again." << endl;
		file.close();
	}
}
//Anthony S
void admRegister() {
	Account newAccount;
	string enteredToken;
	string admToken = "1234ABcd";

	heading();
	cout << "Please insert your Admin Token to proceed: " << endl;
	cin >> enteredToken;

	system("cls");

	if (enteredToken == admToken) {
		heading();
		cout << "\nAdmin Token Verified!\n" << endl;
		cout << "Admin Account Registration Form\n" << endl;
		cout << "Provide your Email address: "; getline(cin, newAccount.email);
		cout << "\nProvide a Password: "; getline(cin, newAccount.password);

		ofstream outputFile("admaccounts.txt", ios::app);
		if (outputFile.is_open()) {
			outputFile << newAccount.email << "," << newAccount.password << endl;
			outputFile.close();
			cout << "Account created successfully!" << endl;

			//Needs menu to direct logged in user to
		}
		else {
			cout << "Account creation failed." << endl;
		}
	}
	else {
		cout << "Invalid admin token. Registration denied.";
	}
}
//Anthony S
void admLogin() {
	string email, password;

	heading();
	cout << "\nEmail address: "; getline(cin, email);
	cout << "\nPassword: "; getline(cin, password);

	ifstream file("admaccounts.txt");
	string line;
	while (getline(file, line)) {
		size_t pos = line.find(",");
		string savedEmail = line.substr(0, pos);
		string savedPassword = line.substr(pos + 1);

		if (savedEmail == email && savedPassword == password) {
			cout << "Login successful!" << endl;
			file.close();
			system("PAUSE");

			//Needs menu to direct logged in user to
		}
	}

	cout << "Invalid email or password. Please try again." << endl;
	file.close();
	return;
}



int main () {
	ofstream file("account.txt" "admaccount.text");
	
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
					bscLogin();
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
