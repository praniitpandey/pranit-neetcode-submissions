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

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return search(word, 0, root);
    }

private:
    bool search(string word, int start, TrieNode* root) {
        TrieNode* currNode = root;
        for (int i = start; i < word.size(); i++) {
            char letter = word[i];

            if (letter == '.') {
                for (auto child : currNode->children) {
                    if (child && search(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            }
            else {
                if (!currNode->children[letter - 'a']) {
                    return false;
                }
                currNode = currNode->children[letter - 'a'];
            }

        }
        
        return currNode->endOfWord;        
    }
};