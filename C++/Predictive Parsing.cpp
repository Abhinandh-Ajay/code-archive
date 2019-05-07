#include <iostream>

using namespace std;

char pr[20][20],fi[20],fo[20];
int fic=0,foc=0;
void traversal(char s, int i, int n);
void findFirst(char s, int i, int n)
{
    int flag = 1,j;
    if(!isupper(pr[i][3]))
    {
        for(j=0;j<fic;j++)
        {
            if(fi[j]==pr[i][3])
            flag=0;
        }
        if(flag==1)
        {
            fi[fic++]=pr[i][3];
        }
    }
    else
    {
        traversal(s,i,n);
    }
}
void followFirst(char s, int i, int n)
{
    int flag = 1,j;
    if(!isupper(pr[i][3]))
    {
        for(j=0;j<foc;j++)
        {
            if(fo[j]==pr[i][3])
            flag=0;
        }
        if(flag==1)
        {
            fo[foc++]=pr[i][3];
        }
    }
    else
    {
        traversal(s,i,n);
    }
}
void findFollow(char s, int n)
{
    int flag=1,j,k,l;
    for(j=0;j<n;j++)
    {
        for(k=3;k<strlen(pr[j]);k++)
        {
            if(pr[j][k]==s)
            {
                if(pr[j][k+1]!='\0')
                {
                    for(l=0;l<n;l++)
                    {
                        if(pr[l][0]==pr[j][k+1])
                        break;
                    }
                    followFirst(s,l,n);
                    if(j==0)
                    {
                        fo[++foc]='$';
                    }
                }
                else
                {
                    findFollow(pr[j][0],n);
                }
            }
        }
    }
}
void traversal(char s, int j, int n)
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
    int i,n;
    char s;
    cout<<"Enter the number of productions\n";
    cin>>n;
    cout<<"Enter the productions one by one\n";
    for(i=0;i<n;i++)
    {
        cin>>pr[i];
    }
    cout<<"Enter NT ";
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(pr[i][0]==s)
        {
            findFirst(s,i,n);
            findFollow(s,n);
        }
    }
    cout<<fi<<endl<<fo;
}
