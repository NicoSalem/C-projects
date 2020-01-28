//
// Created by Nico on 2/6/2019.
//

#ifndef PROJ_1_AUTOMATA_DFA_H
#define PROJ_1_AUTOMATA_DFA_H

#endif //PROJ_1_AUTOMATA_DFA_H


typedef struct DFA * DFA;

struct DFA{
   int fststate;
   int accstates;
   int states;
};

void transition(int* initialstate, int finalstate){
    *initialstate = finalstate;
}
