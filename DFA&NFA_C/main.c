#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "DFA.h"
#include "LinkedList.c"
#include "NFA.h"

//part1
int DF();
int accepts_csc173(char s[]);
int accepts_cat(char s[]);
int accepts_even1(char s[]);
int accepts_even1and0(char s[]);
int accepts_car(char s[]);

//part2
int NF();
int NFA_end_code(char s[]);
int NFA_containingcode(char s[]);
int NFA_washigton(char s[]);
int NFA_endtion(char s[]);


//part3
DFA translator_end_code(NFA n);
DFA translator_containingcode(NFA nfa1);
int dfastatecounter_endcode(char s[]);


int main() {

    printf("CSC 173 PROJECT ONE NICHOLAS SALEM\n");

//  part one
    DF();

// part two
    NF();

// part three
    LinkedList ll = new_LinkedList();
    struct NFA nfa1 = {0,1,5,ll};
    LinkedList_add_at_front(nfa1.ll,0);
    char con[] = " ";
    do {
        printf("translating NFA to DFA and testing if it ends in code\n");
        translator_end_code(&nfa1);
        printf("run again?\n");
        scanf("%s",con);
    }
    while (strcmp(con, "no") != 0);
    do {

        printf("translating NFA to DFA and testing if it contains 'code'\n");
        translator_containingcode(&nfa1);
        printf("run again?\n");
        scanf("%s",con);
    }
    while (strcmp(con, "no") != 0);

    return 0;
}



int setvalue(int* pn, int newv){
    *pn = newv;
}

int DF(){

    char string[] = "hello";
    int x;

    while(strcmp(string, "quit") != 0)
    {
        puts("testing input string on a DFA");
        scanf("%s",string);

        if (strcmp(string, "quit") == 0){break;}

        puts("testing which case? '1' csc173, 2 starts with cat, 3 for even 1s, 4 for even 1and0, 5 if = car etc");
        scanf("%d",&x);

        switch(x){
            case 1:
                printf("answer: %d\n\n",accepts_csc173(string));
                break;
            case 2:
                printf("answer: %d\n\n",accepts_cat(string));
                break;
            case 3:
                printf("answer: %d\n\n",accepts_even1(string));
                break;
            case 4:
                printf("answer: %d\n\n",accepts_even1and0(string));
                break;
            case 5:
                printf("answer: %d\n\n",accepts_car(string));
                break;
            default:
                printf("no match, try again\n");
        }
    }
}

