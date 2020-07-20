//
// Created by Pengr on 2020/7/21.
//

//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Note that an empty string is also considered valid.
//
//Example 4:
//Input: "([)]"
//Output: false

//Example 5:
//Input: "{[]}"
//Output: true

class Solution {
public:
    bool isValid(string s) {

//         // revision
//         if(s.length()<1)
//             return true;
//         string tmp = "";
//         int i,j=0,k=0,l=0;
//         for(i=0;i<s.length();i++){
//             if(s[i]=='(')
//                 j = i;
//             if(s[i]=='[')
//                 k=i;
//             if(s[i]=='{')
//                 l=i;
//             if(s[i]==')' || s[i]==']' || s[i]=='}')
//                 break;
//         }
//         if(i==s.length())
//             return false;
//         if(s[i]==')' && k<=j && l<=j)
//             return isValid(s.substr(0,j)+s.substr(i+1));
//         if(s[i]==']' && j<=k && l<=k)
//             return isValid(s.substr(0,k)+s.substr(i+1));
//         if(s[i]=='}' && j<=l && k<=l)
//             return isValid(s.substr(0,l)+s.substr(i+1));
//         return false;

        // stack
        if(s.length()<1)
            return true;
        stack<char> stac;
        stac.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(stac.empty()){
                stac.push(s[i]);
                continue;
            }
            char c = stac.top();
            if(c=='('){
                if(s[i]==')')
                    stac.pop();
                else
                    stac.push(s[i]);
            }
            else if(c=='['){
                if(s[i]==']')
                    stac.pop();
                else
                    stac.push(s[i]);
            }
            else if(c=='{'){
                if(s[i]=='}')
                    stac.pop();
                else
                    stac.push(s[i]);
            }
            else
                return false;
        }
        if(stac.empty())
            return true;
        return false;
    }
};