class Solution {
private:
    void solve(vector<int> &candidates , vector<int> &temp , vector<vector<int>> &ans , int idx , int target , set<vector<int>> &st){
        if(target == 0){
            vector<int> op;
            op = temp;
            sort(op.begin() , op.end());
            if(st.find(op) == st.end()){
                ans.push_back(temp);
                st.insert(op);
            }
            return;
        }
        if(idx >= candidates.size() || target < 0){
            return;
        }
        temp.push_back(candidates[idx]);
        solve(candidates , temp , ans , idx+1 , target - candidates[idx] , st);
        temp.pop_back();
        solve(candidates , temp , ans , idx+1 , target , st);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> st;
        solve(candidates , temp , ans , 0 , target , st);
        return ans;
    }
};
