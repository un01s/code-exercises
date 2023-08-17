/*
 * leetcode
 * 
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Find all primes <= n.
vector<int>Eratosthenes(int n)
{
    vector<int>q(n+1,0);
    vector<int>primes;
    for (int i=2; i<=sqrt(n); i++)
    {
        if (q[i]==1) continue;
        int j=i*2;
        while (j<=n)
        {
            q[j]=1;
            j+=i;
        }
    }        
    for (int i=2; i<=n; i++)
    {
        if (q[i]==0)
            primes.push_back(i);                
    }
    return primes;
}

void printV(vector<int>& v) {
    cout << "V:[ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    int a[] = {3, 4, 9, 7, 29, 17, 11, 33};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));

    // get the max of the array v1
    int m = *max_element(v1.begin(), v1.end());
    cout << "max: " << m << endl;

    // get all the primes less than or equal to n
    vector<int> p = Eratosthenes(m);
    printV(p);

    return 0;
}
