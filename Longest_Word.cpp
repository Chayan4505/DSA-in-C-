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

    void longestHelper(Node* root, string &ans, string temp){

        for(pair<char, Node*> child : root->children){
            if (child.second->endofWord)
            {
                temp += child.first;

            if ((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size()))
            {
                ans = temp;
            }
            longestHelper(child.second, ans, temp);
            temp = temp.substr(0, temp.size() -1);
            }
            
        }
    }

    string longestStrWithEOW(){
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }

};

string longestWord(vector<string> dict){
    Trie trie;

    for (int i = 0; i < dict.size(); i++)
    {
        trie.insert(dict[i]);
    }
    
    return trie.longestStrWithEOW() ;
}

int main(){
    vector<string> dict = {"a", "banana", "app", "appl","ap", "apply", "apple"};
    cout<<longestWord(dict)<<endl;
    
    return 0;
}
