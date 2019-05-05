/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */
/*
class Solution {
public:
    void dfs(size_t i, vector<string> &res, vector<vector<string> > &dp, string cur){
        if(i == 0){
            res.push_back(cur);
            return ; 
        }
        for(vector<string>::iterator it = dp[i].begin(); it != dp[i].end(); ++it){
            dfs(i - it -> size(), res, dp, cur.empty() ? *it : *it + " " + cur);
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string> >  dp(s.size() + 1);
        unordered_set<string> words;
        copy(wordDict.begin(), wordDict.end(), inserter(words, words.end()));
        dp[0].push_back(string(""));
        vector<string> res;
        string tmp;
        int minlen = INT_MAX, maxlen = INT_MIN;
        for(string str : wordDict){
            minlen = min(minlen, (int)str.size());
            maxlen = max(maxlen, (int)str.size());
        }
        for(int i = 0;i < s.size(); ++i){
            //tmp.clear();
            int sz = min((int)s.size() - i, maxlen);
            for(int len = minlen; len <= sz; ++len){
                //tmp.append(s, i + len - 1, 1);
                //cout<<tmp<<endl;
                tmp = s.substr(i, len);
                if(words.find(tmp) != words.end()){
                    //cout<<1;
                    dp[i + len].push_back(tmp);
                }
                    
            }
        }
        //cout<<dp[s.size()].size();
        dfs(s.size(), res, dp, string());
        return res;
    }
};*/
/*
class Solution {
private: //DFS path build function
    void buildPath(bool isBreakable[], string &s, int pos, vector<string> &res, string curP, unordered_set<string>& wordDict, int minlen, int maxlen)
    {
        int i, len = s.size();
        for(i =minlen; i<= min(maxlen, len - pos); ++i)
            if( isBreakable[pos+i] && wordDict.count(s.substr(pos,i)) ) 
                if(pos+i == len) res.push_back(curP + s.substr(pos,i));
                else buildPath(isBreakable, s, pos+i, res, curP + s.substr(pos,i) + " ", wordDict, minlen, maxlen);
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& words) {
        int sSize = s.size(), len, i, minlen = INT_MAX, maxlen = INT_MIN;
        unordered_set<string> wordDict;
        copy(words.begin(), words.end(), inserter(wordDict, wordDict.end()));
        vector<string> res;
        //isBreakable[i]表示s[i..sSize-1]是否是可分的
        bool isBreakable[sSize+1];
        fill_n(isBreakable, sSize+1, false);
        // find the minimum and maximum word length     
        for (string word : wordDict) { 
            minlen = min(minlen, (int)word.length());
            maxlen = max(maxlen, (int)word.length()); 
        }        
        //DP to build isBreakable
        for(i=sSize-minlen, isBreakable[sSize]= true; i>=0; --i)
            for(len=minlen; len<=min(maxlen, sSize-i); ++len){
                //s.substr(i,len)为s[i ... i+len-1]
                if(isBreakable[i+len] && wordDict.count(s.substr(i,len)) ) {
                    isBreakable[i] = true; 
                    break;
                }
            }
        //if breakable, do DFS path building
        if(isBreakable[0]) 
            buildPath(isBreakable, s, 0, res, "", wordDict, minlen, maxlen);
        return res;
    }
};

*/

class Solution {
public:
    void dfs(bool *isBreakable, string &s, vector<string> &res, unordered_set<string> &words, int pos, int &maxlen, int &minlen, string cur){
        int sz = s.size();
        for(int i = minlen; i <= min((int)maxlen, sz - pos); ++i){
            if(isBreakable[pos + i] && words.count(s.substr(pos, i))){
                if(pos + i == sz)
                    res.push_back(cur + s.substr(pos, i));
                else
                    dfs(isBreakable, s, res, words, pos + i, maxlen, minlen, cur + s.substr(pos, i) + " ");
            }
        }
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //size_t sz = wordDict.size();
        int ssz = s.size();
        bool isBreakable[ssz + 1];
        fill_n(isBreakable, ssz + 1, false);
        unordered_set<string> words;
        copy(wordDict.begin(), wordDict.end(), inserter(words, words.end()));
        isBreakable[ssz] = true;

        int minlen = INT_MAX, maxlen = INT_MIN;
        for(string &str : wordDict){
            minlen = min((int)str.size(), minlen);
            maxlen = max((int)str.size(), maxlen);
        }
        /*
        for(i=sSize-minlen, isBreakable[sSize]= true; i>=0; --i)
            for(len=minlen; len<=min(maxlen, sSize-i); ++len){
                //s.substr(i,len)为s[i ... i+len-1]
                if(isBreakable[i+len] && wordDict.count(s.substr(i,len)) ) {
                    isBreakable[i] = true; 
                    break;
                }
            }
        */
        for(int i = ssz - minlen; i >= 0 ; --i){
            for(int len = minlen; len <= min(maxlen, ssz - i); ++len){
                if(isBreakable[i + len] && words.count(s.substr(i, len))){
                    isBreakable[i] = true;
                    break;
                }
            }
        }

        vector<string> res;
        //for(int i = 0;i < ssz + 1; ++i) cout<< isBreakable[i];
        if(isBreakable[0])
            dfs(isBreakable, s, res, words, 0, maxlen, minlen, string());
        return res;
    }

};


