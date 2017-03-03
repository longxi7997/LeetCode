// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-03-03

/**********************************************************************************
* Reverse digits of an integer.
*
* Example1: x = 123, return 321
* 
* Example2: x = -123, return -321
* 
* Note:
* The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*
* Description:
*	simulation:
*		time  :   
*		space : 
*
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	int reverse(int x) {

		long long int ret = 0;
		long long int tmp = abs((long long)x);
		while (tmp !=0 )
		{
			int remainder = (long)tmp % 10;
			
			ret = ret * 10 + remainder;

			if (ret > INT_MAX || ret < INT_MIN)
				return 0;

			tmp = tmp / 10;
		}

		return x>0?ret:-ret;


	}
};

int main()
{
	Solution m_solution;

	int s = 0;
	
	//int s = -2;

	int result = m_solution.reverse(s );

	cout << result  << endl ;


	system("pause");
	return 0;

}