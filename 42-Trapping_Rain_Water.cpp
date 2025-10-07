#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int trap(vector<int>& height){
    int left = 0;
    int right = height.size() - 1;
    int leftMax = height[left];
    int rightMax = height[right];
    int water = 0;

    while (left < right)
    {
        if (leftMax < rightMax)
        {
            left++;
            leftMax = max(leftMax, height[left]);
            water += leftMax - height[left];
        }
        else{
            right--;
            rightMax = max(rightMax, height[right]);
            water += rightMax - height[right];
        }
    }
    
    return water;
}

int main(){
    
    vector<int> height = {7,0,4,2,5,0,6,4,0,5};
    cout << trap(height) << endl;
    return 0;
}