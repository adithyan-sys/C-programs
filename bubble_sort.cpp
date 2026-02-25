#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // If no swapping occurs, array is already sorted
        if(!swapped)
            break;
    }
}

// Function to display array
void display(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSort(arr, n);

    cout << "Sorted array:\n";
    display(arr, n);

    return 0;
}