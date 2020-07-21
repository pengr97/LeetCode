//
// Created by Pengr on 2020/7/21.
//

//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//    [
//        "((()))",
//        "(()())",
//        "(())()",
//        "()(())",
//        "()()()"
//    ]

class Solution {
public:
    // // solution 1
    // void generate(int currL,int currN,string currP,int n,vector<string>& pares) {
    //     if(currL==0 and currN==n)
    //         pares.push_back(currP);
    //     else if(currN==n){
    //         generate(currL-1,currN,currP+")",n,pares);
    //     }
    //     else{
    //         if(currL==0){
    //             generate(currL+1,currN+1,currP+"(",n,pares);
    //         }
    //         else{
    //             generate(currL+1,currN+1,currP+"(",n,pares);
    //             generate(currL-1,currN,currP+")",n,pares);
    //         }
    //     }
    // }
    // vector<string> generateParenthesis(int n) {
    //     int currL = 0;
    //     int currN = 0;
    //     string currP = "";
    //     vector<string> pares;
    //     generate(currL,currN,currP,n,pares);
    //     return pares;
    // }

    // solution 2
    vector<string> generate2(int n){
        vector<string> res;
        if(n<1)
            return res;
        for(int i=0;i<n;i++){
            vector<string> mid = generate2(i);
            vector<string> tail = generate2(n-1-i);
            if(mid.size()==0 && tail.size()==0){
                string tmp = "()";
                res.push_back(tmp);
            }
            else if(mid.size()==0)
                for(string tstr:tail){
                    string tmp = "()"+tstr;
                    res.push_back(tmp);
                }
            else if(tail.size()==0)
                for(string mstr:mid){
                    string tmp = "("+mstr+")";
                    res.push_back(tmp);
                }
            else
                for(string mstr:mid)
                    for(string tstr:tail){
                        string tmp = "("+mstr+")"+tstr;
                        res.push_back(tmp);
                    }
        }
        return res;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res = generate2(n);
        if(res.size()==0)
            res.push_back("");
        return res;
    }
};