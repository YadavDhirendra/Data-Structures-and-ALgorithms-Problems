//Implement a Phone Directory
//You are given a list/arrays of strings which denotes the contacts that exists in your 
//phone directory. The search query on a string 'str' which is a query string displays 
//all the contacts which are present in the given directory with prefix as 'str'.
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        data = d;
        for (int  i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word)
    {
        //base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return ;
        }

        int index = word[0] - 'a';
        if(root->children[index] == NULL)
        {
            root->children[index] = new TrieNode(word[0]);
        }

        //RECURSION
        insertUtil(root->children[index],word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root,word);
    }

    void printSuggestions(TrieNode* curr,vector<string> &temp,string prefix)
    {
        if(curr->isTerminal)
        {
            temp.push_back(prefix);
            
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode* next = curr->children[ch-'a'];

            if(next != NULL)
            {
                prefix.push_back(ch);
                //aage badhao
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
        
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];

            prefix.push_back(lastch);

            //check for lastch
            TrieNode* curr = prev->children[lastch-'a'];

            //if not found
            if(curr == NULL)
            {
                break;
            }

            //if found
            vector<string> temp;
            printSuggestions(curr,temp,prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList,string &queryStr)
{
    //creation of Trie
    Trie* t = new Trie();

    //insert all contact in trie
    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertWord(str);
    }
    
    return t->getSuggestions(queryStr);
}

int main()
{
    vector<string> contactList = {"cod","coding","codding","code","coly"};
    string query = "coding";
    vector<vector<string>> suggestions = phoneDirectory(contactList,query);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < suggestions[i].size(); j++)
        {
            cout<<suggestions[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
