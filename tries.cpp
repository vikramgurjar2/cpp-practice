#include<iostream>
using namespace std;

class TrieNode
{
    public:
           char data;
           TrieNode* children[26];
           bool isTerminal;
           TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i]= NULL;
            }
            isTerminal= false;
           }

};
class Trie{
    public: 
    TrieNode* root;

    Trie(){
        root = new TrieNode('/');
    }
    void insertuntil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index = word[0]-'A';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }
        
        insertuntil(child,word.substr(1));

    }   
    void insertword(string word){
        insertuntil(root,word);
            }  

    bool searchuntil(TrieNode* root,string word){
        if(word.lenght()==0){
            return root->isTerminal;
        }
        int index = word[0]-'A';
        TrieNode* child;
        if(root->children(index)!= NULL){
            child = root->children(index);
        }
        else{
            return false;

        }
        search(child,word.substr(1));

    }       



    bool search(string word){
        return searchuntil(root,word);

    }
};






int main(){
    trie *t = new Trie();
    t->insertword("abcd");
    cout<<"present or not "<<t->searchword("abcd")<<endl;

return 0;
}