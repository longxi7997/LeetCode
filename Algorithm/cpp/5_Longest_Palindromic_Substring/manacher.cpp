// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-03-02

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
*	Manacher算法:
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

private:
	// 预处理字符串，abc预处理后变成$#a#b#c#^
	string preProcess(string s) 
	{
		string res;
		res.push_back('$');
		res.push_back('#');
		for ( int i=0 ; i<s.length() ; i++ )
		{
			res.push_back(s[i]);
			res.push_back('#');
		}
		res.push_back('^');
		return res;
	}

public:
	string longestPalindrome(string s) {

		int len = s.length();
		if(len <= 1) return s;

		// manacher算法
		string str = preProcess(s);
		len = str.length();

		int id = 0, mx = 0;
		vector<int> p(len, 0);

		for ( int i=1 ; i<len-1 ; i++ )
		{
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;

			while (str[i + p[i]] == str[i - p[i]]) p[i]++;

			if (i + p[i] > mx)
			{
				mx = i + p[i];
				id = i;
			}
			

		}

		//遍历p，寻找最大回文长度
		int maxLen = 0, index = 0;
		for (int i = 0; i < len ; i++)
		{
			if (p[i] > maxLen)
			{
				maxLen = p[i];
				index = i;
			}
		}
		
		return s.substr((index - maxLen) / 2, maxLen - 1);
			

	}
};

int main()
{
	Solution m_solution;

	string s = "dqlvtrcystnncxjffjrkiiqgtcunbwntqrpqkjepzbxzodeckrbrwzjjuptloypmjgbwioqtjzjjgqpaemgvxkapjgbfhhwltvtqgkozuzvlwetftjeocjqrdwlhdwtgzdhwvmuhvmdpkxnzrrizjntxbbpzwtjryecgfajolalwdzxqtknvvvaxuhanzowlbwjraigvrflcqoormbeexekmqpmuuobseumctsiwhvdohywjaylixqgqookgneokebtmoyaspnzbwqzffyocvcylcjobnzbmhsdprzrgdlyzuutyuwygzeldfewicjnukguisceeopckkoviayrcqanzsryhwqhxjxcpiejojztrxad";
	//string s = "abba";
	string result = m_solution.longestPalindrome(s);

	cout << result  << endl ;


	system("pause");
	return 0;

}