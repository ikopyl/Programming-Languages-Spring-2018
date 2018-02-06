# Nehemya McCarter-Ribakoff
# Jozo
# CSC600 / MWF 12:10PM
# 16 October 2016

# 1. 
m([raul, juan, hector, jose, alejandro, pepito, jesus, julio]).
f([maria, irma, alma, juanita, coralia, gloria, marisa]).
family( [raul, juanita, [maria, alma, juan, jose, irma, hector]] ).
family( [ricardo, maria, [alejandro]]).
family([juan, marisa, [julio, gloria]]).
family( [alejandro, coralia, [pepito, jesus]]).

male(X)   :- m(M), member(X, M).
female(X) :- f(F), member(X, F).

parent(P, C)    :- family([P, _, Children]), member(C, Children); family([_, P, Children]), member(C, Children).
father(F, C)    :- male(F), parent(F, C).
mother(M, C)    :- female(M), parent(M, C).
greatgrandparent(GG, C) :- parent(GG, GP), parent(GP, P), parent(P, C).
ancestor(A, C)  :- parent(A, C); parent(A, P), ancestor(A, P).

siblings1(S, C) :- family([_, _, Children]), member(S, Children), member(C, Children).
siblings2(C, S) :- family([_, _, Children]), member(C, Children), member(S, Children).
brother1(B, C)  :- male(B), siblings1(B, C).
brother2(C, B)  :- male(B), siblings2(C, B).
sister1(S, C)   :- female(S), siblings1(S, C).
sister2(C, S)   :- female(S), siblings2(C, S).

cousins(C1, C2) :- parent(P1, C1), parent(P2, C2), siblings1(P1, P2), P1\=P2.

aunt(A, C)  :- sister1(A, P), parent(P, C).
uncle(U, C) :- brother1(U, P), parent(P, C).

grandchild(C, G)     :- parent(G, P), parent(P, C).
grandson(GS, G)      :- grandchild(GS, G), male(GS).
granddaughter(GD, G) :- grandchild(GD, G), female(GD).

# 2.

