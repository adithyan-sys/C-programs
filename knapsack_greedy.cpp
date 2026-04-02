#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
};

// Comparator function to sort by profit/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Item arr[n];

    cout << "Enter profit and weight of each item:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i].profit >> arr[i].weight;
    }

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items by ratio
    sort(arr, arr + n, compare);

    double totalProfit = 0.0;

    for(int i = 0; i < n; i++) {
        if(capacity >= arr[i].weight) {
            // Take full item
            totalProfit += arr[i].profit;
            capacity -= arr[i].weight;
        } else {
            // Take fractional part
            totalProfit += arr[i].profit * ((double)capacity / arr[i].weight);
            break;
        }
    }

    cout << "Maximum Profit = " << totalProfit << endl;

    return 0;
}