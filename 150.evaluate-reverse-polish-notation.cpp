/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */
class Solution {
public:
    int str2int(string &s){
        int res = 0, flag = 1, i = 0;
        if(s[0] == '-'){
            ++i;
            flag = -1;
        }
        for(; i < s.size(); ++i){
            res *= 10;
            res += s[i] - '0';
        }
        return res * flag;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int sz = tokens.size();
        for(int i = 0; i < sz; ++i){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push(str2int(tokens[i]));
            }else{
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                switch (tokens[i][0]){
                    case '+':
                        //cout <<a<<"+"<<b<<"="<<a+b<<endl; 
                        st.push(a + b);
                        break;
                    case '-':
                        //cout <<a<<"-"<<b<<"="<<a-b<<endl; 
                        st.push(a - b);
                        break;
                    case '*':
                        //cout <<a<<"*"<<b<<"="<<a*b<<endl; 
                        st.push(a * b);
                        break;
                    case '/':
                        //cout <<a<<"/"<<b<<"="<<a/b<<endl; 
                        st.push(a / b);
                        break;
                }
            }
        }
        return st.top();
    }
};

