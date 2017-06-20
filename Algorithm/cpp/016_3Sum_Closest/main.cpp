// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-06-20

/**********************************************************************************
* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
*
* Return the sum of the three integers. You may assume that each input would have exactly one solution.
*
* For example, given array S = {-1 2 1 -4}, and target = 1.
* 
* The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target) {

		int len = nums.size();
		
		int minDistance = INT_MAX;

		if (len < 3)
			return minDistance;

		sort(nums.begin(), nums.end());

		for (int i = 0 ; i < len - 2 ; i++)
		{
			
			int secondIndex = i + 1;
			int thirdIndex = len - 1;

			while (secondIndex < thirdIndex)
			{
				int mSum = nums[i] + nums[secondIndex] + nums[thirdIndex] - target;

 				if (abs(mSum) <= abs(minDistance) )
				{
					minDistance = mSum;

					if (minDistance == 0)
						return minDistance+target;
				}
				
				if (mSum < 0)
				{
					secondIndex++;
					while (secondIndex < thirdIndex && nums[secondIndex] == nums[secondIndex - 1])
					{
						secondIndex++;
					}
				}
				else if (mSum > 0)
				{
					thirdIndex--;
					while (secondIndex < thirdIndex && nums[thirdIndex] == nums[thirdIndex + 1])
					{
						thirdIndex--;
					}
				}
			}
			while (i<len - 2 && nums[i] == nums[i + 1])
			{
				i++;
			}

		}

		return minDistance + target;

	}
};



int main()
{

	Solution *s = new Solution();
	//[4, 0, 5, -5, 3, 3, 0, -4, -5]  -2
	//[1, 2, 4, 8, 16, 32, 64, 128] 82
	//[56, 57, -47, -14, 23, 31, 20, 39, -51, 7, -4, 43, -53, 32, 24, 56, -28, 90, -75, -6, 21, -100, 41, -84, 95, 95, 44, 84, 70, -22, -86, -6, 90, -87, 65, -28, -29, -94, 98, -28, -100, 23, -25, 6, -56, -54, -5, 53, -88, -25, -31, -71, -13, -62, 73, -35, -78, 16, 99, 97, 84, -27, -43, -50, 18, -16, -61, 7, -17, 16, -92, 28, 43, -38, -33, -27, 84, -72, -100, -91, -97, -99, 59, -63, 73, 99, 98, -100, -37, -80, 3, 18, 93, -81, 12, -75, -43, 99, 10, 10, -6, 13, 0, 76, -82, -5, 27, -38, -81, 77, -55, -100, 90, -32, -25, -15, -16, 68, -6, 87, 65, -38, 82, 78, -61, 87, -72, 46, 50, -60, 86, 39, 69, 85, -49, 28]
	//int temp[] = { 56, 57, -47, -14, 23, 31, 20, 39, -51, 7, -4, 43, -53, 32, 24, 56, -28, 90, -75, -6, 21, -100, 41, -84, 95, 95, 44, 84, 70, -22, -86, -6, 90, -87, 65, -28, -29, -94, 98, -28, -100, 23, -25, 6, -56, -54, -5, 53, -88, -25, -31, -71, -13, -62, 73, -35, -78, 16, 99, 97, 84, -27, -43, -50, 18, -16, -61, 7, -17, 16, -92, 28, 43, -38, -33, -27, 84, -72, -100, -91, -97, -99, 59, -63, 73, 99, 98, -100, -37, -80, 3, 18, 93, -81, 12, -75, -43, 99, 10, 10, -6, 13, 0, 76, -82, -5, 27, -38, -81, 77, -55, -100, 90, -32, -25, -15, -16, 68, -6, 87, 65, -38, 82, 78, -61, 87, -72, 46, 50, -60, 86, 39, 69, 85, -49, 28 };
	int temp[] = { -100,-100,-100,-100,-100,-99,-97,-94,-92,-91,-88,-87, };
	vector<int> ivector( temp , temp+ sizeof(temp)/sizeof(temp[0]));

	int target = -289;
	
	int resl = s->threeSumClosest(ivector,target);

	cout << resl <<endl;
		


	system("pause");
	return 0;

}