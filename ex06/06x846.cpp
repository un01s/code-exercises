/*
 * leetcode 846
 *
 */

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        priority_queue<int, vector<int>, greater<int>> pq(hand.begin(),
                                                          hand.end());
        while (!pq.empty()) {
            int count = groupSize;
            vector<int> temp;
            while (count > 1 && !pq.empty()) {
                int x = pq.top();
                pq.pop();
                while (pq.top() == x && !pq.empty()) {
                    temp.push_back(pq.top());
                    pq.pop();
                }
                if (pq.top() - x == 1 && !pq.empty()) {
                    count--;
                } else {
                    return false;
                }
            }
            pq.pop();
            for (auto& it : temp) {
                pq.push(it);
            }
        }
        return true;
    }
};

