// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-03-26

/**********************************************************************************
* Implement regular expression matching with support for '.' and '*'.
*
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* The matching should cover the entire input string (not partial).
*		
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
*
*
* Some examples:
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "a*") → true
* isMatch("aa", ".*") → true
* isMatch("ab", ".*") → true
* isMatch("aab", "c*a*b") → true
* 
bool isMatch(string s, string p) {

int slen = s.length();
int plen = p.length();

char pre_char = ' ';
int m = 0;

for (int j = 0; j < p.length() ; j++)
{
pre_char = p[j];
if (p[j] == '*') continue;
m = j;
for (int i = 0; i < s.length() ; )
{

if (s[i] == p[m] || p[m] == '.')
{
pre_char = s[i];
m++;
i++;
if (i == s.length())
return true;
if (m == p.length())
break;

continue;
}

if ( p[m] == '*' && s[i] == pre_char )
{
i++;
if (i == s.length() )
return true;
continue;
}
else if ( p[m] == '*' )
{
m++;
if (m == p.length())
break;

continue;
}

break;

}


}


return false;

};
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
	bool isMatch(string s, string p) {

		int slen = s.length();
		int plen = p.length();

		if (plen == 1 || p[1] != '*')
			return slen && (p[0] == '.' || s[0] == p[0])
			&& isMatch(s + 1, p + 1);

		while ( s[0] && )
		{

		}

		return false;

	};
};



int main()
{
	Solution m_solution;

	string s1 = "aaa";
	string s2 = "ab*ac*a";
	

	bool result = m_solution.isMatch( s1 , s2 );

	cout << result  << endl ;


	system("pause");
	return 0;

}