int accepts_cat(char s[])
{
    printf("testing if input starts with 'cat' \n");
    struct DFA dfa1 = {0,1,4};

    int states[dfa1.states];

    setvalue(&states[0],0);
    setvalue(&states[1],1);
    setvalue(&states[2],2);
    setvalue(&states[3],3);

    int acceptingSs[dfa1.accstates];
    setvalue(&acceptingSs[0],3);

    int state;
    setvalue(&state,dfa1.fststate);

    int i = 0;// to traverse string

    while(s[i] != '\0'){ //until the string has a next character

        printf("%c\n",s[i]);
        printf("first state: %d\n", state);

        if(state==dfa1.fststate){
            if(s[i]=='c'){
//              setvalue(&state,states[1]);
                transition(&state,states[1]);
                printf("yes\n");
                printf("0-1 state set to: %d\n", state);
            }
            else{
                break;
            }
        }
        else if(state==states[1]){
            if(s[i]=='a'){
                setvalue(&state,states[2]);
                printf("1-2 state set to: %d\n", state);
            }
            else{
                setvalue(&state,states[0]);
                printf("1-2 state set to: %d\n", state);
            }
        }
        else if(state==states[2]){
            if(s[i]=='t'){
                setvalue(&state,states[3]);
                printf("yes");
                printf("2-3 state set to: %d\n", state);
            }
            else{
                setvalue(&state,states[0]);
                printf("2-3 state set to: %d\n", state);
            }
        }
        i++;
        printf("\nend state: %d\n", state);
    }

    if (state == states[3]) {
        return 1;
    } else {
        return 0;
    }
}
int accepts_csc173(char s[])
{
    printf("testing if input is 'csc173' \n");
    struct DFA dfa1 = {0,1,7};

    int states[dfa1.states];

    setvalue(&states[0],0);
    setvalue(&states[1],1);
    setvalue(&states[2],2);
    setvalue(&states[3],3);
    setvalue(&states[4],4);
    setvalue(&states[5],5);
    setvalue(&states[6],6);

    int acceptingSs[dfa1.accstates];
    setvalue(&acceptingSs[0],6);

    int state;
    setvalue(&state,dfa1.fststate);

    int i = 0;// to traverse string

    while(s[i] != '\0'){ //until the string has a next character

        if(state==dfa1.fststate){
            if(s[i]=='c'){
                transition(&state,states[1]);
            }
            else{
                break;
            }
        }
        else if(state==states[1]){
            if(s[i]=='s'){
                transition(&state,states[2]);
            }
            else{
                transition(&state,states[0]);
            }
        }
        else if(state==states[2]){
            if(s[i]=='c'){
                transition(&state,states[3]);;
            }
            else{
                transition(&state,states[0]);
            }
        }
        else if(state==states[3]){
            if(s[i]=='1'){
                transition(&state,states[4]);;
            }
            else{
                transition(&state,states[0]);
            }
        }
        else if(state==states[4]){
            if(s[i]=='7'){
                transition(&state,states[5]);;
            }
            else{
                transition(&state,states[0]);
            }
        }
        else if(state==states[5]){
            if(s[i]=='3'){
                transition(&state,states[6]);;
            }
            else{
                transition(&state,states[0]);
            }
        }
        else if(state==states[6]){
            if(s[i]==' '){
                transition(&state,states[0]);;
            }
            else{
                transition(&state,states[0]);
            }
        }

        i++;

    }

    if (state == states[6]) {
        return 1;
    } else {
        return 0;
    }
}
int accepts_even1(char s[])
{
    printf("testing if input has even number of 1s' \n");
    struct DFA dfa1 = {0,1,3};

    int states[dfa1.states];

    setvalue(&states[0],0);
    setvalue(&states[1],1);
    setvalue(&states[2],2);

    int acceptingSs[dfa1.accstates];
    setvalue(&acceptingSs[0],2);

    int state;
    setvalue(&state,dfa1.fststate);

    int i = 0;// to traverse string

    while(s[i] != '\0'){ //until the string has a next character

        if(state==dfa1.fststate){
            if(s[i]=='0'){
                transition(&state,states[0]);
            }
            else if(s[i]=='1'){
                transition(&state,states[1]);
            }
            else{
                printf("invalid input");
                break;
            }
        }
        else if(state==states[1]){
            if(s[i]=='0'){
                transition(&state,states[1]);
            }
            else if(s[i]=='1'){
                transition(&state,states[2]);
            }
            else{
                printf("invalid input");
                break;
            }
        }
        else if(state==states[2]){
            if(s[i]=='0'){
                transition(&state,states[2]);
            }
            else if(s[i]=='1'){
                transition(&state,states[1]);
            }
            else{
                printf("invalid input");
                break;
            }
        }
        i++;

    }

    if (state == states[2]) {
        return 1;
    } else {
        return 0;
    }
}
int accepts_even1and0(char s[]) {
    printf("testing if input has even numbers of 1 and 0 \n");
    struct DFA dfa1 = {0, 1, 4};

    int states[dfa1.states];

    setvalue(&states[0], 0);
    setvalue(&states[1], 1);
    setvalue(&states[2], 2);
    setvalue(&states[3], 3);

    int acceptingSs[dfa1.accstates];
    setvalue(&acceptingSs[0], 3);

    int state;
    setvalue(&state, dfa1.fststate);

    int i = 0;// to traverse string

    while (s[i] != '\0') { //until the string has a next character

        if (state == dfa1.fststate) {
            if (s[i] == '0') {
                transition(&state, states[2]);
            } else if (s[i] == '1') {
                transition(&state, states[1]);
            } else {
                printf("invalid input");
                break;
            }
        } else if (state == states[1]) {
            if (s[i] == '0') {
                transition(&state, states[2]);
            } else if (s[i] == '1') {
                transition(&state, states[3]);
            } else {
                printf("invalid input");
                break;
            }
        } else if (state == states[2]) {
            if (s[i] == '0') {
                transition(&state, states[3]);
            } else if (s[i] == '1') {
                transition(&state, states[1]);
            } else {
                printf("invalid input");
                break;
            }
        } else if (state == states[3]) {
            if (s[i] == '0') {
                transition(&state, states[2]);
            } else if (s[i] == '1') {
                transition(&state, states[1]);
            } else {
                printf("invalid input");
                break;
            }
        }
        i++;
    }

        if (state == states[3]) {
            return 1;
        } else {
            return 0;
        }

}

