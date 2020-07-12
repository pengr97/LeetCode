//
// Created by Pengr on 2020/7/12.
//
//Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
//Input: 3
//Output: 5
//Explanation:
//Given n = 3, there are a total of 5 unique BST's:
//
//  1         3     3      2      1
//   \       /     /      / \      \
//    3     2     1      1   3      2
//   /     /       \                 \
//  2     1         2                 3

class Solution {
public:
    int numTrees(int n) {
        if(n<=2)
            return n;
        int dp[n+1];
        for(int i=0;i<=n;i++)
            dp[i] = 0;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i] += dp[i-j]*dp[i-(i-j)-1];
            }
        }
        return dp[n];
    }
};