//
// Created by Pengr on 2020/7/27.
//

//Given a string, find the length of the longest substring without repeating characters.
//
//Example 1:
//Input: "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
//
//Example 2:
//Input: "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
//
//Example 3:
//Input: "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // // dynamic programming
        // if(s.length()<=1)
        //     return s.length();
        // int dp[s.length()];
        // for(int i=0;i<s.length();i++){
        //     dp[i] = 1;
        // }
        // dp[0] = 1;
        // for(int i=1;i<s.length();i++){
        //     for(int j=i-1;i-1-j<dp[i-1];j--){
        //         if(s[i]!=s[j])
        //             dp[i]+=1;
        //         else
        //             break;
        //     }
        // }
        // int max = dp[0];
        // for(int i=1;i<s.length();i++){
        //     if(dp[i]>max)
        //         max = dp[i];
        // }
        // return max;

        // Sliding window
        int left=0, right=0;
        unordered_map<char, int> window;
        int res = 0;
        while(right<s.length()){
            char c1 = s[right];
            window[c1]++;
            right++;
            while(window[c1]>1){
                window[s[left]]--;
                left++;
            }
            res = max(res, (right-left));
        }
        return res;
    }
};