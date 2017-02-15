// Source : https://github.com/longxi7997/LeetCode/Algorithm/cpp/1_TwoSum
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-02-15

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
*Descripton:  use array to save the status,
*             but if the MAXN is too large, it will Exeed Memory Limit
*             time:n, memory: MAXN
*
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

const int N = 200002;
const int OFFSET = 100000;

class Solution
{

private:

	int idOfNum[N];

public:
	vector<int> twoSum ( vector<int> &numbers , int target ) {
		
		int array_size_ = numbers.size ( );
		
		vector<int> result_index_;

		memset(idOfNum, 0, sizeof(idOfNum));

		for ( int i = 0; i < array_size_; i++ )
		{
			int rest_ = target - numbers[i];

			if ( idOfNum[ rest_ + OFFSET ] )
			{
				result_index_.push_back(idOfNum[rest_ + OFFSET] -1 );
				result_index_.push_back( i );
				return result_index_;
			}

			idOfNum[numbers[i] + OFFSET] = i + 1 ;
		}
	}
};

int main ( )
{
	vector<int> mresult;

	Solution m_solution;

	int x[ ] = { 3,3 };
	vector<int> m_Input( std::begin(x) , std::end(x)  );

	int target = 6;

	mresult = m_solution.twoSum ( m_Input , target );


	cout << mresult [ 0 ] <<endl ;
	cout << mresult [ 1 ] <<endl;
	
	system ( "pause" );
	return 0;
	
}