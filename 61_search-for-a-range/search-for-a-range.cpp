/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/search-for-a-range
@Language: C++
@Datetime: 16-09-26 00:50
*/

//--Method one : STL function;
// class Solution {
//     /** 
//      *@param A : an integer sorted array
//      *@param target :  an integer to be inserted
//      *return : a list of length 2, [index1, index2]
//      */
// public:
//     vector<int> searchRange(vector<int>& nums, int target)
//     {
//         if (!binary_search(nums.begin(), nums.end(), target))
//             return {-1, -1};
            
//         auto low = lower_bound (nums.begin(), nums.end(), target);
//         auto up = upper_bound (nums.begin(), nums.end(), target);    
        
//         return {low - nums.begin(), up - nums.begin() - 1};
//     }
// };

// --Method two: O(n) common solution;
// class Solution {
// public:
// vector<int> searchRange(vector<int>& nums, int target) {
// vector<int> res;
// bool findFirst = false;
// res.push_back(-1);
// res.push_back(-1);
// for(int i = 0; i < nums.size(); ++i){
// if(target == nums[i] && !findFirst){
// res.pop_back();
// res.pop_back();
// res.push_back(i);
// res.push_back(i);
// findFirst = true;
// }
// if(target == nums[i]){
// res.pop_back();
// res.push_back(i);
// }
// }
// return res;
// }
// };

class Solution{
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        int begin = lower_bound(A, target);
        int end = upper_bound(A, target);

        if (begin < A.size() && A[begin] == target)
            return {begin, end - 1};

        return {-1, -1};
    }

private:
    int lower_bound(vector<int> &A, int target) {
        int left = 0;
        int right = A.size();
       
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        //After the loop left == right , so mid = right = left;
        //Thus:A[mid] >= target;(Beacuse right = mid);
        // (A[mid] == target) in the end because the right == left at last;
        //so mid will become the first index of the target;
        
        return left;
    }

    int upper_bound(vector<int> &A, int target) {
        int left = 0;
        int right = A.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        //After the loop left == right , so mid = right = left;
        //Thus:A[mid] > target;(Beacuse right = mid);
        //so mid will become the last index plus 1 of the target;
        
        return left;
    }
};

