 #include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

int largestSubWith0Sum(vector<int> arr){
    unordered_map<int, int> m;// <sum, idx >

    int sum = 0;
    int ans = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        sum += arr[j];

        if (m.count(sum))
        {
            int currLen = j- m[sum];    // j - idx
            ans = max(ans, currLen);
        }
        else{
            m[sum] = j;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {15,-2,2,-8,1,7,10};
    
    cout<<"Ans = "<<largestSubWith0Sum(arr)<<endl;
    return 0;
}