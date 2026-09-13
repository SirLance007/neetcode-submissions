class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i< strs.size();i++){
            ans += strs[i];
            ans += "=";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string result = "";
        for(int i = 0; i<s.length();i++){
            if(s[i] == '='){
                ans.push_back(result);
                result = "";
            }
            else{
                result += s[i];
            }
        }
        return ans;
    }
};
