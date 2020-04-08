#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include "LinkedList.c"

//#include "main.h"


int main(int argc, char *argv[])
{
    visited_urls = new_LinkedList();
    href_list = new_LinkedList();

    //char *nick = "";
    
    currentPage1 = argv[1];

    rec(currentPage1);

    if(href_list->first != NULL)
    {
        print_List(href_list);
        Node current = href_list->first;
        printf("\ncurrent->data1:\n%s\n\n",current->data);
        int cont = 0;

        while(current->next!=NULL);
        {
            printf("\niteration number:\n%d\n\n",cont);    
            printf("\ncurrent->data1:\n%s\n\n",current->data);
            if(cont>=200){break;}
            currentPage1 = current->data;
            printf("\nHREF LIST\n");
            print_List(href_list);

            printf("\nVISITED URL LIST\n");
            print_List(visited_urls);
    
            if(LinkedList_contains(visited_urls,current->data))
            {
                printf("\nALREADY VISITED \n");
                current = current->next;
                LinkedList_remove(href_list, current->prev->data);
            }
            else
            {
                printf("\nFIRST VISIT\n");
                //check if url is valid
                if(current->data[0]=='h'&&current->data[1]=='t'&&current->data[2]=='t'&&
                current->data[3]=='p'&&current->data[4]=='s'){current = current->next;
                cont++;current=current->next;}

                currentPage1 = current->data;
                LinkedList_add_at_end(href_list, currentPage1);
                rec(currentPage1);
                
                current = current->next;
                LinkedList_remove(href_list, current->prev->data);
                cont++;
            }       
        }
    }

    printf("\nLAST HREF LIST\n");
    print_List(href_list);
    printf("\n\nthe end\n");
	return 0;
}

void rec(char *currentPage)
{
    printf("\ninside rec\n");

    currentPage1 = currentPage;
    char *response = socket_TCP_HTTP(currentPage1);

    LinkedList_add_at_end(visited_urls,currentPage1);
    get_a_tags(response);

    printf("\nend rec\n");
}

char *socket_TCP_HTTP(char *server)
{
    printf("\ninside socket\n");
    int sock = 0;
    long valread;
    struct sockaddr_in serv_addr;
    char *gettxt = "GET ";
    char *get_path = getPath_fromURL(server);
    char * httptxt = " HTTP/1.1\n";
    char *hosttxt = "Host: ";
    char *host = getHost_fromURL(server);
    // printf("HOST: %s\n",host);
    char *close = "\nConnection: close\n\n";

    char *request = malloc(strlen(gettxt)+strlen(get_path)+strlen(httptxt)+strlen(hosttxt)+strlen(host)+strlen(close)+1000);
    //char *request = malloc(strlen(get)+strlen(close)+1);
    strcpy(request, gettxt);
    strcat(request, get_path);
    strcat(request, httptxt);
    strcat(request, hosttxt);
    strcat(request, host);
    strcat(request, close);

    printf("\nREQUEST:\n%s\n",request);

    char buffer[100000] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return "";
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(getHostIP(host));

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
        i++;
    }

    //printf("\nRESPONSE:\n%s\nEND OF RESPONSE\n",response);

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
    // printf("Official name is: %s\n", he->h_name);
    // printf("IP address: %s\n", inet_ntoa(*(struct in_addr*)he->h_addr));
    char *ip = inet_ntoa(*(struct in_addr*)he->h_addr);
    //printf("All addresses: ");
    addr_list = (struct in_addr **)he->h_addr_list;
    for(i = 0; addr_list[i] != NULL; i++) {
        //printf("%s ", inet_ntoa(*addr_list[i]));
    }
    //printf("\n");

    return ip;
}

void get_a_tags(char *htmlpage)
{
    printf("\ninside a\n");
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
                while(keepGoing)
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
                    n++; c++;
                }
                char *hr = get_href(a_tag);
                currentLink = hr;
                //printf("does hreflist contain %s: %d\n",currentLink,LinkedList_contains(href_list,currentLink));
                if(hr!="badForm" && !(LinkedList_contains(href_list,currentLink))){LinkedList_add_at_end(href_list,currentLink);}
            }
        }
    }
    printf("\nend a\n");
}

char *get_href(char *tag)
{
    printf("\ninside href\n");
    char *href = malloc(3);
    strcpy(href, "");
    int n = 1;
    bool iswellFormatted = true;

    for(int co=0; co<strlen(tag);co++)
    {
        if(tag[co]=='h' && tag[co+1]=='r' && tag[co+2]=='e' && tag[co+3]=='f')
        {
            int cc = co+6;
            while(true)
            {
                if(tag[cc]=='\"' || cc>=1000){break;}
                if(cc>=1000){iswellFormatted = false; break;}
                href = realloc(href, (n* sizeof(char)+3));
                char ch[2];
                ch[0] = tag[cc]; ch[1]='\0';
                strcat(href, ch);
                cc++; n++;
            }
        }
    }
    if(n==1){return "badForm";}
    if(iswellFormatted==true)
    {       
        char *rootURL = malloc(3);
        rootURL = realloc(rootURL,strlen(currentPage1)+strlen(href)+1000);
        strcpy(rootURL,"");
        if(href[0]=='/')
        {   
            int c=1;
            for(c; c<strlen(currentPage1); c++)
            {
                if(currentPage1[c]=='/'&&currentPage1[c-1]=='/' && currentPage1[c-1]!=':'){ break;}
            }
            for(int i=0; i<c; i++)
            {
                rootURL[i]=currentPage1[i];
            }
        }
        strcat(rootURL, href);
        return rootURL;
    }
    return "badForm";
    
}