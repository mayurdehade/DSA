/* Practical No: 2 -> Program to implement HashSet*/
/*
    1. Insert Element in Set
    2. Search Element in Set
    3. Delete Element in Set
    4. Union of Two Set
    5. Intersection of two sets
    6. Difference of two sets
*/

#include <iostream>
using namespace std;

int HT1[10];
int HT2[10];

int size = 10;

void init()
{
    for(int i=0; i<size; i++)
    {
        HT1[i] = 0;
        HT2[i] = 0;
    }
}

void display()
{
    int i;
    cout<<"\n\t Hash Table 01";
    cout<<"\n Index: \t";
    for (int i=0; i<size; i++)
    {
        cout<<i<<" ";
    }

    cout<<"\n Key: \t\t";
    for(int i =0; i<size; i++)
    {
        cout<<HT1[i]<<" ";
    }

    cout<<"\n\t Hash Table 02";
    cout<<"\n Index: \t";
    for(int i=0; i<size; i++)
    {
        cout<<i<<" ";
    }

    cout<<"\n Key: \t\t";
    for(int i=0; i<size; i++)
    {
        cout<<HT2[i]<<" ";
    }
}

void insert_A(int key)
{
    int index;
    index = key % size;
    HT1[index] = key;
    cout<<"\n\t Key "<<key<<" Inserted in Set-A";
}

void insert_B(int key)
{
    int index;
    index = key % size;
    HT2[index] = key;
    cout<<"\n\t Key "<<key<<" Inserted in Set-B";
}

void search_A(int key)
{
    int index;
    cout<<"\n Searching "<<key<<" in Set A";
    index = key % size;

    if(HT1[index] == key)
        cout<<"\n\t Key "<<key<<" found in bucket "<<index;
    else
        cout<<"\n\t Key "<<key<<" Not Found...!!!";
}

void search_B(int key)
{
    int index;
    cout<<"\n Searching "<<key<<" in Set B";
    index = key % size;

    if(HT2[index]==key)
        cout<<"\n\t Key "<<key<<" found in bucket "<<index;
    else cout<<"\n\t Key "<<key<<" Not Found...!!!";
}

void delete_A(int key)
{
    int index;
    cout<<"\n Deleting "<<key<<" from Set A";
    index = key % size;
    
    if(HT1[index]==key)
    {
        HT1[index] = 0;
        cout<<"\n\t Key "<<key<<" found in Bucket "<<index<<" and Deleted";
    }
    else
        cout<<"\n]t Key "<<key<<" Not Found...!!!";
}

void delete_B(int key)
{
    int index;
    cout<<"\n Deleting "<<key<<" from Set B";
    index = key % size;

    if(HT2[index]==key)
    {
        HT2[index] = 0;
        cout<<"\n\t Key "<<key<<" found in Bucket "<<index<<" and Deleted.";
    }
    else cout<<"\n\t Key "<<key<<" Not Found...!!!";
}

//find duplicated elements
int dup(int val)
{
    int i, dupl = 0;
    for(i=0; i<size; i++)
    {
        if(val==HT1[i])
        {
            dupl = 1;
        }
    }
    return dupl;
}

void unionAB()
{
    int i,j;
    int C[10];
    
    j=0;

    for(i=0; i<size; i++)
    {
        if(HT1[i]!=0)
        {
            C[j] = HT1[i];
            j++;
        }
    }

    for(i=0; i<size; i++)
    {
        if(HT2[i]!=0)
        {
            if(dup(HT2[i])==0)
            {
                C[j] = HT2[i];
                j++;
            }
        }
    }

    cout<<"\n\t Union of Set-A,B = {";
    for(i=0;i<j;i++)
        cout<<C[i]<<" , ";
        cout<<"}";
}


void intersection_AB()
{
    int i,j;
    int C[5];

    j=0;

    for(i=0;i<size;i++)
    {
        if(HT2[i]!=0)
        {
            if(dup(HT2[i])==1)
            {
                C[j] = HT2[i];
                j++;
            }
        }
    }

    cout<<"\n\t Intersection of Set-A,B = {";
    for(i=0;i<j;i++)
        cout<<C[i]<<" , ";
    cout<<"}";
}

void diff_AB()
{
    int i,j,k,flag;
    int C[5];
    k=0;

    for(i=0;i<size;i++)
    {
        flag=0;
        for(j=0;j<size;j++)
        {
            if(HT1[i]==HT2[j])
                flag = 1;
        }
        if(flag==0)
        {
            C[k] = HT1[i];
            k++;
        }
    }

    cout<<"\n\n\t Difference Set A-B = { ";
    for(i=0;i<k; i++)
        cout<<C[i]<<" , ";
    cout<<"}";
}

void diff_BA()
{
    int i,j,k,flag;
    
    int C[5];

    k=0;
    for(i=0; i<size;i++)
    {
        flag=0;
        for(j=0;j<size;j++)
        {
            if(HT2[i]==HT1[j])
                flag = 1;
        }
        if(flag == 0)
        {
            C[k] = HT2[i];
            k++;
        }
    }
    
    cout<<"\n\n\t Difference Set B-A = {";
    for(i=0; i<k; i++)
    {
        cout<<C[i]<<",";
    }
    cout<<"}";
}

int main()
{
    cout<<"A C++ Program to implement set an ADT using Hash Table"<<endl;

    cout<<"\n\n 1. Initializing Hash Tables"<<endl;

    init();
    display();

    cout<<"\n\n 2. Insert Keys in Hash Tables"<<endl;
    insert_A(1);
    insert_A(3);
    insert_A(5);
    insert_A(7);
    insert_A(9);

    insert_B(2);
    insert_B(3);
    insert_B(4);
    insert_B(6);
    insert_B(8);
    insert_B(10);

    display();

    //searching elements

    search_A(2);

    search_B(2);

    //Delete elements 
    delete_A(5);
    delete_B(6);

    unionAB();

    intersection_AB();

    display();

    diff_AB();
    diff_BA();

    return 0;
}