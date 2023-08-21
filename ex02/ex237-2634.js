/*
 * leetcode 2634
 * filter elements from array
 *
 */

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const res = []
    arr.forEach((itm,i)=> {
        if(fn.call(this, itm, i)){
            res.push(itm)
        }
    });
    return res;    
};

