#include <stdio.h>
#include <stdlib.h>


#define PORT 80

FILE * filePointer;


char *currentPage1;
LinkedList visited_urls;
LinkedList href_list;
char *currentLink;
// char *responseh;
// char *responseh2;
// int num = 1;

char *socket_TCP_HTTP(char *server);
char *getHostIP(char *hostname);
void get_a_tags(char *htmlpage);
char *get_href(char *tag);
void rec(char *currentPage);

char *getHost_fromURL(char *url)
{
    char *host = malloc(strlen(url)+3);
    strcpy(host,"");
    bool stp = false;
    for(int i=0; i<strlen(url); i++)
    {
        if(url[i]=='w'&&url[i+1]=='w'&&url[i+2]=='w'&&url[i+3]=='.' && stp==false)
        //if(url[i]=='.' && stp==false)
        {
            for(int c=i; c<strlen(url);c++)
            {   
                if(url[c]=='/'){break;}
                char arr[2]; arr[0] = url[c]; arr[1]='\0';
                strcat(host,arr);
                
            }
            stp = true;
        }
    }
    if(stp==false)
    {
        for(int i=0; i<strlen(url); i++)
        {
            if(url[i]==':' &&url[i+1]=='/' &&url[i+2]=='/' && stp==false)
            {
                for(int c=i+3; c<strlen(url);c++)
                {   
                    if(url[c]=='/'){break;}
                    char arr[2]; arr[0] = url[c]; arr[1]='\0';
                    strcat(host,arr);
                    stp = true;
                }
            }
        }
    }
    return host;
}

char *getPath_fromURL(char *url)
{

    char *path = malloc(strlen(url)+3);
    strcpy(path,"/");
    bool stp = false;
    for(int i=1; i<strlen(url); i++)
    {
        if(url[i]=='/' &&url[i-1]!='/' &&url[i-1]!=':' && stp==false)
        {
            for(int c=i+1; c<strlen(url);c++)
            {   
                char arr[2]; arr[0]=url[c]; arr[1]='\0';
                strcat(path,arr);
            }
            stp = true;
        }
    }
    return path;

}

bool compareStrings(char *s1, char *s2)
{
    if(strlen(s1)!=strlen(s2)){return false;}
    for(int i=0; i<strlen(s1); i++)
    {
        if(s1[i]!=s2[i]){return false;}
    }
    return true;
}


