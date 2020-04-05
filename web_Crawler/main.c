#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

#include "LinkedList.c"
#include "main.h"


int main(int argc, char *argv[])
{

//    get_href("<a href=\"/intl/pt-BR/policies/privacy/\">Privacidade</a>");
    HTML_pages = new_LinkedList();
    a_tags = new_LinkedList();
    href_list = new_LinkedList();

    char *initialPage;
    initialPage = argv[1];

    char *response = socket_TCP_HTTP(initialPage);

    get_a_tags(response);
    print_List(a_tags);

    Node current = a_tags->first;
    while(current->next!=NULL)
    {
        get_href(current->data);
        current = current->next;
    }
    print_List(href_list);

	return 0;
}

char *socket_TCP_HTTP(char *server)
{
    int sock = 0;
    long valread;
    struct sockaddr_in serv_addr;
    char *get = "GET / HTTP/1.1\n";
    char *host = "Host: ";
    char *close = "\nConnection: close\n\n";

    char *request = malloc(strlen(get)+strlen(host)+strlen(server)+strlen(close)+1);
    strcpy(request, get);
    strcat(request,host);
    strcat(request,server);
    strcat(request,close);
    printf("%s",request);

    char buffer[1000] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return "";
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(getHostIP(server));

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return "";
    }

    send(sock , request , strlen(request) , 0);

    char *response = malloc(1);
    int i = 1;
    strcpy(response,"");
    while((valread = recv(sock , buffer, sizeof(buffer)-1, MSG_WAITALL)) >0)
    {
        response = realloc(response, (i* sizeof(buffer))+2);
        strcat(response,buffer);
        //printf("%s\n",buffer);
        i++;

    }
//    fclose(filePointer);
    printf("response: %s",response);
    return response;
}

char *getHostIP(char *hostname)
{
    int i;
    struct hostent *he;
    struct in_addr **addr_list;
    struct in_addr addr;

    he = gethostbyname(hostname);
    if (he == NULL) { // do some error checking
        herror("gethostbyname"); // herror(), NOT perror()
        exit(1);
    }
// print information about this host:
    printf("Official name is: %s\n", he->h_name);
    printf("IP address: %s\n", inet_ntoa(*(struct in_addr*)he->h_addr));
    char *ip = inet_ntoa(*(struct in_addr*)he->h_addr);
    printf("All addresses: ");
    addr_list = (struct in_addr **)he->h_addr_list;
    for(i = 0; addr_list[i] != NULL; i++) {
        printf("%s ", inet_ntoa(*addr_list[i]));
    }
    printf("\n");

    return ip;
}

void get_a_tags(char *htmlpage)
{
    for(int c=0; c<strlen(htmlpage);c++)
    {
        if(htmlpage[c]=='<')
        {
            if(htmlpage[c+1]=='a')
            {

                char *a_tag = malloc(1);
                strcpy(a_tag, "");
                int n = 1;
                bool keepGoing = true;
                do
                {
                    a_tag = realloc(a_tag, (n* sizeof(char)+10));
                    char ch[2];
                    ch[0] = htmlpage[c]; ch[1]='\0';
                    strcat(a_tag, ch);

                    if(htmlpage[c]=='<' && htmlpage[c+1]=='/' && htmlpage[c+2]=='a' && htmlpage[c+3]=='>')
                    {
                        char cls[4];
                        cls[0] = htmlpage[c+1];cls[1] = htmlpage[c+2];
                        cls[2] = htmlpage[c+3];cls[3] = '\0';
                        strcat(a_tag, cls);
                        keepGoing = false;
                    }
                    n++;
                    c++;
                }
                while(keepGoing);
//                get_href(a_tag);
//                printf("a tag: %s\n",a_tag);
               LinkedList_add_at_end(a_tags,a_tag);
            }
        }
    }
}

void get_href(char *tag)
{
    char *href = malloc(1);
    strcpy(href, "");
    int n = 1;

    for(int co=0; co<strlen(tag);co++)
    {

        if(tag[co]=='h' && tag[co+1]=='r' && tag[co+2]=='e' && tag[co+3]=='f')
        {

            int cc = co+6;
            while(true)
            {
                if(tag[cc]=='\"'){break;}
                href = realloc(href, (n* sizeof(char)+3));
                char ch[2];
                ch[0] = tag[cc]; ch[1]='\0';
                strcat(href, ch);
                cc++;
            }

        }
    }
    //printf("href: %s\n",href);
    LinkedList_add_at_end(href_list,href);
}