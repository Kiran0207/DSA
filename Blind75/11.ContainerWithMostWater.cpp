class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int n=height.size();
        int j=n-1;
        int maximumArea=0;
        while(i<j){
            if(height[i]>height[j]){
                int area=height[j]*(j-i);
                maximumArea=max(maximumArea,area);
                j--;
            }
            else{
                int area=height[i]*(j-i);
                maximumArea=max(maximumArea,area);
                i++;
            }
        }
        return maximumArea;
    }
};
