#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Braedan M
void heading() {//this removes the hassle
	cout << "School Information System" << endl;
	cout << "-------------------------" << endl << endl;
}
// Bernadette W
struct accTypes{
	struct teacher {
		string teacherDetails;
		string classes[6] = {
			"English", "Sciences", "Math", "History", "Arts", "Technology"
		};
	};
	struct parent {
		string parentDetails;
		//student will just be stored as ID
		vector<int> student;
		// both class and report are arrays so we can match their values to show student grades with each class
		string report[6];
	};
	
};
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
		cout << "3. Help/Contact Us" << endl;
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
					cout << "Invalid Input" << endl;
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
				cout << "------------" << endl << endl;
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
			//Help and Contact Us info
			//Braedan M
			heading();//School title is in every main menu
			cout << "Help and Contact Us" << endl;
			cout << "-----------------" << endl << endl;
			cout << "Help" << endl;
			cout << "----" << endl;
			cout << "This is a School Infortmation console app. ";
			cout << "Here you will find information about the school through a personal account." << endl << endl;
			cout << "These include:" << endl;
			cout << "- Basic accounts which can access 'Classes' and 'Reports'" << endl;
			cout << "- Admin accounts can view and modify: 'Teachers', 'Classes' and 'Reports'" << endl << endl;
			cout << "1. Sign-in/Create Account, this is for basic users who want to log-in and view their student/s records." << endl;
			cout << "2. Admin Access, this is for admins to view and modify school related data like teachers and records." << endl;
			cout << "3. Help/Contact Us, this is where you are now and provides context to the system." << endl;
			cout << "4. Exit, this will exit the system and end all processes." << endl << endl;
			cout << "Contact Us" << endl;
			cout << "-------" << endl;
			cout << "Phone: 09 376 7295" << endl;
			cout << "Email: syshelp@support.com" << endl << endl;
			cout << "=====================================================================" << endl << endl;				
			break;

		case 4://exits
			return 0;

		default:
			cout << "Invalid Input" << endl;
		}
	}while (opt != 4);
		return 0;
}
