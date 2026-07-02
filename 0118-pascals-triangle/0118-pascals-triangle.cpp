class Solution {
public:
    vector<int>gen(int row){
        long long ans=1;
        vector<int>arr;
        arr.push_back(1);
        for(int col=1;col<row;col++){
            ans=ans*(row-col);
            ans=ans/col;
            arr.push_back(ans);
        }
        return arr;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(gen(i));

        }
        return ans;
        
    }
};