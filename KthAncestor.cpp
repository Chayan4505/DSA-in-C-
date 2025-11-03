#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx++;

    if (nodes[idx] == -1)
    {
        return NULL;
    }
    

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}


Node* LCA2(Node* root, int n1, int n2){

    if (root == NULL)
    {
        return NULL;
    }
    

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);
    
    if (leftLCA != NULL && rightLCA != NULL)
    {
        return root;
    }
    
    return leftLCA == NULL ? rightLCA : leftLCA;

}

int distance(Node* root, int n){
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == n)
    {
        return 0;
    }
    
    int leftDist = distance(root->left, n);
    if (leftDist != -1)
    {
        return leftDist+1;
    }
    int rightDist = distance(root->right, n);
    if (rightDist != -1)
    {
        return rightDist+1;
    }    

    return -1;
}

int minDist(Node* root, int n1, int n2){
    Node* lca = LCA2(root, n1, n2);

    int dist1 = distance(lca, n1);
    int dist2 = distance(lca, n2);

    return dist1 + dist2;
}

int KthAncestor(Node* root, int node, int k){
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == node)
    {
        return 0;
    }
    
    int leftDist = KthAncestor(root->left, node, k);
    int rightDist = KthAncestor(root->right, node, k);

    if (leftDist == -1 && rightDist == -1)
    {
        return -1;
    }
    
    int validVal = leftDist == -1 ? rightDist : leftDist;
    if (validVal + 1 == k )
    {
        cout<<" Kth Ancestor : "<<root->data<<endl;
    }
    
    return validVal + 1;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    int node = 5 , k = 2;
    KthAncestor(root, node, k);

    return 0;
} 