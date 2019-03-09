/*
Binary Search Tree(BST) full code.
Inorder,preorder,postorder and searching all topics are in one code.
code written by : GM_Sompod Date : 09-03-2019
*/
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
node* Insert_Data(node* root,int data); // function prototype
node* MakeNewNode(int data); // function prototype
bool SearchBST(node* root,int value); // function prototype
void InorderShow(node* root); // function prototype
void PreorderShow(node* root); // function prototype
void PostorderShow(node* root); // function prototype
int main()
{
    node* root;
    root = NULL;
    root = Insert_Data(root,15);
    root = Insert_Data(root,10);
    root = Insert_Data(root,20);
    root = Insert_Data(root,8);
    root = Insert_Data(root,12);
    root = Insert_Data(root,17);
    root = Insert_Data(root,25);
    cout << "Inorder Tree's data are : " << endl;
    InorderShow(root);
    cout<<endl;
    cout << "PreorderShow Tree's data are : " << endl;
    PreorderShow(root);
    cout<<endl;
    cout << "PostorderShow Tree's data are : " << endl;
    PostorderShow(root);
    cout<<endl;
    int value;
    cout << endl << "Input a value for search from tree : ";
    cin >> value;

    bool x = SearchBST(root,value);
    if(x == true)
    {
        cout << "The value "<<value<< " is Found" <<endl;
    }
    else
    {
        cout << "The value "<<value<< " is Not Found" << endl;
    }
    return 0;
}

node* Insert_Data(node* root,int data)   // this function for insert new value into tree
{

    if(root == NULL)
    {
        return MakeNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert_Data(root->left,data);
    }
    else
    {
        root->right = Insert_Data(root->right,data);
    }
    return root;

}
node* MakeNewNode(int data) // this function for create new function
{
    node* newnode = new node();
    newnode -> data = data;
    newnode -> left = newnode -> right = NULL;
    return newnode;
}

bool SearchBST(node* root,int value) // this function for search value from tree
{
    if(root == NULL) return false;
    else if(root->data == value) return true;
    else if(value <= root->data) return SearchBST(root->left,value);
    else return SearchBST(root->right,value);
}

void InorderShow(node* root){ // This function are use for show the tree data Inorderly
    if(root != NULL)
    {
        InorderShow(root->left);
        cout << root->data << " ";
        InorderShow(root->right);
    }
}

void PreorderShow(node* root) // This function are use for show the tree data Preorderly
{
    if(root != NULL)
    {
        cout << root->data << " ";
        PreorderShow(root->left);
        PreorderShow(root->right);
    }
}

void PostorderShow(node* root) // This function are use for show the tree data Postorderly
{
    if(root != NULL)
    {
        PostorderShow(root->left);
        PostorderShow(root->right);
        cout << root->data << " ";

    }
}
