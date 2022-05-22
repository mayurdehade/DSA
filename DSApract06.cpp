#include <iostream>
using namespace std;

int adjMtx[4][4];
int Row = 4;
int Col = 4;
struct Node
{
    char data;
    struct Node *down, *next;
}*Head;


char vertex(int val)
{
    if(val == 0)
    return 'A';
    else if(val == 1)
    return 'B';
    else if(val == 2)
    return 'C';
    else
    return 'D';
}

void create_adjMtx()
{
    int i, j;

    for(i=0; i<Row; i++)
    {
        for(j=0; j<Col; j++)
        {
            cout<<"\n Is Edge from vertex "<<vertex(i)<<" to "<<vertex(j)<<" ? : ";
            cin>>adjMtx[i][j];
        }
    }
}

void display_adjMtx()
{
    int i, j;

    for(i=0; i<Row; i++)
    {
        cout<<"\n";
        for(j=0; j<Col; j++)
        {
            cout<<"\t"<<adjMtx[i][j];
        }
    }
}

void create_adjList()
{
    struct Node *Newnode, *move, *p;
    int i;
    int nodes;
    int edges;

    cout<<"\n\n How many Vertices in Graph: ";
    cin>>nodes;

    for(i=0; i<nodes; i++)
    {
        Newnode = new struct Node;

        Newnode->data = vertex(i);
        Newnode->down = NULL;
        Newnode->next = NULL;

        if(Head == NULL)
        {
            Head = Newnode;
            move = Head;
        }
        else
        {
            move->down = Newnode;
            move = move->down;
        }

    }

    move = Head;
    p = Head;
    while(move != NULL)
    {
        cout<<"\n How many adjacent vertices for "<<move->data<<" : ";
        cin>>edges;

        for(i=0; i<edges; i++)
        {
            Newnode = new struct Node;

            cout<<"\n\t Enter An Adjacent Vertex: ";
            cin>>Newnode->data;
            Newnode->down = NULL;
            Newnode->next = NULL;

            p->next = Newnode;
            p = p->next;
        }

        move = move->down;
        p = move;
    }

}

void display_adjList()
{
    struct Node *move, *p;

    move = Head;

    while(move != NULL)
    {
        cout<<"\n\t | "<<move->data<<" |--> ";
        p = move->next;
        while(p != NULL)
        {
            cout<<p->data<<" --> ";
            p = p->next;
        }
        cout<<"NULL";

        move = move->down;
        p = move;
    }
}

int main()
{
    cout<<"\n\n A C++ Program to Represent Graph Data Structure using Adjacency Matrixand List.";

    cout<<"\n\n 1. Creating Adjacency Matrix.........";
    create_adjMtx();

    cout<<"\n\n 2. Display Adjacency Matrix.........";
    display_adjMtx();

    cout<<"\n\n 3. Create Adjacency List.........";
    Head = NULL;
    create_adjList();

    cout<<"\n\n 4. Display Adjacency List.........";
    display_adjList();

    return 0;
}
