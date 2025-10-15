#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int currGas = 0;
        int startIndex = 0;

        for (int i = 0; i < gas.size(); i++) {
            currGas += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];

            if (currGas < 0) {
                startIndex = i + 1;
                currGas = 0;
            }
        }

        return totalGas >= 0 ? startIndex : -1;
    }
};

int main() {
    Solution sol;
    vector<int> gas, cost;
    int n;

    cout << "Enter number of gas stations: ";
    cin >> n;

    gas.resize(n);
    cost.resize(n);

    cout << "Enter gas available at each station:\n";
    for (int i = 0; i < n; i++) {
        cin >> gas[i];
    }

    cout << "Enter cost to travel to next station:\n";
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    int start = sol.canCompleteCircuit(gas, cost);

    if (start == -1)
        cout << "It is not possible to complete the circuit.\n";
    else
        cout << "Start at station index: " << start << endl;

    return 0;
}
