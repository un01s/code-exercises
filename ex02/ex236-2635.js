/*
 * leetcode 2635
 * apply transform over each element in array
 *
 */

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    arr.forEach((itm, idx) => {
        arr[idx] = fn(itm, idx);
    })
    return arr;    
};

function plusone(n) { return n+1; }

