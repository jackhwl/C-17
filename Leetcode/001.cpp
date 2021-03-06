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
#include <unordered_map>


using namespace std;

//
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		vector<int> result;
//		//41.65%
//		//for (int i = 0; i < nums.size() - 1; i++) {
//		//	
//		//	auto second = find(begin(nums) + i + 1, end(nums), target-nums[i]);
//		//	if (second != end(nums)) {
//		//		auto secondIndex = second - begin(nums);
//		//		result.push_back(i);
//		//		result.push_back(secondIndex);
//		//		break;
//		//	}
//		//}
//
//		//70.97
//		unordered_map<int, vector<int>> myNums;
//		//for (int i = 0; i < nums.size(); i++) {
//		//	myNums[nums[i]].push_back(i);
//		//}
//		//for (int i = 0; i < nums.size(); i++) {
//		//	auto next = myNums.find(target-nums[i]);
//		//	if (next != myNums.end()) {
//		//		auto nextnum = next->second;
//		//		if (nextnum.size() == 1) {
//		//			if (nextnum[0] != i) {
//		//				result.push_back(i);
//		//				result.push_back(nextnum[0]);
//		//				break;
//		//			}
//		//		} else {
//		//			result.push_back(i);
//		//			result.push_back(nextnum[1]);
//		//			break;
//		//		}
//		//	}
//		//}
//
//		//92.29%
//		//for (int i = 0; i < nums.size(); i++) {
//		//	auto next = myNums.find(target - nums[i]);
//		//	if (next != myNums.end()) {
//		//		auto nextnum = next->second;
//		//		if (nextnum.size() == 1) {
//		//			if (nextnum[0] != i) {
//		//				result.push_back(i);
//		//				result.push_back(nextnum[0]);
//		//				break;
//		//			}
//		//		}
//		//		else {
//		//			result.push_back(i);
//		//			result.push_back(nextnum[1]);
//		//			break;
//		//		}
//		//	}
//		//	else {
//		//		myNums[nums[i]].push_back(i);
//		//	}
//		//}
//		return result;
//
//	};
//};


//99.71%
static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); ++i) {
			auto next = myNums.find(target - nums[i]);
			if (next != myNums.end()) {
				return { next->second, i };
			}
			myNums[nums[i]] = i;
		}
	}
private:
	unordered_map<int, int> myNums;
};

int main1()
{
	//map<int, int> aa;
	vector<int> nums{ 2,5,5,11 };
	Solution myso;
	auto result = myso.twoSum(nums, 10);
	
	getchar();
    return 0;
}

