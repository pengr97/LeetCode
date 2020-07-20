//
// Created by Pengr on 2020/7/21.
//

//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//Example:
//
//Input: "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
public:
    void gene(vector<string> &res, map<char, string> datas, string digits, string ans){
        if(digits.length()<1)
            res.push_back(ans);

        char d = digits[0];
        string mapStr = datas[d];
        for(int i=0;i<mapStr.length();i++){
            gene(res, datas, digits.substr(1), ans+mapStr[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length()<1)
            return res;
        map<char, string> datas;
        datas['1'] = "";
        datas['2'] = "abc";
        datas['3'] = "def";
        datas['4'] = "ghi";
        datas['5'] = "jkl";
        datas['6'] = "mno";
        datas['7'] = "pqrs";
        datas['8'] = "tuv";
        datas['9'] = "wxyz";
        datas['0'] = " ";
        gene(res, datas, digits, "");
        return res;
    }
};