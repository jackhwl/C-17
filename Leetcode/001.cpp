// Leetcode.cpp : Defines the entry point for the console application.
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].


#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//41.65%
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		
		for (int i = 0; i < nums.size() - 1; i++) {
			auto second = find(begin(nums) + i + 1, end(nums), target-nums[i]);
			if (second != end(nums)) {
				auto secondIndex = second - begin(nums);
				result.push_back(i);
				result.push_back(secondIndex);
				break;
			}
		}
		return result;
	};
};

int main()
{
	vector<int> nums{ 1, 7, 11, 15, 21, 73, 2, 25 };
	Solution myso;
	auto result = myso.twoSum(nums, 9);
	
	getchar();
    return 0;
}