int accepts_car(char s[])
{
    printf("testing if input is 'car' \n");
    struct DFA dfa1 = {0,1,7};

    int states[dfa1.states];

    setvalue(&states[0],0);
    setvalue(&states[1],1);
    setvalue(&states[2],2);
    setvalue(&states[3],3);

    int acceptingSs[dfa1.accstates];
    setvalue(&acceptingSs[0],3);

    int state;
    setvalue(&state,dfa1.fststate);

    int i = 0;// to traverse string

    while(s[i] != '\0'){ //until the string has a next character

        if(state==dfa1.fststate){
            if(s[i]=='c'){
                transition(&state,states[1]);
            }
            else{
                break;
            }
        }
        else if(state==states[1]){
            if(s[i]=='a'){
                transition(&state,states[2]);
            }
            else{
                transition(&state,states[0]);
            }
        }
        else if(state==states[2]){
            if(s[i]=='r'){
                transition(&state,states[3]);;
            }
            else{
                transition(&state,states[0]);
            }
        }
        else if(state==states[3]){
            if(s[i]==' '){
                transition(&state,states[0]);;
            }
            else{
                transition(&state,states[0]);
            }
        }

        i++;
    }

    if (state == states[3]) {
        return 1;
    } else {
        return 0;
    }
}

int NF(){

    char string[] = "hello";
    int x;

    while(strcmp(string, "quit") != 0)
    {

        puts("testing input string on a NFA");
        scanf("%s",string);

        if (strcmp(string, "quit") == 0){break;}

        puts("testing which case? 1(ending in code) 2(containing code) 3(partial anagrams of washington) 4(ending in tion)");
        scanf("%d",&x);

        switch(x){
            case 1:
                printf("testing if input ends with 'code'");
                printf("answer: %d\n\n",NFA_end_code(string));
                break;
            case 2:
                printf("testing if input contains 'code'");
                printf("answer: %d\n\n",NFA_containingcode(string));
                break;
            case 3:
                printf("testing if input is anagram of 'washington' (if answer is 1, then it is not a parcial anagram)");
                printf("answer: %d\n\n",NFA_washigton(string));
                break;
            case 4:
                printf("testing if input ends in 'tion'");
                printf("answer: %d\n\n",NFA_endtion(string));
                break;
            default:
                printf("no match, try again\n");
        }
    }
}

