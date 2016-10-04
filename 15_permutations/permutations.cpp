/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/permutations
@Language: C++
@Datetime: 16-10-02 04:10
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> num) {
        
        // write your code here
        vector<vector<int>> allPer;
        vector<int> per;
        if(num.empty()) 
        {
         allPer.push_back(per);
         return allPer;
        }
        sort(num.begin(),num.end());
        vector<bool> used(num.size(),false);
        findPerUniq(num, used, per, allPer);
        return allPer;
    }
    
void findPerUniq(vector<int> &num, vector<bool> &used, vector<int> &per, vector<vector<int>> &allPer) {
        if(per.size()==num.size()) {
            allPer.push_back(per);
            return;
        }
        
        for(int i=0; i<num.size(); i++) {
            if(used[i]) continue;
            // if(i>0 && num[i]==num[i-1] && !used[i-1]) continue;
            used[i] = true;
            per.push_back(num[i]);
            findPerUniq(num, used, per, allPer);
            per.pop_back();
            used[i] = false;
        }
    }
};


