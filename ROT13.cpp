#include <iostream>
#include <conio.h>

const int character = 13; // the half quantity of the alphabet
char firstAlphabet[] = {"abcdefghijklm"};
char lastAlphabet[] = {"nopqrstuvwxyz"};
char firstCapitalAlphabet[] = {"ABCDEFGHIJKLM"};
char lastCapitalAlphabet[] = {"NOPQRSTUVWXYZ"};
char firstNumber[] = {"01234"};
char lastNumber[] = {"56789"};

int main(){
	std::string plainText;
	std::cout << "text encryptor with ROT13\n";
	std::cout << "insert text: ";
	getline(std::cin, plainText);
	
	// scan the text
	char cipherText[int(plainText.length())];
	for(int i = 0; i < int(plainText.length()); i++){
		if(plainText[i] == ' '){
			cipherText[i] = plainText[i];
		}
		if(plainText[i] != ' '){
			cipherText[i] = plainText[i];
		}
		for(int j = 0; j < character; j++){
			if(plainText[i] == firstAlphabet[j]){
				cipherText[i] = lastAlphabet[j];
			}
			if(plainText[i] == lastAlphabet[j]){
				cipherText[i] = firstAlphabet[j];
			}
			if(plainText[i] == firstCapitalAlphabet[j]){
				cipherText[i] = lastCapitalAlphabet[j];
			}
			if(plainText[i] == lastCapitalAlphabet[j]){
				cipherText[i] = firstCapitalAlphabet[j];
			}
			if(plainText[i] == lastNumber[j]){
				cipherText[i] = firstNumber[j];
			}
			if(plainText[i] == firstNumber[j]){
				cipherText[i] = lastNumber[j];
			}
		}
	}
	
	std::cout << "chiper text: " << cipherText;

	return 0;
}
