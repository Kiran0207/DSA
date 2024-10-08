class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConOnes = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                maxConOnes = max(maxConOnes, count);
                count = 0; 
            }
        }
        maxConOnes = max(maxConOnes, count);
        return maxConOnes;
    }
};