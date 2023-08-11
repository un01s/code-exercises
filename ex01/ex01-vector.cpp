#include <iostream>
#include <vector>

using namespace std;

// pass by value
int square(int v) {
    cout << "v=" << v << endl;
    return v*v;
}
/*
// pass by reference as a pointer
int double(int *pNum) {
    cout << "pNum = " << pNum << endl;
    return (*pNum)*2;
}
*/

// pass by reference with reference
int cube(int & rNum) {
    cout << "rNum = " << rNum << endl;
    return rNum*rNum*rNum;
}

int main()
{
    // vector initialization
    //vector<int> v1 = {1, 2, 3, 4, 5};
    //vector<int> v2 {1, 2, 3, 4, 5};
    vector<int> v3(5, 0); // size = 5, initial values = 0
    
    // Create a vector containing integers
    int a[] = {7, 5, 17, 8};
    vector<int> v(a, a + sizeof(a)/sizeof(int));
 
    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);
 
    // Print out the vector
    cout << "v = { ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << "}; \n";

    // check some functions
    cout << v.size() << endl;

    vector<vector<int> > vm(3, vector<int>(4, 0));
    cout << vm.size() << endl;

    // references or aliases
    // a reference is declared as an alias of another variable
    // it stores the address of the variable
    // once a reference is established, you cannot change the reference to 
    // reference another variable.
    int num = 88;
    int & refNum = num; // alias, both refNum and num refer to the same value
    cout << "num=" << num << endl;
    cout << "refNum=" << refNum << endl;

    refNum = 12;
    cout << "num=" << num << endl;
    cout << "refNum=" << refNum << endl;
    cout << "&num=" << &num << endl;
    cout << "&refNum=" << &refNum << endl;

    num = 45;
    cout << "num=" << num << endl;
    cout << "refNum=" << refNum << endl;
    
    // pointers
    int num1 = 88, num2 = 99;
    int * pNum1 = &num1;
    cout << "num1 = " << num1 << endl;
    cout << "*pNum1 = " << *pNum1 << endl;
    cout << "&num1 = " << &num1 << endl;
    cout << "pNum1 = " << pNum1 << endl;

    // pass by value, reference (pointer) and reference
    int test = 3;
    cout << "square(test)=" << square(test) << endl;
    //cout << "double(&test)=" << double(&test) << endl;
    cout << "cube(test)=" << cube(test) << endl;

    return 0;
}
