#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

#include"User.hpp"

using namespace std;

vector<User> users;


bool userExist(const string& username) {
	for (int i = 0; i < users.size(); i++) {
		if (users[i].username == username) {
			return true; // User already exists
		}
	}
	return false; // User does not exist
}

bool loginUser(const string& username, const string& password) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i].username == username && users[i].password == password) {
			return true; // Login successful
			}
		}
		return false; // Login failed
}

void loadUser() {
	ifstream file("user.txt");

	if (!file) {
		cout << "Error: Could not open file." << endl;
		return;
	}

	users.clear();

	string line;
	while (getline(file, line)) {

		if(line.empty()) {
			continue; // Skip empty lines
		}

		stringstream ss (line);
		User userInfo;

		getline(ss, userInfo.username, ',');
		getline(ss, userInfo.password);

		if(!userInfo.username.empty() && !userInfo.password.empty()) {
			users.push_back(userInfo);
		}
		else {
			cout << "Warning: Skipping invalid user entry in file." << endl;
		}
	}

	file.close();
}

void saveUser() {
	ofstream file("user.txt");

	if (!file) {
		cout << "Error: Could not open file." << endl;
		return;
	}

	for (int i = 0; i < users.size(); i++) {
		file << users[i].username << "," << users[i].password << endl;
	}

	file.close();

}


void userMenu() {

	loadUser();
	char loginChoice;
	User user;
	string enteredUsername, enteredPassword;

	cout << "=================================" << endl;
	cout << "            USER MENU            " << endl;
	cout << "=================================" << endl;

	cout << "1. Register\n";
	cout << "2. Login\n";
	cout << "0. Exit\n";

	do {
		cout << "-------------------------";
		cout << "Enter choice : ";
		cin >> loginChoice;

		switch(loginChoice) {

		case '1':
			cout << "================================\n";
			cout << "            Register            \n";
			cout << "================================\n";

			cout << "Username :";
			cin >> user.username;
			cout << "Password :";
			cin >> user.password;
			
			cout << "-----------------------------------------";
			if (userExist(user.username)){
				cout << "Username exist! Please use another username.";
				continue;
			}
			else {
				users.push_back(user);
				saveUser();

				cout << "Register successful! You can log in now.\n";
				cout << "Press ENTER to continue...";
			}
			break;


		case '2':
			cout << "================================\n";
			cout << "             Login              \n";
			cout << "================================\n";
			cout << "Username :";
			cin >> enteredUsername;
			cout << "Password :";
			cin >> enteredPassword;

			if(loginUser(enteredUsername, enteredPassword)) {
				cout << "Login successful!\n";
				cout << "Welcome, " << enteredUsername << "!\n";
				cout << "Press ENTER to continue...";
				break;

			} else {
				cout << "Invalid username or password. Please try again.\n";
			}
			break;
				
		case '0':
			cout << "Exiting user menu. Thank you.\n";
			break;

				
		default:
			cout << "Invalid choice. Please try again.\n";
			
		}
	} while (loginChoice != '0');
		
		
}

