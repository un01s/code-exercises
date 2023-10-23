"""
leetcode 2908
"""

INF = 10 ** 9

class SegmentTree:
    def __init__(self, data, default=INF, func=min):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])


    def __getitem__(self, idx):
        return self.data[idx + self._size]

    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def query(self, start, stop):
        """func of data[start, stop)"""
        start += self._size
        stop += self._size

        res_left = res_right = self._default
        while start < stop:
            if start & 1:
                res_left = self._func(res_left, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res_right = self._func(self.data[stop], res_right)
            start >>= 1
            stop >>= 1

        return self._func(res_left, res_right)

class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        n = len(nums)
        
        seg = SegmentTree([INF] * n)
        
        ind = sorted(range(n), key = lambda x: nums[x])
        
        best = INF
        for i in ind:
            left = seg.query(0, i)
            right = seg.query(i, n)
            cc = nums[i]
            if left < cc and right < cc:
                best = min(best, left + right + nums[i])
                
            seg[i] = nums[i]
        
        if best == INF:
            return -1
        
        return best

