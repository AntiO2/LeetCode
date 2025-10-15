/*
 * Copyright 2025 PixelsDB.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

package top.antio2.array.s3350;

import java.util.List;

class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int ans = 0;
        int preLen = 0;
        int currLen = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            ++currLen;
            if(i == nums.size() - 1 || nums.get(i) >= nums.get(i + 1))
            {
                ans = Math.max(ans, Math.max(currLen / 2, Math.min(preLen, currLen)));
                preLen = currLen;
                currLen = 0;
            }
        }
        return ans;
    }
}
