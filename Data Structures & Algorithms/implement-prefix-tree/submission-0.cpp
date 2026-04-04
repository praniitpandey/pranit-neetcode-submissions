class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* currNode = root;
        for (char letter : word) {
            if (!currNode->children[letter - 'a']) {
                currNode->children[letter - 'a'] = new TrieNode();
            }
            currNode = currNode->children[letter - 'a'];
        }
        currNode->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* currNode = root;
        for (char letter : word) {
            if (!currNode->children[letter - 'a']) {
                return false;
            }
            currNode = currNode->children[letter - 'a'];
        }
        
        return currNode->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* currNode = root;
        for (char letter : prefix) {
            if (!currNode->children[letter - 'a']) {
                return false;
            }
            currNode = currNode->children[letter - 'a'];
        }
        
        return true;
    }
};
