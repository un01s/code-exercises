/*
 * priority queue
 * 
 * one of the three container adapters defined in the standard library of C++
 * the other two container adapters are stack and queue.
 *
 * The insertion of elements in the priority queue is similar to the ordinary 
 * queue, but the removal of the elements is done according to the priority. 
 * So, the element having the highest priority pops out first. 
 * In case of multiple elements with the same priority, the element which 
 * occurs first will be served first.
 *
 * for example, todo task with different priorities.
 *
 */

#include <concepts>
#include <functional>
#include <iostream>
#include <queue> // priority queue, deque, queue
#include <string_view>
#include <vector>

using namespace std;

void printQ(priority_queue<int>& q) {
    if (q.empty()) return;

    cout << "priority queue: ";
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    return;
}

int main()
{
    //const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    priority_queue<int> q0;
    q0.push(50);
    q0.push(100);
    q0.push(20);
    q0.push(300);
    q0.push(10);
    printQ(q0);
    // priority queue: 300 100 50 20 10 
    // the biggest integer shows up first

    priority_queue<int> myQ1;
    priority_queue<int> myQ2;
    myQ1.push(2);
    myQ1.push(4);
    myQ1.push(6);
    myQ1.push(8);
    // {8, 6, 4, 2}

    myQ2.push(1);
    myQ2.push(3);
    myQ2.push(5);
    myQ2.push(7);
    // {7, 5, 3, 1}

    myQ1.swap(myQ2);
    printQ(myQ1);
    printQ(myQ2);

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
