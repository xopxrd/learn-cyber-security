#include <iostream>
#include <conio.h>
#include <fstream>

const int length = 10;

void regist();
bool login();

int main(){
	int choice;
	std::cout << "1. Register\n";
	std::cout << "2. Login\n";
	std::cout << "Choice: ";
	std::cin >> choice;
	
	switch(choice){
		case 1:
			regist();
			main();
			break;
		
		case 2:
			{
			bool status = login();
			if(!status){
				std::cout << "invalid username or password!\n";
			}else{
				std::cout << "\nSuccesfully logged in!" << std::endl;
				}
			}
			break;
		
		default:
			std::cout << "invalid input!\n";
	}
	
	return 0;
}

void regist(){
	std::string name,password;
	std::cout << "input username: ";
	std::cin >> name;
	std::cout << "input password (max 10 characters): ";
	char hide = getch();
	for(int i = 0; i < length; i++){
		if(hide != 13){
			password.push_back(hide);
			// hide characters
			std::cout << "*";
			hide = getch();
		}
	}
	
	// ROT 13 encrypt algorithm
	std::cout << "\nencrypting . . .\n";
	char encrypt[length];
	std::ofstream encryptedPass(name + ".txt");
	encryptedPass << name << std::endl;
	for(int i = 0; i < int(password.length()); i++){
		encrypt[i] = int(password[i] + 13);
		encryptedPass << encrypt[i];
	}
	encryptedPass.close();
	
	std::cout << std::endl;
}

bool login(){
	std::string username, password, uname, pw;
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
	getline(read, uname);
	getline(read, pw);
	read.close();
	
	char decrypt[length];
	for(int i = 0; i < int(pw.length()); i++){
		decrypt[i] = int(pw[i] - 13);
	}
	
	if(username == uname && password == decrypt)
		return true;
	else
		return false;
}
