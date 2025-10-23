#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.length() - 1; i >= 0; i--) {
            int digit = num[i] - '0';
            if (digit & 1) { 
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main() {
    string num;
    cout << "Enter a numeric string: ";
    cin >> num;

    Solution obj;
    string result = obj.largestOddNumber(num);

    if (result != "") {
        cout << "Largest odd number from the string is: " << result << endl;
    } else {
        cout << "No odd number can be formed." << endl;
    }

    return 0;
}
