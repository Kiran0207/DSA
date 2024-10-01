//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        if(arr.size()==1){
            return -1;
        }
        int secondLargestElement=INT_MIN;
        int firstLargestElement=INT_MIN;
        
        for(auto i:arr){
            if(i>firstLargestElement)   firstLargestElement=i;
        }
        
        for(auto i:arr){
            if(i>secondLargestElement && i!=firstLargestElement) secondLargestElement=i;
        }
        return secondLargestElement==INT_MIN ? -1:secondLargestElement;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends