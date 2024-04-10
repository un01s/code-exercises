/*
 * leetcode 950
 * reveal cards in increasing order
 * deque
 *
 */

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(rbegin(deck), rend(deck));
        deque<int> dq;
        int n = deck.size();
        dq.push_front(deck[0]);
        for (int i = 1; i < n; i++) {
            int x = dq.back();
            dq.pop_back();
            dq.push_front(x);
            dq.push_front(deck[i]);
        }

        vector<int> res;
        while (!dq.empty()) {
            res.push_back(dq.front());
            dq.pop_front();
        }
        return res;
    }
};