int NFA_end_code(char s[])
{
    LinkedList possiblestates = new_LinkedList();
    LinkedList_add_at_front(possiblestates,0);

    struct NFA nfa1 = {0,1,5, possiblestates};

    int i = 0;// to traverse string

    while(s[i] != '\0'){ //until the string has a next character

          if(LinkedList_contains(nfa1.ll,0) &&
          !LinkedList_contains(nfa1.ll,1)   &&
          !LinkedList_contains(nfa1.ll,2)   &&
          !LinkedList_contains(nfa1.ll,3)   &&
          !LinkedList_contains(nfa1.ll,4))
          {
            if(s[i]=='c'){
                transitionNFA(nfa1.ll,1);
            }
            else{
            }
        }
        else if(LinkedList_contains(nfa1.ll,1) && LinkedList_contains(nfa1.ll,0))
          {
            if(s[i]=='o')
            {
                LinkedList_remove(nfa1.ll,1);
                transitionNFA(nfa1.ll,2);
            }
            else if(s[i]=='c')
            {

            }
            else
            {
                LinkedList_remove(nfa1.ll,1);
            }
        }
        else if((LinkedList_contains(nfa1.ll,2) && LinkedList_contains(nfa1.ll,0)))
          {
              if(s[i]=='d')
              {
                  LinkedList_remove(nfa1.ll,2);
                  transitionNFA(nfa1.ll,3);
              }
              else if(s[i]=='c')
              {
                  LinkedList_remove(nfa1.ll,2);
                  transitionNFA(nfa1.ll,1);
              }
              else{
                  LinkedList_remove(nfa1.ll,2);
              }
          }
          else if((LinkedList_contains(nfa1.ll,3) && LinkedList_contains(nfa1.ll,0)))
          {
              if(s[i]=='e')
              {
                  LinkedList_remove(nfa1.ll,3);
                  transitionNFA(nfa1.ll,4);
              }
              else if(s[i]=='c')
              {
                  int a1[] = {0,1,-1};
                  LinkedList_remove(nfa1.ll,3);
                  transitionNFA(nfa1.ll,1);
              }
              else{
                  int a1[] = {0,-1};
                  LinkedList_remove(nfa1.ll,3);
              }
          }
          else if((LinkedList_contains(nfa1.ll,4) && LinkedList_contains(nfa1.ll,0)))
          {
              if(s[i]=='c')
              {
                  LinkedList_remove(nfa1.ll,4);
                  transitionNFA(nfa1.ll,1);
              }
              else{
                  LinkedList_remove(nfa1.ll,4);
              }
          }
        i++;
    }

    if (LinkedList_contains(nfa1.ll,4))
    {
        return 1;
    }

    else
        {
        return 0;
        }

}
int NFA_containingcode(char s[])
{
    LinkedList possiblestates = new_LinkedList();
    LinkedList_add_at_front(possiblestates,0);

    struct NFA nfa1 = {0,1,5, possiblestates};

    int i = 0;// to traverse string

    while(s[i] != '\0'){ //until the string has a next character

        if(LinkedList_contains(nfa1.ll,0) &&
           !LinkedList_contains(nfa1.ll,1)   &&
           !LinkedList_contains(nfa1.ll,2)   &&
           !LinkedList_contains(nfa1.ll,3)   &&
           !LinkedList_contains(nfa1.ll,4))
        {
            if(s[i]=='c'){
                transitionNFA(nfa1.ll,1);
            }
            else{
            }
        }
        else if(LinkedList_contains(nfa1.ll,1) && LinkedList_contains(nfa1.ll,0))
        {
            if(s[i]=='o')
            {
                LinkedList_remove(nfa1.ll,1);
                transitionNFA(nfa1.ll,2);
            }
            else if(s[i]=='c')
            {

            }
            else
            {
                LinkedList_remove(nfa1.ll,1);
            }
        }
        else if((LinkedList_contains(nfa1.ll,2) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]=='d')
            {
                LinkedList_remove(nfa1.ll,2);
                transitionNFA(nfa1.ll,3);
            }
            else if(s[i]=='c')
            {
                LinkedList_remove(nfa1.ll,2);
                transitionNFA(nfa1.ll,1);
            }
            else{
                LinkedList_remove(nfa1.ll,2);
            }
        }
        else if((LinkedList_contains(nfa1.ll,3) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]=='e')
            {
                LinkedList_remove(nfa1.ll,3);
                transitionNFA(nfa1.ll,4);
            }
            else if(s[i]=='c')
            {
                int a1[] = {0,1,-1};
                LinkedList_remove(nfa1.ll,3);
                transitionNFA(nfa1.ll,1);
            }
            else{
                int a1[] = {0,-1};
                LinkedList_remove(nfa1.ll,3);
            }
        }
