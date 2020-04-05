#include <stdio.h>
#include <stdlib.h>

#define PORT 80

FILE * filePointer;
LinkedList HTML_pages;
LinkedList a_tags;
LinkedList href_list;

char *socket_TCP_HTTP(char *server);
char *getHostIP(char *hostname);
void get_a_tags(char *htmlpage);
void get_href(char *tag);

