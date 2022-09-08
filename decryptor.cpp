#include <iostream>
#include <fstream>

const int character_18 = 18; // ROT18
char character_1[] = {"abcdefghijklmnopqr"};
char character_2[] = {"stuvwxyz0123456789"};
char character_3[] = {"ABCDEFGHIJKLMNOPQR"};
char character_4[] = {"STUVWXYZ0123456789"};

const int character_13 = 13; // the half quantity of the alphabet
char firstAlphabet[] = {"abcdefghijklm"};
char lastAlphabet[] = {"nopqrstuvwxyz"};
char firstCapitalAlphabet[] = {"ABCDEFGHIJKLM"};
char lastCapitalAlphabet[] = {"NOPQRSTUVWXYZ"};

int main (int argc, char const *argv[]){
    int choice;
    std::string file;
    std::cout << "decryptor program\n";
    std::cout << "enter the name of the text file you want to decrypt: ";
    std::cin >> file;
    std::cout << "1. ROT13\n";
    std::cout << "2. ROT18\n";
    std::cout << "choose decryptor: ";
    std::cin >> choice;

    switch (choice){
    case 1:
    {
        std::string line13;
        std::string text13;
        std::ifstream read13;
        read13.open(file + ".txt");
            while (!read13.eof()){
                getline(read13, line13);
                char cipherText13[int(line13.length())];
                for(int i = 0; i < int(line13.length()); i++){
					if(line13[i] == ' '){
						cipherText13[i] = line13[i];
					}
					if(line13[i] != ' '){
						cipherText13[i] = line13[i];
					}
					for(int j = 0; j < character_13; j++){
						if(line13[i] == firstAlphabet[j]){
							cipherText13[i] = lastAlphabet[j];
						}
						if(line13[i] == lastAlphabet[j]){
							cipherText13[i] = firstAlphabet[j];
						}
						if(line13[i] == firstCapitalAlphabet[j]){
							cipherText13[i] = lastCapitalAlphabet[j];
						}
						if(line13[i] == lastCapitalAlphabet[j]){
							cipherText13[i] = firstCapitalAlphabet[j];
						}
					}
				}
				text13.append(cipherText13);
            }
        read13.close();
		
		/* make a decyption file
		   you can uncomment this file if you want to make the .txt file
        std::ofstream decryptFile13("decrypt13" + file + ".txt");
        decryptFile13 << text13;
        decryptFile13.close();
        */
        
        std::cout << text13;
    }
        break;
    case 2:
    {
		std::string line18;
		std::string text18;
        std::ifstream read18;
        read18.open(file + ".txt");
            while (!read18.eof()){
                getline(read18, line18);
                char cipherText18[int(line18.length())];
				for(int i = 0; i < int(line18.length()); i++){
					if(line18[i] == ' '){
						cipherText18[i] = line18[i];
					}
					if(line18[i] != ' '){
						cipherText18[i] = line18[i];
					}
					for(int j = 0; j < character_18; j++){
						if(line18[i] == character_1[j]){
							cipherText18[i] = character_2[j];
						}
						if(line18[i] == character_2[j]){
							cipherText18[i] = character_1[j];
						}
						if(line18[i] == character_3[j]){
							cipherText18[i] = character_4[j];
						}
						if(line18[i] == character_4[j]){
							cipherText18[i] = character_3[j];
						}
					}
				}
				text18.append(cipherText18);
			}
		read18.close();

		/* make a decyption file
		   you can uncomment this file if you want to make the .txt file
        std::ofstream decryptFile18("decrypt18" + file + ".txt");
        decryptFile18 << text18;
        decryptFile18.close();
        */
		
        std::cout << text18;
	}
        break;
    default:
        break;
    }

    return 0;
}
