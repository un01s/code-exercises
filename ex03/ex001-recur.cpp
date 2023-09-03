#include <iostream> 

using namespace std;

void countDown(int n) {
    if (n == 0) {
        cout << "Done!" << endl;
        return;
    } else {
        cout << n << endl;
        countDown(n-1); // recursion
    }
}

int main() {
    countDown(10);
    return 0;
}
