class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string str;
        for(char ch:s){
            if(ch=='('){
                
                if(cnt!=0){
                    str+=ch;
                    

                }cnt++;
            }
            else{
                cnt--;
                if(cnt!=0){
                    str+=ch;
                }
            }
        }return str;
    }
};