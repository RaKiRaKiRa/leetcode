/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *phead, *ptail;
        if(dict.find(endWord) == dict.end())
            return 0;
        head.insert(beginWord);
        tail.insert(endWord);
        int res = 2;
        while(head.size() && tail.size()){
            if(head.size() < tail.size()){
                phead = &head;
                ptail = &tail;
            }else{
                ptail = &head;
                phead = &tail;
            }
            unordered_set<string> tmp;
            for(unordered_set<string>::iterator it = phead -> begin(); it != phead -> end(); ++it){
                string word = *it;
                for(int i = 0;i < word.size(); ++i){
                    char t = word[i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        word[i] = c;
                        if(ptail -> find(word) != ptail -> end())
                            return res;
                        if(dict.find(word) != dict.end()){
                            tmp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
            *phead = tmp;
            ++res;

        }
        return 0;
    }
};

