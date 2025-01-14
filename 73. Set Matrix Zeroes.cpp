// https://leetcode.com/problems/set-matrix-zeroes/description/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<matrix[i][j]<<" ";
                if(!matrix[i][j]){
                    row[i] = 1;
                    col[j] = 1;
                    // break;
                }
            }
            // cout<<endl;
        }
        // for(auto x: col)cout<<x<<" ";
        // cout<<endl;
        // for(auto x: row)cout<<x<<" ";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(col[j] || row[i])matrix[i][j] = 0;
            }
        }
    }
};