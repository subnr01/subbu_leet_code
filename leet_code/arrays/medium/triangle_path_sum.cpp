/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) 
    {
        // mini contains the last row of the triangle (4,1,8,3)
        vector<int> mini = triangle[triangle.size()-1];
        for ( int i = triangle.size() - 2; i>= 0 ; --i )
            for ( int j = 0; j < triangle[i].size() ; ++ j )
                mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
        return mini[0];
    }
};

/*
The flow is like this:

First iteration:
4 1 8 3
7 6 10 3
9 10  10 3
2 10 10 3
11 ....

*/