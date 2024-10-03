class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start=0,end=0;

        while(start!= nums.size() && end != nums.size()){
            if(nums[start]==0 && nums[end]==0){
                end++;
            }
            else if(nums[start]==0 && nums[end]!=0){
                swap(nums[start++],nums[end]);
                end=start;
            }
            else if(nums[start]!=0 && nums[end]==0){
                start++;
            }
            else{
                start++;
                end++;
            }
        }
    }
};