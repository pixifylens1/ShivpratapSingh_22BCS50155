#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int l = 0, r = 0;
    int n = s.length();
    int maxlength = 0;
    map<char, int> mpp;

    for (int i = 0; i < 255; i++) {
        mpp[i] = -1;
    }

    while (r < n) {
        if (mpp[s[r]] != -1) {
            if (mpp[s[r]] >= l) {
                l = mpp[s[r]] + 1;
            }
        }

        int len = r - l + 1;
        maxlength = max(maxlength, len);
        mpp[s[r]] = r;
        r++;
    }

    return maxlength;
}

int main() {
    string s = "abcabcbb";
    

    int result = lengthOfLongestSubstring(s);
    cout << "The length of the longest substring: " << result << endl;

    return 0;
}