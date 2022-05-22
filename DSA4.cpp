/*DSA Practical No. 4: Implementing Binray Search Tree*/

#include <iostream>
using namespace std;

//for finding the key
int level = 0;

struct Node{
    int data;
    struct Node *left, *right;
}*Root, *Parent;

//function to create root of BST
void create_BST(int val)
{
    //creating the object of the structure Node
    struct Node *Newnode; //Pointer Object

    Newnode = new struct Node; //memeory allocation

    Newnode->data = val;
    Newnode->left = NULL;
    Newnode->right = NULL;

    if(Root == NULL)
    {
        Root = Newnode;
        cout<<"\n\t Root "<<Root->data<<" of BST is Readu Now...!";
    }
    else{
        cout<<"\n\t Root already exitst!";
    }
}

//function to display BST in Preorder_BST (Data->Left->Right)
void Preorder_BST(struct Node *root)
{
    if(root != NULL)
    {
        cout<<" "<<root->data;
        Preorder_BST(root->left);
        Preorder_BST(root->right);
    }
}

//function to display BST in Inorder_BST (Left->Data->Root)
void Inorder_BST(struct Node *root)
{
    if(root != NULL)
    {
        Inorder_BST(root->left);
        cout<<" "<<root->data;
        Inorder_BST(root->right);
    }
}

//function to display BST in Postorder_BST (Left->Right->Data)
void Postorder_BST(struct Node *root)
{
    if(root != NULL)
    {
        Postorder_BST(root->left);
        Postorder_BST(root->right);
        cout<<" "<<root->data;
    }
}

//function to create new node
struct Node* create_Node(int val)
{
    struct Node *Newnode; //pointer variable
    Newnode = new struct Node; //allocate memory

    Newnode->data = val; //root
    Newnode->left = NULL;
    Newnode->right = NULL;

    return Newnode;
}

//function to insert new nodes in BST
void insert_BST(struct Node *current, struct Node *Newnode)
{
    if(current != NULL)
    {
        if(Newnode->data <= current->data)
        {
            if(current->left == NULL)
            {
                current->left = Newnode;
                cout<<"\n\nNewnode "<<Newnode->data<<" is inserted as left child of "<<current->data;
            }
            else{
                insert_BST(current->left,Newnode);
            }
        }
        else
        {
            if(current->right == NULL)
            {
                current->right = Newnode;
                cout<<"\n\nNewnode "<<Newnode->data<<" is inserted as right child of "<<current->data;
            }
            else
            {
                insert_BST(current->right, Newnode);
            }
        }
    }
}

//function for searching node
void search_Node(struct Node *root, int Key)
{
    if(root != NULL)
    {
        if(Key == root->data)
        {
            cout<<"\n\t Key is found on level "<<level;
        }
        else if(Key < root->data)
        {
            level++;
            search_Node(root->left, Key);
        }
        else
        {
            level++;
            search_Node(root->right, Key);
        }
    }
    else{
        cout<<"\n\t Key not found!";
    }
}

//function for finding min value
void Min_Node()
{
    struct Node *p;
    p = Root;
    
    while(p->left != NULL)
        p = p->left;

    cout<<"\n\n Min Node/Value: "<<p->data;
}

//function for finding max value
void Max_Node()
{
    struct Node *p;
    p = Root;

    while(p->right != NULL)
        p = p->right;

    cout<<"\n\n Max Node/Value: "<<p->data;
}


//finding the minValueNode from subtree
struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
    /*Loop down to find the leftmost leaf*/
    current = current->left;
    return current;
}

//function for deletion of node
struct Node* delete_Node(struct Node *root, int Key)
{
    //base case
    if(root == NULL)
        return root;
    
    //If the key to be deleted is smaller than the root's
    else if(Key<root->data)
        root->left = delete_Node(root->left, Key);

    //If the key to be deleted is greater than the root's
    else if(Key>root->data)
        root->right = delete_Node(root->right, Key);

    //If the key to be delteled is same as root
    else{
        //node has no child
        if(root->left == NULL and root->right == NULL)
            return NULL;
        
        //node with only one child or no child
        else if(root->left == NULL)
        {
            struct Node* temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == NULL)
        {
            struct Node* temp = root->left;
            delete root;
            return temp;
        }

        //node with two children: Get the inorder successor
        //(smallest in the right substree)
        struct Node* temp = minValueNode(root->right);

        //copy the inorder sucessor's content to this node
        root->data = temp->data;

        //delete the inorder successor
        root->right = delete_Node(root->right, temp->data);
    }

}


//main function
int main()
{
    cout<<"\n\t Binrary search Tree and it's Operations ";
    struct Node *Newnode;
    int Key;

    Root = NULL;
    cout<<"\n\n1. Creating BST...";
    create_BST(25);
    cout<<"\n\n2.Inserting New Nodes in BST...";
    
    Newnode = create_Node(10);
    insert_BST(Root, Newnode);
    
    Newnode = create_Node(22);
    insert_BST(Root, Newnode);

    Newnode = create_Node(110);
    insert_BST(Root, Newnode);

    Newnode = create_Node(30);
    insert_BST(Root, Newnode);

    Newnode = create_Node(1);
    insert_BST(Root, Newnode);

    Newnode = create_Node(3);
    insert_BST(Root, Newnode);

    cout<<"\n\n3. Display/Traversing BST....";
    cout<<"\n\n Preorder Traversal: ";
    Preorder_BST(Root);

    cout<<"\n\n Inorder Traversal: ";
    Inorder_BST(Root);

    cout<<"\n\n Postorder Traversal: ";
    Postorder_BST(Root);

    cout<<"\n\n4. Search a Key in BST....";
    cout<<"\n\tEnter the Key to Search: ";
    cin>>Key;

    search_Node(Root,Key);

    cout<<"\n\n5. Find Min/Max Node in BST....";
    Min_Node();
    Max_Node();

    cout<<"\n\n6. Delete a Key for BST...";
    Root = delete_Node(Root, 30);
    cout<<"\n\nAfter deleting 30 Inorder Traversal: ";
    Inorder_BST(Root);

    Root = delete_Node(Root, 212);
    cout<<"\n\nAfter deleting 22 Inorder Traversal: ";
    Inorder_BST(Root);

    return 0;
}