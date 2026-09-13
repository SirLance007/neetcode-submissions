class Solution {
private:
    void solve(int openN , int closeN , int n , vector<string> &res , string& st){
        if(openN == closeN && openN == n){
            res.push_back(st);
            return;
        }
        if(openN < n){
            st += "(";
            solve(openN+1 , closeN , n , res , st);
            st.pop_back();
        }
        if(closeN < openN){
            st += ')';
            solve(openN , closeN+1 , n , res , st);
            st.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string st;
        solve(0 , 0 , n , res , st);
        return res;
    }
};
