/*
 * list
 *
 */

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void printL(list<int>& l) {
    cout << "List: { ";
    for (int n : l) {
        cout << n << " ";
    }
    cout << " }" << endl;
}

int main() {
    list<int> l;

    l.push_back(7);
    l.push_back(5);
    l.push_back(16);
    l.push_back(9);

    l.push_front(25);
    l.push_back(2);

    //l.insert(l.begin()+3, 33);
    //l.erase(l.begin()+5);

    printL(l);

    return 0;
}
