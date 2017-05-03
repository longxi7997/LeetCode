// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-05-04

/**********************************************************************************
*
*
*
*
* Write a function to find the longest common prefix string amongst an array of strings.
*
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



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
		string common_prefix = "";

		for (int i = 0; i < strs.size(); i++)
		{
			if (i == 0)
				common_prefix = strs[0];

			else
			{

				string temp = strs[i];
				int j = 0;
				while (j < common_prefix.size() && j < temp.size() && common_prefix[j] == temp[j])
				{
					j++;
				}
				
				common_prefix = common_prefix.substr(0, j);

			}

		}

		return common_prefix;
    }
};



int main()
{
	
	Solution *mSolution = new Solution();


	vector<string> s;
	s.push_back("assdfasdfasdf");
	s.push_back("asszcvz");

	
	cout<< mSolution->longestCommonPrefix( s )  << endl ;

	system("pause");
	return 0;

}