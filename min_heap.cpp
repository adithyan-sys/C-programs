#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> x;
        minHeap.push(x);
    }

    cout << "Min Heap elements (smallest to largest): ";
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}