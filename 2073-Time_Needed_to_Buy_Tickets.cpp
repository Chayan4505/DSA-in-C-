#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        int n = tickets.size();
        for(int i =0; i<n; i++){
            q.push({tickets[i], i});
        }
        int time = 0;
        while(!q.empty()){
            pair<int, int> front = q.front();
            q.pop();
            int num_tickets = front.first;
            int og_i = front.second;
            num_tickets--;
            time++;
            if(og_i == k && num_tickets == 0){
                return time;
            }
            if(num_tickets > 0){
                q.push({num_tickets, og_i});
            }
        }
        return time;
    }
};

int main() {
    Solution sol;
    vector<int> tickets;
    int n, k;

    cout << "Enter number of people: ";
    cin >> n;

    cout << "Enter tickets required for each person:\n";
    tickets.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tickets[i];
    }

    cout << "Enter index (k) of person: ";
    cin >> k;

    int result = sol.timeRequiredToBuy(tickets, k);
    cout << "Time required for person " << k << " to finish buying tickets: " << result << endl;

    return 0;
}