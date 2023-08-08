/*
 * priority queue
 *
 */

#include <concepts>
#include <functional>
#include <iostream>
#include <queue>
#include <string_view>
#include <vector>

using namespace std;
 
int main()
{
    //const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};

    int a[] = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));

    priority_queue<int> q1; // Max priority queue
    for (int i = 0; i < v1.size(); i++) {
        q1.push(v1[i]);
        cout << v1[i] << " ";
    }  
    cout << endl;

    // another way
    priority_queue<int, vector<int>, greater<int> > minq1(v1.begin(), v1.end());
    //priority_queue<int, vector<int>, greater<int> > minq1(data.begin(), data.end());

    for(int i = 0; i < minq1.size(); i++) {
        cout << minq1.top() << " ";
        minq1.pop(); 
    }
    cout << endl;

    return 0;
}
