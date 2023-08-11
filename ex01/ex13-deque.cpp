#include <deque>
#include <iostream>

using namespace std;

int main() {
    int a[] = {1, 2, 3};
    deque<int> d(a, a + sizeof(a)/sizeof(int));

    d.push_front(13);
    d.push_back(21);
    for (int e : d) {
        cout << e << " "; 
    }
    cout << endl;

    return 0;
}
