#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
char pr[20][20],L[20];
int tc=0;
void findL(int j)
{
    int i,flag=1,k;
    flag=1;
    for(i=3;pr[j][i]!='\0';i++)
    {
        if(!isupper(pr[j][i]))
        {
            for(k=0;k<tc;k++)
            {
                if(L[k]==pr[j][i])
                flag=0;
            }
            if(flag==1)
            {
                L[tc++]=pr[j][i];
            }
            break;
        }
    }
}
void traversal(int j,int n)
{
    int i;
    if(isupper(pr[j][3]))
    {
        for(i=j+1;i<n;i++)
        {
            if(pr[j][3]==pr[i][0])
            {
                findL(i);
                if(isupper(pr[i][3]))
                    traversal(i,n);
            }
        }
    }
}
int main()
{
    int n,pos=0,i;
    char s;
    cout<<"Enter the number of productions: ";
    cin>>n;
    cout<<"Enter the production one by one\n";
    for(i=0;i<n;i++)
    {
        cin>>pr[i];
    }
    cout<<"Enter NL to find leading and trialing\n";
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(s==pr[i][0])
        {
            pos=i;
            break;
        }
    }
    findL(pos);
    traversal(pos,n);
    cout<<L;
}
