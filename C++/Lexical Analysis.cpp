#include<iostream>
#include<string.h>
#include<ctype.h>
int isKeyword(char* buffer)
{
    char keywords[32][50]=  {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int i,flag=0;
    for(i=0;i<32;i++)
    {
        if(strcmp(keywords[i],buffer)==0)
        {
            flag=1;
            break;
        }
    }
    return flag;
}
int isIncOp(char buffer[])
{
    char ops[2][3]={"++","--"};
    int i,flag=0;
    for(i=0;i<2;i++)
    {
        if(strcmp(ops[i],buffer))
        {
            flag=1;
            break;
        }
    }
    return flag;
}
int main()
{
    char str[]="for(i=0;i<n;i++)",
    relop[]={"<>"},
    arithop[]={"+-*/%="},
    paren[]={"{}()[]"},
    delimi[]={":;"},
    buffer[10];
    int i,j,k=0;
    for(i=0;i<strlen(str);i++)
    {
        for(j=0;j<6;j++)
        {
            if(str[i]==arithop[j])
            {
                std::cout<<arithop[j]<<" is an arithmetic operator\n";
            }
        }
        for(j=0;j<2;j++)
        {
            if(str[i]==relop[j])
            {
                std::cout<<relop[j]<<" is a relational operator\n";
            }
        }
        for(j=0;j<6;j++)
        {
            if(str[i]==paren[j])
            {
                std::cout<<paren[j]<<" is a parenthesis\n";
            }
        }
        for(j=0;j<2;j++)
        {
            if(str[i]==delimi[j])
            {
                std::cout<<delimi[j]<<" is a delimiter\n";
            }
        }
        if(isdigit(str[i]))
        {
            std::cout<<str[i]<<" is a number\n";
        }
        if(isalpha(str[i]))
        {
            while(isalpha(str[i]))
            {
                buffer[k]=str[i];
                i++;
                k++;
            }
            i--;
            buffer[k]='\0';
            k=0;
            if(isKeyword(buffer)==1)
            {
                std::cout<<buffer<<" is a keyword\n";
            }
            else
            {
                std::cout<<buffer<<" is an identifier\n";
            }
        }
    }
    return 0;
}
