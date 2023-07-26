/*
 * leetcode 406
 *
 *
 *
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// greedy
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0]; // from high to short
    }
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int> > que;
        for (int i = 0; i < people.size(); i++) {
            int pos = people[i][1];
            std::list<vector<int> >::iterator it = que.begin();
            while(pos--) {
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int> >(que.begin(), que.end());
    }
};


int main() {
    return 0;
}
