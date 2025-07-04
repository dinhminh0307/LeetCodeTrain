class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n_set = set(nums)
        hash_map = {}
        res_set = set()
        seq = []
        # find the start of sequence
        for n in n_set:
            if n - 1 not in n_set and n not in seq:
                seq.append(n)

        for n in seq:
            arr = []
            if n not in arr:
                arr.append(n)
            temp_n = n
            while temp_n in n_set:
                if temp_n + 1 in n_set:
                    arr.append(temp_n + 1)
                temp_n = temp_n + 1
            
            if tuple(arr) not in hash_map:
                hash_map[tuple(arr)] = len(arr)
        
        for key in hash_map:
            res_set.add(hash_map[key])
        
        if len(res_set) == 0:
            return 0
        return max(res_set)
