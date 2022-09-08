#include <iostream>
#include <fstream>

const int character = 18; // ROT18
char character_1[] = {"abcdefghijklmnopqr"};
char character_2[] = {"stuvwxyz0123456789"};
char character_3[] = {"ABCDEFGHIJKLMNOPQR"};
char character_4[] = {"STUVWXYZ0123456789"};

int main(int argc, char const *argv[]){
	std::string plainText;
	std::cout << "text encryptor with ROT18\n";
	std::cout << "insert plain text: ";
	getline(std::cin, plainText);

	char cipherText[int(plainText.length())];
	for(int i = 0; i < int(plainText.length()); i++){
		if(plainText[i] == ' '){
			cipherText[i] = plainText[i];
		}
		if(plainText[i] != ' '){
			cipherText[i] = plainText[i];
		}
		for(int j = 0; j < character; j++){
			if(plainText[i] == character_1[j]){
				cipherText[i] = character_2[j];
			}
			if(plainText[i] == character_2[j]){
				cipherText[i] = character_1[j];
			}
			if(plainText[i] == character_3[j]){
				cipherText[i] = character_4[j];
			}
			if(plainText[i] == character_4[j]){
				cipherText[i] = character_3[j];
			}
		}
	}
	
	std::string title;
	std::cout << "insert the title of the text: ";
	std::cin >> title;

	std::ofstream file(title + ".txt");
	file << cipherText;
	file.close();

	return 0;
}
