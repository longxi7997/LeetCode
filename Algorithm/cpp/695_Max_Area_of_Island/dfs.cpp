// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-06-26

/**********************************************************************************
* Given a non-empty 2D array grid of 0's and 1's, 
* an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
*
* You may assume all four edges of the grid are surrounded by water.
*
* Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
*
* 
* Example 1:
	[[0,0,1,0,0,0,0,1,0,0,0,0,0],
	[0,0,0,0,0,0,0,1,1,1,0,0,0],
	[0,1,1,0,1,0,0,0,0,0,0,0,0],
	[0,1,0,0,1,1,0,0,1,0,1,0,0],
	[0,1,0,0,1,1,0,0,1,1,1,0,0],
	[0,0,0,0,0,0,0,0,0,0,1,0,0],
	[0,0,0,0,0,0,0,1,1,1,0,0,0],
	[0,0,0,0,0,0,0,1,1,0,0,0,0]]
* Given the above grid, return 6. Note the answer is not 11, 
* because the island must be connected 4-directionally.
*
*
* Example 2:
	[[0,0,0,0,0,0,0,0]]

* Given the above grid, return 0.
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;




class Solution
{
public:

	int dfs( vector<vector<int>>& grid ,int  i,int j ) {

		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 0;

		if ( grid[i][j] >0 )
		{
			grid[i][j] = 0;
			return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
		}
		
		return 0;
	}

	
	int maxAreaOfIsland(vector<vector<int>>& grid) {


		/*for (int i = 0 ; i < grid.size() ; i++)
		{
			for (int j = 0 ; j < grid[0].size() ; j++)
			{
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}*/


		int maxArea = 0;
		for (int i=0 ; i<grid.size() ; i++)
		{
			for (int j=0 ; j<grid[0].size() ; j++)
			{
				if ( grid[i][j]>0)
				{
					maxArea = max(maxArea, dfs(grid, i, j));
				}
				
			}
		}
		return maxArea;
	}
};


int main()
{

	Solution *s = new Solution();

	vector<vector<int>> temp = {{1, 1, 0, 1, 0, 0, 1, 1}, { 0, 1, 0, 1, 1, 1, 1, 0 }, { 1, 1, 1, 1, 0, 0, 0, 1 }};
	

	
	 cout<< s->maxAreaOfIsland(temp);
	

	system("pause");
	return 0;

}