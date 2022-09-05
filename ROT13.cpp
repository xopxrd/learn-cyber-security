#include <iostream>
#include <conio.h>
#include <fstream>

const int length = 10;
const int character = 13; //character in array char

char character_1[] = {"abcdefghijklm"};
char character_2[] = {"nopqrstuvwxyz"};
char character_3[] = {"ABCDEFGHIJKLM"};
char character_4[] = {"NOPQRSTUVWXYZ"};

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
				std::cout << "\ninvalid username or password!\n";
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
	char encryptPass[int(password.length())];
	std::cout << "\nencrypting . . .\n";
	for(int i = 0; i < int(password.length()); i++){
		if(password[i] == ' ')
			encryptPass[i] = password[i];
		if(password[i] != ' ')
			encryptPass[i] = password[i];
			
		for(int j = 0; j < character; j++){
			if(password[i] == character_1[j])
				encryptPass[i] = character_2[j];
			if(password[i] == character_2[j])
				encryptPass[i] = character_1[j];
			if(password[i] == character_3[j])
				encryptPass[i] = character_4[j];
			if(password[i] == character_4[j])
				encryptPass[i] = character_3[j];
		}
	}
	
	std::ofstream file(name + ".txt");
	file << name << "\n" << encryptPass;
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
	
	char decrypt[int(pw.length())];
	for(int i = 0; i < int(pw.length()); i++){
		if(password[i] == ' ')
			decrypt[i] = password[i];
		if(password[i] != ' ')
			decrypt[i] = password[i];
			
		for(int j = 0; j < character; j++){
			if(password[i] == character_1[j])
				decrypt[i] = character_2[j];
			if(password[i] == character_2[j])
				decrypt[i] = character_1[j];
			if(password[i] == character_3[j])
				decrypt[i] = character_4[j];
			if(password[i] == character_4[j])
				decrypt[i] = character_3[j];
		}
	}
	
	if(username == uname && pw == decrypt)
		return true;
	else
		return false;
}
