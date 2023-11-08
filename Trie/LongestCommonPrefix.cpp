//Longest Common Prefix
#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childcount;

    TrieNode(char d)
    {
        data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
        childcount = 0;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* &root,string word)
    {
        //base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int  index = word[0] - 'a';

        if(root->children[index] == NULL)
        {   
            root->childcount++;
            root->children[index] = new TrieNode(word[0]);
        }

        //RECURSION
        insertUtil(root->children[index],word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root,word);
    }

    void lcp(string arr,string &ans)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            char ch = arr[i];
           
           if(root->childcount == 1){
           ans.push_back(ch);

           //aage badhao
           int index = ch-'a';
           root = root->children[index];
           }
           else
           break;

           if(root->isTerminal)
           break;
        }
        
    }
};

string longestCommonPrefix2(vector<string> &arr, int n)
{
    Trie *t = new Trie();
    //insert all words in trie
    for (int i = 0; i < n; i++)
    {
        t->insertWord(arr[i]);
    }

    string ans = "";
    string first = arr[0];
    t->lcp(first,ans);
    return ans;
    
}
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    //for traversing all characters of first string
    for (int i = 0; i < arr[0].size(); i++)
    {
        char ch = arr[0][i];

        bool match = true;

        //comparing letter to letter with other string
        for (int j = 1; j < n; j++)
        {
            //not match
            if (ch != arr[j][i])
            {
                match = false;
                break;
            }
        }

        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

int main()
{
    vector<string> arr = {"coding","codehelp","coder"};
    int n = 3;
    string lcp = longestCommonPrefix(arr,n);
    string lcp2 = longestCommonPrefix2(arr,n);
    cout<<lcp<<endl;
    cout<<lcp2<<endl;
    return 0;
}