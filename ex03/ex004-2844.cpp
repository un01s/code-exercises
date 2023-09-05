
class Solution {
public:
    int find_zero(string &s) {
        for(auto c : s) {
            if(c == '0') return 1;
        }
        return 0;
    }
    
    int get_op(string s, string ref) {
        int at = s.size() - 1;
        while(at >= 0 and s[at] != ref.back()) at -= 1;
        if(at == -1) return s.size() - find_zero(s);
        int at2 = at - 1;
        while(at2 >= 0 and s[at2] != ref[0]) at2 -= 1;
        if(at2 == -1) return s.size() - find_zero(s);
        return s.size() - at2 - 2;
    }
    
    int minimumOperations(string num) {
        return min(min(get_op(num, "00"), get_op(num, "25")), min(get_op(num, "50"), get_op(num, "75")));    
    }
};

