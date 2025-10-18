#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxActivities(vector<int> start, vector<int> end){
    cout<<"Selecting A0 \n";
    int count = 1;
    int currEndTime = end[0];

    for (int i = 0; i < start.size(); i++)
    {
        if (start[i] >= currEndTime)
        {
            cout<<"Selecting A"<<i<<endl;
            count++;
            currEndTime = end[i];
        }
    }
    return count;    
}

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second; //ascending
}

int main(){
    // vector<int> start = {1,3,0,5,8,5};
    // vector<int> end = {2,4,6,7,9,9};

    // cout<<maxActivities(start, end)<<endl;

     vector<int> start = {0,1,2};
    vector<int> end = {9,2,4};

    vector<pair<int,int>> act(3, make_pair(0,0));
    act[0] = make_pair(0,9);
    act[1] = make_pair(1,2);
    act[2] = make_pair(2,4);

    for (int i = 0; i < act.size(); i++)
    {
        cout<<act[i].first<<","<<act[i].second<<endl;
    }
    
    sort(act.begin(), act.end(), compare);
    cout<<"-------------Sorted----------\n";
    for (int i = 0; i < act.size(); i++)
    {
        cout<<"A"<<i<<" : "<<act[i].first<<","<<act[i].second<<endl;;

    }
    
    return 0;
}