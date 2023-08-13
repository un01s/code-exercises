/*
 * leetcode 277
 *
 */

class Solution {
public:
    int findCelebrity(int n) {
        if (n == 1) return 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        // remove non-celebrity first
        while (q.size() >= 2) {
            // get two, eliminate one
            int cand = q.front(); q.pop();
            int other = q.front(); q.pop();
            if (knows(cand, other) || !knows(other, cand)) {
                // cand is not celebrity, eliminate
                // let other in 
                q.push(other);
            } else {
                // other is not celebrity
                // let cand in the queue
                q.push(cand);
            }
        }

        // only one candidate now
        int cand = q.front(); q.pop();
        for (int other = 0; other < n; other++) {
            if (other == cand) {
                continue;
            }
            // just make sure all others know cand
            // and cand does not know others
            if (!knows(other, cand) || knows(cand, other)) {
                return -1;
            }
        }
        return cand;
    }
};

