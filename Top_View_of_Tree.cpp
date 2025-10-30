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

int height(Node* root){
    if (root == NULL)
    {
        return 0;
    }
    
    int leftHT = height(root->left);
    int rightHT = height(root->right);

    int currHT = max(leftHT, rightHT) +1;
    return currHT; 
}


int diameter1(Node* root){
    if (root == NULL)
    {
        return 0;
    }
    
    int currDM = height(root->left) + height(root->left) +1;
    int leftDM = diameter1(root->left);
    int rightDM = diameter1(root->right);

    int diameter = max(currDM , max(leftDM , rightDM)) ;
    return diameter; 
}

pair<int, int> diameter2(Node* root){
    if (root == NULL)
    {
        return make_pair(0,0);
    }
    
    // < diameter, height>
    pair<int, int> leftInfo = diameter2(root->left);
    pair<int, int> rightInfo = diameter2(root->right);

    int currDia = leftInfo.second +rightInfo.second +1;
    int finalDia = max(currDia, max(leftInfo.first, rightInfo.first));
    int finalHT = max(leftInfo.second, rightInfo.second) +1;

    return make_pair(finalDia, finalHT);
}

bool isIdentical(Node* root1, Node* root2){
      if (root1 == NULL && root2 == NULL)
    {
        return true;
    } 
    else if (root1== NULL || root2 == NULL)
    {
        return false;
    }

    if (root1->data != root2->data)
    {
        return false;
    }
    
    return isIdentical(root1->left, root2->left) &&
            isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* Subroot){
    if (root == NULL && Subroot == NULL)
    {
        return true;
    } 
    else if (root== NULL || Subroot == NULL)
    {
        return false;
    }
    
    
    if (root->data == Subroot->data)
    {
        // identical for subtrees
        if(isIdentical(root, Subroot)){
            return true;
        }
    }

    int isLeftSubtree = isSubtree(root->left, Subroot);

    if (!isLeftSubtree){
        return isSubtree(root->right, Subroot);
    }

    return true;
        
}

void topView(Node* root){
    queue<pair<Node*, int>> Q;  //(node, HD)
    map<int, int> m;   // <HD, node->data>

    Q.push(make_pair(root, 0));
    while (!Q.empty())
    {
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if (m.count(currHD) == 0)    // HD -> add in map
        {
            m[currHD] = currNode->data;
        }
        
        if (currNode->left != NULL)
        {
            pair<Node*, int> left = make_pair(currNode->left, currHD-1);
            Q.push(left);
        }
        
        if (currNode->right != NULL)
        {
            pair<Node*, int> right = make_pair(currNode->right, currHD+1);
            Q.push(right);
        }
    }
    

    for(auto it : m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    topView(root);

    return 0;
} 