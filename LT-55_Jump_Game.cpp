#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int>& nums) {
    int maxind = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxind) {
            return false;
        }
        maxind = max(maxind, nums[i] + i);
    }
    return true;
}

int main() {
    vector<int> nums = {3,2,1,0,4};
    bool result = canJump(nums);
    if (result) {
        cout<<"You can reach the last index.";
    } else {
        cout<<"You cannot reach the last index";
    }
    return 0;
}