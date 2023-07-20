/*
 * leetcode 735
 *
 * TODO
 * https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/735.%20Asteroid%20Collision.cpp
 *
 */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> r;

        // the key is to find one moving toward another
        // then the collision happens: bigger left, smaller exploded
        // the same size means both explode.
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            if (st.empty() || st.top() < 0) {
                st.push(asteroids[i]);
            } else if (st.top() > 0 && asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                int tmp = asteroids[i];
                int flag = 1;
                while (!st.empty() || st.top() > 0) {
                    if (st.top()+tmp == 0) {
                        // both same size moving toward each other
                        // both will explode
                        cout << st.top() << "-";
                        st.pop();
                        flag = 0;
                        break;
                    } else if (st.top()+tmp < 0) {
                        cout << st.top() << "-";
                        st.pop();
                        continue;
                    } else {
                        flag = 0;
                        break;
                    }
                }
                if (flag) st.push(tmp);
            }
        }
        // pop the stack and reverse the order
        int n = st.size();
        int i = 0;
        if (n > 1) {
            vector<int> res(n, 0);
            cout << "[ ";
            while(!st.empty()) {
                //r.push_back(st.top());
                cout << st.top() << " ";
                res[n-i-1] = st.top();
                //res.push_back(st.top());
                st.pop();
                i++;
            }
            cout << "]" << endl;
        }
        
        return r;
    }
};

