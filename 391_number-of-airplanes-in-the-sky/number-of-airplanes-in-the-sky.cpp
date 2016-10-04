/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/number-of-airplanes-in-the-sky
@Language: C++
@Datetime: 16-09-25 22:36
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<pair<int,bool>>V;
        for(int i=0;i<airplanes.size();i++)
        {
            V.push_back(make_pair(airplanes[i].start,true));
            V.push_back(make_pair(airplanes[i].end,false));
        }
        sort(V.begin(),V.end());
        int cnt = 0,res=0;
        for(int i=0;i<V.size();i++)
        {
            if(V[i].second == true) cnt++;
            else
            cnt--;
            res = max(res,cnt);
        }
        return res;
    }
};