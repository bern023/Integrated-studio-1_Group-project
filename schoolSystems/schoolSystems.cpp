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

//Anthony S
struct User {
	string email;
	string password;
};

//Anthony S
void bscRegister() {
	User newUser;
	string token;

	heading();
	cout << "Please enter your Admin Token to proceed: " << endl;
	cin >> token;

	system("cls");

	if (token == "1234ABcd") {
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
	int attempts = 0;

	while (attempts < 3) {
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
		attempts++;

	}
	cout << "\nToo many login attempts. Redirecting to Main Menu.\n" << endl;
	return false;
}
//Anthony S
void admRegister() {
	User newUser;
	string enteredToken;
	string token;

	heading();
	cout << "Please enter your Admin Token to proceed: " << endl;
	cin >> token;

	system("cls");

	if (token == "1234ABcd") {
		heading();
		cout << "\nAdmin Token Verified!\n" << endl;
		cout << "Admin Account Registration Form\n" << endl;
		cout << "Enter your Email address: ";	cin >> newUser.email;
		cout << "Enter a Password: "; cin >> newUser.password;

		ofstream file("users.txt", ios::app);
		if (file.is_open()) {
			file << newUser.email << " " << newUser.password << endl;
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
	int attempts = 0;
	string token;

	heading();
	cout << "Please enter your Admin Token to proceed: " << endl;
	cin >> token;

	system("cls");

	if (token == "1234ABcd") {
		while (attempts < 3) {
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
			attempts++;
		}
		cout << "\nToo many login attempts. Redirecting to Main Menu.\n" << endl;
		return 0;
	}
	else {
		cout << "Invalid admin token. Please try again.\n";
		system("PAUSE");
		return 0;
	}

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
	fstream file("users.txt");
	string user;
	int lineNumber;
	vector<string> lines;


	cout << "Please enter the line number you would like to delete:";
	cin >> lineNumber;
	//Braedan M
	while (cin.fail()) {//if input fails
		cin.clear();//clears the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
		cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
		cin >> lineNumber;//asks for input again
	}
	lineNumber--;
	// reading the file and storing file contents in vector of strings
	file.open("users.txt", ios::in);
	if (file.fail()) {
		cout << "Error opening file." << endl;
	}
	while (getline(file, user)) {
		lines.push_back(user);

	}
	file.close();
	if (lineNumber > lines.size()) {
		cout << "That number is not within the range of the text file" << endl;
		cout << "File has" << lines.size() << "lines" << endl;
	}
	//overriding the contents of the file
	file.open("users.txt", ios::out);
	if (file.fail()) {
		cout << "Error opening file." << endl;
	}
	for (int i = 0; i < lines.size(); i++) {
		if (i != lineNumber) {
			file << lines[i] << endl;

		}
	}
	file.close();
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
//Bernadette W
void dTeachers() {
	fstream file;
	string teacher;
	int lineNumber;
	vector<string> lines;


	cout << "Please enter the line number you would like to delete:";
	cin >> lineNumber;
	//Braedan M
	while (cin.fail()) {//if input fails
		cin.clear();//clears the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
		cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
		cin >> lineNumber;//asks for input again
	}
	lineNumber--;
	// reading the file and storing file contents in vector of strings
	file.open("teachers.txt", ios::in);
	if (file.fail()) {
		cout << "Error opening file." << endl;
	}
	while (getline(file, teacher)) {
		lines.push_back(teacher);

	}
	file.close();
	if (lineNumber > lines.size()) {
		cout << "That number is not within the range of the text file" << endl;
		cout << "File has" << lines.size() << "lines" << endl;
	}
	//overriding the contents of the file
	file.open("teachers.txt", ios::out);
	if (file.fail()) {
		cout << "Error opening file." << endl;
	}
	for (int i = 0; i < lines.size(); i++) {
		if (i != lineNumber) {
			file << lines[i] << endl;

		}
	}
	file.close();

	
}
//Bernadette W
void cClasses() {
	fstream file;
	string userInput;
	file.open("Subjects.txt", ios::app);
	if (file.is_open()) {
		cout << "Please enter subject name:";
		cin >> userInput;
		file << userInput;
		file.close();

	}
}
//Bernadette W
void lClasses() {
	fstream file;
	string subject;
	file.open("Subjects.txt", ios::in);
	if (file.is_open()) {
		while (getline(file, subject)) {
			cout << subject << endl;
		}
		file.close();
	}
}
// Bernadett W
void dClasses() {
	fstream file;
	string subject;
	vector<string> lines;
	int lineNumber;
	cout << "Please enter the number of the line you want to delete:";
	cin >> lineNumber;
	//Braedan M
	while (cin.fail()) {//if input fails
		cin.clear();//clears the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
		cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
		cin >> lineNumber;//asks for input again
	}
	lineNumber--;
	// reading the file and storing file contents in vector of strings
	file.open("Subjects.txt", ios::in);
	if (file.fail()) {
		cout << "Error opening file." << endl;
	}
	while (getline(file, subject)) {
		lines.push_back(subject);

	}
	file.close();
	if (lineNumber > lines.size()) {
		cout << "That number is not within the range of the text file" << endl;
		cout << "File has" << lines.size() << "lines" << endl;
	}
	//overriding the contents of the file
	file.open("Subjects.txt", ios::out);
	if (file.fail()) {
		cout << "Error opening file." << endl;
	}
	for (int i = 0; i < lines.size(); i++) {
		if (i != lineNumber) {
			file << lines[i] << endl;

		}
	}
	file.close();
}

//Braedan M
void cParents() {//Creates a new parent data
	string pSurname, pName;//variables used for Parent's name

	heading();
	cout << "Please enter a parent surname then first name" << endl;
	cout << "Surname: "; cin >> pSurname;
	cout << "First Name: "; cin >> pName;

	ofstream file("parents.txt", ios::app);
	if (file.is_open()) {//adds to the parents.txt file
		file << pSurname << ", " << pName << endl;
		file.close();
		cout << "Parent added successfully!" << endl;

		system("PAUSE");

	}
	else {
		cout << "Parent could not be added." << endl;//if error
	}

}

//Braedan M
void lParents() {//lists recorded parents
	ifstream file("parents.txt");
	string parent;

	if (file.is_open()) {
		cout << "List of Parents:" << endl;
		while (getline(file, parent)) {
			cout << parent << endl;
		}
		file.close();
		cout << endl;
	}
	else {//if error
		cout << "Unable to open file." << endl;
	}
}
//Braedan M 
void dParents() {
	fstream file;
	string subject;
	vector<string> lines;
	int lineNumber;
	cout << "Please enter the number of the line you want to delete:";
	cin >> lineNumber;
	//Braedan M
	while (cin.fail()) {//if input fails
		cin.clear();//clears the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
		cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
		cin >> lineNumber;//asks for input again
	}
	lineNumber--;
	// reading the file and storing file contents in vector of strings
	file.open("parents.txt", ios::in);
	if (file.fail()) {
		cout << "Error opening file." << endl;
	}
	while (getline(file, subject)) {
		lines.push_back(subject);

	}
	file.close();
	if (lineNumber > lines.size()) {
		cout << "That number is not within the range of the text file" << endl;
		cout << "File has" << lines.size() << "lines" << endl;
	}
	//overriding the contents of the file
	file.open("parents.txt", ios::out);
	if (file.fail()) {
		cout << "Error opening file." << endl;
	}
	for (int i = 0; i < lines.size(); i++) {
		if (i != lineNumber) {
			file << lines[i] << endl;

		}
	}
	file.close();
}

//Braedan M
void cReports() {//Creates a new report data
	string sSurname, sName;//variables used for Student's name
	string subj1, subj2, subj3, subj4, subj5, subj6;

	heading();
	cout << "Please enter a student surname then first name" << endl;
	cout << "Surname: "; cin >> sSurname;
	cout << "First Name: "; cin >> sName;
	cout << endl << "Enter Student grades:" << endl;
	cout << "Math: "; cin >> subj1;
	cout << "English: "; cin >> subj2;
	cout << "P.E: "; cin >> subj3;
	cout << "Technology: "; cin >> subj4;
	cout << "Art: "; cin >> subj5;
	cout << "Science: "; cin >> subj6;

	ofstream file("reports.txt", ios::app);
	if (file.is_open()) {//adds to the reports.txt file
		file << sSurname << ", " << sName << endl;
		file << "Math: " << subj1 << ", English: " << subj2 << endl;
		file << "P.E: " << subj3 << ", Technology: " << subj4 << endl;
		file << "Art: " << subj5 << ", Science: " << subj6 << endl;
		file << "--------------------" << endl;
		file.close();
		cout << "Report added successfully!" << endl;

		system("PAUSE");

	}
	else {
		cout << "Report could not be added." << endl;//if error
	}

}

//Braedan M
void lReports() {//lists recorded reports
	ifstream file("reports.txt");
	string report;

	if (file.is_open()) {
		cout << "List of Reports:" << endl;
		while (getline(file, report)) {
			cout << report << endl;
		}
		file.close();
		cout << endl;
	}
	else {//if error
		cout << "Unable to open file." << endl;
	}
}
//Bernadette W
void dReports() {
	fstream file;
	string report;
	int start, end;
	vector<string> lines;


	cout << "Please enter the start of line number you would like to delete:";
	cin >> start;
	//Braedan M
	while (cin.fail()) {//if input fails
		cin.clear();//clears the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
		cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
		cin >> start;//asks for input again
	}
	start--;
	cout << "Please enter the end of line number you would like to delete:";
	cin >> end;	//Braedan M
	while (cin.fail()) {//if input fails
		cin.clear();//clears the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
		cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
		cin >> end;//asks for input again
	}
	end--;
	// reading the file and storing file contents in vector of strings
	file.open("reports.txt", ios::in);
	if (file.fail()) {
		cout << "Error opening file." << endl;
	}
	while (getline(file, report)) {
		lines.push_back(report);

	}
	file.close();
	if (end > lines.size()) {
		cout << "That number is not within the range of the text file" << endl;
		cout << "File has" << lines.size() << "lines" << endl;
	}
	//overriding the contents of the file
	file.open("reports.txt", ios::out);
	if (file.fail()) {
		cout << "Error opening file." << endl;
	}
	for (int i = 0; i < lines.size(); i++) {
		if (i < start || i > end) {
			file << lines[i] << endl;
		}
	}
	file.close();
}

int main () {	
	string email;
	
//Braedan M
	int opt;//declares the variable used for user choice
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
		//Braedan M
		while (cin.fail()) {//if input fails
			cin.clear();//clears the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
			cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
			cin >> opt;//asks for input again
		}
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
				//Braedan M
				while (cin.fail()) {//if input fails
					cin.clear();//clears the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
					cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
					cin >> opt;//asks for input again
				}
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
							cout << "4. Parents" << endl;
							cout << "5. Return to Main Menu" << endl;
							cout << "6. Exit" << endl << endl;
							cout << "Enter your choice:" << endl;
							cin >> opt;
							//Braedan M
							while (cin.fail()) {//if input fails
								cin.clear();//clears the error flag
								cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
								cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
								cin >> opt;//asks for input again
							}
							system("cls");//clears what's on screen

							switch (opt) {
							case 1:
								//Reports
								lReports();
								system("PAUSE");
								system("cls");//clears what's on screen
								break;

							case 2:
								//Classes
								lClasses();
								system("PAUSE");
								system("cls");//clears what's on screen
								break;

							case 3:
								//Teachers
								lTeachers();
								system("PAUSE");
								system("cls");//clears what's on screen
								break;

							case 4:
								//Parents
								lParents();
								system("PAUSE");
								system("cls");//clears what's on screen
								break;

							case 5:
								//Main Menu
								main();
									break;

							case 6:
								//Exit
								return 0;

							default:
								cout << "Invalid Input" << endl;
							}
						} while (opt != 5);//loops while option is not 5
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
				//Braedan M
				while (cin.fail()) {//if input fails
					cin.clear();//clears the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
					cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
					cin >> opt;//asks for input again
				}
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
							cout << "4. Modify Parents" << endl;
							cout << "5. List Users" << endl;
							cout << "6. Delete User" << endl;
							cout << "7. Return to Main Menu" << endl;
							cout << "8. Exit" << endl << endl;
							cout << "Enter your choice:" << endl;
							cin >> opt;
							//Braedan M
							while (cin.fail()) {//if input fails
								cin.clear();//clears the error flag
								cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
								cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
								cin >> opt;//asks for input again
							}
							system("cls");//clears what's on screen

							switch (opt) {
							case 1:
								//Modify Reports
								do {
									//Braedan M
									heading();//School title is in every main menu
									cout << "Modify Reports" << endl;
									cout << "--------------" << endl << endl;
									cout << "1. Create Reports" << endl;
									cout << "2. List Reports" << endl;
									cout << "3. Delete Reports" << endl;
									cout << "4. Return to previous menu" << endl;
									cout << "Enter your choice:" << endl;
									cin >> opt;
									//Braedan M
									while (cin.fail()) {//if input fails
										cin.clear();//clears the error flag
										cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
										cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
										cin >> opt;//asks for input again
									}
									system("cls");//clears what's on screen

									switch (opt) {
									case 1:
										//create Reports
										cReports();
										break;

									case 2:
										//list Reports
										lReports();
										system("PAUSE");
										system("cls");//clears what's on screen
										break;

									case 3:
										//delete Reports
										dReports();
										break;

									case 4:
										//return to previous menu
										break;
									}
								} while (opt != 4);
								break;

							case 2:
								//Modify Classes
								do {
									//Braedan M
									heading();//School title is in every main menu
									cout << "Modify Classes" << endl;
									cout << "---------------" << endl << endl;
									cout << "1. Create Classes" << endl;
									cout << "2. List Classes" << endl;
									cout << "3. Delete Classes" << endl;
									cout << "4. Return to previous menu" << endl;
									cout << "Enter your choice:" << endl;
									cin >> opt;
									//Braedan M
									while (cin.fail()) {//if input fails
										cin.clear();//clears the error flag
										cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
										cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
										cin >> opt;//asks for input again
									}
									system("cls");//clears what's on screen

									switch (opt) {
									case 1:
										//create classes
										cClasses();
										break;

									case 2:
										//list classes
										lClasses();
										system("PAUSE");
										system("cls");//clears what's on screen
										break;

									case 3:
										//delete classes
										dClasses();
										break;

									case 4:
										//return to previous menu
										break;
									}
								} while (opt != 4);
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
									//Braedan M
									while (cin.fail()) {//if input fails
										cin.clear();//clears the error flag
										cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
										cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
										cin >> opt;//asks for input again
									}
									system("cls");//clears what's on screen

									switch (opt) {
									case 1:
										//create teachers
										cTeachers();
										break;

									case 2:
										//list teachers
										lTeachers();
										system("PAUSE");
										system("cls");//clears what's on screen
										break;

									case 3:
										//delete teachers
										dTeachers();
										break;

									case 4:
										//return to previous menu
										break;
									}
								} while (opt != 4);
								break;
							case 4:
								//modify parents
								do {
									//Braedan M
									heading();//School title is in every main menu
									cout << "Modify Parents" << endl;
									cout << "--------------" << endl << endl;
									cout << "1. Create Parents" << endl;
									cout << "2. List Parents" << endl;
									cout << "3. Delete Parents" << endl;
									cout << "4. Return to previous menu" << endl;
									cout << "Enter your choice:" << endl;
									cin >> opt;
									//Braedan M
									while (cin.fail()) {//if input fails
										cin.clear();//clears the error flag
										cin.ignore(numeric_limits<streamsize>::max(), '\n');//gets rid of invalid input
										cout << "Invalid input. Please enter a integer. \n";//outputs messages to user
										cin >> opt;//asks for input again
									}
									system("cls");//clears what's on screen

									switch (opt) {
									case 1:
										//create parents
										cParents();
										break;

									case 2:
										//list parents
										lParents();
										system("PAUSE");
										system("cls");//clears what's on screen
										break;

									case 3:
										//delete parents
										dParents();
										break;

									case 4:
										//return to previous menu
										break;
									}
								} while (opt != 4);
								break;

							case 5:
								//List Users - Anthony S
								listUsers();
								break;

							case 6:
								//Delete User - Anthony S
								listUsers();
								cout << "Enter an email to delete: ";
								cin >> email;
								deleteUser(email);
								break;
                  
							case 7:
								//Main Menu
								main();
								break;
                  
							case 8:
								//Exit
								return 0;

							default:
								cout << "Invalid Input" << endl;
							}
						} while (opt != 7);//loops while option is not 7
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
					main();
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
			cout << "- Basic accounts which can access 'Classes','Reports', 'Teachers' and 'Parents'" << endl;
			cout << "- Admin accounts can view and modify: 'Teachers', 'Classes' and 'Reports' and 'Parents'" << endl << endl;
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
