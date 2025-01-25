#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  vector<vector<int>> threeSum(  vector<int>& nums) {
      vector<int> newnums = nums;
      vector<  vector<int>> triplets;
      sort(newnums.begin(), newnums.end());
    
    for (int i = 0; i < newnums.size(); i++) {
        if (i > 0 && newnums[i] == newnums[i - 1]) {
            continue;
        }
        
        int target = -newnums[i];
        int j = i + 1;
        int k = newnums.size() - 1;
        
        while (j < k) {
            int sum = newnums[j] + newnums[k];
            
            if (sum == target) {
                triplets.push_back({newnums[i], newnums[j], newnums[k]});
                while (j < k && newnums[j] == newnums[j + 1]) j++;
                while (j < k && newnums[k] == newnums[k - 1]) k--;
                j++;
                k--;
            } else if (sum < target) {
                j++;
            } else {
                k--;
            }
        }
    }
    
    return triplets;
  }

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}