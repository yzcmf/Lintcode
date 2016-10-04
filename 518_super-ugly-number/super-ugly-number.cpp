/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/super-ugly-number
@Language: C++
@Datetime: 16-10-01 07:40
*/

class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //Write your code here
        vector<int>res(n,1);
        int k = primes.size();
        vector<int>index(k,0);
        
        for(int i=1;i<n;i++)
        {
            int min_num = INT_MAX;
            for(int j=0;j<k;j++)
            {
                min_num = min(min_num,primes[j]*res[index[j]]);
            }
            
            res[i] = min_num;
            for(int j=0;j<k;j++)
            {
                if(min_num == primes[j]*res[index[j]])
                index[j]++;
            }
        }
        
        return res[n-1];
    }
};