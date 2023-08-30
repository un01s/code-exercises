/*
 * 
 */

def beautifulSubsets(self, A: List[int], k: int) -> int:
        count = Counter(A)

        def dp(a):
            dp0, dp1 = dp(a - k) if a - k in count else (1, 0)
            return dp0 + dp1, dp0 * (pow(2, count[a]) - 1)

        return reduce(mul, (sum(dp(a)) for a in count if not count[a + k])) - 1

powers = [1]
for _ in range(20):
    powers.append(powers[-1] * 2)

def count(vals):
    acc = 1
    last = 0
    for count in vals:
        last = (acc - last) * (powers[count] - 1)
        acc += last
    return acc

class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        cnt = Counter(nums)
        ans = 1
        for item in cnt:
            if item - k not in cnt:
                vals = []
                while item in cnt:
                    vals.append(cnt[item])
                    item += k
                ans *= count(vals)
        return ans - 1


class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = 0;
        for (int x : nums) mx = max(mx, x);

        // vis[i] 表示目前子集中有几个 i
        int vis[mx + 1];
        memset(vis, 0, sizeof(vis));

        int ans = 0;
        function<void(int)> dfs = [&](int pos) {
            // dfs 结束，是合法子集
            if (pos == n) { ans++; return; }

            // === 分支 1：尝试把第 pos 个数加入子集 ===
            vis[nums[pos]]++;
            // 检查是否存在 nums[pos] + k 和 nums[pos] - k
            bool flag = true;
            if (nums[pos] + k <= mx && vis[nums[pos] + k] > 0) flag = false;
            if (nums[pos] - k >= 0 && vis[nums[pos] - k] > 0) flag = false;
            // 若检查通过则可以把第 pos 个数加入子集
            if (flag) dfs(pos + 1);
            // 撤销第 pos 个数的影响
            vis[nums[pos]]--;

            // === 分支 2：第 pos 个数不加入子集 ===
            dfs(pos + 1);
        };
        dfs(0);
        // 题目要求非空子集，答案减 1
        return ans - 1;
    }
};

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int K) {
        // 把每个数按 mod k 分组
        unordered_map<int, map<int, int>> groups;
        for (int x : nums) {
            // t 是 x 属于哪一组
            int t = (x % K + K) % K;
            // groups[t][x] 表示第 t 组里，x 有几个
            groups[t][x]++;
        }

        const int MOD = 1e9 + 7;
        // P[i]：2 的 i 次方
        long long P[nums.size() + 1];
        P[0] = 1;
        for (int i = 1; i <= nums.size(); i++) P[i] = P[i - 1] * 2 % MOD;
        
        long long ans = 1;
        // 对每个分组计算组内的选法
        for (auto it = groups.begin(); it != groups.end(); it++) {
            // map 是有序的
            map<int, int> &mp = it->second;
            int n = mp.size();
            long long f[n][2];
            memset(f, 0, sizeof(f));
            // 初值
            f[0][0] = 1;
            f[0][1] = (P[mp.begin()->second] - 1 + MOD) % MOD;
            // 套递推方程
            int i = 1;
            for (auto it2 = next(mp.begin()); it2 != mp.end(); it2++, i++) {
                // last：上一个不同的数是几
                // now：当前数是几
                // cnt：当前数有几个
                int last = prev(it2)->first, now = it2->first, cnt = it2->second;
                f[i][0] = (f[i - 1][0] + f[i - 1][1]) % MOD;
                if (now - last == K) f[i][1] = f[i - 1][0] * (P[cnt] - 1 + MOD) % MOD;
                else f[i][1] = (f[i - 1][0] + f[i - 1][1]) * (P[cnt] - 1 + MOD) % MOD;
            }
            // 每一组的答案乘起来，就是最终答案
            ans = ans * (f[n - 1][0] + f[n - 1][1]) % MOD;
        }
        // 题目要求非空子集，答案减 1
        return (ans - 1 + MOD) % MOD;
    }
};

