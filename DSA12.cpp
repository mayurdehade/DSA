/*DSA Practical No. 12 -> Program to implement Random/Direct Access files. */

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    cout<<"\n\t Program to implement Random/Direct Access Files ";

    //creating the object of the ofstream for writing data into file
    ofstream fout;

    fout.open("first.txt", ios::out);
    cout<<"\nWriting into the file";

    cout<<"\nLocation: "<<fout.tellp(); 
    //give current location of put pointer
    
    cout<<"\nLine 01: Hi, My name is Mayur Dehade";
    fout<<"Hi, My name is Mayur Dehade";

    cout<<"\nLocation: "<<fout.tellp();
    cout<<"\nLine 02: I am the second year computer engineering student";
    fout<<"\nI am the second year computer engineering student";

    cout<<"\nLocation: "<<fout.tellp();
    cout<<"\nLine 03: Would you like to be my Friend..?";
    fout<<"\nWould you like to be my Friend..?";

    cout<<"\nLocation: "<<fout.tellp();

    //closing the file
    fout.close();

    //opening the file for input (Reading the data)
    ifstream fin;

    fin.open("first.txt", ios::in);
    cout<<"\nReading the data from file";

    //getting location of get pointer
    cout<<"\nLocation: "<<fin.tellg();
    cout<<"\nShift control to...";

    //changing the position of the get pointer
    fin.seekg(78, ios::beg); 
    //change the location of the pointer 20 from beginning

    cout<<"\nLocation: "<<fin.tellg();

    cout<<"\nReading the data....\n";

    char c[100];

    while(!fin.eof())
    {
        fin.getline(c, 100);
        cout<<c;
    }

    return 0;

}