#include <iostream>
#include <cctype>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
   setlocale (LC_ALL, "RU");
    string input;
    cout << "Введите строку символов: ";
    getline(cin, input);

    string lowerCase, upperCase, hexNumbers;
    ostringstream hexStream;

    for (char c : input) {
        if (isalpha(c)) {
            lowerCase += tolower(c);
            upperCase += toupper(c);
        }
        else if (isdigit(c)) {
            int number = c - '0';
            hexStream << hex << uppercase << number;
        }
    }

    string hexResult = hexStream.str();
    string replacedSpaces = input;

    for (char& c : replacedSpaces) {
        if (c == ' ') {
            c = '#';
        }
    }

    cout << "Все буквы в нижнем регистре: " << lowerCase << endl;
    cout << "Все буквы в большом регистре: " << upperCase << endl;
    cout << "Числа в строке (HEX): " << hexResult << endl;
    cout << "Строка с заменой пробелов на #: " << replacedSpaces << endl;

    return 0;
}
