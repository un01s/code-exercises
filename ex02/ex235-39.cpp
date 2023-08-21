/*
 * leetcode 39
 * 
 * backtracking
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    vector<int> tmp;

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {

        backtrack(candidates, target);
        return result;
    }

    void backtrack(vector<int> &candidates, int target) {
        if (target == 0) {
            result.push_back(tmp);
            return;
        } else if (target < 0) {
            return;
        }

        int max = 0;
        for (int k = 0; k < tmp.size(); k++) {
            if (tmp[k] > max)
                max = tmp[k];
        }

        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] >= max) {
                tmp.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i]);
                tmp.pop_back();
            }
        }
    }
};

void printV2(vector<vector<int> >& v) {
    cout << "vector:[";
    for (int i = 0; i < v.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

int main() {
    int a[] = {2, 3, 6, 7};
    int target = 7;
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    Solution s;
    vector<vector<int> > ans = s.combinationSum(v, target);

    printV2(ans);

    return 0;
}
