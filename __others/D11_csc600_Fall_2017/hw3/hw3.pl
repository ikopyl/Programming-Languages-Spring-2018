
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
ancestor(A, C)  :- parent(A, C).
ancestor(A, C)  :- parent(P, C), ancestor(A, P).

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


is_member(X, L) :- member(X, L).
is_head(X, L) :- [H|_] = L, H = X.
last_element([X], X).
last_element([_|T], X) :- last_element(T, X).
adjacent2(X,Y,[X,Y|_]).
adjacent2(X,Y,[_|T]) :- adjacent2(X,Y,T).

adjacent3(X,Y,Z,[X,Y,Z|_]).
adjacent3(X,Y,Z,[_|T]) :- adjacent3(X,Y,Z,T).

append1([],L,L).
append2ppend1([X|T1],L2,[X|T3]) :- append1(T1,L2,T3).

delete1(X,[X|T],T).
delete1(X,[H,T],[H,T1]) :- delete1(X,T,T1).

append2([],E,[E]).
append2([X|T1],E2,[X|T3]) :- append2(T1,E2,T3).

insert1(X,L,XL) :- delete1(X,XL,L).

length1([],0).
length1([_|T],N) :- length1(T,N1), N is 1 + N1.

reverse1([],[]).
reverse1([H|T],X) :- reverse1(T,Y), append2(Y,H,X).

palindrome(L1) :- reverse1(L1,X), X=L1.

display1([]) :- nl.
display1([H|T]) :- write(H), tab(1), display1(T).


nocheck(_,[]).
nocheck(X/Y,[X1/Y1 | Rest]) :- 
	X=\=X1, 
	Y=\=Y1, 
	abs(Y1-Y) =\= abs(X1-X), 
	nocheck(X/Y,Rest).

legal([]).
legal([X/Y | Rest]) :-
	legal(Rest),
	member(X,[1,2,3,4,5,6,7,8]),
	member(Y,[1,2,3,4,5,6,7,8]),
	nocheck(X/Y, Rest).

eight_queens(X) :-
	X = [1/_,2/_,3/_,4/_,5/_,6/_,7/_,8/_],
	legal(X).
