#include <algorithm> // Include necessary header for sort

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int right = 0;
        int left = 0;
        string result = "";
        while (right < s2.length()) {
            result += s2[right];

            if (result.size() == s1.size()) {
                string st1 = result;
                string st2 = s1;
                std::sort(st1.begin(), st1.end()); // Fix: Sort properly
                std::sort(st2.begin(), st2.end()); // Fix: Sort properly
                if (st1 == st2) {
                    return true;
                }
            }

            // Fix: Move this inside `if (result.size() == s1.size())`
            if (right - left + 1 >= s1.size()) { 
                result.erase(result.begin()); // Fix: Remove first character instead of `pop_back()`
                left++;
            }

            right++;
        }
        return false;
    }
};
