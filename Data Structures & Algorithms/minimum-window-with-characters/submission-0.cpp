class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char , int> mp;
        for(int i = 0; i < m ; i++){
            mp[t[i]]++;
        }
        int maxi = INT_MAX;
        string ans = "";
        for(int i = 0; i < n ; i++){
            unordered_map<char , int> op;
            op = mp;
            string str = "";
            for(int j = i; j < n ; j++){
                str += s[j];
                if(op.find(s[j]) != op.end()){
                    op[s[j]]--;
                    if(op[s[j]] == 0){
                        op.erase(s[j]);
                    }
                    if(op.size() == 0){
                        if(maxi > j-i+1){
                            maxi = j-i+1;
                            ans = str;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
