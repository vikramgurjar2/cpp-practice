#include <iostream>
using namespace std;

class TrieNode
{

public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUntil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption , word will be in Caps

        int index = word[0] - 'A';
        TrieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        return insertUntil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUntil(root, word);
    }

    bool searchUntil(TrieNode *root, string word)
    {
        // basecase
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUntil(child, word.substr(1));
    }
    bool searchword(string word)
    {
        return searchUntil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ABCD");

    cout << "the word is present or not " << t->searchword("ABCD") << endl;
    cout << "something ";
    return 0;
}