class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++) {
            string s = to_string(i);
            if(s.size() & 1) continue;
            int sum = 0;
            for(int j = 0; j < s.size(); j++) {
                if(2 * j < s.size()) sum += s[j] - '0';
                else sum -= s[j] - '0';
            }
            if(sum == 0) cnt += 1;
        }
        return cnt;    
    }
};

