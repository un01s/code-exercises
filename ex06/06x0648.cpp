/*
 * leetcode 648
 * replace words
 *
 */

class TrieNode {
public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
    string word;

    TrieNode(char ch) {
        this->ch = ch;
        isTerminal = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        word = "";
    }
};

class Solution {
public:
    TrieNode* root;
    void insert(string& word) {
        auto crawl = root;

        int n = word.size();
        for (int i = 0; i < n; i++) {
            int child = word[i] - 'a';
            if (crawl->children[child] == NULL) {
                crawl->children[child] = new TrieNode(word[i]);
            }

            crawl = crawl->children[child];
        }
        crawl->isTerminal = true;
        crawl->word = word;
    }

    string search(string& word) {
        auto crawler = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (crawler->isTerminal == true)
                return crawler->word;

            int child = word[i] - 'a';

            if (crawler->children[child] == NULL) {
                return word;
            }

            crawler = crawler->children[child];
        }

        return word;
    }

    vector<string> getAllWords(string& sentence) {
        vector<string> v;
        string word = "";
        int n = sentence.size();

        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                v.push_back(word);
                word = "";
            } else {
                word.push_back(sentence[i]);
            }
        }

        v.push_back(word);

        return v;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode('\0');

        for (auto i : dictionary) {
            insert(i);
        }

        vector<string> v = getAllWords(sentence);
        string ans = "";
        for (auto i : v) {
            ans += search(i);
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};

