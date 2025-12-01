class Solution {
public:
    bool canBreak(string s,set<string>& st,int n,int index,vector<int>&dp){
        if(index>=n){
            return true;
        }
        if(dp[index]!=-1) return dp[index];
        if(st.find(s)!=st.end()){
            dp[index]=true;
        }
        for(int i=1;i<n-index+1;i++){
            string newS=s.substr(index,i);
            if(st.find(newS)!=st.end() && canBreak(s,st,n,index+i,dp)){
                return dp[index]=true;
            }
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(n + 1, 0);
        dp[n] = 1; // empty string is valid

        for (int index = n - 1; index >= 0; index--) {
            for (int len = 1; len < n - index+1; len++) {
                string sub = s.substr(index, len);

                if (st.count(sub) && dp[index + len]) {
                    dp[index] = 1;
                    break; // IMPORTANT: stop checking longer substrings
                }
            }
        }

        return dp[0];
}

};
