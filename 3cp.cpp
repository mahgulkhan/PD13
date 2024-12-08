#include <iostream>
#include <fstream>
using namespace std;
string field(string,int);
void read(int &index,int age[],string name[]);
fstream file;

int main()
{
    int index =0;
    string name[100];
    int age[100];
    read(index,age,name);
}
string field(string record, int fields)
{
    int count=1;
    string item;
    for (int i = 0; i < record.length(); i++)
    {
        if (record[i]==',')
        {
            count++;
        }
        else if (count == fields)
        {
            item += record[i];
        } 
    } 
    return item; 
}
void read(int &index,int age[],string name[])
{
    string record;
    fstream text;
    text.open("text.txt",ios:: in );
    while (!(text.eof()))
    {
        getline(text,record);
        name[index]=field(record,1);
        age[index]=stoi(field(record,2));
        index=index+1;
    }
    fstream cake;
    cake.open("cake.txt",ios::out);

    for (int i = 0; i < index; i++)
    {
        if (age[i]%2==0)
        {
            cake << "##############" <<endl;
            cake << "# " << age[i] << " HB " << name[i] << "! " << age[i] <<" #" <<endl;
            cake << "##############" <<endl;
        }
        else
        {
            cake << "**************" <<endl;
            cake << "* " << age[i] << " HB " << name[i] << "! " << age[i] <<" *" <<endl;
            cake << "**************" <<endl;
        }   
    }
    cake.close();
}
