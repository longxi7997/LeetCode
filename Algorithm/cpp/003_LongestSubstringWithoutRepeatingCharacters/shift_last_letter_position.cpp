// Source : https://github.com/longxi7997/LeetCode/Algorithm/cpp/1_TwoSum
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-02-19

/**********************************************************************************
* Given a string, find the length of the longest substring without repeating characters.
* Examples:
*
*	Given "abcabcbb", the answer is "abc", which the length is 3.

*	Given "bbbbb", the answer is "b", with the length of 1.

*	Given "pwwkew", the answer is "wke", with the length of 3.
*	Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*
* Descripton:  shift the last un-repeated letter's position
*
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

const int N = 300; // N : Ïàµ±ÓÚ¶ÔÃ¿ÖÖ×ÖÄ¸½øÐÐhash, ÓÃÒÔ±íÊ¾¸Ã×ÖÄ¸×îºó³öÏÖµÄÎ»ÖÃ

class Solution
{
public:
	int lengthOfLongestSubstring(string s) {

		int maxlen = 0;
		int left = 0;  // left: Ö¸Ïò×î×ó±ßµÄ²»±»ÖØ¸´µÄ×ÖÄ¸

		int prev[N];  // ¼ÇÂ¼Ã¿¸ö×ÖÄ¸×îºó³öÏÖµÄÎ»ÖÃ
		memset(prev, -1, sizeof(prev));

		int str_size = s.length();

		for (int i = 0 ; i < str_size ; i++)
		{
			if (prev[s[i]] >= left)
			{
				left = prev[s[i]] + 1;
			}

			maxlen = max(maxlen, i - left + 1);

			prev[s[i]] = i;

		}
		return maxlen;

	}
};

int main()
{
	Solution m_solution;

	string s = "abcabcaa";


	cout << m_solution.lengthOfLongestSubstring(s) << endl ;

	system("pause");
	return 0;

}