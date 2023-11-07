/*
 * 001 two sum
 *
 */

func twoSum(nums []int, target int) []int {
    index := make(map[int] int)
    for i, v := range nums {
        if _, ok := index[target-v]; ok {
            return []int{index[target-v], i}
        }
    }
    return nil
}

