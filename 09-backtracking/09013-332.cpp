/**
 * Leetcode 332 
 *
 *
 * 2023-07-23
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    unordered_map<string, map<string, int> > targets;
    bool backtracking(int ticketNum, vector<string>& result) {
        if(result.size() == ticketNum + 1) {
            return true;
        }
        for(pair<const string, int>& target : targets[result[result.size()-1]]) {
            if (target.second > 0) {
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }        
    vector<string> findItinerary(vector<vector<string> >& tickets) {
        targets.clear();

        vector<string> result;
        for(const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++;
        }
        result.push_back("JFK");
        backtracking(tickets.size(), result);
        return result;
    }
};

int main() {
    
    return 0;
}

