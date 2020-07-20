//
// Created by Pengr on 2020/7/21.
//

//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//Example 1:
//
//Input: ["flower","flow","flight"]
//Output: "fl"
//Example 2:
//
//Input: ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.
//Note:
//
//All given inputs are in lowercase letters a-z.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if((int)strs.size()<1)
            return res;
        int len = (int)strs[0].length();
        for(int i=0;i<len;i++){
            int j;
            for(j=1;j<(int)strs.size();j++)
                if(i>=strs[j].length() || strs[j][i]!=strs[0][i])
                    break;
            if(j==(int)strs.size())
                res += strs[0][i];
            else
                break;
        }
        return res;
    }
};