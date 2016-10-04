/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/fast-power
@Language: C++
@Datetime: 16-09-21 07:35
*/

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        //if(n==1) return a%b;
        if(n<0) return 0;
        if(n==0) return 1%b;
        
        //(a*b) % p = ((a%p) * (b%p)) % p; 
        //(a = p*k + m;b = p*t + n; (a*b)%p = (m*n)%p;can be:a1,a2,...,an);
        
        long long product = fastPower(a,b,n/2); 
        product = (product*product)%b;
        
        if(n%2==1) product = (product*a) % b;
        
        return (int)product;
    }
};