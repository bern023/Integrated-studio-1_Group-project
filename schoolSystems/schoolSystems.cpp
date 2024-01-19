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
	string enteredToken;
	string admToken = "ABcd1234";

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
bool bscLogin() {
	string email, password;
	int attempts = 0;

	while (attempts < 3) {
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
		attempts++;

	}
	cout << "\nToo many login attempts. Redirecting to Main Menu.\n" << endl;
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
			file << "admin," << newUser.email << " " << newUser.password << endl;
			file.close();
			cout << "Administrator account created successfully!" << endl;

			system("PAUSE");
		
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
	int attempts = 0;

	while (attempts < 3) {
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
		attempts++;

	}
	cout << "\nToo many login attempts. Redirecting to Main Menu.\n" << endl;
	return false;
}

//Anthony S
void listUsers() {
	ifstream file("users.txt");
	string user;

	if (file.is_open()) {
		while (getline(file, user)) {
			cout << user << endl;
		}
		file.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}
}
//Anthony S
void deleteUser(const string& email) {
	ifstream file("users.txt");
	ofstream temp("temp.txt");
	string user;

	if (file.is_open() && temp.is_open()) {
		while (getline(file, user)) {
			if (user != email) {
				temp << user << endl;
			}
		}
		file.close();
		temp.close();
		remove("users.txt");
		rename("temp.txt", "users.txt");
		cout << "User deleted successfully." << endl;
	}
	else {
		cout << "Unable to delete user." << endl;
	}
}

//Braedan M
void cTeachers() {//Creates a new teacher data
	string tSurname, tName;//variables used for Teacher's name

	heading();
	cout << "Please enter a teacher surname then first name" << endl;
	cout << "Surname: "; cin >> tSurname;
	cout << "First Name: "; cin >> tName;

	ofstream file("teachers.txt", ios::app);
	if (file.is_open()) {//adds to the teachers.txt file
		file << tSurname << ", " << tName << endl;
		file.close();
		cout << "Teacher added successfully!" << endl;

		system("PAUSE");

	}
	else {
		cout << "Teacher could not be added." << endl;//if error
	}

}

//Braedan M
void lTeachers() {//lists recorded teachers
	ifstream file("teachers.txt");
	string teacher;

	if (file.is_open()) {
		cout << "List of Teachers:" << endl;
		while (getline(file, teacher)) {
			cout << teacher << endl;
		}
		file.close();
		cout << endl;
	}
	else {//if error
		cout << "Unable to open file." << endl;
	}
}




