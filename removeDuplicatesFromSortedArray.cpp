class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                nums[i-1]=INT_MAX;
            }
        }
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=INT_MAX) count++;
            else break;
        }
        return count;
    }
};