//        else if((LinkedList_contains(nfa1.ll,4) && LinkedList_contains(nfa1.ll,0)))
//        {
//            if(s[i]=='c')
//            {
//                LinkedList_remove(nfa1.ll,4);
//                transitionNFA(nfa1.ll,1);
//            }
//            else{
//                LinkedList_remove(nfa1.ll,4);
//            }
//        }
        i++;
    }

    if (LinkedList_contains(nfa1.ll,4))
    {
        return 1;
    }

    else
    {
        return 0;
    }

}

int NFA_washigton(char s[])
{
    LinkedList possiblestates = new_LinkedList();
    LinkedList_add_at_front(possiblestates,0);

    struct NFA nfa1 = {0,1,5, possiblestates};

    int i = 0;// to traverse string

    while(s[i] != '\0')
    { //until the string has a next character

        if(LinkedList_contains(nfa1.ll,0) &&
           !LinkedList_contains(nfa1.ll,1)   &&
           !LinkedList_contains(nfa1.ll,2)   &&
           !LinkedList_contains(nfa1.ll,3)   &&
           !LinkedList_contains(nfa1.ll,4)   &&
           !LinkedList_contains(nfa1.ll,5)   &&
           !LinkedList_contains(nfa1.ll,6)   &&
           !LinkedList_contains(nfa1.ll,7)   &&
           !LinkedList_contains(nfa1.ll,8)   &&
           !LinkedList_contains(nfa1.ll,9)   &&
           !LinkedList_contains(nfa1.ll,10)   &&
           !LinkedList_contains(nfa1.ll,11)   &&
           !LinkedList_contains(nfa1.ll,12)   &&
           !LinkedList_contains(nfa1.ll,13)   &&
           !LinkedList_contains(nfa1.ll,14)   &&
           !LinkedList_contains(nfa1.ll,15)   &&
           !LinkedList_contains(nfa1.ll,16)   &&
           !LinkedList_contains(nfa1.ll,17)   &&
           !LinkedList_contains(nfa1.ll,18)   &&
           !LinkedList_contains(nfa1.ll,19)
           )
        {
            if(s[i]=='a'){
                transitionNFA(nfa1.ll,1);
            }
            else if (s[i]=='g'){
                transitionNFA(nfa1.ll,3);
            }
            else if (s[i]=='h'){
                transitionNFA(nfa1.ll,5);
            }
            else if (s[i]=='i'){
                transitionNFA(nfa1.ll,7);
            }
            else if (s[i]=='n'){
                transitionNFA(nfa1.ll,9);
            }
            else if (s[i]=='o'){
                transitionNFA(nfa1.ll,12);
            }
            else if (s[i]=='s'){
                transitionNFA(nfa1.ll,14);
            }
            else if (s[i]=='t'){
                transitionNFA(nfa1.ll,16);
            }
            else if (s[i]=='w'){
                transitionNFA(nfa1.ll,18);
            }
            else{
                transitionNFA(nfa1.ll,2);
                break;
            }

        }
        else if(LinkedList_contains(nfa1.ll,1) && LinkedList_contains(nfa1.ll,0))
        {
            if(s[i]=='a')
            {
                transitionNFA(nfa1.ll,2);
            }
            else
            {

            }
        }
        else if((LinkedList_contains(nfa1.ll,2)&& LinkedList_contains(nfa1.ll,1) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]==' ')
            {
                break;
            }
            else{
                break;
            }
        }
        else if(LinkedList_contains(nfa1.ll,3) && LinkedList_contains(nfa1.ll,0))
        {
            if(s[i]=='g')
            {
                transitionNFA(nfa1.ll,4);
            }
            else
            {

            }
        }
        else if((LinkedList_contains(nfa1.ll,4)&& LinkedList_contains(nfa1.ll,3) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]==' ')
            {
                break;
            }
            else{
                break;
            }
        }
        else if(LinkedList_contains(nfa1.ll,5) && LinkedList_contains(nfa1.ll,0))
        {
            if(s[i]=='h')
            {
                transitionNFA(nfa1.ll,6);
            }
            else
            {

            }
        }
        else if((LinkedList_contains(nfa1.ll,6)&& LinkedList_contains(nfa1.ll,5) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]==' ')
            {
                break;
            }
            else{
                break;
            }
        }
        else if(LinkedList_contains(nfa1.ll,7) && LinkedList_contains(nfa1.ll,0))
        {
            if(s[i]=='i')
            {
                transitionNFA(nfa1.ll,8);
            }
            else
            {

            }
        }
        else if((LinkedList_contains(nfa1.ll,8)&& LinkedList_contains(nfa1.ll,7) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]==' ')
            {
                break;
            }
            else{
                break;
            }
        }
        else if(LinkedList_contains(nfa1.ll,9) && LinkedList_contains(nfa1.ll,0) && !LinkedList_contains(nfa1.ll,10))
        {
            if(s[i]=='n')
            {
                transitionNFA(nfa1.ll,10);
            }
            else
            {

            }
        }
        else if((LinkedList_contains(nfa1.ll,9)&& LinkedList_contains(nfa1.ll,10) && LinkedList_contains(nfa1.ll,0))&&!LinkedList_contains(nfa1.ll,11))
        {
            if(s[i]=='n')
            {
                transitionNFA(nfa1.ll,11);
            }
            else{

            }
        }
        else if((LinkedList_contains(nfa1.ll,9)&& LinkedList_contains(nfa1.ll,10) && LinkedList_contains(nfa1.ll,11) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]==' ')
            {
                break;
            }
            else{
                break;
            }
        }
        else if(LinkedList_contains(nfa1.ll,12) && LinkedList_contains(nfa1.ll,0))
        {
            if(s[i]=='o')
            {
                transitionNFA(nfa1.ll,13);
            }
            else
            {

            }
        }
        else if((LinkedList_contains(nfa1.ll,13)&& LinkedList_contains(nfa1.ll,12) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]==' ')
            {
                break;
            }
            else{
                break;
            }
        }
        else if(LinkedList_contains(nfa1.ll,14) && LinkedList_contains(nfa1.ll,0))
        {
            if(s[i]=='s')
            {
                transitionNFA(nfa1.ll,15);
            }
            else
            {

            }
        }
        else if((LinkedList_contains(nfa1.ll,15)&& LinkedList_contains(nfa1.ll,14) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]==' ')
            {
                break;
            }
            else{
                break;
            }
        }
        else if(LinkedList_contains(nfa1.ll,16) && LinkedList_contains(nfa1.ll,0))
        {
            if(s[i]=='t')
            {
                transitionNFA(nfa1.ll,17);
            }
            else
            {

            }
        }
        else if((LinkedList_contains(nfa1.ll,17)&& LinkedList_contains(nfa1.ll,16) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]==' ')
            {
                break;
            }
            else{
                break;
            }
        }
        else if(LinkedList_contains(nfa1.ll,18) && LinkedList_contains(nfa1.ll,0))
        {
            if(s[i]=='w')
            {
                transitionNFA(nfa1.ll,19);
            }
            else
            {

            }
        }
        else if((LinkedList_contains(nfa1.ll,19)&& LinkedList_contains(nfa1.ll,18) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]==' ')
            {
                break;
            }
            else{
                break;
            }
        }
        i++;
    }

    if (LinkedList_contains(nfa1.ll,2)||LinkedList_contains(nfa1.ll,4)||LinkedList_contains(nfa1.ll,6)
    ||LinkedList_contains(nfa1.ll,8)||LinkedList_contains(nfa1.ll,11)||LinkedList_contains(nfa1.ll,13)
    ||LinkedList_contains(nfa1.ll,15)||LinkedList_contains(nfa1.ll,17)||LinkedList_contains(nfa1.ll,19)
    )
    {
        return 1;
    }

    else
    {
        return 0;
    }

}

