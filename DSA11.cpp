/* DSA Practical No. 11 -> Sequential Access File Handling */

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fout;

    cout<<"\n\tSequential File Handling Operation";
    cout<<"\n\nOpening file for writing";

    fout.open("abc.txt", ios::out);

    if(!fout){
        cout<<"\nThere is an error opening the file";

    }
    else{
        cout<<"\n\nFile opened successfully!";
        cout<<"\n\nWriting the data into file";
        cout<<"\n\nline 1: Hi My name is Mayur Dehade.";
        fout<<"Hi My name is Mayur Dehade";
        cout<<"\n\nline 2: I am the second year computer engineering student.";
        fout<<"\nI am the second year computer engineering student.";
        cout<<"\n\nline 3: Hey how are You?";
        fout<<"\nHey how are You?";
    }

    //closing the file
    fout.close();

    fstream fin;

    fin.open("abc.txt", ios::in);

    char temp[100];

    if(!fin){
        cout<<"\n\nThere is an error in opening the file.";
    }
    else{
        cout<<"\n\nFile opened successfuly for reading.";
        cout<<"\n\nReading data from file";
        fin.getline(temp, 100);
        cout<<"\n\n"<<temp;
        fin.getline(temp,100);
        cout<<"\n\n"<<temp;
        fin.getline(temp,100);
        cout<<"\n\n"<<temp;
    }

    fin.close();
    return 0; 

}