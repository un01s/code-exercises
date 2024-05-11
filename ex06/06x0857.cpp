/*
 * leetcode 857
 * minimum cost to hire K workers
 *
 */

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        struct Worker {
            int quality;
            int wage;
            Worker() : quality(0), wage(0) {}
            Worker(int q, int w) : quality(q), wage(w) {}
            double ratio() const { return double(wage) / quality; }
            bool operator<(const Worker& o) { return ratio() < o.ratio(); }
        };
        int i, j;
        double ans = 1e9;
        vector<Worker> W;
        for (i = 0; i < quality.size(); ++i) {
            W.emplace_back(Worker(quality[i], wage[i]));
        }
        std::sort(W.begin(), W.end());
        priority_queue<int> heap;
        int sumq = 0;
        for (const Worker& worker : W) {
            heap.push(worker.quality);
            sumq += worker.quality;
            if (heap.size() > k) {
                sumq -= heap.top();
                heap.pop();
            }
            if (heap.size() == k) {
                ans = std::min(ans, worker.ratio() * sumq);
            }
        }
        return ans;
    }
};

