class Trie {
private:
    Trie* ch[26] = {0};
public:
    Trie* get(char c) {
        return ch[c - 'a'];
    }
    
    void set(char c, Trie* trie) {
        ch[c - 'a'] = trie;
    }
    
    bool end = false;
};