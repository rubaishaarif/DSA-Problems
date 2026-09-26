#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
    vector<int> arr;

public:
    MedianFinder() {}

    void addNum(int num) {
        arr.push_back(num);
    } 

    double findMedian() {
        int size = arr.size();

        sort(arr.begin(), arr.end());

        // Even number of elements
        if (size % 2 == 0) {
            return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
        } 
        // Odd number of elements
        else {
            return arr[size / 2];
        }
    }
};

int main() {    
    MedianFinder* medianFinder = new MedianFinder(); 
    medianFinder->addNum(2);
    medianFinder->addNum(3);
    medianFinder->addNum(1);
    medianFinder->addNum(10);
    
    cout << medianFinder->findMedian() << endl;

    medianFinder->addNum(3);
    cout << medianFinder->findMedian() << endl; 

    delete medianFinder; 
    return 0;
}