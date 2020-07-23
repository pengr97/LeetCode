//
// Created by Pengr on 2020/7/24.
//
//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
//Example 1:
//    Input: num1 = "2", num2 = "3"
//    Output: "6"
//
//Example 2:
//    Input: num1 = "123", num2 = "456"
//    Output: "56088"
//
//Note:
//    The length of both num1 and num2 is < 110.
//    Both num1 and num2 contain only digits 0-9.
//    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
//    You must not use any built-in BigInteger library or convert the inputs to integer directly.

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length()<1 || num2.length()<1)
            return "";
        if((num1.length()==1&&num1[0]=='0') || (num2.length()==1&&num2[0]=='0'))
            return "0";
        string res = "0";
        for(int i=num1.length()-1;i>=0;i--){
            int c1 = num1[i]-'0';
            int jinwei = 0;
            int duiqi = num1.length()-1-i;
            for(int j=num2.length()-1;j>=0;j--){
                int c2 = num2[j]-'0';
                int curr = (c1*c2+jinwei)%10;
                jinwei = (c1*c2+jinwei)/10;
                if(duiqi<res.length()){
                    int tmp = (res[res.length()-1-duiqi]-'0') + curr;
                    res[res.length()-1-duiqi] = (tmp%10+'0');
                    jinwei += tmp/10;
                }
                else {
                    res = (char)(curr+'0')+res;
                }
                duiqi+=1;
            }
            if(jinwei>0)
                res = (char)(jinwei+'0')+res;
        }
        return res;
    }
};
