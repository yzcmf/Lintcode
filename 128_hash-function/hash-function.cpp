/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/hash-function
@Language: C++
@Datetime: 16-09-14 03:52
*/

//(a + b) % p = (a % p + b % p) % p 
//(a - b) % p = (a % p - b % p) % p 
//(a b) % p = (a % p b % p) % p 
// a^b % p = ((a % p)^b) % p 
//(a b) % p = (a % p b) % p
class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        
        long res = 0;//long is enough for the res inside the for loop;
        
        for(int i=0;i<key.size();i++)
        {
            res = (int)key[i] + 33*res;
            res = res % HASH_SIZE;
            //Each time we observe for one character and see its position
            //Just need to memorize that one character one time is enough
        }
        
        //res = res % HASH_SIZE;
        //Note:can not leave it outside the range is not enough for res;
        //Even using the double double;
        
        return (int)res;
    }
};