/*
 *  
 *
 */

#include <iostream>
#include <vector>

using namespace std;

void show(vector<vector<int> >& v) {
    cout << "[ ";
    for(int i = 0; i < v.size(); i++) {
        cout << "[ ";
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]" << endl;
}

int main() {
    vector<int> v(10, 5);
    int sum = 0;
    for (int i = 0; i < v.size(); i++){
        sum += v[i]*2;
    }
    cout << "sum is " << sum << endl;
    
    vector<vector<int> > test;
    vector<int> a(1,1);
    vector<int> b(2,2);
    vector<int> c(3,3);
    
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);

    show(test);

    return 0;
}
