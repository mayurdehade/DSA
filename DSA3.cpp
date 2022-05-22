/* Practical No: 03 -> Program to implement General Tree. */

#include <iostream>
using namespace std;

struct Node
{
    char name[25];
    struct Node *link1;
    struct Node *link2;
    struct Node *link3;
}*Root, *Ch;

void create_tree()
{
    struct Node *temp;
    temp = new struct Node; 

    cout<<"Enter Book Name: ";
    cin>>temp->name;
    temp->link1 = NULL;
    temp->link2 = NULL;
    temp->link3 = NULL;

    if(Root == NULL)
        Root = temp;
}

void display()
{
    if(Root)
        cout<<"\n\n Book Name: "<<Root->name;
    
    Ch = Root->link1;
    if(Ch)
    {
        cout<<"\n\n Chapter 01: "<<Ch->name;
        if(Ch->link1)
            cout<<"\n\t Section 01: "<<Ch->link1->name;
        if(Ch->link2)
            cout<<"\n\t Section 02: "<<Ch->link2->name;
        if(Ch->link3)
            cout<<"\n\t Section 03: "<<Ch->link3->name;
    }

    Ch = Root->link2; 
    if(Ch)
    {
        cout<<"\n\n Chapter 02: "<<Ch->name;
        if(Ch->link1)
            cout<<"\n\t Section 01: "<<Ch->link1->name;
        if(Ch->link2)
            cout<<"\n\t Section 02: "<<Ch->link2->name;
        if(Ch->link3)
            cout<<"\n\t Section 03: "<<Ch->link3->name;
    }

    Ch = Root->link3;
    if(Ch)
    {
        cout<<"\n\n Chapter 03: "<<Ch->name;
        if(Ch->link1)
            cout<<"\n\t Section 01: "<<Ch->link1->name;
        if(Ch->link2)
            cout<<"\n\t Section 02: "<<Ch->link2->name;
        if(Ch->link3)
            cout<<"\n\t Section 03: "<<Ch->link3->name;
    }
}

void insert_Chapter()
{
    struct Node *temp;
    temp = new struct Node;

    cout<<"\n\t Enter Chapter Name: ";
    cin>>temp->name;
    temp->link1 = NULL;
    temp->link2 = NULL;
    temp->link3 = NULL;

    if(Root->link1 == NULL)
        Root->link1 = temp;
    else if(Root->link2 == NULL)
        Root->link2 = temp;
    else if(Root->link3 == NULL)
        Root->link3 = temp;
    else 
        cout<<"\n No More Chapter can be added..!!!";
}

void insert_Sec()
{
    struct Node *temp;
    temp = new struct Node;

    cout<<"\n\t Enter Section Name: ";
    cin>>temp->name;
    temp->link1 = NULL;
    temp->link2 = NULL;
    temp->link3 = NULL;

    if(Ch->link1 == NULL)
        Ch->link1 = temp;
    else if(Ch->link2 == NULL)
        Ch->link2 = temp;
    else if(Ch->link3 == NULL)
        Ch->link3 = temp;
    else cout<<"\n No More Section can be added.";
}

void insert_Section()
{
    int chap;
    cout<<"\n\n Enter Section of Chapter(1/2/3): ";
    cin>>chap;

    switch(chap)
    {
        case 1: Ch = Root->link1;
            insert_Sec();
            insert_Sec();
            break;
        case 2: Ch = Root->link2;
            insert_Sec();
            insert_Sec();
            break;
        case 3: Ch = Root->link3;
            insert_Sec();
            insert_Sec();
    }
}

int main()
{
    Root = NULL;
    create_tree();

    insert_Chapter();
    insert_Chapter();
    insert_Chapter();

    insert_Section();
    insert_Section();
    insert_Section();

    display();

    return 0;
}