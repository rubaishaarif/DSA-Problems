#include <iostream>
#include <queue>
using namespace std;
int Winner(int n, int k) {
    queue<int> friends;
    for (int i = 1; i <= n; ++i) {
        friends.push(i);
    }
    while (friends.size() > 1) {
        for (int i = 0; i < k - 1; ++i) {
            friends.push(friends.front());
            friends.pop();
        }
         friends.pop();
        
    }
    return friends.front();
}

int main() {
    int n = 5, k = 2;
    cout << Winner(n, k);
    return 0;
}