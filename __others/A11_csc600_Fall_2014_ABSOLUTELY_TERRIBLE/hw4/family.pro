%Facts
m([taikai,namihei,kaihei,taizou,toshio,norisuke,katuo,masuo,sakeo,
	ikura,tarao,norio]).
f([nagie,fune,okoze,nanako,kaoru,taiko,wakame,sazae]).

family([masuo,sazae,[tarao]]).
family([namihei,fune,[wakame,katuo,sazae]]).
family([sakeo,_,[norio]]).
family([_,_,[masuo,sakeo]]).
family([norisuke,taiko,[ikura]]).
family([_,nagie,[norisuke]]).
family([kaihei,_,[kaoru]]).
family([taizou,okoze,[]]).
family([toshio,_,[nanako]]).
family([_,_,[fune,taizou,toshio]]).
family([taikai,_,[nagie,kaihei,namihei]]).

%Rules
male(X) :- m(M), member(X,M).
female(X) :- f(F), member(X,F).

father(X,C) :- family([X,_,L]), member(C,L).
mother(X,C) :- family([_,X,L]), member(C,L).
parent(X,C) :- family([_,X,L]), member(C,L).
parent(X,C) :- family([X,_,L]), member(C,L).

siblings1(X,Y) :- parent(A,X), parent(B,Y), A==B, X\=Y.
siblings2(X,Y) :- family([_,_,L]), member(X,L), member(Y,L), X\=Y.
brother1(X,Y) :- siblings1(X,Y), male(X), male(Y).
brother2(X,Y) :- siblings2(X,Y), male(X), male(Y).
sister1(X,Y) :- siblings1(X,Y), female(X), female(Y).
sister2(X,Y) :- siblings2(X,Y), female(X), female(Y).
cousins(X,Y) :- siblings1(A,B), parent(C,X), parent(D,Y), A==C, B==D.

uncle(U,C) :- parent(X,C), siblings1(Y,U), male(U), X==Y.
aunt(A,C) :- parent(X,C), siblings1(Y,A), female(A), X==Y.
grandparent(G,C) :- parent(X,C), parent(G,Y), X==Y.
grandmother(G,C) :- grandparent(X,C), female(G), X==G.
grandfather(G,C) :- grandparent(X,C), male(G), X==G.
grandchild(C,G) :- grandparent(G,C).

greatgrandparent(G,C) :- parent(G,X), grandparent(Y,C), X==Y.
ancestor(A,C) :- greatgrandparent(A,C).
ancestor(A,C) :- parent(P,C), ancestor(A,P).


