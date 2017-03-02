// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-02-28

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
*	Expand Aroud  Center: 
*		time  : O(n^2)  
*		space : O(1)
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
	string longestPalindrome(string s) {

		const int len = s.length();

		int start = 0 , maxLen = 0;

		for ( int i=0 ; i<len ; i++ )
		{
			// 以 i 为中心 的 偶数长度 回文
			int low = i, high = i + 1;
			while (low >= 0 && high < len && s[low] == s[high])
			{
			
				if (high - low + 1 > maxLen)
				{
					maxLen = high - low + 1;
					start = low;
				}
				low--; 
				high++;
				
			}
			

			// 以 i 为中心 的 奇数长度 回文
			low = i-1, high = i + 1;
			while (low >= 0 && high < len && s[low] == s[high])
			{
				if (high - low + 1 > maxLen)
				{
					maxLen = high - low + 1;
					start = low;
				}
				low--;
				high++;
				
			}

		}

		if (maxLen == 0)
			return s.substr( 0,1);
		else
			return s.substr( start , maxLen );


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