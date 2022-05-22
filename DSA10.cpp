/* 
Practical No. 10 -> 
a] Created BST and display, 
b] convert BST to MAX heap Tree and display
c] Display Maximum Marks.
*/

#include <iostream>
using namespace std;

struct Node{
    int marks;
    struct Node *left;
    struct Node *right;
} *root;

struct Node* createNode()
{
    struct Node *temp;
    temp = new struct Node;

    cout<<"\n\t Enter Marks: ";
    cin>>temp->marks;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void create_BST()
{
    if(root == NULL)
    {
        root = createNode();
        cout<<"\n\t Root of BST Tree is Created";
    }
}

void insert(struct Node *Root, struct Node *newnode)
{
    if(newnode->marks < Root->marks)
    {
        if(Root->left == NULL)
            Root->left = newnode;
        else
            insert(Root->left, newnode);
    }
    else{
        if(Root->right == NULL)
            Root->right = newnode;
        else
            insert(Root->right, newnode);
    }
}

void preorder(struct Node *Root)
{
    if(Root!=NULL)
    {
        cout<<" "<<Root->marks;
        preorder(Root->left);
        preorder(Root->right);
    }
}

void MaxHeapify(struct Node *Parent)
{
    int val;
    val = Parent->right->marks;
    Parent->right->marks = Parent->marks;
    Parent->marks = val;
}

int main()
{
    int cnt, i, j;
    struct Node *newnode;

    cout<<"\n\nCreate and Display MAX Heap Tree";
    root = NULL;
    i = j = 0;
    create_BST(); 

    cout<<"\n\n How many nodes to insert? : "; 
    cin>>cnt;
    
    for(i=0; i<cnt; i++)
    {
    newnode = createNode(); 
    insert(root , newnode);
    }

    cout<<"\n\n Preorder Traversal: ";
    preorder(root);

    MaxHeapify(root);
    MaxHeapify(root->left);
    MaxHeapify(root->right);
    MaxHeapify(root);

    cout<<"\n\n After Heapifying BST.........";
    cout<<"\n\n Max Heap Tree Preorder Traversal: ";
    preorder(root);
    cout<<"\n\n Maximum Marks: "<<root->marks;
    cout<<"\n\n";

    return 0;
}