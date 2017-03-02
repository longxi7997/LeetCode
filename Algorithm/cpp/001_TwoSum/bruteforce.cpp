// Source : https://github.com/longxi7997/LeetCode/Algorithm/cpp/1_TwoSum
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-01-15

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
*
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{

public:
	vector<int> twoSum ( vector<int> &numbers , int target ) {
		int array_size_ = numbers.size ( );
		vector<int> result_index_;

		for ( int i = 0; i < array_size_; i++ )
		{
			for ( int j = i+1; j < array_size_; j++ )
			{

				if ( numbers [ i ] + numbers [ j ] == target )
				{
					result_index_.push_back ( i);
					result_index_.push_back ( j);
					return result_index_;
				}
			}
		}
	}
};

int main ( )
{
	vector<int> mresult;

	Solution m_solution;

	int x[ ] = { 3,2,4 };
	vector<int> m_Input( std::begin(x) , std::end(x)  );

	int target = 6;

	mresult = m_solution.twoSum ( m_Input , target );


	cout << mresult [ 0 ] <<endl ;
	cout << mresult [ 1 ] <<endl;
	
	system ( "pause" );
	return 0;
}