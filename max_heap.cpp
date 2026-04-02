#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxHeap;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> x;
        maxHeap.push(x);
    }

    cout << "Max Heap elements (largest to smallest): ";
    while(!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    return 0;
}