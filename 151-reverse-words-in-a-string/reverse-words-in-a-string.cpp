class Solution {
public:
    string reverseWords(string s) {
        vector<string> final;
        string word;
        for(char ch : s){
            
            if(ch!=' '){
               word+=ch;
            }
            else if(!word.empty()){
                final.push_back(word);
                word="";
            }
        }
        if(!word.empty()){
            final.push_back(word);
        }
        reverse(final.begin(),final.end());
        string result;
        for(int i=0; i<final.size(); i++){
          if(i>0) result=result+' '+final[i];
          else result+=final[i]; 
        }
        return result;
    }
};