/*
 * leetcode 455
 * assign cookies
 *
 * g[] greedy factor, which is the minimum size of a cookie that the child will
 * be content with
 * each cookie has a size s[j]
 *
 * 2023-07-24
 *
 * not two loops here but only one for-loop
 * another one uses self-decrement!
 * 
 * either big cookie for big appetite
 * or small appetite for small cookie
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// local optimal leads to global optimal
// big appetite looking for big cookie
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                result++;
                index--;
            }
        }
        return result;
    }
};

// little cookie for little appetite
class Solution2 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index = 0;
        for(int i = 0; i < s.size(); i++) { // cookie first
            if(index < g.size() && g[index] <= s[i]){ // appetite
                index++;
            }
        }
        return index;
    }
};

int main() {
    return 0;
}

