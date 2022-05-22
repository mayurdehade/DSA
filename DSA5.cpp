/*  Practical N0. 5 -> Program to create and display and expression tree*/
#include <iostream>
using namespace std;

char postfix[10];

struct Node{
    char data;
    struct Node *left;
    struct Node *right;
} *Root;

struct Node* stack[10];
int top = -1;

void push_stk(struct Node *newnode)
{
    top++;
    stack[top] = newnode;
}

struct Node* pop_stk()
{
    struct Node *temp;
    temp = stack[top];
    top--;

    return temp;
}

struct Node* create_Node(char val)
{
    struct Node *Newnode;

    Newnode = new struct Node;

    Newnode->data = val;
    Newnode->left = NULL;
    Newnode->right = NULL;

    return Newnode;
}

void create_Exptree()
{
    int i;
    struct Node *Newnode;
    cout<<"\n\n Enter the Postfix Expression: ";
    cin>>postfix;

    for(i=0; postfix[i] != '\0'; i++)
    {
        if(postfix[i] == 'a' || postfix[i] == 'b' || postfix[i] == 'c' || postfix[i] == 'd')
        {
            Newnode = create_Node(postfix[i]);
            push_stk(Newnode);
        }

        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            Newnode = create_Node(postfix[i]);
            Newnode->right = pop_stk();
            Newnode->left = pop_stk();
            push_stk(Newnode);
        }
    }

    if(Root == NULL)
    {
        Root = pop_stk();
        cout<<"\n\t Expression Tree is Ready Now...!!!";
    }
}

void preorder_ExpTree(struct Node *root)
{
    if(root)
    {
        cout<<" "<<root->data;
        preorder_ExpTree(root->left);
        preorder_ExpTree(root->right);
    }
}

void inorder_ExpTree(struct Node *root)
{
    if(root)
    {
        inorder_ExpTree(root->left);
        cout<<" "<<root->data;
        inorder_ExpTree(root->right);
    }
}

void postorder_ExpTree(struct Node *root)
{
    if(root)
    {
        postorder_ExpTree(root->left);
        postorder_ExpTree(root->right);
        cout<<" "<<root->data;
    }
}

int main()
{
    Root = NULL;
    create_Exptree();

    cout<<"\nPreorder Traversal of Expression Tree: ";
    preorder_ExpTree(Root);

    cout<<"\nInorder Traversal of Expression Tree: ";
    inorder_ExpTree(Root);

    cout<<"\nPostorder Traversal of Expression Tree: ";
    postorder_ExpTree(Root);

    return 0;
}