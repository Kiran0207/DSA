#include<bits/stdc++.h>
class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string encodedString="";
        for(auto i:s){
            int len=i.length();
            encodedString=encodedString+to_string(len)+"#"+i;
        }
        return encodedString;
    }

    vector<string> decode(string& s) {
        vector<string> decodedString;
        int i = 0;
    
        while (i < s.length()) {
            string len = "";
    
            // read number until '#'
            while (s[i] != '#') {
                len += s[i];
                i++;
            }
    
            int strLen = stoi(len);
            i++; // skip '#'
    
            // now extract the string of length strLen
            string word = s.substr(i, strLen);
            decodedString.push_back(word);
            i += strLen;
        }
    
        return decodedString;
    }

};
