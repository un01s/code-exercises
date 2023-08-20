/*
 * leetcode 2620
 * counter
 *
 */

/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    curr = n;
    return function() {
        curr++;
        return curr-1;    
    };
};