int NFA_endtion(char s[])
{
    LinkedList possiblestates = new_LinkedList();
    LinkedList_add_at_front(possiblestates,0);

    struct NFA nfa1 = {0,1,5, possiblestates};

    int i = 0;// to traverse string

    while(s[i] != '\0'){ //until the string has a next character

        if(LinkedList_contains(nfa1.ll,0) &&
           !LinkedList_contains(nfa1.ll,1)   &&
           !LinkedList_contains(nfa1.ll,2)   &&
           !LinkedList_contains(nfa1.ll,3)   &&
           !LinkedList_contains(nfa1.ll,4))
        {
            if(s[i]=='t'){
                transitionNFA(nfa1.ll,1);
            }
            else{
            }
        }
        else if(LinkedList_contains(nfa1.ll,1) && LinkedList_contains(nfa1.ll,0))
        {
            if(s[i]=='i')
            {
                LinkedList_remove(nfa1.ll,1);
                transitionNFA(nfa1.ll,2);
            }
            else if(s[i]=='t')
            {

            }
            else
            {
                LinkedList_remove(nfa1.ll,1);
            }
        }
        else if((LinkedList_contains(nfa1.ll,2) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]=='o')
            {
                LinkedList_remove(nfa1.ll,2);
                transitionNFA(nfa1.ll,3);
            }
            else if(s[i]=='t')
            {
                LinkedList_remove(nfa1.ll,2);
                transitionNFA(nfa1.ll,1);
            }
            else{
                LinkedList_remove(nfa1.ll,2);
            }
        }
        else if((LinkedList_contains(nfa1.ll,3) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]=='n')
            {
                LinkedList_remove(nfa1.ll,3);
                transitionNFA(nfa1.ll,4);
            }
            else if(s[i]=='t')
            {
                int a1[] = {0,1,-1};
                LinkedList_remove(nfa1.ll,3);
                transitionNFA(nfa1.ll,1);
            }
            else{
                int a1[] = {0,-1};
                LinkedList_remove(nfa1.ll,3);
            }
        }
        else if((LinkedList_contains(nfa1.ll,4) && LinkedList_contains(nfa1.ll,0)))
        {
            if(s[i]=='t')
            {
                LinkedList_remove(nfa1.ll,4);
                transitionNFA(nfa1.ll,1);
            }
            else{
                LinkedList_remove(nfa1.ll,4);
            }
        }
        i++;
    }

    if (LinkedList_contains(nfa1.ll,4))
    {
        return 1;
    }

    else
    {
        return 0;
    }

}

