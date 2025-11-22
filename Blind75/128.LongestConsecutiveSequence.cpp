class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        set<int>freq;
        for(auto i:nums){
            freq.insert(i);
        }
        for(auto i:freq){
            if(freq.find(i-1)!=freq.end()){
                continue;
            }
            else{
                int currLen=0;
                while(freq.find(i)!=freq.end()){
                    currLen++;
                    i+=1;
                }
                ans=max(ans,currLen);
            }
        }
        return ans;
    }
};