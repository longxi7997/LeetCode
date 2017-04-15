// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-04-15

/**********************************************************************************
* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
*
* push(x) -- Push element x onto stack.
* pop() -- Removes the element on top of the stack.
* top() -- Get the top element.
* getMin() -- Retrieve the minimum element in the stack.
*
*
* MinStack minStack = new MinStack();
*minStack.push(-2);
*minStack.push(0);
*minStack.push(-3);
*minStack.getMin();   --> Returns -3.
*minStack.pop();
*minStack.top();      --> Returns 0.
*minStack.getMin();   --> Returns -2.
* 
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


class MinStack
{
public:
	/** initialize your data structure here. */
	struct MyStruct
	{
		int value;
		int m_min;
		MyStruct *next;
		MyStruct *pre;
	};

	MyStruct *m_head;
	MyStruct *m_tail;
	int m_count;


	MinStack() {

		m_head = NULL;
		m_tail = NULL;
		m_count = 0;
	}

	void push(int x) {

		
		MyStruct *m_temp = new MyStruct;
		m_temp->value = x;
		m_temp->next = NULL;


		if ( m_count == 0)
		{

			m_head = new MyStruct;
			m_tail = new MyStruct;

			m_temp->m_min = m_temp->value;
			m_temp->pre = NULL;
			m_head = m_temp;
			m_tail = m_temp;
			m_count++;
		}
		else
		{
			if (  m_tail->m_min <= m_temp->value )
			{
				m_temp->m_min = m_tail->m_min;
			}
			else
			{
				m_temp->m_min = m_temp->value;
			}
			m_temp->pre = m_tail;
			m_tail->next = m_temp;
			m_tail = m_temp;
			m_count++;
		}
			
		
	}

	void pop() {

		if ( m_tail != m_head)
		{
			MyStruct *m_temp = m_tail;

			m_tail = m_tail->pre;
			m_tail->next = NULL;

			delete m_temp;

			m_count--;

			
		}
		else
		{
			m_head = NULL;
			m_tail = NULL;
			m_count--;
		}
	}

	int top() {

		return m_tail->value;
	}

	int getMin() {

		return m_tail->m_min;
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/

int main()
{
	
	MinStack *obj = new MinStack();

	obj->push(2147483646);
	obj->push(2147483647);

	obj->pop();
	obj->pop();

	obj->push(2147483647);

	cout << obj->getMin() << endl ;


	cout << obj->top() << endl ;

	cout << obj->getMin() << endl ;

	system("pause");
	return 0;

}