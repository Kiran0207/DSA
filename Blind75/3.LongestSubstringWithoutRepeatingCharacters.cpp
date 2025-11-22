class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> freq;
        int currMax=0;
        int left=0,right=0;
        while(right<s.length()){
            if(freq.find(s[right])==freq.end()){
                freq.insert(s[right]);
                right++;
                currMax=max(currMax,right-left);
            }
            while(left<s.length() && freq.find(s[right])!=freq.end()){
                freq.erase(s[left]);
                left++;
            }
        }
        return currMax;
    }
};