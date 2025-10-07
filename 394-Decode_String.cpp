#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

string decodeString(string s){
    stack<int> st;
    stack<string> st1;
    string sb;
    int n = 0;

    for (char c : s)
    {
        if (isdigit(c))
        {
            n = n*10 + (c - '0');
        }
        else if (c == '[')
        {
            st.push(n);
            n = 0;
            st1.push(sb);
            sb = "";
        }
        else if(c == ']')
        {
            int k = st.top();
            st.pop();
            string temp = sb;
            sb = st1.top();
            st1.pop();
            while ((k--> 0))
            {
                sb+=  temp;
            }
            
        }
        else{
            sb += c;
        }
    }
    return sb;
}

int main() {
    cout << decodeString("3[a]2[bc]") << endl;    // ✅ Output: aaabcbc
    cout << decodeString("2[abc]3[cd]ef") << endl; // ✅ Output: abcabccdcdcdef
    return 0;
}