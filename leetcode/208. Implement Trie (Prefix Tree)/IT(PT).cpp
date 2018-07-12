/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
class Trie {
private:
    vector<Trie*> trie;
    bool stop = false;
public:
    /** Initialize your data structure here. */
    Trie() {
        trie = vector<Trie*>(26, nullptr);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.size()==0) {
            stop = true;
            return;
        }
        char c = word[0]-'a';
        if(trie[c] == nullptr)
            trie[c] = new Trie();
        trie[c]->insert(word.substr(1, word.size()-1));
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.size()==0) return stop;
        char c = word[0]-'a';
        if(trie[c] == nullptr)
            return false;
        return trie[c]->search(word.substr(1, word.size()-1));
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.size()==0) return true;
        char c = prefix[0]-'a';
        if(trie[c] == nullptr)
            return false;
        return trie[c]->startsWith(prefix.substr(1, prefix.size()-1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */