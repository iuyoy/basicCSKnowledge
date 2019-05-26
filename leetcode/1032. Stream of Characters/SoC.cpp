/*
Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
 

Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.
*/
// forward trie O(<=m*m*len+n) n:word number, len:length of word, m:number of query
struct TrieNode
{
    vector<TrieNode*> next;
    bool end;
    TrieNode(){end=0, next = vector<TrieNode*>(26, NULL);}
};

class StreamChecker {
public:
    TrieNode* root;
    vector<TrieNode*> querys;
    
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(auto word:words){
            TrieNode* t = root;
            for(char c:word){
                if(t->next[c-'a'] == NULL)
                    t->next[c-'a'] = new TrieNode();
                t = t->next[c-'a'];
            }
            t->end = true;
        }
        querys.push_back(root);
    }
    
    bool query(char letter) {
        vector<TrieNode*> next_querys({root});
        bool ret = false;
        for(auto t : querys){
            if(t->next[letter-'a'] != NULL){
                if(t->next[letter-'a']->end)
                    ret = true;
                next_querys.push_back(t->next[letter-'a']);
            }
        }
        querys = next_querys;
        return ret;
    }
};

// backward Trie O(m*len+n) n: word number, len:max length of word, m:number of query
struct TrieNode
{
    TrieNode* next[26];
    bool end;
    TrieNode(){end=0; memset(next, 0, sizeof(TrieNode*)*26);}
};

class StreamChecker {
public:
    TrieNode* root;
    list<char> stream;
    int max_length;
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        max_length = 0;
        for(auto word:words){
            TrieNode* t = root;
            int n = word.size();
            max_length = max(max_length, n);
            for(int i=n-1; i>=0; --i){
                if(t->next[word[i]-'a'] == nullptr)
                    t->next[word[i]-'a'] = new TrieNode();
                t = t->next[word[i]-'a'];
            }
            t->end = true;
        }
    }
    
    bool query(char letter) {
        stream.push_front(letter-'a');
        if(stream.size()>max_length)
            stream.pop_back();
        TrieNode* t = root;
        for(auto it=stream.begin(); it!=stream.end(); it++){
            if(t->next[*it] != NULL){
                if(t->next[*it]->end)
                    return true;
                t = t->next[*it];
                continue;
            }
            return false;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */