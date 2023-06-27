#include <iostream>
#include <unordered_set>

using namespace std;

void show(unordered_set<int>& set) {
    for (int e : set)
        cout << e << " ";
    cout << endl;
}

int main() {
    //unordered_set<int> nums{2, 3, 4, 7, 1, 9};
    int a[] = {2, 3, 4, 7, 1, 9};
    unordered_set<int> nums(a, a + sizeof(a)/sizeof(int));
    show(nums);

    return 0;
}
