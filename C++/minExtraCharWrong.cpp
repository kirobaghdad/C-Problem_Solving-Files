#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

class Solution
{

    // trie node
    struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];

        // isEndOfWord is true if the node represents
        // end of a word
        bool isEndOfWord;
    };

    // Returns new trie node (initialized to NULLs)
    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode = new TrieNode;

        pNode->isEndOfWord = false;

        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;

        return pNode;
    }

    // If not present, inserts key into trie
    // If the key is prefix of trie node, just
    // marks leaf node
    void insert(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
        }

        // mark last node as leaf
        pCrawl->isEndOfWord = true;
    }

    // Returns true if key presents in trie, else
    // false
    int search(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return 0;

            pCrawl = pCrawl->children[index];
        }

        if ((pCrawl->isEndOfWord))
            return 2;
        else
            return 1;
    }

public:
    int minExtraChar(string s, vector<string> dictionary)
    {
        struct TrieNode *root = getNode();

        for (string t : dictionary)
            insert(root, t);

        int ans = 0;

        int prev = 0;

        int temp;

        int n = s.length();

        for (int i = 0; i < s.length(); i++)
        {
            temp = search(root, s.substr(prev, i - prev + 1));

            if (temp == 0)
            {
                // if (i == prev && i != 0)
                //     prev = i + 1;
                // else
                {
                    ans++;
                    prev = i;
                    i--;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.minExtraChar("sayhelloworld", {"hello", "world"});
    return 0;
}