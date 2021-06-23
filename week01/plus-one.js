// https://leetcode-cn.com/problems/plus-one

// 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

// 你可以假设除了整数 0 之外，这个整数不会以零开头。

/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let overflow = false;
    for (let i = digits.length - 1; i >= 0; i--) {
        let digit = digits[i];
        let sum = digit + 1;
        digits[i] = sum % 10;
        if (digits[i] == sum) {
            overflow = false;
            break;
        }
        overflow = true;
    }

    if (overflow) {
        digits.unshift(1);
    }
    return digits;
};