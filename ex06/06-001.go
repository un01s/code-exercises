/*
 * leetcode 001 two sum
 */

func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
    for i, v := range nums {
        if index, ok := m[target-v]; ok {
            return []int{i, index}
        }
        m[v] = i
    }
    panic("this test case has no solution")
}

