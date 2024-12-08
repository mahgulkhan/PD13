#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void display(string);
void read(string &alpha);
fstream file;

int main()
{
    string alpha;
    display(alpha);
}
void read(string &alpha)
{
    string record;
    fstream text;
    text.open("alphabets.txt",ios:: in );
    getline(text,record);
    alpha = record;
    text.close();
}
void display(string alpha)
{
    read(alpha);
    string notpresent;
    bool present[26]= {false};
        for (int x = 0; alpha[x] !='\0'; x++)
        {
            char a=alpha[x];
            if (a>='a' && a<='z')
            {
                present[a-'a']=true;
            } 
        }
        for (int i = 0; i < 26; i++)
        {
            if (!present[i])
            {
                notpresent += char('a'+i);
            } 
        }
    fstream text;
    text.open("alphabets.txt",ios:: app);
    text << "\n" << notpresent;
    text.close();
}