int main () {
	ofstream file("account.txt");
	string email;
	
//Braedan M
	int opt;//declares the variable used for user choice
	string email;//declare variable for user email
	do {//do while loop for main menu
		heading();//School title is in every main menu
		cout << "Main Menu" << endl;
		cout << "---------" << endl << endl;
		cout << "1. Sign-in" << endl;
		cout << "2. Admin Access" << endl;
		cout << "3. Help/Contact Us" << endl;
		cout << "4. Exit" << endl << endl;
		cout << "Enter your choice:" << endl;
		cin >> opt;
		system("cls");//clears what's on screen

		switch (opt) {
		case 1: {

			//Sign-in (basic)
			do {//do while loop for menu
				//Braedan M
				heading();//School title is in every main menu
				cout << "Student Account" << endl;
				cout << "---------------" << endl << endl;
				cout << "1. Log-in" << endl;
				cout << "2. Return to Main Menu" << endl;
				cout << "3. Exit" << endl << endl;
				cout << "Enter your choice:" << endl;
				cin >> opt;
				system("cls");//clears what's on screen

				switch (opt) {
				case 1:
					//Log In
					if (bscLogin()) {
						// if user logs in, this is where it will direct the user to.
						//Braedan M
						do {//do while loop for menu
							//Braedan M
							heading();//School title is in every main menu
							cout << "Student Details" << endl;
							cout << "---------------" << endl << endl;
							cout << "1. Reports" << endl;
							cout << "2. Classes" << endl;
							cout << "3. Teachers" << endl;
							cout << "4. Return to Main Menu" << endl;
							cout << "5. Exit" << endl << endl;
							cout << "Enter your choice:" << endl;
							cin >> opt;
							system("cls");//clears what's on screen

							switch (opt) {
							case 1:
								//Reports
								break;

							case 2:
								//Classes
								break;

							case 3:
								//Teachers
								break;

							case 4:
								//Main Menu
								main();
									break;

							case 5:
								//Exit
								return 0;

							default:
								cout << "Invalid Input" << endl;
							}
						} while (opt != 4);//loops while option is not 4
					}
					break;	

				case 2:
					//return to menu
					break;

				case 3:
					//exit
					return 0;

				default:
					cout << "Invalid Input" << endl;
				}
			} while (opt != 2);//loops while option is not 2
		}
			  break;
		case 2:
			//Admin Access
			do {//do while loop for menu
				//Braedan M
				heading();//School title is in every main menu
				cout << "Admin Access" << endl;
				cout << "------------" << endl << endl;
				cout << "1. Log-in" << endl;
				cout << "2. Create an Admin account" << endl;
				cout << "3. Create a Basic account" << endl;
				cout << "4. Return to Main Menu" << endl;
				cout << "5. Exit" << endl << endl;
				cout << "Enter your choice:" << endl;
				cin >> opt;
				system("cls");//clears what's on screen

				switch (opt) {
				case 1:
					//Log In
					if (admLogin()) {
						// if user logs in, this is where it will direct the user to.
						//Braedan M
						do {
							//Braedan M
							heading();//School title is in every main menu
							cout << "Admin Mode" << endl;
							cout << "----------" << endl << endl;
							cout << "1. Modify Reports" << endl;
							cout << "2. Modify Classes" << endl;
							cout << "3. Modify Teachers" << endl;
							cout << "4. List Users" << endl;
							cout << "5. Delete User" << endl;
							cout << "6. Return to Main Menu" << endl;
							cout << "7. Exit" << endl << endl;
							cout << "Enter your choice:" << endl;
							cin >> opt;
							system("cls");//clears what's on screen

							switch (opt) {
							case 1:
								//Modify Reports
								break;

							case 2:
								//Modify Classes
								break;

							case 3:
								//Modify Teachers
								do {
									//Braedan M
									heading();//School title is in every main menu
									cout << "Modify Teachers" << endl;
									cout << "---------------" << endl << endl;
									cout << "1. Create Teachers" << endl;
									cout << "2. List Teachers" << endl;
									cout << "3. Delete Teachers" << endl;
									cout << "4. Return to previous menu" << endl;
									cout << "Enter your choice:" << endl;
									cin >> opt;
									system("cls");//clears what's on screen

									switch (opt) {
									case 1:
										//create teachers
										cTeachers();
										break;

									case 2:
										//list teachers
										lTeachers();
										break;

									case 3:
										//delete teachers

										break;

									case 4:
										//return to previous menu
										break;
									}
								} while (opt != 4);
								break;

							case 4:
								//List Users - Anthony S
								listUsers();
								break;

							case 5:
								//Delete User - Anthony S
								cout << "Enter an email to delete: ";
								cin >> email;
								deleteUser(email);
								break;
                  
							case 6:
								//Main Menu
								main();
								break;
                  
							case 7:
								//Exit
								return 0;

							default:
								cout << "Invalid Input" << endl;
							}
						} while (opt != 6);//loops while option is not 6
					}
					break;

				case 2:
					//Create an account - user to enter a token to access
					admRegister();
					break;

				case 3:
					//create basic account
					bscRegister();
					break;

				case 4:
					//return to menu
					break;

				case 5:
					//exit
					return 0;

				default:
					cout << "Invalid Input";
				}
			} while (opt != 4);//loops while input is not 4

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
			cout << "1. Sign-in, this is for basic users who want to log-in and view the school records." << endl;
			cout << "2. Admin Access, this is for admins to view and modify school related data like teachers and records." << endl;
			cout << "3. Help/Contact Us, this is where you are now and provides context to the system." << endl;
			cout << "4. Exit, this will exit the system and end all processes." << endl << endl;
			cout << "Contact Us" << endl;
			cout << "-------" << endl;
			cout << "Phone: 09 376 7295" << endl;
			cout << "Email: syshelp@support.com" << endl << endl;
			cout << "=====================================================================" << endl << endl;
			system("PAUSE");//pauses info in screen until user clicks any key
			system("cls");//clears what's on screen
			break;

		case 4://exits
			return 0;

		default:
			cout << "Invalid Input" << endl;
		}
	}while (opt != 4);
		return 0;
}
