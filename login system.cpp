#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

bool isLoggedIn(){
	std::string username, password, un, pw;
	
	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "Enter password: ";
	char ch = getch();
		while(ch != 13){
			password.push_back(ch);
			std::cout << "*";
			ch = getch();
		}
	
	std::ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);
	read.close();
	
	if (un == username && pw == password)
		return true;
	else
		return false;
}

int main(){
	int choice;
	
	std::cout << "1. Register\n";
	std::cout << "2. Login\n";
	std::cout << "Your choice: ";
	std::cin >> choice;
	if(choice == 1){
		std::string username, password;
		std::cout << "select a username: ";
		std::cin >> username;
		std::cout << "select a password: ";
		char ch = getch();
		while(ch != 13){
			password.push_back(ch);
			std::cout << "*";
			ch = getch();
		}
		std::cout << "\nreenter the password: ";
		std::string repass;
		ch = getch();
		while(ch != 13){
			repass.push_back(ch);
			std::cout << "*";
			ch = getch();
		}
		
		if(password != repass){
			std::cout << "\nthe password doesn't match!";
			main();
		}else{
			std::ofstream file(username + ".txt");
			file << username << std::endl << password;
			file.close();
			std::cout << std::endl;
			main();
		}
		
		}else if(choice == 2){
		bool status = isLoggedIn();
			if (!status){
				std::cout << "\nfalse login!" << std::endl;
				system("PAUSE");
				return 0;
			}else{
				std::cout << "\nSuccesfully logged in!" << std::endl;
				system("PAUSE");
				return 1;
			}
		}
	
	return 0;
}