DFA translator_end_code(NFA nfa1)
{
    char s[] = "";
    puts("testing input string on a DFA translated from an NFA");
    scanf("%s",s);

    int answer = NFA_end_code(s);

//    int dfastates = dfastatecounter(string, n);

    int i=0;
    int dfastates=5;
    while(s[i] != '\0'){ //until the string has a next character

        if(LinkedList_contains(nfa1->ll,0)    &&
           !LinkedList_contains(nfa1->ll,1)   &&
           !LinkedList_contains(nfa1->ll,2)   &&
           !LinkedList_contains(nfa1->ll,3)   &&
           !LinkedList_contains(nfa1->ll,4))
        {
            if(s[i]=='c'){
                transitionNFA(nfa1->ll,1);
            }
            else{
            }
        }
        else if(LinkedList_contains(nfa1->ll,1) && LinkedList_contains(nfa1->ll,0))
        {
            if(s[i]=='o')
            {
                LinkedList_remove(nfa1->ll,1);
                transitionNFA(nfa1->ll,2);
            }
            else if(s[i]=='c')
            {

            }
            else
            {
                LinkedList_remove(nfa1->ll,1);
            }
        }
        else if((LinkedList_contains(nfa1->ll,2) && LinkedList_contains(nfa1->ll,0)))
        {
            if(s[i]=='d')
            {
                LinkedList_remove(nfa1->ll,2);
                transitionNFA(nfa1->ll,3);
            }
            else if(s[i]=='c')
            {
                LinkedList_remove(nfa1->ll,2);
                transitionNFA(nfa1->ll,1);
            }
            else{
                LinkedList_remove(nfa1->ll,2);
            }
        }
        else if((LinkedList_contains(nfa1->ll,3) && LinkedList_contains(nfa1->ll,0)))
        {
            if(s[i]=='e')
            {
                LinkedList_remove(nfa1->ll,3);
                transitionNFA(nfa1->ll,4);
            }
            else if(s[i]=='c')
            {
                LinkedList_remove(nfa1->ll,3);
                transitionNFA(nfa1->ll,1);
            }
            else{
                LinkedList_remove(nfa1->ll,3);
            }
        }
        else if((LinkedList_contains(nfa1->ll,4) && LinkedList_contains(nfa1->ll,0)))
        {
            if(s[i]=='c')
            {
                LinkedList_remove(nfa1->ll,4);
                transitionNFA(nfa1->ll,1);
            }
            else{
                LinkedList_remove(nfa1->ll,4);
            }
        }
        i++;
    }

    struct DFA * resulting_dfa={0,1,dfastates};
    printf("number of states in the result on DFA is: %d\n",dfastates);

    printf("running on the resulting DFA. \n answer: %d\n",answer);

    return resulting_dfa;
}

