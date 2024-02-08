/*
 * leetcode 279
 * perfect squares
 *
 */

class Solution {
public:
    bool is_square(int n){
        double sqrt_n=sqrt(n);
        return sqrt_n==int(sqrt_n);
    }
    int numSquares(int n) {
        while (n%4==0) n/=4;
        if (n%8==7) return 4;

        if (is_square(n)) return 1;
        
        double&& sqrt_n=sqrt(n);
        for(int i=1; i<=sqrt_n; i++)
        {
            int&& y=n-i*i;
            if (is_square(y)) return 2;//2 squares;
        }
       
        return 3;    
    }
};

