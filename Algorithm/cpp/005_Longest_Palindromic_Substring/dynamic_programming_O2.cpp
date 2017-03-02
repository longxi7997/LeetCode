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
*	DP: 
*		time  : O(n^2)  
*		space : O(n^2)
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
		if (len <= 1) return s;
		vector<vector<int> > dp(len, vector<int>(len));   //dp[i][j]表示s[i..j]是否是回文


		int resLeft = 0, resRight = 0;
		
		for( int k=1 ; k<= len ; k++)
		{
			for ( int i=0 ; i<=len-k ; i++ )
			{
				if ( k>3? (s[i] == s[i + k - 1] && dp[i + 1][i + k - 2]):(s[i] == s[i + k - 1]) )
				{

					dp[i][i + k - 1] = true;
					
					if (resRight - resLeft + 1 < k)
					{
						resLeft = i;
						resRight = i + k - 1;
					}
				}
			}
		}


		return s.substr(resLeft,resRight-resLeft+1);


	}
};

int main()
{
	Solution m_solution;

	//string s = "dqlvtrcystnncxjffjrkiiqgtcunbwntqrpqkjepzbxzodeckrbrwzjjuptloypmjgbwioqtjzjjgqpaemgvxkapjgbfhhwltvtqgkozuzvlwetftjeocjqrdwlhdwtgzdhwvmuhvmdpkxnzrrizjntxbbpzwtjryecgfajolalwdzxqtknvvvaxuhanzowlbwjraigvrflcqoormbeexekmqpmuuobseumctsiwhvdohywjaylixqgqookgneokebtmoyaspnzbwqzffyocvcylcjobnzbmhsdprzrgdlyzuutyuwygzeldfewicjnukguisceeopckkoviayrcqanzsryhwqhxjxcpiejojztrxad";
	string s = "abba";

	string result = m_solution.longestPalindrome(s);

	cout << result  << endl ;


	system("pause");
	return 0;

}