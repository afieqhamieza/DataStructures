class Solution(object):
    def minDominoRotations(self, tops, bottoms):
        """
        :type tops: List[int]
        :type bottoms: List[int]
        """
        
        if len(tops) != len(bottoms): return -1
        if len(tops) == 0: return 0
        
        for cand in set([tops[0], bottoms[0]]):  # Candidates.
            count_top = count_bottom = 0
            
            for i in range(len(tops)):
                if cand not in (tops[i], bottoms[i]): 
                    break
                    
                count_top += int(cand != bottoms[i])
                count_bottom += int(cand != tops[i])
                
            else:
                return min(count_top, count_bottom)
            
        return -1
        