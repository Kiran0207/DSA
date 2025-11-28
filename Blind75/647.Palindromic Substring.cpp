class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            //even length
            int start=i;
            int end=i+1;
            while(start>=0 && end<n && s[start]==s[end]){
                count++;
                start--;
                end++;
            }
            //odd length
            start=i;
            end=i;
            while(start>=0 && end<n && s[start]==s[end]){
                count++;
                start--;
                end++;
            }
        }
        return count;
    }
};
