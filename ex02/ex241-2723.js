/*
 * leetcode 2723
 *
 */

var addTwoPromises = async function(promise1, promise2) {
    return new Promise((resolve, reject) => {
        promise1.then((num1) => {
            promise2.then((num2) => {
                resolve(num1 + num2);
            });
        });
    });
}

