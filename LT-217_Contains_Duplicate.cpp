#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> numSet;
    for (int num : nums) {
        if (numSet.find(num) != numSet.end()) {
            return true;
        }
        numSet.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1}; // Example input
    if (containsDuplicate(nums)) {
        cout << "The array contains duplicates." << endl;
    } else {
        cout << "The array does not contain duplicates." << endl;
    }
    return 0;
}