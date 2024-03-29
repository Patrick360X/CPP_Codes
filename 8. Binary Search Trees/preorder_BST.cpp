#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* construct_BST(int preorder[], int* preorderIdx, int key, int min, int max, int n) {

    if (*preorderIdx >= n)                              // T.C of this constructBST function will be O(n)
    {
        return NULL;
    }

    Node* root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n)
        {
            root->left = construct_BST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if(*preorderIdx < n)
        {
            root->right = construct_BST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }
    
    return root;
}

void printPreorder(Node* root) {
    if (root == NULL)
    {
        return;
    }
    
    cout<<root->data<< " ";
    printPreorder(root->left);
    printPreorder(root->right);

}

int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;
    Node* root = construct_BST(preorder, &preorderIdx, preorder[0], INT16_MIN, INT16_MAX, n);
    printPreorder(root);

    return 0;
}
