#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, string> m;
    m[101] = "absbb";
    m[102] = "kajskk";
    m[103] = "hggsh";

    // cout<<m[102]<<endl;

    for(auto jkj : m){
        cout<<"Key: "<<jkj.first<<" , "<<"Value: "<<jkj.second<<endl;
    }
    return 0;
} 