// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-04-24

/**********************************************************************************
*
*
*
*
* Given an integer, convert it to a roman numeral.
*
* Input is guaranteed to be within the range from 1 to 3999.
* 
*
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
	int val[13] = {
		1000, 900, 500, 400,
		100, 90, 50, 40,
		10, 9, 5, 4,
		1
	};
	string syb[13] = {
		"M", "CM", "D", "CD",
		"C", "XC", "L", "XL",
		"X", "IX", "V", "IV",
		"I"
	};

public:
	string intToRoman(int num) {
		string roman;
		int i = 0, k;
		while (num > 0)
		{
			k = num / val[i];
			while (k--)
			{
				roman += syb[i];
				num -= val[i];
			}
			i++;
		}
		return roman;
	}
};

int main()
{
	
	Solution *s = new Solution();

	string a = s->intToRoman(999);
	cout<<a<< endl ;

	system("pause");
	return 0;

}