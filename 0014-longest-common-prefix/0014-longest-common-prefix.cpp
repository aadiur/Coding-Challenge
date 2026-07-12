class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string start=strs[0];
        string end=strs[strs.size()-1];
        string ans="";
        for(int i=0;i<start.size();i++){
            if(start[i]!=end[i])break;
            ans+=start[i];

        }return ans;
        
    }
};