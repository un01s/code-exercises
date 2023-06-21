/*
 *
 * data structure: array
 * - continuous address in memory
 * - the same data type
 * - the index to access the data, d[index] 
 * - the pointer to get the address (&d[index]))
 * 
 */

#include <iostream>

using namespace std;

// 2-D array, 
// the first index is row, 
// the second index is column.
//
void test_arr() {
    int array[2][3] = {
        {0, 1, 2},
	{3, 4, 5}
    };
    cout << &array[0][0] << " " << &array[0][1] << " " << &array[0][2] << endl;
    cout << &array[1][0] << " " << &array[1][1] << " " << &array[1][2] << endl;
}

int main() {
    test_arr();

    return 0;
}

