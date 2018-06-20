/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

// 38.36%
var twoSum = function (nums, target) {
    for (var i = 0; i < nums.length; i++) {
        var n2 = nums.lastIndexOf(target - nums[i]);
        if (n2 > 0 && n2 != i) {
            return [i, n2];
        }
    }
};

//  12.6%
var twoSum = function (nums, target) {
    for (var i = 0; i < nums.length; i++) {
        var nums2 = nums.slice(i + 1);
        var n2 = nums2.indexOf(target - nums[i]);
        if (n2 >= 0) {
            return [i, n2 + i + 1];
        }
    }
};

//  68.21%
var twoSum = function (nums, target) {
    var nums2 = [];
    for (var i = 0; i < nums.length; i++) {
        var n2 = nums2.indexOf(target - nums[i]);
        if (n2 >= 0) {
            return [n2, i];
        }
        nums2.push(nums[i]);
    }
};

// 99.96%
var twoSum = function (nums, target) {
    let hash = {};
    for (let i = 0; i < nums.length; i++) {
        let n = nums[i];
        let m = target - n;
        let mindex = hash[m];
        if (mindex !== undefined) {
            return [mindex, i];
        }
        hash[n] = i;
    }
};