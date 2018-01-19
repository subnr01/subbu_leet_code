/*


Given many words, words[i] has weight i.

Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix). 
It will return the word with given prefix and suffix with maximum weight. If no word exists, return -1.

Examples:
Input:
WordFilter(["apple"])
WordFilter.f("a", "e") // returns 0
WordFilter.f("b", "") // returns -1
Note:
words has length in range [1, 15000].
For each test case, up to words.length queries WordFilter.f may be made.
words[i] has length in range [1, 10].
prefix, suffix have lengths in range [0, 10].
words[i] and prefix, suffix queries consist of lowercase letters only.



*/

//Related topics
//Trie
//LOOK at solns for complexity

//Trie with map
struct Trie {
    unordered_map<char,Trie*> nxt;
    int mx;
    
    Trie() {
        mx = -1;
    }
    
    void add(string w, int x) {
        Trie *cur = this;
        for (char c:w) {
            if (!cur->nxt.count(c)) cur->nxt[c] = new Trie();
            cur= cur->nxt[c];
            cur->mx = max(cur->mx,x);
        }
    }
    
    int f(string w) {
        Trie *cur = this;
        for (char c:w) {
            if (!cur->nxt.count(c)) return -1;
            cur= cur->nxt[c];
        }
        return cur->mx;
    }
};

class WordFilter {
public:
    Trie* root;
    
    WordFilter(vector<string> words) {
        root = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            int m = min(10,(int)words[i].size());
            string r = words[i].substr(words[i].size()-m) + "*";
            reverse(r.begin(),r.end());
            string t;
            for (int j = 0; j < m; ++j) {
                root->add(t + r,i);
                t+= words[i][j];
            }
            root->add(t+r,i);
        }
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        return root->f(prefix + "*" + suffix);
    }
};




//Soln with two trie
struct Trie {
    vector<int> words; // index of words
    vector<Trie *> children;
    Trie() {
        children = vector<Trie *>(26, nullptr);
    }
    // Thanks to @huahualeetcode for adding this in case of memory leak
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
    
    void add(const string &word, size_t begin, int index) {
        words.push_back(index);
        if (begin < word.length()) {
            if (!children[word[begin] - 'a']) {
                children[word[begin] - 'a'] = new Trie();
            }
            children[word[begin] - 'a']->add(word, begin + 1, index);
        }
    }
    
    vector<int> find(const string &prefix, size_t begin) {
        if (begin == prefix.length()) {
            return words;
        } else {
            if (!children[prefix[begin] - 'a']) {
                return {};
            } else {
                return children[prefix[begin] - 'a']->find(prefix, begin + 1);
            }
        }
    }
};

class WordFilter {
public:
    WordFilter(vector<string> words) {
        forwardTrie = new Trie();
        backwardTrie = new Trie();
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            forwardTrie->add(word, 0, i);
            reverse(word.begin(), word.end());
            backwardTrie->add(word, 0, i);
        }
    }
    
    int f(string prefix, string suffix) {
        auto forwardMatch = forwardTrie->find(prefix, 0);
        reverse(suffix.begin(), suffix.end());
        auto backwardMatch = backwardTrie->find(suffix, 0);
        // search from the back
        auto fIter = forwardMatch.rbegin(), bIter = backwardMatch.rbegin();
        while (fIter != forwardMatch.rend() && bIter != backwardMatch.rend()) {
            if (*fIter == *bIter) {
                return *fIter;
            } else if (*fIter > *bIter) {
                fIter ++;
            } else {
                bIter ++;
            }
        }
        return -1;
    }
    
private:
    Trie *forwardTrie, *backwardTrie;
};
