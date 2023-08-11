/*
 * leetcode 204 count primes
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// time limit exceeded
class Solution {
public:
    vector<int> primes;
    void print(vector<int>& v) {
        cout << "[ ";
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "]" << endl;
    }
    int countPrimes(int n) {
        if(n<=2) return 0;
        int ans=1;
        for(int i=3;i<n;i+=2){
            if(isprime(i)){
                ans++;
                primes.push_back(i);
            }
        }
        return ans;
    }
private:
    int isprime(int x){
        for(int i=0;i<primes.size();i++){
            if(primes[i]>sqrt(x)) return true;
            if(x%primes[i]==0) return false;
        }
        return true;
    }
};

bool checkPrime(int x)
    {
        for(int i=2;i<x;i++)
        {
            if(x%i==0) return false;
        }
        return true;
    }

int main() {
    for (int i = 2; i < 100; i++) {
        if (checkPrime(i)) {
            cout << i << ",";
        }
        cout << endl;
    }
    return 0;
}
