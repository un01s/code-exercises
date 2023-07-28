/*
 * leetcode 402
 * Remove K Digits
 *
 * give string num representing a non-negative integer num, and an integer k
 * remove k digits and return the smallest possible integer after removal k 
 * digits from num
 *
 * greedy
 * 
 * remove digits where decreasing occurs
 * 1432219
 * 4->3, remove 4
 * 3->2, remove 3
 * 2->2, remove 2
 *
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// this greedy cannnot pass all the test cases
// num = "10001" k = 4, expect "0"
//  
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";

        string res;
        int n = k; 
        int len = num.size();
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            // use < instead of <=
            while(!res.empty() && n > 0 && num[i] < res.back()) {
                n--;
                res.pop_back();
            }
            res.push_back(num[i]);
        }
        cout << ": res=" << res << endl;

        while(res[cnt] == '0') {
            cnt++;
        }
        cout << ": cnt=" << cnt << endl;
        res = res.substr(cnt, len-k-cnt);
        cout << ": res=" << res << endl;

        return !res.size() ? "0" : res;
    }
};

// this is correct
class Solution2 {
public:
    string removeKdigits(string num, int k) {
        stack<char>Stack;
        int count=0;
            
        for (int i=0; i<num.size(); i++)
        {
            if (Stack.empty()||num[i]>=Stack.top())
            {
                Stack.push(num[i]);
            }
            else if (num[i]<Stack.top())
            {
                while (!Stack.empty() && num[i]<Stack.top() && count<k)
                {
                    Stack.pop();
                    count++;
                }
                Stack.push(num[i]);
            }
        }
        
        for (int i=count+1; i<=k; i++)
            Stack.pop();
        
        string result;
        while (!Stack.empty())
        {
            result+=Stack.top();
            Stack.pop();
        }
        while (result.size()>0 && result.back()=='0')
            result.pop_back();
                
        reverse(result.begin(),result.end());
        if (result=="")
            result="0";
        
        return result;        
    }
};

int main() {
    string s1 = "1432219";
    int k1 = 3;
    string s2 = "10200";
    int k2 = 1;
    string s3 = "10";
    int k3 = 2;
    string s4 = "112";
    int k4 = 1;
    string s5 = "10001";
    int k5 = 4;

    Solution2 ans;
    cout << s1 << endl;
    cout << ans.removeKdigits(s1, k1) << endl;

    cout << s2 << endl;
    cout << ans.removeKdigits(s2, k2) << endl;

    cout << s3 << endl;
    cout << ans.removeKdigits(s3, k3) << endl;

    cout << s4 << endl;
    cout << ans.removeKdigits(s4, k4) << endl;
    // expect 11

    cout << s5 << endl;
    cout << ans.removeKdigits(s5, k5) << endl;
    // expect "0"
    return 0;
}

