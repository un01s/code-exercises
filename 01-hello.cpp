/*
 * conio.h is a C header file used mostly by MS-DOS compilers to provide console input/output.
 * 
 */
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    // output
    cout << "Hello World!" << endl;

    // input and output
    int age;
    cout << "Enter your age:" << endl;
    cin >> age;

    // if-else
    if (age >= 18) {
        cout << "you can vote\n";
    } else {
        cout << "not eligibel for voting\n";
    }

    int x, y;
    cout << "Enter two numbers:" << endl;
    cin >> x >> y;

    if (x == y) {
        cout << "both nunmbers are equal\n";
    } else if (x > y) {
        cout << "the first is greater than the second\n";
    } else {
        cout << "the first is less than the second\n";
    }

    // loop
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    int i = 0;
    int sum = 0;
    while (i < 5) {
        sum += i;
        i++;
    }
    cout << "sum (from 0 to 4) = " << sum << endl;

    i = 1;
    do {
        cout << i << " ";
        i++;
    } while (i < 6);
    cout << endl;

    return 0;
}
