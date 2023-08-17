/*
 * leetcode 542
 * 0 1 matrix
 *
 */

class Solution {
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;

public:
    bool Judge(int i,int j){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return false;
        }
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> V1;
        vector<vector<int>> V2;
        vector<int> tmp;

        m = mat.size();
        n = mat[0].size();


        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(mat[i][j] == 0){
                    tmp.push_back(i);
                    tmp.push_back(j);
                    V1.push_back(tmp);
                    tmp.clear();
                }else{
                    mat[i][j] = -1;
                }
            }
        }

        int deep = 1;
        while(!V1.empty()){
            for(int i = 0;i < V1.size();i ++){
                for(int k = 0;k < 4;k ++){
                    int i_tmp = V1[i][0] + dir[k][0];
                    int j_tmp = V1[i][1] + dir[k][1];
                    if(Judge(i_tmp,j_tmp) && mat[i_tmp][j_tmp] == -1){
                        mat[i_tmp][j_tmp] = deep;
                        tmp.clear();
                        tmp.push_back(i_tmp);
                        tmp.push_back(j_tmp);
                        V2.push_back(tmp);
                    }
                }
            }
            V1 = V2;
            deep ++;
            V2.clear();
        }

        return mat;
    }
};

