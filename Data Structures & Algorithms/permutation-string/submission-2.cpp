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
                std::sort(st1.begin(), st1.end()); 
                std::sort(st2.begin(), st2.end()); 
                if (st1 == st2) {
                    return true;
                }
                result.erase(result.begin()); 
                left++;
            }
            right++;
        }
        return false;
    }
};
