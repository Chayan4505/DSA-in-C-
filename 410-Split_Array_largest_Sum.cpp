#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = INT_MIN, high = 0, mid, ans = 0;

        for (auto &i : nums) {
            high += i;                   
            low = max(low, (long long)i); 
        }

        while (low <= high) {
            mid = low + (high - low) / 2;
            long long sum = 0;
            int parts = 1; 

            for (auto &i : nums) {
                sum += i;
                if (sum > mid) {
                    parts++;
                    sum = i;
                }
            }

            if (parts > k) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << obj.splitArray(nums, k) << endl;  
    return 0;
}
