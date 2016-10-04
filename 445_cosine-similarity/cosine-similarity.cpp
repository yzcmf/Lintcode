/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/cosine-similarity
@Language: C++
@Datetime: 16-09-14 02:59
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        if(A.empty()||B.empty()) return 2.0000;
        
        double sum_ab = 0.0;
        double sum_aa = 0.0;
        double sum_bb = 0.0;
        
        for(int i=0;i<A.size();i++)
        {
            sum_ab += A[i]*B[i];
            sum_aa += A[i]*A[i];
            sum_bb += B[i]*B[i];
        }
        
        if(!sum_aa||!sum_bb) return 2.0000;
        
        double res = sum_ab/(sqrt(sum_aa)*sqrt(sum_bb));
        
        return res;
    }
};
