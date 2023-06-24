#include <iostream>
#include <string>

int main () {
    std::string unary;

    std::cout << "Enter Unary String: ";
    std::getline(std::cin, unary);

    std::string binaryString;
    int count, test;

    while (unary.length() > 0) {
        count = 0;
        if (unary[1] = 0) {
            unary.erase(0, 3);
            while (unary[0] == '0') {
                count++;
                unary.erase(0, 1);
            }
            while (count > 0) {
                binaryString += "0";
                count--;
            }
            std::cout << binaryString << std::endl;
            unary.erase(0, 1);
        }
        else {
            unary.erase(0, 2);
            while (unary[0] == '0') {
                count++;
                unary.erase(0, 1);
            }
            while (count > 0) {
                binaryString += "1";
                count--;
            }
            std::cout << binaryString << std::endl;
            unary.erase(0, 1);
        }
        test++;
        std::cout << "Test" << test << std::endl;
    }
    std::cout << binaryString << std::endl;
    return 0;
}