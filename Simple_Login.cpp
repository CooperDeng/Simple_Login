// This file was last edited by Chengfeng Deng at March 14, 2022
// This is a simple login logic for a parking lot managment system, mainly acheived using the read file feature in fstream
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// This function is made for verifying if the user has logged into the system.
bool LoggedInState() 
{
// standard username and password
// un_v stands for username validation
// pw_v stands for password validation
	string username, password, un_v, pw_v;

	cout << "Please enter your username to the Parking lot Management System (PMS):";
	cin >> username;

	cout << "Please enter your pass word:";
	cin >> password;

// Notice that in order to log into the system there has to be a txt file present
// in the repository denoted. Feel free to change the repository to anywhere you want.
	ifstream read("E:\\" + username + ".txt");

	getline(read, un_v);
	getline(read, pw_v);

// Validating that the username and password matches.
	if (un_v == username && pw_v == password) 
	{
		return true;
	}
	else 
	{
		return false;
	}

}


// The main function contains operations that allows user to interact with
// the program by using terminal inputs.
int main() 
{
	
    int choice {0};
	cout << "Welcome to the Parking lot Management System (PMS)! Please select your option!" << endl;
	cout << "1: Register\n2:Login\nPlease Enter Your Choice" << endl;
	cin >> choice;	

// Creating an account
	if (choice == 1) 
	{
		string username, password;

		cout << "select a username: "; cin >> username;
		cout << "select a password: "; cin >> password;

		if (username == password) 
		{
			cout << "Username cannot be same as password!" << endl;
			main();
		}
		
// Open file, write down the account detail, save it for later use.
		ofstream file;
		file.open("E:\\" + username + ".txt");
		file << username << endl << password;
		file.close();
		main();
	}

// Login
	else if (choice == 2) 
	{
		bool status = LoggedInState();

		if (!status) 
		{
			cout << "Your Username and Password does not match! Please try again!" << endl;
			system("PAUSE");
			return 0;
		}
		else 
		{
			cout << "You have been logged into the Parking lot Management System(PMS)!" << endl;
			system("PAUSE");
			return 1;
		}
	}

// When User Enters stuff other than 1 or 2, we throw an error no.99, because it is the best number in the world.
	else 
	{
		try
		{
			int test_block { choice };
			if (test_block != 1 || test_block != 2)
			{
				throw 99;
			}
		}
		catch (int x) 
		{
			cout << "Error no." << x << ", input invalid." << endl;
		}
	}

}
