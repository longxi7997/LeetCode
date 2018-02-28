import javax.print.attribute.standard.PrinterLocation;

import java.lang.System.*;
import java.lang.reflect.Array;
import java.util.Arrays;

// Source : https://github.com/longxi7997/LeetCode/Algorithm/cpp/1_TwoSum
// Author : Xi Long
// Email  : longxi7997@gmail.com
// Date   : 2018-02-28

/**********************************************************************************
*
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
* You may assume that each input would have exactly one solution.
*
* Example:
*
*	Given nums = [2, 7, 11, 15], target = 9,
*
*	Because nums[0] + nums[1] = 2 + 7 = 9,
*
*	return [0, 1].
* 
* 暴力解法   时间复杂度O(n^2)
*
**********************************************************************************/

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
//		System.out.println( "asdf ");
		
		Solution solution = new Solution();
		
		int[] a = {2,7,11,15};
		int target = 9;
		
		
		System.out.println( Arrays.toString(  solution.twoSum(a, target) ) ) ;
		
		
	}

}



class Solution {
    public int[] twoSum(int[] nums, int target) {
        
    	
    	for( int i=0 ; i<nums.length-1 ; i++)
    	{
    		for( int j=i+1 ; j<nums.length ; j++)
    		{
    			if (nums[i] + nums[j] == target) {
					
    				System.out.println( i );

    				
    				return new int[] {i,j};
    				
				}
    		}
    	}
    	

    	throw new IllegalArgumentException( "no result " );
    }
}