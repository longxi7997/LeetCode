// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-03-03

/**********************************************************************************
* Implement atoi to convert a string to an integer.
*
* 
* Hint:
		Carefully consider all possible input cases. 
*		If you want a challenge, please do not see below and ask yourself what are the possible input cases.
* 
* Note:
*		It is intended for this problem to be specified vaguely (ie, no given input specs). 
*		You are responsible to gather all the input requirements up front.
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
	int myAtoi(string str) {

		// 去掉空格
		
		int i = 0;
		int len = str.length();
		int sign = 1; 
		int ret = 0;   // Solution 2:  long long int 
		while ( i<len && str[i]==' ')
		{
			i++;
		}
		if (i == len) return 0;

		if ( str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else if ( str[i]== '+')
		{
			i++;
		}
		
		while ( i<len)
		{
			if ( !isdigit(str[i]) )
			{
				break;
			}

			if ( sign ==1  && (ret >( INT_MAX- (str[i]-'0'))/10 ) )
			{
				return INT_MAX;
			}

			int a = (INT_MIN + (str[i] - '0')) / 10 ;
			if (sign==-1 && ( -ret < ( INT_MIN + (str[i]-'0') )/10 ) )
			{
				return INT_MIN;
			}
			ret = ret * 10 + (str[i] - '0');


			/*if ( sign>0 && ret>INT_MAX)
			{
				return INT_MAX;
			}
			if ( sign<0 && ret*sign < INT_MIN)
			{
				return INT_MIN;
			}*/
			/*if (((sign > 0) ? (ret>INT_MAX) : (ret > (long long)INT_MAX + 1)) )
			{
				return 0;
			}*/
			i++;
		}


		return sign*ret;
		
	}
};


int main()
{
	Solution m_solution;

	string s = "2147483647";
	

	int result = m_solution.myAtoi( s );

	cout << result  << endl ;


	system("pause");
	return 0;

}