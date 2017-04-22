// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-04-22

/**********************************************************************************
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*
* 
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
	int maxArea(vector<int>& height) {

		int m_MaxArea = 0;
		

		int left = 0;
		int right = height.size()-1;

		while ( right > left )
		{
			m_MaxArea = max( min(height[left],height[right])*(right-left) , m_MaxArea );

			height[left] <= height[right] ? left++ : right--;
		}

		return m_MaxArea;

	}
};

int main()
{
	
	Solution *s = new Solution();
		
	vector<int> a;
	a.push_back(3);
	a.push_back(5);

	int mMax = s->maxArea( a );


	cout << a.size() << endl ;

	system("pause");
	return 0;

}