#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n; 
        int index = n - 1;

        while (k > 0) {
            int add = min(25, k); 
            ans[index] = 'a' + add;
            k -= add;
            index--;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n, k;
    cout << "Enter length of string (n): ";
    cin >> n;
    cout << "Enter numeric value (k): ";
    cin >> k;

    string result = obj.getSmallestString(n, k);
    cout << "Smallest string with numeric value " << k << " is: " << result << endl;

    return 0;
}
