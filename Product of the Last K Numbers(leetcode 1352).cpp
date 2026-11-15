#include <iostream>
#include <queue>
using namespace std;
class ProductOfNumbers {
    queue<int> q;
public:
    ProductOfNumbers() {}

    void add(int num) {
        q.push(num);
    }

    int getProduct(int k) {
        int n = q.size();
        int skip = n - k;
        int product = 1;

        for (int i = 0; i < n; ++i) {
            int val = q.front();
            q.pop();
            
            if (i >= skip) {
                product *= val;
            }
            
            q.push(val); // Re-queue to preserve state
        }
        return product;
    }
};

int main() {
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);

    cout << productOfNumbers.getProduct(2) << endl; // Returns 20
    cout << productOfNumbers.getProduct(3) << endl; // Returns 40
    cout << productOfNumbers.getProduct(4) << endl; // Returns 0

    productOfNumbers.add(8);
    cout << productOfNumbers.getProduct(2) << endl; // Returns 32

    return 0;
}