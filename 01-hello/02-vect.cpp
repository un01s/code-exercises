/*
 * array is a fundamental data structure.
 * vector is used more often for its built-in functions. 
 * array can be allocated on the stack. 
 * when using new, array is allocated dynamically on the heap.
 *
 * the inherent disadvantage of array is that its size cannot be chnaged
 * vector is created to address the dynamic usage.
 * in this sense, vector can be called dynamic array.
 * resizing a vector is possible, 
 * adding an element to a vector is not that difficult.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class MyVector {
private:
    int* nums;
    int numCapacity = 10; // default numCapacity
    int numSize = 0;
    int extendRatio = 2;
public:
    MyVector() {
        nums = new int[numCapacity];
    }
    ~MyVector() {
        delete[] nums;
    }
    int size() {
        return numSize;
    }
    int capacity() {
        return numCapacity;
    }
    int get(int index) {
        if (index < 0 || index >= size()) {
            throw out_of_range("out of range");
        }
        return nums[index];
    }
    void set(int index, int val) {
        if (index < 0 || index >= size()) {
            throw out_of_range("out of range");
        }
        nums[index] = val; 
    }
    void add(int val) {
        if (size() == capacity()) extendCapacity();
        nums[size()] = val;
        numSize++;
    }
    void insert(int index, int val) {
        if (index < 0 || index >= size()) {
            throw out_of_range("out of range");
        }
        if (size() == capacity()) extendCapacity();
        // shift all elements after index
        for(int j = size()-1; j >= index; j--) {
            nums[j+1] = nums[j];
        }
        nums[index] = val;
        numSize++;
    }
    int remove(int index) {
        if (index < 0 || index >= size()) {
            throw out_of_range("out of range");
        }
        int v = nums[index];
        // shift forward
        for (int j = index; j < size()-1; j++) {
            nums[j] = nums[j+1];
        }    
        numSize--;
        return v;
    }
    void extendCapacity() {
        // 
        int newCap = numCapacity * extendRatio;
        int *tmp = nums;
        nums = new int[newCap];
        for (int i = 0; i < size(); i++) {
            nums[i] = tmp[i];
        }
        delete[] tmp;
        numCapacity = newCap;
    }
};

void show(vector<int>& v) {
    cout << "[ ";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

void show2(vector<vector<int> >& v) {
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

void traverse(int* nums, int size) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        count++;
    }
}

int find(int* nums, int size, int val) {
    for(int i = 0; i < size; i++) {
        if (nums[i] == val) {
            return i;
        }
    }
    return -1;
}


int main() {
    // stack allocated
    int arr[5] = {0};
    int nums[5] = {1, 2, 3, 4, 5};
    // heap used
    int* arr2 = new int[5];

    vector<int> list1;
    vector<int> list2(5, 0);
    //vector<int> list3 = {1, 2, 3, 4};
    // mac g++ does not like the above initialization
    list1.push_back(1); // add element to the tail
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    show(list1);
    list1.insert(list1.begin()+3, 99);
    cout << "insert 99 at the index of 3" << endl;
    show(list1);
    list1.erase(list1.begin()+2);
    cout << "erase the element at the index of 2" << endl;
    show(list1);

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

    show2(test);

    return 0;
}
