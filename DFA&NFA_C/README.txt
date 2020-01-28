Partners:
Nicholas salem 
Syed Muhammad qasim sudais
Andrea tsao

Overview and description of the project:

Our project is composed of three parts:
1)running input through a dfa to check if the input meets the requirement to be accepted, printing 1 if it is accepted and 0 if it is not.
2) running input through a nfa to check if the input meets the requirement to be accepted, printing 1 if it is accepted and 0 if it is not.
3)converting a NFA to a dfa and printing the number of states in the resulting dfa; the result – if the input is accepted or not; and returning the resulting dfa.

And uses a few classes:
Main.c – where the main method is 
DFA.h – where the data structure DFA was created
NFA.h – where the data structure NFA was created
LinkedList.h and LinkedList.c (provided by the professor) – makes it possible to use linked lists

Detailed description of each part:

1)	Part one uses functions to represent each individual dfa.

The five functions are:
Accepts_csc173 – determines if input is csc173
Accepts_cat – determines if input starts with cat
Accepts_even1 – determins if input has an even number of 1s
Accepts_car – determines if the input is exactly the word car.

Each function represents a specific DFA and the function named “DF” takes them all and groups them into a while loop and switch case statements. The while loop goes until a string=”quit” is entered. And the switch case statements were used to ensure that the input is only tested with the intended criteria. Every case contains one of the functions for a dfa against which the input will be tested.

To make each dfa function, I used the dfa data structure created in the dfa.h file and passes the defining components of them. Basically, start at the defined start state and navigate the other states depending on the current character in the input character array using a while loop and s[i] with incrementing i.  And if at the end of while loop (=at the end of the input char[]) if the result is an accepting state print 1.


2)	Part two uses functions to represent each individual nfas.
The functions are:
NFA_end_code
NFA_containingcode
NFA_washington
NFA_endtion

Every function represents an individual nfa.
Similarly, a function with the name of NF groups them together and also uses a while and switch case statements.
Since computers cant run non deterministically and have the possibility of being simultaneously in two states, we used a simulation of an nfa. Instead of using integers, we used LinkedList to contain the possible states the nfa could be and at the end of the input array, if the linked list contained any of the accepting states defined, the input was accepted.
* NFA_washington is a simulation of the nfa found in the book. It works but is large.

3)	Part three uses two funtions, each to convert a NFA to a DFA
The funtions are:
Translator_end_code
Translator_containingcode

Each function will ask for the user to input a string and will test this string on the dfa resulting from the translation of the nfa passed in as a paramenter; print the number of states in the resulting dfa and return the resulting dfa.

Overview of the classes used:
	DFA.h – responsible for creating a dfa, takes 3 integers – first state, accepting states and states.
		Has a function named transition that when called updates the value of the current state
NFA.h – similar in idea as the dfa. however, with the addition of a linked list to represent all possible states as an int would not suffice since it is nondeterministic and can bein multiple states at once.

 



