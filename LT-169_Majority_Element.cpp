#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int majorityElement(const   vector<int>& nums) {
      unordered_map<int, int> countMap;
    int majorityCount = nums.size() / 2;

    for (int num : nums) {
        countMap[num]++;
        if (countMap[num] > majorityCount) {
            return num;
        }
    }

    return -1; 
}

int main() {
      vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = majorityElement(nums);
      cout << "The majority element is: " << result <<   endl;
    return 0;
}