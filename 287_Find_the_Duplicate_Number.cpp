#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int findDuplicate( vector<int>& nums) {
       unordered_set<int> seen;
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return num;
        }
        seen.insert(num);
    }
    return -1; 
}

int main() {
       vector<int> nums = {1, 3, 4, 2, 2};
    int duplicate = findDuplicate(nums);
       cout << "The duplicate number is: " << duplicate <<    endl;
    return 0;
}