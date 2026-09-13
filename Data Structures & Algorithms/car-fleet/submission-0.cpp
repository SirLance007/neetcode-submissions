class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<float , float>> ans;
        vector<float> values;
        stack<float> st;
        for(int i = 0; i < n ; i++){
            ans.push_back({position[i] , speed[i]});
        }
        sort(ans.begin() , ans.end());
        for(int i = 0; i < n ; i++){
            int dist = ans[i].first;
            int sppeed = ans[i].second;
            double time = (double)(target-dist)/sppeed;
            values.push_back(time);
        }
        // for(auto it : values){
        //     cout << it << " ";
        // }
        // cout << endl;
        for(int i = n-1; i >= 0 ; i--){
            if(st.empty()){
                st.push(values[i]);
            }else if(st.top() < values[i]){
                st.push(values[i]);
            }
        }
        return st.size();
    }
};
