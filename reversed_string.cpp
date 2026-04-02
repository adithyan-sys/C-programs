#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, reversed = "";

    cout << "Enter a string: ";
    getline(cin, str);

    for(int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }

    cout << "Reversed string is: " << reversed << endl;

    return 0;
}