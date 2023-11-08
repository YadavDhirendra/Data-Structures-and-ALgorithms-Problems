//Trie Implementation
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char d)
    {
        data = d;
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

    void insertUtil(TrieNode *root, string word)
    {
        //base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        //Assuming string to be in CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        //char is present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else //absent
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //RECURSION
        return insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        //base case
        if(word.length() == 0)
        return root->isTerminal;

        int index = word[0] - 'A';
        TrieNode* child;
        
        //present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else//absent
        {
            return false;
        }

        //RECURSION
        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root,word);
    }

    bool prefixUtil(TrieNode* root,string word)
    {
        //base case
        if(word.length() == 0)
        return true;

        int index = word[0] - 'A';
        
        //present
        if(root->children[index] != NULL)
        {   
            //RECURSION
            return prefixUtil(root->children[index],word.substr(1));
        }
        else
        {
            return false;
        }
    }

    bool prefixWord(string word)
    {
        return prefixUtil(root,word);
    }

    bool isEmpty(TrieNode* root)
    {
        for (int i = 0; i < 26; i++)
        {
            if(root->children[i])
            return false;
        }
        return true;
        
    }

    TrieNode* removeUtil(TrieNode* root,string word)
    {
        //if tree is empty
        if(!root)
        return NULL;

        //if last character of key is being processed
        if(word.length() == 1)
        {
            //This node is no more terminal for the given word
            if(root->isTerminal)
            root->isTerminal = false;

            //if given is not prefix of any other word
            if(isEmpty(root))
            {
                delete (root);
                root = NULL;
            }
            return root;
        }

        //RECURSION
        int index = word[0] - 'A';
        root->children[index] = removeUtil(root->children[index],word.substr(1));

        //If root does not have any child and it is not terminal
        if(isEmpty(root) && root->isTerminal == false)
        {
            delete root;
            root = NULL;
        }
        
        return root;
    }

    void removeWord(string word)
    {
        root = removeUtil(root,word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("CAN");
    t->insertWord("DO");
    t->insertWord("GENERATION");
    t->insertWord("ARM");
    t->insertWord("ARE");
    t->insertWord("ARMADILLO");
    cout<<"CAN is present or not : "<<t->searchWord("CAN")<<endl;
    cout<<"ARM prefix is present or not : "<<t->prefixWord("ARM")<<endl;
    t->removeWord("CAN");
    cout<<"CAN is present or not : "<<t->searchWord("CAN")<<endl;
    return 0;
}
