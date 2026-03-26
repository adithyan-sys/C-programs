#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "===== Heap Sort Algorithm =====\n";
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted Array (Ascending): ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}