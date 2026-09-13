class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char,int> mp;
        for(char c : t) mp[c]++;

        int left = 0;
        int required = mp.size();
        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++){
            char c = s[right];

            if(mp.find(c) != mp.end()){
                mp[c]--;
                if(mp[c] == 0)
                    required--;
            }

            while(required == 0){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                char lc = s[left];
                if(mp.find(lc) != mp.end()){
                    mp[lc]++;
                    if(mp[lc] > 0)
                        required++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
