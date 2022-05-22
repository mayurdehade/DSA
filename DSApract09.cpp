#include <iostream>
using namespace std;

struct HBTNode
{
    int Key;
    char Mean[10];

    HBTNode *left;
    HBTNode *right;
}*Root;

void create_HBT()
{
    int i;
    int nodes;
    int done;
    struct HBTNode *Newnode, *current;

    cout<<"\n\n Enter the no of nodes to insert in HBT.? : ";
    cin>>nodes;

    for(i=0; i<nodes; i++)
    {
        Newnode = new struct HBTNode; //...Memory Allocation

        cout<<"\n\t Enter Keyword: "; //...store Keys
        cin>>Newnode->Key;
        cout<<"\n\t Enter Meaning: "; //...store Meanings
        cin>>Newnode->Mean;
        Newnode->left = NULL; //...Left and Right pointers initially NULL
        Newnode->right = NULL;

        if(Root == NULL)
        {
            Root = Newnode;
        }
        else
        {
            done = 0;
            current = Root;

            while(!done)
            {
                if(Newnode->Key < current->Key)
                {
                    if(current->left == NULL)
                    {
                        current->left = Newnode;
                        done = 1;
                    }
                    else
                        current = current->left;
                }
                else
                {
                    if(current->right == NULL)
                    {
                        current->right = Newnode;
                        done = 1;
                    }
                    else
                        current = current->right;
                }
            }

        }

    }

}


void display_HBT(struct HBTNode *root)
{
    if(root) 
    {
        cout<<"\n\t"<<root->Key<<" - "<<root->Mean; 
        display_HBT(root->left); 
        display_HBT(root->right); 
    }
}



void Sorted_List(struct HBTNode *root)
{
    if(root) 
    {
        Sorted_List(root->left); 
        cout<<"\n\t"<<root->Key<<" - "<<root->Mean; 
        Sorted_List(root->right); 
    }
}


void Find_Keyword(int key)
{
    int comp = 0;
    int level = 0;
    int done;
    struct HBTNode *current;

    done = 0;
    current = Root;
    while(!done)
    {
        if(key < current->Key)
        {
            current = current->left;
            level++;
            comp++;
        }
        else if(key > current->Key)
        {
            current = current->right;
            level++;
            comp++;
        }
        else
        {
            done = 1;
            comp++;
            cout<<"\n\t Key : "<<key;
            cout<<"\n\t Found at Level: "<<level;
            cout<<"\n\t No. of Comparisons: "<<comp;
        }

    }

}

int main()
{
    cout<<"\n -------***A C++ Program to Implement Dictionary using Height-Balanced Tree.***-------\n";

    cout<<"\n 1. Store Keywords and Meanings in Height-Balanced Tree.";
    Root = NULL;
    create_HBT();

    cout<<"\n 2. Display Keywords and Meanings in Height-Balanced Tree.";
    cout<<"\n Keyword - Meaning";
    display_HBT(Root);

    cout<<"\n 3. Display a Sorted List of Keywords and Meanings.";
    cout<<"\n Keyword - Meaning";
    Sorted_List(Root);

    cout<<"\n 4. Display Number of Comparisons required to find a keyword.";
    Find_Keyword(1);
    return 0;
}
