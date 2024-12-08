#include <iostream>
#include <fstream>
using namespace std;
string morsecode(char);
string tomorse(string &input);
string code[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---","-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",};
main() 
{
    string line;
    cout << "Enter a string: ";
    getline(cin,line);
    string output = tomorse(line);
    cout << "Morse Code: " << output << endl;
}
string morsecode(char a) 
{
    if (a>='a' && a<='z') 
    {
        a=a-('a'-'A');
    }
    if (a>='A' && a<='Z') 
    {
        return code[a-'A'];
    }
    if (a==' ') 
    {
        return "-.-.-.-";
    }
    else 
    {
    return "";
    }
}
string tomorse(string &line) 
{
    string result;
    for (int i = 0; line[i] != '\0'; i++) 
    {
        string morse = morsecode(line[i]);
        result += morse + " ";
    }
    return result;
}