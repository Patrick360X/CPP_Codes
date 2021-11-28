#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
    
    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

int search(int inOrder[], int start, int end, int curr) {
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == curr)
        {
            return i;
        }
        
    }
    return -1;
}

Node* buildTree(int preOrder[], int inOrder[], int start, int end){
    static int idx = 0;

    if (start > end)
    {
        return NULL;
    }

    int curr = preOrder[idx];
    idx++;
    Node* node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(inOrder, start, end , curr);           // curr will store the position of root node
    node->left = buildTree(preOrder, inOrder, start, pos-1);// & to the left of it will be left subtree 
    node->right = buildTree(preOrder, inOrder, pos+1, end); // & to the right will be its right subtree

    return node;
}

void inOrderPrint(Node* root) {

    if(root == NULL) {
        return;
    }

    inOrderPrint(root->left);
    cout<< root->data<<" ";
    inOrderPrint(root->right);
}

int main()
{
    int preOrder[] = {1,2,4,3,5};
    int inOrder[] = {4,2,1,5,3};

    //build tree
    Node* root = buildTree(preOrder, inOrder, 0, 4);
    inOrderPrint(root);

    return 0;
}
