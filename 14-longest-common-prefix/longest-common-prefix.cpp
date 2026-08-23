class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if (s.empty()) return "";
        sort(s.begin(), s.end());
        string first = s[0];
        string last = s[s.size()-1];
        int minLength= min(first.length(), last.length());
        string ans="";
        for(int i =0; i<minLength; i++){
            if(first[i]==last[i]) ans+=first[i];
            else break;
        }
        return ans;
    }
};