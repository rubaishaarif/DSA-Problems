#include <iostream>
#include <vector>
using namespace std;

void permute(vector<int>& arr, int idx) {
    // base case: fixed everyone, print one full permutation
    if (idx == arr.size()) {
        for (int x : arr) cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = idx; i < arr.size(); i++) {
        swap(arr[idx], arr[i]);   // CHOOSE: place arr[i] at position idx
        permute(arr, idx + 1);    // EXPLORE: solve the rest
        swap(arr[idx], arr[i]);   // BACKTRACK: undo, restore original order
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    permute(arr, 0);
    return 0;
}