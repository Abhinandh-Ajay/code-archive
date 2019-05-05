#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char states[20][20],str[20];
int s=0;

void r_plus(char a,char b)
{
    states[s][s+1] = 'E';
    states[s][s+3] = 'E';
    states[s+1][s+2] = a;
    states[s+3][s+4] = b;
    states[s+2][s+5] = 'E';
    states[s+3][s+5] = 'E';
    s = s + 5;
}
void r_star(char a)
{
    states[s][s+1] = a;
    states[s][s+2] = 'E';
    states[s+1][s] = 'E';
    s = s + 2;
}
void r_dot(char a)
{
    states[s][s+1] = a;
    s = s + 1;
    cout<<"Dot";
}
void display()
{
    int i,j;
    cout<<"--------------------\n";
    cout<<"  ";
    for(i=0;i<s;i++)
    {
        cout<<i+1<<" ";
    }
    cout<<endl;
    for(i=0;i<s;i++)
    {
        cout<<i+1<<" ";
        for(j=0;j<s;j++)
        {
            cout<<states[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int i,j;
    cout<<"Enter a regular expression\n";
    cin>>str;
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            states[i][j]=' ';
        }
    }
    for(i=0;i<strlen(str);i++)
    {
        if ((isalpha(str[i]) && isalpha(str[i+1])) || (isalpha(str[i]) && str[i+1]=='\0'))
        {
            r_dot(str[i]);
        }
        else if (str[i]=='+')
        {
            r_plus(str[i-1],str[i+1]);
            i++;
        }
        else if (str[i]=='*')
        {
            r_star(str[i-1]);
        }
        else
        {

        }
    }
    s++;
    display();
}
