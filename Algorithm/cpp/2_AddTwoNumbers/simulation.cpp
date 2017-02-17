// Source : https://github.com/longxi7997/LeetCode/Algorithm/cpp/1_TwoSum
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-02-17

/**********************************************************************************
*
*  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
*
*  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*
*	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*	Output: 7 -> 0 -> 8
*
*Descripton: 
*
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode *head_ = new ListNode(0);

		ListNode *temp = head_;

		int sum_ = 0;
		while (1)
		{
			if ( l1 != NULL )
			{
				sum_ += l1->val;
				l1 = l1->next;
			}

			if ( l2!=NULL)
			{
				sum_ += l2->val;
				l2 = l2->next;
			}

			temp->val = sum_ % 10;
			sum_ /= 10;

			if ( l1 !=NULL || l2!=NULL || sum_)
			{
				temp->next = new ListNode(0);
				temp = temp->next;
			}
			else
				break;

		}
		return head_;
	}
};

int main ( )
{
	
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(8);

	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(2);

	Solution m_solution;

	ListNode *result = m_solution.addTwoNumbers(l2, l1);

	while ( result !=NULL )
	{
		cout << result->val <<endl;
		result = result->next;

	}

	system ( "pause" );
	return 0;
	
}