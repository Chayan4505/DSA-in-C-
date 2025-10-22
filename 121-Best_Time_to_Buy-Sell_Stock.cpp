#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        
        vector<int> maxArr(n);
        maxArr[n - 1] = prices[n - 1];
        
        for(int i = n - 2; i >= 0; i--) {
            maxArr[i] = max(maxArr[i + 1], prices[i]);
        }
        
        int profit = 0;
        for(int i = 0; i < n; i++) {
            int currProfit = maxArr[i] - prices[i];
            profit = max(profit, currProfit);
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};  
    Solution obj;
    int result = obj.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}
