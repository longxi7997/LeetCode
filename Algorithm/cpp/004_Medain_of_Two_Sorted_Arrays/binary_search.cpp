// Source : https://github.com/longxi7997/LeetCode
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2017-02-19

/**********************************************************************************
* There are two sorted arrays nums1 and nums2 of size m and n respectively.
*
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
* 
* Example 1:
*
*	nums1 = [1, 3]
*	nums2 = [2]
*	The median is 2.0

* Example 2:
*	nums1 = [1, 2]
*	nums2 = [3, 4]
*	The median is (2 + 3)/2 = 2.5
*
* Description:
*	binary serch, O(log(n+m))
*
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{

private:
	double findKth(vector<int>& nums1, vector<int>& nums2 , int Kth ) {

		if (nums1.size() > nums2.size())
			return findKth( nums2 , nums1, Kth );

		if (nums1.size() == 0)
			return nums2[Kth-1];

		if (Kth == 1)
			return min(nums1[0], nums2[0]);
		

		int pa = min(Kth / 2, (int)nums1.size() ) , pb = Kth - pa;

		if (nums1[pa - 1] < nums2[pb - 1])
		{
			vector<int> temp( nums1.begin() + pa , nums1.end() ) ;
			return findKth(temp, nums2, Kth - pa);
		}
			
		else if (nums1[pa - 1] > nums2[pb - 1])
		{
			vector<int> temp(nums2.begin() + pb, nums2.end()) ;
			return findKth(nums1,temp , Kth - pb);
		}
		else
			return nums1[pa - 1];
		

	};

public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		if ((nums1.size() + nums2.size()) & 0x1) // 若为奇数
			return findKth(nums1, nums2 , (nums1.size() + nums2.size())/2+1 );
		else
			return ( findKth(nums1, nums2, (nums1.size() + nums2.size()) / 2) 
				+ findKth(nums1, nums2, (nums1.size() + nums2.size()) / 2 +1 ) ) / 2;
	}
};

int main()
{
	Solution m_solution;

	vector<int> nums1; nums1.push_back(3);
	vector<int> nums2; nums2.push_back(1) ; nums2.push_back(2) ; nums2.push_back(4) ;
	nums2.push_back(5) ; nums2.push_back(6) ;

	cout << m_solution.findMedianSortedArrays( nums1 , nums2 ) << endl ;


	system("pause");
	return 0;

}