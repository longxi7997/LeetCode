// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-06-26

/**********************************************************************************
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
* Find all unique quadruplets in the array which gives the sum of target.
*
* Note: The solution set must not contain duplicate quadruplets.
*
* For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
*
* 
* A solution set is:
* [
*   [-1,  0, 0, 1],
*   [-2, -1, 1, 2],
*   [-2,  0, 0, 2]
* ]
*
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
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		int len = nums.size();


		vector<vector<int>> ret;
		int mTarget = target;

		if (len < 3)
			return ret;

		sort(nums.begin(), nums.end());


		for (int i = 0 ; i < len - 3 ; i++)
		{
			
			for (int secondIndex = i + 1 ; secondIndex < len - 2 ; secondIndex++)
			{
				int thirdIndex = secondIndex + 1;
				int fourthIndex = len - 1 ;

				while (thirdIndex < fourthIndex)
				{
					int mSum = nums[i] + nums[secondIndex] + nums[thirdIndex] + nums[fourthIndex];
					if (mSum < mTarget)
					{
						thirdIndex++;
					}
					else if (mSum > mTarget)
					{
						fourthIndex--;
					}
					else
					{
						ret.push_back({ nums[i] , nums[secondIndex] ,  nums[thirdIndex] , nums[fourthIndex] , }) ;
						thirdIndex++;
						fourthIndex--;

						while (thirdIndex < fourthIndex && nums[fourthIndex] == nums[fourthIndex + 1])
						{
							thirdIndex--;
						}
						while (thirdIndex < fourthIndex && nums[thirdIndex] == nums[thirdIndex - 1])
						{
							thirdIndex++;
						}
					}

				}

				while ( secondIndex<len - 3 && nums[secondIndex] == nums[secondIndex + 1])
				{
					secondIndex++;
				}
			}

			while (i < len - 2 && nums[i] == nums[i + 1])
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
	
	int temp[] = { 1, 0, -1, 0, -2, 2 };
	vector<int> ivector(temp, temp + sizeof(temp) / sizeof(temp[0]));

	int target = 0;

	vector<vector <int>> resl = s->fourSum(ivector, target);

	
	for (int i = 0 ; i < resl.size() ; i++)
	{
		for (int j = 0 ; j < resl[i].size() ; j++)
		{
			cout << resl[i][j] << ' ';
		}
		cout << endl;

	}


	system("pause");
	return 0;

}