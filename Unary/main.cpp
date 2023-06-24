#include <iostream>
#include <string>

int asciiToBinary(int ascii) {
    int binary = 0;
    int remainder, i = 1;

    while (ascii != 0) {
        remainder = ascii % 2;
        ascii /= 2;
        binary += remainder * i;
        i *= 10;
    }

    return binary;
}

std::string binaryToString (int binary) {
    std::string binaryString = std::to_string(binary);
    while(binaryString.length() < 7) {
        binaryString = "0" + binaryString;
    }
    return binaryString;
}

std::string binaryStringToUnary (std::string binaryString) {
    std::string unary;
    int count;

    while(binaryString.length() > 0) {
        count = 0;
        if (binaryString[0] == '1') {
            while (binaryString[0] == '1') {
                count++;
                binaryString.erase(0, 1);
            }
            unary += "0 ";
            while (count > 0) {
                unary += "0";
                count--;
            }
            unary += " ";
        }
        else {
            while (binaryString[0] == '0') {
                count++;
                binaryString.erase(0, 1);
            }
            unary += "00 ";
            while (count > 0) {
                unary += "0";
                count--;
            }
            unary += " ";
        }
        
    }
    if (unary[unary.length() - 1] == ' ') {
        unary.erase(unary.length() - 1, 1);            
    }

   return unary;
}

int main () {
    std::string message, binaryMessage;
    std::string binaryString;
    std::string unaryString;
    int ascii;
    
    std::cout << "Enter a message: ";
    std::getline(std::cin, message);

    for (int i = 0; i < message.length(); i++) {
        ascii = (int)message[i];
        std::cout << message[i] << " in ascii: " << ascii << std::endl;
        binaryString += binaryToString(asciiToBinary(message[i]));        
    }

    unaryString = binaryStringToUnary(binaryString);

    std::cout << "binaryString: " << binaryString << std::endl;
    std::cout << "unaryString: " << unaryString << std::endl;

    return 0;
} 