#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode{
  public:
      char data;
      TrieNode* children[26];
      bool isTerminal;
      TrieNode(char ch){
           data=ch;
            for(int i=0; i<26; i++){
                children[i]=NULL;
            }
            isTerminal=false;
      }
};


class Trie{
  public:
  TrieNode* root;
   Trie(){
        root=new TrieNode('\0');
   }

   void insertwordutil(TrieNode* root, string word){
        if(word.length()==0){
          root->isTerminal=true;
          return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
          child=root->children[index];
        }
        else{
          child=new TrieNode(word[0]);
          root->children[index]=child;

        }
        insertwordutil(child, word.substr(1));
   }

   void insertword(string word){
       insertwordutil(root,word);
   }
  
};

int main() {
    
    Trie t;
    t.insertword("hello");
    t.insertword("world");
    t.insertword("hi"); 
    return 0;
}