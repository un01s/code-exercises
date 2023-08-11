#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
 
int main()
{
    unordered_map<int, string> dict;
    dict[1] = "one";
    dict[6] = "six";
    dict[3] = "three";
    dict[4] = "four";
    dict[5] = "five";
    dict[2] = "two";
    dict[5] = "five";

    cout << "dict: { ";
    for (int i = 0; i < dict.size(); i++)
    {
        cout << i+1 << ":" << dict[i+1] << ",";
    }
    cout << "}\n\n";
 
    for (int i = 1; i != 8; i++)
    {
        cout << "dict.count(" << i << ") = " << dict.count(i) << '\n';
    }

    return 0;
}
