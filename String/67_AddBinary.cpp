//
// Created by Pengr on 2020/8/5.
//
//Given two binary strings, return their sum (also a binary string).
//
//The input strings are both non-empty and contains only characters 1 or 0.
//
//Example 1:
//    Input: a = "11", b = "1"
//    Output: "100"
//
//Example 2:
//    Input: a = "1010", b = "1011"
//    Output: "10101"
//
//Constraints:
//    Each string consists only of '0' or '1' characters.
//    1 <= a.length, b.length <= 10^4
//    Each string is either "0" or doesn't contain any leading zero.

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int idx_a = a.length()-1;
        int idx_b = b.length()-1;
        int jinwei = 0;
        while(idx_a>=0 && idx_b>=0){
            int tmp = (a[idx_a]-'0')+(b[idx_b]-'0')+jinwei;
            jinwei = tmp/2;
            char c = tmp%2+'0';
            res = c+res;
            idx_a--;
            idx_b--;
        }
        while(idx_a>=0){
            int tmp = (a[idx_a]-'0')+jinwei;
            jinwei = tmp/2;
            char c = tmp%2+'0';
            res = c+res;
            idx_a--;
        }
        while(idx_b>=0){
            int tmp = (b[idx_b]-'0')+jinwei;
            jinwei = tmp/2;
            char c = tmp%2+'0';
            res = c+res;
            idx_b--;
        }
        if(jinwei>0){
            char c = jinwei+'0';
            res = c+res;
        }

        return res;
    }
};