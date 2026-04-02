#include <iostream>
#include <cstring>
using namespace std;

#define NO_OF_CHARS 256

// Function to fill bad character array
void badCharHeuristic(string pattern, int size, int badChar[]) {
    for (int i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1;

    for (int i = 0; i < size; i++)
        badChar[(int)pattern[i]] = i;
}

// Boyer Moore Search Function
void search(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();

    int badChar[NO_OF_CHARS];
    badCharHeuristic(pattern, m, badChar);

    int shift = 0;  

    while (shift <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            cout << "Pattern found at index: " << shift << endl;

            shift += (shift + m < n) ? 
                     m - badChar[text[shift + m]] : 1;
        }
        else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    search(text, pattern);

    return 0;
}