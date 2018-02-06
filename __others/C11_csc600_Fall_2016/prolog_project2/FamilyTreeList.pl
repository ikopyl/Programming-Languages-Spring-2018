ma([josh,roger,alex,mason,ron,jido,steven,joey,babbat,bob,bill]).
f([renee,shayna,sue,joyce,kim,hannah,adel]).

family([babbat,adel,[joyce]]).
family([joyce,bill,[bob]]).
family([jido,joyce,[renee,sue,steven]]).
family([roger,renee,[josh,shayna]]).
family([ron,sue,[alex,mason]]).
family([steven,kim,[hannah,joey]]).
family([bill,joyce,[bob]]).

male(X) :- ma(L), member(X,L).
female(X) :- f(L), member(X,L).

father(X,Y) :- family([X,_,T]),member(Y,T),male(X).
mother(X,Y) :- family([_,X,T]),member(Y,T),female(X).
parent(X,Y) :- family([F,M,T]),member(Y,T),member(X,[F,M]).

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
grandson(A,B) :- grandparent(B,A),male(A).
granddaughter(A,B) :- grandparent(B,A),female(A).

greatgrandparent(A,B) :- parent(A,P),grandparent(P,B).

ancestor(A,B) :- parent(A,B).
ancestor(A,B) :- parent(P,B), ancestor(A,P).
