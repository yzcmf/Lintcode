/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/mini-twitter
@Language: C++
@Datetime: 16-10-02 01:51
*/

/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */
/*
 这道题让我们实现一个迷你推特，具有发布消息，获得时间线，新鲜事，加关注和取消关注等功能，其中获得用户的时间线是返回最新10条推特，而新鲜事是返回最新10条自己的和好友的推特，如果取消关注了，那么返回的新鲜事中就没有取消关注的好友的推特。这是一道蛮有意思的设计题，我们为了简化问题，不会真的去获取系统时间来给推特排序，而是我们使用一个变量order，每发布一条消息，order自增1，这样我们就知道order大的发布的就晚，我们新建一个结构体Node，用来给每个tweet绑定一个order，然后我们写一个从一个Node数组中返回最后10个Node的函数，和一个从Node数组中返回前10个Node的函数，然后我们还需要两个哈希表，一个用来建立每个用户和其所有好友之间的映射，另一个用来建立每个用户和其发布的所有推特之间的映射，另外我们还需要一个变量order来记录发布推特的顺序。

对于postTweet函数，我们首先利用Tweet类提供的create函数建立一个tweet，然后我们看发布者是否在users_tweets里，如果不在添加这个用户，然后将这条推特加到和其映射的数组中，最后返回tweet。

对于getTimeline函数，我们先从该用户的推特集中返回最新的10条推特，然后按时间先后顺序排序，然后再返回即可。

对于getNewsFeed函数，我们先把该用户的推特集中最新10条保存下来，然后遍历其所有的好友，将其好友的最新10条保存下来，然后整个按时间先后顺序排序，返回最新10条即可。

对于follow函数，我们将好友加入用户的好友表里。

对于unfollow函数，我们将好友从用户的好友表里删除。

*/
//Reference: http://www.cnblogs.com/grandyang/p/5507316.html;
class MiniTwitter {
public:
    //我们新建一个结构体Node，用来给每个tweet绑定一个order;
    struct Node {
        int order;
        Tweet tweet;
        Node(int o, Tweet t): order(o), tweet(t){}
    };
    
    //从一个Node数组中返回最后10个Node的函数
    vector<Node> getLastTen(vector<Node> t) {
        int last = 10;
        if (t.size() < 10) last = t.size();
        return vector<Node>(t.end() - last, t.end());
    }
    
    //从Node数组中返回前10个Node的函数
    vector<Node> getFirstTen(vector<Node> t) {
        int last = 10;
        if (t.size() < 10) last = t.size();
        return vector<Node>(t.begin(), t.begin() + last);
    }
    
    MiniTwitter() {
        // initialize your data structure here.
        order = 0;
    }
    
    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        //  Write your code here
        Tweet tweet = Tweet::create(user_id, tweet_text);
        if (!users_tweets.count(user_id)) users_tweets[user_id] = {};
        order++; //order is great, repreasent the lastest new tweet;
        users_tweets[user_id].push_back(Node(order, tweet));
        return tweet;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        // Write your code here
        vector<Node> t;
        if (users_tweets.count(user_id)) {
            t = getLastTen(users_tweets[user_id]);
        }
        if (friends.count(user_id)) {
            for (auto it : friends[user_id]) {
                if (users_tweets.count(it)) {
                    vector<Node> v = getLastTen(users_tweets[it]);
                    t.insert(t.end(), v.begin(), v.end());
                }
            }
        }
        sort(t.begin(), t.end(), [](const Node &a, const Node &b){return a.order > b.order;});
        vector<Tweet> res;
        t = getFirstTen(t);
        for (auto a : t) {
            res.push_back(a.tweet);
        }
        return res;
    }
        
    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet> getTimeline(int user_id) {
        // Write your code here
        vector<Node> t;
        if (users_tweets.count(user_id)) {
            t = getLastTen(users_tweets[user_id]);
        }
        sort(t.begin(), t.end(), [](const Node &a, const Node &b){return a.order > b.order;});
        vector<Tweet> res;
        //t = getFirstTen(t); -- no use;
        for (auto a : t) {
            res.push_back(a.tweet);
        }
        return res;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
       // Write your code here
       //unordered_map<int, set<int>> friends;
       friends[from_user_id].insert(to_user_id);
       //from_user_id => many to_user_id
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        //unordered_map<int, set<int>> friends;
        friends[from_user_id].erase(to_user_id);
        //from_user_id => many to_user_id
    }
private:
    unordered_map<int, set<int>> friends;
    unordered_map<int, vector<Node>> users_tweets;
    int order;    
};