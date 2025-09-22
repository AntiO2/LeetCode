package top.antio2.hash.s3005_count_elements_with_maximum_frequency;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for(int n : nums) count.put(n, count.getOrDefault(n, 0) + 1);
        int max = 0;
        int ans = 0;
        for(Map.Entry<Integer,Integer> e:count.entrySet())
        {
            if(e.getValue() == max)
            {
                ans += e.getValue();
            }
            if(e.getValue() > max)
            {
                max = e.getValue();
                ans = max;
            }
        }
        return ans;
    }
}