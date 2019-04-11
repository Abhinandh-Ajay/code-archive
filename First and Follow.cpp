#include <iostream>
#include <string.h>
using namespace std;
char pr[20][20],fi[20];
int fic=0;
void traversal(char s,int j,int n);
void findFirst(char s,int i,int n)
{
    int flag=1,j;
    if(!isupper(pr[i][3]))
    {
        for(j=0;j<fic;j++)
        {
            if(fi[j]==pr[i][3])
            flag=0;
        }
        if (flag==1)
        {
            fi[fic++]=pr[i][3];
        }
    }
    else
    {
        traversal(s,i,n);
    }
}
void traversal(char s,int j,int n)
{
    int i;
    for(i=j+1;i<n;i++)
    {
        if(pr[j][3]==pr[i][0])
        {
            if(!isupper(pr[i][3]))
            {
                findFirst(s,i,n);
            }
            else
            {
                traversal(s,i,n);
            }
        }
    }
}
int main()
{
    int i;
    char s,n;
    cout<<"Enter the total number of productions: ";
    cin>>n;
    cout<<"Enter the productions one by one\n";
    for(i=0;i<n;i++)
    {
        cin>>pr[i];
    }
    cout<<"Enter the value to find first and follow: ";
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(pr[i][0]==s)
        {
            findFirst(s,i,n);
        }
    }
    cout<<fi;
}
