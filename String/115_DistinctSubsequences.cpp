//
// Created by Pengr on 2020/7/17.
//

//Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
//A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//It's guaranteed the answer fits on a 32-bit signed integer.
//
//Example 1:
//Input: S = "rabbbit", T = "rabbit"
//Output: 3
//Explanation:
//As shown below, there are 3 ways you can generate "rabbit" from S.
//(The caret symbol ^ means the chosen letters)
//
//rabbbit
//^^^^ ^^
//rabbbit
//^^ ^^^^
//rabbbit
//^^^ ^^^

class Solution {
public:
    // 暴力解法，递归穷举
    // int numDistinct(string s, string t) {
    //     if(s.length()<t.length() || (s.length()<1&&t.length()>0))
    //         return 0;
    //     if(t.length()<1)
    //         return 1;
    //     int num = 0;
    //     if(t[0]==s[0])
    //         num += numDistinct(s.substr(1), t.substr(1));
    //     num += numDistinct(s.substr(1), t.substr(0));
    //     return num;
    // }

    // 动态规划解法
    int numDistinct(string s, string t) {
        // Use long to avoid overflow
        long dp[s.length()+1][t.length()+1];

        for(int i=0;i<=s.length();i++){
            for(int j=0;j<=t.length();j++){
                dp[i][j] = 0;
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;

            }
        }

        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                if(t[j-1]!=s[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            }
        }

        return dp[s.length()][t.length()];
    }
};