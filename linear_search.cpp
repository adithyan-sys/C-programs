#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i;          // return index if found
        }
    }
    return -1;                 // return -1 if not found
}

int main() {
    int arr[100];
    int n, key;
    
    cout << "Enter size of array (max 100): ";
    cin >> n;
    
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter element to search: ";
    cin >> key;
    
    int result = linearSearch(arr, n, key);
    
    if(result != -1) {
        cout << key << " found at index " << result << endl;
        cout << "Position: " << result + 1 << endl;
    } else {
        cout << key << " not found in the array" << endl;
    }
    
    return 0;
}


