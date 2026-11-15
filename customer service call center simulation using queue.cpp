#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
class Call{
public:
    int callID;
    int arrivalTime;
    string customerName;

    Call(int id, int time, string name) 
        : callID(id), arrivalTime(time), customerName(name) {}
};

class CallCenter {
private:
    queue<Call> callQueue;
    int numCSRs;
    vector<bool> csrAvailable;

public:
    CallCenter(int csrs) : numCSRs(csrs), csrAvailable(csrs, true) {}

    void addCall(int id, int time, string name) {
        Call newCall(id, time, name);
        callQueue.push(newCall);
        cout << "Call " << id << " from " << name << " added to queue at time " << time << ".\n";
    }

    void processCalls() {
        for (int i = 0; i < numCSRs; ++i) {
            if (csrAvailable[i] && !callQueue.empty()) {
                Call currentCall = callQueue.front();
                callQueue.pop();
                csrAvailable[i] = false;

                cout << "CSR " << i + 1 << " is now handling Call " << currentCall.callID 
                     << " from " << currentCall.customerName << ".\n";

                csrAvailable[i] = true;
                cout << "CSR " << i + 1 << " completed Call " << currentCall.callID << ".\n";
            }
        }
    }
};

int main() {
    CallCenter center(2);

    center.addCall(101, 1, "Alice");
    center.addCall(102, 2, "Bob");
    center.addCall(103, 3, "Charlie");

    cout << "\n--- Processing First Batch ---\n";
    center.processCalls();

    cout << "\n--- Processing Remaining Calls ---\n";
    center.processCalls();

    return 0;
}