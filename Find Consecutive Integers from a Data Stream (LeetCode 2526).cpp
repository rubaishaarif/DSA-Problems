#include <iostream>
#include <queue>

using namespace std;

class DataStream {
private:
    queue<int> q;
    int targetValue;
    int targetK;
    int matchingCount;

public:
    DataStream(int value, int k) : targetValue(value), targetK(k), matchingCount(0) {}

    bool consec(int num) {
        q.push(num);
        if (num == targetValue) {
            matchingCount++;
        }

        if (q.size() > targetK) {
            if (q.front() == targetValue) {
                matchingCount--;
            }
            q.pop();
        }

        return matchingCount == targetK;
    }
};

int main() {
    DataStream dataStream(4, 3);
    cout << boolalpha;
    cout << dataStream.consec(4) << endl; // returns false
    cout << dataStream.consec(4) << endl; // returns false
    cout << dataStream.consec(4) << endl; // returns true
    cout << dataStream.consec(3) << endl; // returns false

    return 0;
}