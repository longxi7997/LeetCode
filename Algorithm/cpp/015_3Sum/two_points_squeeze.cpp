// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-06-16

/**********************************************************************************
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
*
* Find all unique triplets in the array which gives the sum of zero.
* 
* Note: The solution set must not contain duplicate triplets.
*
* For example, given array S = [-1, 0, 1, 2, -1, -4],
*
* A solution set is:
* [
*	[-1, 0, 1],
*	[-1, -1, 2]
* ]
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		
		int len = nums.size();


		vector<vector<int>> ret;
		int mTarget = 0;

		if (len < 2)
			return ret;

		sort(nums.begin(), nums.end());
		
		
		for (int i = 0 ; i < len - 2 ; i++)
		{

			int secondIndex = i + 1;
			int thirdIndex = len - 1;

			while ( secondIndex < thirdIndex )
			{
				int mSum = nums[i] + nums[secondIndex] + nums[thirdIndex];
				if ( mSum < mTarget)
				{
					secondIndex++;
				}
				else if ( mSum > mTarget )
				{
					thirdIndex--;
				}
				else
				{
					ret.push_back({ nums[i] , nums[secondIndex] , nums[thirdIndex]  }) ;
					secondIndex++;
					thirdIndex--;

					while ( secondIndex < thirdIndex && nums[thirdIndex]== nums[thirdIndex+1] )
					{
						thirdIndex--;
					}
					while (secondIndex < thirdIndex && nums[secondIndex] == nums[secondIndex - 1])
					{
						secondIndex++;
					}
				}

			}

			while ( i<len-2 && nums[i]==nums[i+1])
			{
				i++;
			}
		}


		return ret;
	}
};


int main()
{

	Solution *s = new Solution();

	//int temp[] = {-1, 0, 1, 2, -1, -4};
	int temp[] = { -2,0,1,1,2 };
	vector<int> ivector( temp , temp+ sizeof(temp)/sizeof(temp[0]));

	
	vector<vector <int>> resl = s->threeSum(ivector);


	for (int i = 0 ; i < resl.size() ; i++)
	{
		for (int j = 0 ; j < resl[i].size() ; j++)
		{
			cout << resl[i][j]<<' ';
		}
		cout << endl;

	}


	system("pause");
	return 0;

}