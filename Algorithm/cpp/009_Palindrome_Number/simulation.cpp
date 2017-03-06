// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-03-06

/**********************************************************************************
* Determine whether an integer is a palindrome. Do this without extra space.
*
* 
* Some hints:
*		Could negative integers be palindromes? (ie, -1)
*		If you are thinking of converting the integer to string, note the restriction of using extra space.
* 
*		You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
*		you know that the reversed integer might overflow. How would you handle such case?
*
*		There is a more generic way of solving this problem.
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
	bool isPalindrome(int x) {

		long long int rev = 0;
		long long int x_ = x;

		while ( x_ > 0 )
		{
			rev = rev * 10 + x_ % 10;
			x_ = x_ / 10;
		}
		
		return rev == (long long)x;

	}
};


int main()
{
	Solution m_solution;

	int s = -2147447412;
	

	bool result = m_solution.isPalindrome( s );

	cout << result  << endl ;


	system("pause");
	return 0;

}