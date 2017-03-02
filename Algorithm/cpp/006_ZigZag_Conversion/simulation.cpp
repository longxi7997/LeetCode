// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-03-02

/**********************************************************************************
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
* (you may want to display this pattern in a fixed font for better legibility)
*
* P   A   H   N
* A P L S I I G
* Y   I   R
* 
*
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
* Example 1:
*
*	Input: "PAYPALISHIRING , 3"
*
*	Output: "PAHNAPLSIIGYIR"
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
	string convert(string s, int numRows) {

		if (numRows == 1) return s ;

		int len = s.length();
		int step = numRows * 2 - 2;

		string ret = "";
		for (int i = 0; i < len ; i+= step )
		{
			ret += s[i];
		}
		
		for (int i = 1; i < numRows - 1; i++)
		{
			for (int j = i; j < len; j += step)
			{
				ret += s[j];
				if (j + (step - i * 2) < len)
					ret += s[j + (step - i * 2)];
			}
		}

		for (int i = numRows - 1; i < len; i += step)
			ret += s[i];
		
		return ret;

	}
};

int main()
{
	Solution m_solution;

	string s = "PAYPALISHIRING";
	
	string result = m_solution.convert(s , 3 );

	cout << result  << endl ;


	system("pause");
	return 0;

}