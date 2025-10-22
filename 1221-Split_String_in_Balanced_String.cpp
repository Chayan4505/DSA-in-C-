#include <iostream>
#include <string>
using namespace std;

int balancedStringSplit(string s) {
    int ans = 0;     
    int countR = 0; 
    int countL = 0;  

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == 'R') {
            countR++;
        } else if (s[i] == 'L') {
            countL++;
        }


        if (countR == countL) {
            ans++;
            countR = 0;
            countL = 0;
        }
    }

    return ans;
}

int main() {
    string s = "RLRRLLRLRL";
    cout << balancedStringSplit(s) << endl;  
    return 0;
}
