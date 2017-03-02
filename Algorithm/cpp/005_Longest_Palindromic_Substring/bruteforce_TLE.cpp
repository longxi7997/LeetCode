// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-02-24

/**********************************************************************************
* TGiven a string s, find the longest palindromic substring in s. 
* You may assume that the maximum length of s is 1000.
*
* 
* Example 1:
*
*	Input: "babad"
*
*	Output: "bab"
*
*	Note: "aba" is also a valid answer.
*
* Example 1:
*
*	Input: "cbbd"
*
*	Output: "bb"
*
* Description:
*	brute force: O(n^3) : Time Limit Exceeded
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

private: 
	bool isPalindrome( string s) {
		
		for (int i = 0 ; i < s.length() /2 ; i++)
		{
			if ( s[i] != s[s.length() - 1 - i])
				return false;
		}

		return true;
	}

public:
	string longestPalindrome(string s) {

		int len_palindrame;

		for ( len_palindrame=s.length() ; len_palindrame>1 ;len_palindrame--  )
		{
			
			for (int s_position = 0; s_position < s.length() - len_palindrame+1 ; s_position++)
			{
				string palindrome(s.begin() + s_position  ,s.begin() + s_position+len_palindrame);

				if (isPalindrome(palindrome))
					return palindrome;
			}

		}

		string palindrome(s.begin() , s.begin() + len_palindrame);
		return palindrome;


	}
};

int main()
{
	Solution m_solution;

	string s = "dqlvtrcystnncxjffjrkiiqgtcunbwntqrpqkjepzbxzodeckrbrwzjjuptloypmjgbwioqtjzjjgqpaemgvxkapjgbfhhwltvtqgkozuzvlwetftjeocjqrdwlhdwtgzdhwvmuhvmdpkxnzrrizjntxbbpzwtjryecgfajolalwdzxqtknvvvaxuhanzowlbwjraigvrflcqoormbeexekmqpmuuobseumctsiwhvdohywjaylixqgqookgneokebtmoyaspnzbwqzffyocvcylcjobnzbmhsdprzrgdlyzuutyuwygzeldfewicjnukguisceeopckkoviayrcqanzsryhwqhxjxcpiejojztrxad";

	string result = m_solution.longestPalindrome(s);

	cout << result  << endl ;


	system("pause");
	return 0;

}