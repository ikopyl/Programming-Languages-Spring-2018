m([arnell, ernesto, elmer, eugene, emil, joshua, eli, chris]).
f([erlinda, nenita, loreena, elyza, lilliana, christine, jocelyn]).

family([arnell, erlinda, [nenita]]).
family([ernesto, nenita, [elmer, eugene, emil, loreena]]).
family([elmer, christine, [joshua, eli]]).
family([eugene, jocelyn, [elyza]]).
family([chris, loreena, [lilliana]]).

male(PERSON) :-
       m(MALES), member(PERSON, MALES).
female(PERSON) :-
       f(FEMALES), member(PERSON, FEMALES).

father(FATHER, CHILD) :-
	family([FATHER, _, CHILDREN]), member(CHILD, CHILDREN).
mother(MOTHER, CHILD) :-
    family([_, MOTHER, CHILDREN]), member(CHILD, CHILDREN).
parent(PARENT, CHILD) :-
	father(PARENT, CHILD); mother(PARENT, CHILD).

siblings1(CHILD1, CHILD2) :-
	parent(PARENT, CHILD1),
	parent(PARENT, CHILD2),
	CHILD1 \= CHILD2.

siblings2(CHILD1, CHILD2) :-
	parent(PARENT1, CHILD1),
	parent(PARENT1, CHILD2),
	parent(PARENT2, CHILD1),
	parent(PARENT2, CHILD2),
	CHILD1 \= CHILD2.
brother1(CHILD1, CHILD2) :-
	siblings1(CHILD1, CHILD2),
	male(CHILD1).
brother2(CHILD1, CHILD2) :-
	siblings2(CHILD1, CHILD2),
	male(CHILD1).
sister1(CHILD1, CHILD2) :-
	siblings1(CHILD1, CHILD2),
	female(CHILD1).
sister2(CHILD1, CHILD2) :-
	siblings2(CHILD1, CHILD2),
	female(CHILD1).
cousins(CHILD1, CHILD2) :-
	parent(PARENT, CHILD1),
	siblings1(PARENT, SIBLING),
	parent(SIBLING, CHILD2).
uncle(UNCLE, CHILD) :-
	parent(PARENT, CHILD),
	siblings1(PARENT, UNCLE),
	male(UNCLE).
aunt(AUNT, CHILD) :-
	parent(PARENT, CHILD),
	siblings1(PARENT, AUNT),
	female(AUNT).
grandchild(GRANDPARENT, CHILD) :-
	parent(PARENT, CHILD),
	parent(GRANDPARENT, PARENT).
grandson(GRANDPARENT, CHILD) :-
	grandchild(GRANDPARENT, CHILD),
	male(CHILD).
granddaughter(GRANDPARENT, CHILD) :-
	grandchild(GRANDPARENT, CHILD),
	female(CHILD).
greatgrandparent(GREATGRANDPARENT, CHILD) :-
	grandchild(GREATGRANDPARENT, PARENT),
	parent(PARENT, CHILD).
ancestor(ANCESTOR, CHILD) :-
	parent(ANCESTOR, CHILD);
	(parent(PARENT, CHILD), ancestor(ANCESTOR, PARENT)).