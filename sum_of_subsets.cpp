#include <bits/stdc++.h>
using namespace std;

void findSubsets(vector<int>& arr, int target, vector<int> subset, int index, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(subset);
        return;
    }
    if (index == arr.size() || target < 0) {
        return;
    }

    // Include current element
    subset.push_back(arr[index]);
    findSubsets(arr, target - arr[index], subset, index + 1, result);
    subset.pop_back();

    // Exclude current element
    findSubsets(arr, target, subset, index + 1, result);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;

    vector<vector<int>> result;
    vector<int> subset;

    findSubsets(arr, target, subset, 0, result);

    cout << "Array : ";
    for(int x : arr) cout << x << " ";
    cout << "\nTarget Sum : " << target << "\n\n";

    cout << "Subsets that sum to " << target << ":\n";
    if (result.empty()) {
        cout << "No subset found!\n";
    } else {
        for(auto& sub : result) {
            cout << "{ ";
            for(int x : sub) cout << x << " ";
            cout << "}\n";
        }
    }
    return 0;
}