DFA translator_containingcode(NFA nfa1)
{
    char s[] = "";
    puts("testing input string on a DFA translated from an NFA");
    scanf("%s",s);

    int answer = NFA_containingcode(s);

//    int dfastates = dfastatecounter(string, n);

    int i=0;
    int dfastates=5;
    while(s[i] != '\0'){ //until the string has a next character

        if(LinkedList_contains(nfa1->ll,0)    &&
           !LinkedList_contains(nfa1->ll,1)   &&
           !LinkedList_contains(nfa1->ll,2)   &&
           !LinkedList_contains(nfa1->ll,3)   &&
           !LinkedList_contains(nfa1->ll,4))
        {
            if(s[i]=='c'){
                transitionNFA(nfa1->ll,1);
            }
            else{
            }
        }
        else if(LinkedList_contains(nfa1->ll,1) && LinkedList_contains(nfa1->ll,0))
        {
            if(s[i]=='o')
            {
                LinkedList_remove(nfa1->ll,1);
                transitionNFA(nfa1->ll,2);
            }
            else if(s[i]=='c')
            {

            }
            else
            {
                LinkedList_remove(nfa1->ll,1);
            }
        }
        else if((LinkedList_contains(nfa1->ll,2) && LinkedList_contains(nfa1->ll,0)))
        {
            if(s[i]=='d')
            {
                LinkedList_remove(nfa1->ll,2);
                transitionNFA(nfa1->ll,3);
            }
            else if(s[i]=='c')
            {
                LinkedList_remove(nfa1->ll,2);
                transitionNFA(nfa1->ll,1);
            }
            else{
                LinkedList_remove(nfa1->ll,2);
            }
        }
        else if((LinkedList_contains(nfa1->ll,3) && LinkedList_contains(nfa1->ll,0)))
        {
            if(s[i]=='e')
            {
                LinkedList_remove(nfa1->ll,3);
                transitionNFA(nfa1->ll,4);
            }
            else if(s[i]=='c')
            {
                LinkedList_remove(nfa1->ll,3);
                transitionNFA(nfa1->ll,1);
            }
            else{
                LinkedList_remove(nfa1->ll,3);
            }
        }
        i++;
    }

    struct DFA * resulting_dfa={0,1,dfastates};
    printf("number of states in the result on DFA is: %d\n",dfastates);

    printf("running on the resulting DFA. \n answer: %d\n",answer);

    return resulting_dfa;
}
