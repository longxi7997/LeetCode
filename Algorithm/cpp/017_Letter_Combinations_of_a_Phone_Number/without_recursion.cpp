// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-06-21

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

	vector<string> dfs( vector<int> digits ,  vector<string> resl ) {

		while ( digits.size() >0)
		{
			int i= digits.back();
			digits.pop_back();
			

			vector<string> temp;
			for ( int j=0 ; j<resl.size() ; j++ ) 
			{
				/*for each(char chTemp in dic[i])
				{
					temp.push_back(chTemp + resl[j] );
				}*/
				for (int ch = 0 ; ch < dic[i].length() ; ch++)
				{
					temp.push_back( dic[i][ch] + resl[j]);
				}


			}
			
			resl = temp;

		}

		return resl;

	}

public:
	vector<string> letterCombinations(string digits) {
		

		vector<string> resl;

		if (digits.length() == 0)
		{
			return resl;
		}

		resl.push_back("");

		vector<int> intDigits;

		/*for each ( char var in digits)
		{
			intDigits.push_back( var-'0' );
		}*/
		for (int i = 0 ; i < digits.length() ; i++)
		{
			intDigits.push_back(digits[i] - '0');
		}
	


		resl = dfs( intDigits,  resl );

		return resl;

	}
};





int main()
{

	Solution *s = new Solution();
	

	string strTemp = "23";


	vector<string> resl = s->letterCombinations(strTemp);

	for ( int i=0; i <resl.size() ; i++ )
	{
		cout << resl[i] << endl;
	}
		

	system("pause");
	return 0;

}