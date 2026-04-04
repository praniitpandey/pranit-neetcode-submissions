class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;

    TrieNode() {
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
            if (!currNode->children.count(letter)) {
                currNode->children[letter] = new TrieNode();
            }
            currNode = currNode->children[letter];
        }
        currNode->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* currNode = root;
        for (char letter : word) {
            if (!currNode->children.count(letter)) {
                return false;
            }
            currNode = currNode->children[letter];
        }
        
        return currNode->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* currNode = root;
        for (char letter : prefix) {
            if (!currNode->children.count(letter)) {
                return false;
            }
            currNode = currNode->children[letter];
        }
        
        return true;
    }
};
