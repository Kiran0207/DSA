class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> complements;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int remainingTarget = target-nums[i];
            if(complements.count(remainingTarget)){
                return {complements[remainingTarget],i};
            }
            complements[nums[i]]=i;
        }
        return {};
    }
};