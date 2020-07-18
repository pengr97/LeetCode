//
// Created by Pengr on 2020/7/18.
//

//Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string (not partial).
//
//Note:
//    s could be empty and contains only lowercase letters a-z.
//    p could be empty and contains only lowercase letters a-z, and characters like . or *.
//
//Example 3:
//    Input:
//    s = "ab"
//    p = ".*"
//    Output: true
//    Explanation: ".*" means "zero or more (*) of any character (.)".

class Solution {
public:
//     // Recursive exhaustive
//     bool isMatch(string s, string p) {
//         if(s.length()==0 && p.length()==0)
//             return true;
//         if(s.length()==0||p.length()==0)
//             return false;
//         if(p.length()>1){
//             if(p[1]=='*'){
//                 bool res = false;
//                 res = res||isMatch(s, p.substr(2)); // * for 0
//                 if(p[0]=='.' || p[0]==s[0]){
//                     res = res||isMatch(s.substr(1), p.substr(2)); // * for 1
//                     res = res||isMatch(s.substr(1), p); // * for more
//                 }
//                 return res;
//             }
//         }

//         if(p[0]=='.' || p[0]==s[0])
//             return isMatch(s.substr(1), p.substr(1));
//         else
//             return false;
//     }

    // Dynamic programming
    bool isMatch(string s, string p) {
        int dp[s.length()+1][p.length()+1];
        for(int i=0;i<=s.length();i++){
            for(int j=0;j<=p.length();j++){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(int j=1;j<=p.length();j++){
            if(p[j-1]=='*')
                dp[0][j] = dp[0][j-1]||dp[0][j-2];
            else
                dp[0][j] = 0;
        }
        for(int i=1;i<=s.length();i++){
            dp[i][0] = 0;
        }

        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=p.length();j++){
                if(p[j-1]=='*')
                    dp[i][j] = dp[i][j-2]||dp[i][j-1]||((dp[i-1][j-1]||dp[i-1][j])&&(p[j-1-1]=='.'||p[j-1-1]==s[i-1]));
                else if(p[j-1]=='.')
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = s[i-1]==p[j-1]&&dp[i-1][j-1];
            }
        }
        return dp[s.length()][p.length()];
    }
};