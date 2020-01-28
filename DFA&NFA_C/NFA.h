//
// Created by Nico on 2/6/2019.

#ifndef PROJ_1_AUTOMATA_DFA_H
#define PROJ_1_AUTOMATA_DFA_H
#endif //PROJ_1_AUTOMATA_DFA_H

#include "LinkedList.h"



typedef struct NFA * NFA;

struct NFA{
    int fststate;
    int accstates;
    int states;
    LinkedList ll; //possible states
};

void setvalueNFA(int* pn, int newv)
{
    *pn = newv;
}

int contains(int final[], int n)
{
    int i=0;
    while (final[i] != -1)
    {
        if(final[i]==n){
            return 1;
        }
        i++;
    }
    return 0;
}



void transitionNFA(LinkedList l, int a)
{
   LinkedList_add_at_end(l,a);
}

