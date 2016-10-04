/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/single-number-iii
@Language: C++
@Datetime: 16-09-30 20:45
*/

/*
那么两个不一样的数，那么把数组所有的数字异或，得到的是a^b，那么如何分别得到a，b呢。我们知道a！= b，所以a^b，肯定有一位为1假如是第j位，则说明a，b中肯定在那个为1的位，一个是0，一个是1，那么我们就把原来的数组分成两组，一个是j位为1，一个j位为0的，然后分别异或。我们知道相同的数字j位肯定也相同。所以把大问题转换成了两个相同的小问题。这个题也只能找出来a，b。至于谁是a，谁是b。由于条件不充分也不能判定。
如果对所有元素进行异或操作，最后剩余的结果是出现次数为1次的两个数的异或结果，此时无法直接得到这两个数具体的值。但是，因为这两个数一定是不同的，所以最终异或的值至少有一个位为1。我们可以找出异或结果中第一个值为1的位，然后根据该位的值是否为1，将数组中的每一个数，分成两个部分。这样每个部分，就可以采用Sing number I中的方法得到只出现一次的数。
*/
//Time:O(n)
//Space:O(1)
class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    // int findFirstBit1(int num) {
    //     int index = 0;
    //     while((num & 1) == 0) {
    //         ++index;
    //         num >>= 1;
    //     }
    //     return index;
    // }

    // bool isBit1(int num, int index) {
    //     num = num >> index;
    //     return (num & 1);
    // }

    // vector<int> singleNumberIII(vector<int> &A) {
    //     int n = A.size();
    //     int result = A[0];
    //     for(int i = 1; i < n; ++i) {
    //         result ^= A[i];
    //     }

    //     //我们知道a！= b，所以a^b，肯定有一位为1假如是第j位，
    //     //则说明a，b中肯定在那个为1的位，一个是0，一个是1，根据异或的性质；
    //     //那么我们就把原来的数组分成两组，一个是j位为1，一个j位为0的，然后分别异或。
    //     int indexOfBit1 = findFirstBit1(result);

    //     int num1 = 0, num2 = 0;
    //     for(int i = 0; i < n; i++) {
    //         if(isBit1(A[i], indexOfBit1)) {
    //             num1 ^= A[i];
    //         }
    //         else
    //             num2 ^= A[i];
    //     }
    //     vector<int> res;
    //     res.push_back(num1);
    //     res.push_back(num2);
    //     return res;
    // }
    
    vector<int>singleNumberIII(vector<int> &A){
        // write your code here
        int t = 0;
        for(auto v : A)
            t ^= v;
        
        int mask = t & ~(t-1);
        // t=111011000;
        // (t-1) = 111010111: find the first bit 1 from the right;
        // ~(t-1)= 000101000: the bits higher than first bit 1 will become opposite from original
        // t & ~(t-1) = 000001000 : only the first bit 1 will left;
        int x = 0;
        int y = 0;
        
        for(auto v : A)
        {
            if(v & mask) // first bit 1 numbers;
                x^=v;
            else//first bit not 1 numbers
                y^=v;
        }
        
        return vector<int>{x,y};
}
};
//http://www.wengweitao.com/lintcode-single-number-i-ii-iii-luo-dan-de-shu.html