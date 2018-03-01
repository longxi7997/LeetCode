import javax.print.attribute.standard.PrinterLocation;

import java.lang.System.*;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashMap;

// Source : https://github.com/longxi7997/LeetCode/Algorithm/java
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
* 
* Description:
* 	
* 	HashMap
* 	time : O(n)
* 	space£» O(n)
*
**********************************************************************************/

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
//		System.out.println( "asdf ");
		
		Solution solution = new Solution();
		
//		int[] a = {2,7,11,15};
		int[] a = {3,3};
		int target = 6;
		
		System.out.println( Arrays.toString(  solution.twoSum(a, target) ) ) ;
		
	}

}



class Solution {
    public int[] twoSum(int[] nums, int target) {
        
    	
    	HashMap<Integer, Integer> numsMap = new HashMap<>();
    	for( int i=0 ; i<nums.length ; i++)
    	{
    		if( numsMap.get(nums[i])!=null && (2*nums[i]==target) )
    			return new int[] { numsMap.get(nums[i]) , i};
    		else
    			numsMap.put( nums[i], i);
    	}
    	
    	for ( int i=0 ; i< nums.length-1 ; i++) 
    	{
    		
    		if( numsMap.get( target-nums[i] ) != null && (2*nums[i]!=target) ) 
    		{
    			return new int[] {i , numsMap.get( target-nums[i] ) };
     		}
    		
		}
    	

    	throw new IllegalArgumentException( "no result " );
    }
}












