/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

// Trie
class WordDictionary {
private:
    vector<WordDictionary*> trie;
    bool stop = false;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = vector<WordDictionary*>(26, nullptr);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if(word.size()==0) {
            stop = true;
            return;
        }
        char c = word[0]-'a';
        if(trie[c] == nullptr)
            trie[c] = new WordDictionary();
        trie[c]->addWord(word.substr(1, word.size()-1));
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word.size()==0) return stop;
        if(word[0] == '.'){
            for(auto t:trie){
                if(t!=nullptr && t->search(word.substr(1, word.size()-1)))
                    return true;
            }
            return false;
        }
        char c = word[0]-'a';
        if(trie[c] == nullptr)
            return false;
        return trie[c]->search(word.substr(1, word.size()-1));
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */