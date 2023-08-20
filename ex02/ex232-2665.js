/*
 * leetcode 2665
 *
 * https://github.com/00sahad/Leet-Code-solutions/
 * 
 */

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    val = init;
    return {
        increment: () => val += 1,
        decrement: () => val -= 1,
        reset: () => val = init
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */

