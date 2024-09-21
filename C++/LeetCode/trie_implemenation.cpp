#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode1
{
public:
    vector<TreeNode1 *> next;
    char val;
    bool end;

    TreeNode1()
    {
        val = '-';
        end = false;
    }

    TreeNode1(char val)
    {
        this->val = val;
        end = false;
    }

    TreeNode1(char val, TreeNode1 *next)
    {
        this->val = val;
        this->next.push_back(next);
        end = false;
    }
};

class Trie
{
    vector<TreeNode1 *> trie;

public:
    Trie()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        trie = vector<TreeNode1 *>(26);
    }

    void insert(string word)
    {

        int i = 1;

        TreeNode1 *temp = trie[word[0] - 'a'];
        TreeNode1 *newNode;

        if (temp == nullptr)
        {
            trie[word[0] - 'a'] = new TreeNode1(word[0]);
            temp = trie[word[0] - 'a'];
        }

        if (word.size() == 1)
        {
            temp->end = true;
            return;
        }

        while (i < word.size())
        {
            bool found = false;
            for (int j = 0; j < temp->next.size(); j++)
            {
                if (temp->next[j]->val == word[i])
                {
                    temp = temp->next[j];
                    if (i == word.size() - 1)
                        temp->end = true;

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                newNode = new TreeNode1(word[i]);
                temp->next.push_back(newNode);
                temp = newNode;
                if (i == word.size() - 1)
                    temp->end = true;
            }

            i++;
        }
    }

    bool search(string word)
    {
        if (trie[word[0] - 'a'] && trie[word[0] - 'a']->val == word[0])
        {
            int i = 1;

            TreeNode1 *temp = trie[word[0] - 'a'];

            if (word.size() == 1)
                return temp->end == true;

            while (i < word.size())
            {
                bool found = false;
                for (int j = 0; j < temp->next.size(); j++)
                {
                    if (temp->next[j]->val == word[i])
                    {
                        temp = temp->next[j];
                        if (i == word.size() - 1)
                        {
                            return temp->end;
                        }

                        found = true;
                        break;
                    }
                }

                if (!found)
                    return false;

                i++;
            }
        }

        return false;
    }

    bool startsWith(string prefix)
    {
        if (trie[prefix[0] - 'a'] && trie[prefix[0] - 'a']->val != '-')
        {
            int i = 1;

            TreeNode1 *temp = trie[prefix[0] - 'a'];

            if (prefix.size() == 1)
                return true;

            while (i < prefix.size())
            {
                bool found = false;
                for (int j = 0; j < temp->next.size(); j++)
                {
                    if (temp->next[j]->val == prefix[i])
                    {
                        temp = temp->next[j];
                        if (i == prefix.size() - 1)
                        {
                            return true;
                        }

                        found = true;
                        break;
                    }
                }

                if (!found)
                    return false;

                i++;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:

 */

int main()
{
    Trie *obj = new Trie();
    obj->insert("a");
    cout << obj->search("a") << endl;
    // bool param_3 = obj->startsWith(prefix);

    return 0;
}