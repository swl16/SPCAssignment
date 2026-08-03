#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<fstream>
#include <sstream>

using namespace std;


struct Member {
	string id;
	string name;
	int age;
	string phNo;
	char gender;
};


static void userMenu() {
	char loginChoice;
	string username;
	string password;

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

		switch (loginChoice) {
		case '1':
			cout << "================================\n";
			cout << "            Register            \n";
			cout << "================================\n";

			cout << "Username :";
			cin >> username;
			cout << "Password :";
			cin >> password;
			
			cout << "-----------------------------------------";
			if (userExist) {
				cout << "Register successful!";
				cout << "Press ENTER to continue...";
				userMenu();
				break;
			}
			else {
				cout << "Username exist! Please use another username.";
			}
				
				

				
				
				
		}
	} while (loginChoice != '0');
		
		
}

bool userExist(string targetUsername, string password) {
	ifstream file("user.txt");

	if (!file.is_open()) {
		cerr << "Error: Could not open file." << endl;
		return false;
	}

	string line, username, password;
	while (getline(file, line)) {
		stringstream ss (line);
		if (ss >> username >> password) {
			if (username == targetUsername) {
				file.close();
				return false; // Match found!
			}
		}
	}

	file.close();
	return true;
}

void storeUser() {

}