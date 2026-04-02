#include <iostream>
using namespace std;

int main() {
    int n, num, sum = 0;

    cout << "Enter the number of values: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "Enter number " << i << ": ";
        cin >> num;
        sum = sum + num;   
    }

    // Display the result
    cout << "The sum of the entered numbers is: " << sum << endl;

    return 0;
}