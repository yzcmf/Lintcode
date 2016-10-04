/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/submatrix-sum
@Language: C++
@Datetime: 16-10-01 02:51
*/

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        vector<vector<int>> res;
        if(matrix.empty() || matrix[0].empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<n;i++) {
            vector<int>sum(m, 0);
            for(int j=i;j<n;j++) {
                for(int k=0;k<m;k++) 
                    sum[k] += matrix[k][j];
                //Find a subarray with 0 sum
                int lastSum = 0;
                unordered_map<int,int>ht;
                ht[0] = -1;
                for(int v=0;v<m;v++) {
                    lastSum += sum[v];
                    if(ht.count(lastSum)) {
                        res.push_back(vector<int>({ht[lastSum]+1, i}));
                        res.push_back(vector<int>({v, j}));
                        return res;
                    }
                    ht[lastSum] = v;
                }
            }
        }
        return res;
    }
};
//Subarry sum -- now in the two demension array and do it one col by one col;
//Note: the i col is start with 0 and then come to the right;
//From the i to j; j is start with col i;
//sum[k] as the j col first and using the hashmap method just like subarry sum
//The add the first col to the second col, one by one;