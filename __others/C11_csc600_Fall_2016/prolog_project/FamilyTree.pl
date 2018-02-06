male(josh).
male(roger).
male(alex).
male(mason).
male(ron).
male(jido).
male(steven).
male(joey).
male(babbat).
male(bob).

female(renee).
female(shayna).
female(sue).
female(joyce).
female(kim).
female(hannah).
female(adel).

parent(renee,josh).
parent(roger,josh).
parent(renee,shayna).
parent(roger,shayna).
parent(jido,renee).
parent(joyce,renee).
parent(jido,sue).
parent(joyce,sue).
parent(sue,alex).
parent(ron,alex).
parent(sue,mason).
parent(ron,mason).
parent(steven,joey).
parent(kim,joey).
parent(steven,hannah).
parent(kim,hannah).
parent(joyce,steven).
parent(jido,steven).
parent(adel,joyce).
parent(babbat,joyce).
parent(joyce,bob).

mother(X,Y) :- parent(X,Y),female(X).
father(X,Y) :- parent(X,Y), male(X).

sibling1(A,B) :- parent(P,A), parent(P,B),A\=B. 
brother1(A,B) :- parent(P,A), parent(P,B), male(A), A\=B.
sister1(A,B) :- parent(P,A), parent(P,B), female(A), A\=B.

sibling2(A,B) :- mother(M,A), mother(M,B), father(F,A), father(F,B), A\=B.
brother2(A,B) :- mother(M,A), mother(M,B), father(F,A), father(F,B), male(A), A\=B.
sister2(A,B) :- mother(M,A), mother(M,B), father(F,A), father(F,B), female(A), A\=B.

cousin(A,B) :- parent(P1,A), parent(P2,B), sibling2(P1,P2).
aunt(A,B) :- parent(P,B), sibling2(P,A), female(A).
uncle(A,B) :- parent(P,B), sibling2(P,A), male(A).
grandparent(A,B) :- parent(A,P),parent(P,B).
grandmother(A,B) :- grandparent(A,B),female(A).
grandfather(A,B) :- grandparent(A,B),male(A).
grandchild(A,B) :- grandparent(B,A).

greatgrandparent(A,B) :- parent(A,P),grandparent(P,B).

ancestor(A,B) :- parent(A,B).
ancestor(A,B) :- parent(P,B), ancestor(A,P).