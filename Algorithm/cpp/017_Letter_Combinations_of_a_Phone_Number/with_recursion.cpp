// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-06-26

/**********************************************************************************
* Given a digit string, return all possible letter combinations that the number could represent.
*
* A mapping of digit to letters (just like on the telephone buttons) is given below.
*
* 1 2 3 
* 4 5 6
* 7 8 9
* * 0 #
*
* Input:Digit string "23"
*
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*
*
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;




class Solution
{
private:
	const string dic[10] = { " " , "1" , "abc" , "def" , "ghi" , "jkl", "mno","pqrs", "tuv", "wxyz" };

	
	void dfs(vector<string> &res , vector<int> &intDigits, string &dig ,   int cur)
	{
		if (cur == intDigits.size())
		{
			res.push_back(dig);
			return ;
		}

		for (int i = 0 ; i < dic[intDigits[cur]].size() ; i++)
		{
			dig.push_back( dic[intDigits[cur]][i] );
			//dig += dic[intDigits[cur]][i];
			dfs(res, intDigits, dig, cur + 1);

			dig.pop_back();
		}
		
	}

public:
	vector<string> letterCombinations(string digits) {
		
		vector<string> resl;

		if (digits.length() == 0)
		{
			return resl;
		}

		vector<int> intDigits;
		/*for each ( char var in digits)
		{
			intDigits.push_back( var-'0' );
		}*/
		for (int i = 0 ; i < digits.length() ; i++)
		{
			intDigits.push_back(digits[i] - '0');
		}

		string dig="";
		dfs( resl , intDigits, dig ,  0 );

		return resl;

	}
};




int main()
{

	Solution *s = new Solution();
	

	string strTemp = "1";


	vector<string> resl = s->letterCombinations(strTemp);

	for ( int i=0; i <resl.size() ; i++ )
	{
		cout << resl[i] << endl;
	}
		

	system("pause");
	return 0;

}