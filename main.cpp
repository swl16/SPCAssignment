#include<iostream>
#include<iomanip>
#include "Admin.cpp"
#include "User.cpp"
#include "Schedule.cpp"
using namespace std;

int main() {

	char choice;

	cout << "================================" << endl;
	cout << "    WELCOME TO FITNESS GYM!!" << endl;
	cout << "================================" << endl;

	cout << "1. User" << endl;
	cout << "2. Admin" << endl;
	cout << "0. Exit" << endl;

	do {
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case '1':
			userMenu();
			break;
		case '2':
			adminMenu();
			break;
		case '0':
			cout << "Exiting the program." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != '0');


	return 0;
}
