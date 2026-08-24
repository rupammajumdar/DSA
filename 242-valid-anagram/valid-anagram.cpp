class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;
        if(s.length()!=t.length()) return false;
        for(int i=0; i<s.length(); i++){
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        for(auto &it : mps){
            char letter = it.first;
            int count =it.second;
            if(mpt[letter] != count)  return false ;
        }
        return true;
    }
};