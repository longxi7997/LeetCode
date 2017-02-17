// Source : https://github.com/longxi7997/LeetCode/Algorithm/cpp/1_TwoSum
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-02-17

/**********************************************************************************
*
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
* You may assume that each input would have exactly one solution.
*
* Example:
*
*	Given nums = [2, 7, 11, 15], target = 9,
*
*	Because nums[0] + nums[1] = 2 + 7 = 9,
*
*	return [0, 1].
*
*Descripton:  sort and find the answer with two points
*
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


const int N = 0;

class Solution
{

public:
	vector<int> twoSum ( vector<int> &numbers , int target ) {

		int array_size_ = numbers.size ( );
		int left_ = 0, right_ = array_size_ - 1, sum_ = 0;


		vector<int> result_index_;

		vector<int> sorted_(numbers);
		std::sort(sorted_.begin(), sorted_.end());

		while ( left_ < right_ )
		{
			sum_ = sorted_[left_] + sorted_[right_];
			
			if (sum_ == target)
			{
				for (int i = 0 ; i < array_size_ ; i++)
				{
					if (numbers[i] == sorted_[left_])
						result_index_.push_back(i);
					else if (numbers[i] == sorted_[right_])
						result_index_.push_back(i);

					if (result_index_.size() == 2)
						return result_index_;
				}

			}
			else if (sum_ > target)
			{
				right_--;
			}
			else
			{
				left_++;
			}
		}
	}

};

int main ( )
{
	vector<int> mresult;

	Solution m_solution;

	int x[ ] = { 2,5,5,11 };
	vector<int> m_Input( std::begin(x) , std::end(x)  );

	int target = 10;

	mresult = m_solution.twoSum ( m_Input , target );


	cout << mresult [ 0 ] <<endl ;
	cout << mresult [ 1 ] <<endl;
	
	system ( "pause" );
	return 0;
	
}