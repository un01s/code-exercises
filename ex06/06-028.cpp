/*
 * leetcode 973
 * K closest points to origin
 *
 */

class Solution {
class info{
        public:
        int x;
        int y;
        float distance; // int must be avoided as for decimals we will get equall distances for diff points
        info(int a , int b)
        {
            x = a;
            y = b;
        // as always we are finding the distance from the origin so
            distance = sqrt (x*x + y*y);

        }
    };
    
class compare{
   public:
   bool operator()(info* point1 , info* point2)
   {
       if( point1->distance > point2->distance)
       {
           return true;
       }
       else{
           return false;
       }
   }
};

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<info*,vector<info*>,compare> minheap;

        for( int i = 0 ; i < points.size() ; i ++)
        {
            // current point
            int x1 = points[i][0];
            int y1 = points[i][1];
            info* newinfo = new info(x1,y1);
            minheap.push(newinfo);
        }
        vector<vector<int>> ans;
        while(k > 0)
        {
            // make point of the top element and push it into the ans
            info* temp = minheap.top();
            minheap.pop();
            int xval = temp->x;
            int yval = temp->y;
            // now push the point into the ans
            vector<int> temp2 ;
            temp2.push_back(xval);
            temp2.push_back(yval);
            ans.push_back(temp2);
            k--;
        }
        return ans;    
    }
};

