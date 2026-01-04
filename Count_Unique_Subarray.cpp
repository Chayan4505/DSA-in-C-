#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
  public:
    unordered_map<char, Node*> children;
    bool endofWord;
    int freq;
    
    Node(){
        endofWord = false;
    }
};

class Trie{
    Node* root;
  public:
    Trie(){
        root = new Node();
        root->freq = -1;
    }  

    void insert(string key){
        Node* temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq = 1;
            }
            else {
                temp->children[key[i]]->freq++;
            }
            temp = temp->children[key[i]];
        }
        temp->endofWord = true;
    }

    int countHelper(Node* root){
        int ans = 0;

        for(pair<char, Node*> child : root->children){
            ans += countHelper(child.second);
        }
        return ans + 1;
    }

    int countNodes(){
        return countHelper(root);
    }
};

int countUniqueSunstr(string str){
    Trie trie;

    for (int i = 0; i < str.size(); i++)
    {
        string suffix = str.substr(i);
        trie.insert(suffix);
    }
    return trie.countNodes();
}


int main(){
    string str= "ababa";
    string str2= "abc";

    cout<<countUniqueSunstr(str)<<endl;
    cout<<countUniqueSunstr(str2)<<endl;
    
    return 0;
}
