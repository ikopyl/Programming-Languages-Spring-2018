m([abraham, brock, dean, hank, jeffrey, john, jordan, justin, ralph, rusty]).  
f([cindy, eve, ethyl, gertrude, jackie, jill, jody, kristy, sandy]).
family([abraham, ethyl, [ralph]]).
family([gertrude, ralph, [john, rusty]]).   
family([rusty, eve, [hank, dean, brock, sandy, kristy, jody]]).
family([john, jill, [jackie, jordan, jeffrey, justin]]).

male(X) 	           :- m(Male), member(X,Male).
female(X) 	           :- f(Female), member(X,Female).
parent(P,C)            :- family([P,_,Children]), member(C,Children); family([_,P,Children]), member(C,Children).
father(F,C)            :- male(F), parent(F,C).
mother(M,C)            :- female(M), parent(M,C).
siblings1(S,C)         :- family([_,_,Children]), member(S,Children), member(C,Children).
siblings2(C,S)         :- family([_,_,Children]), member(S,Children), member(C,Children).
brother1(B,C)          :- siblings1(B,C), male(B).
brother2(C,B)          :- siblings1(C,B), male(B).
sisters1(S,C)          :- siblings1(S,C), female(S).
sisters2(C,S)          :- siblings1(C,S), female(S).
cousins(X,C)           :- parent(P1,X), parent(P2,C), siblings1(P1,P2), P1\=P2.
uncle(U,C)             :- parent(P1,C), brother1(P1,U).
aunt(A,C)              :- parent(P1,C), aunt1(P1,A).
grandchild(C,G)        :- parent(G,P1), parent(P1,C).
grandson(C,G)          :- grandchild(C,G), male(C).
granddaughter(C,G)     :- grandchild(C,G), female(C).
greatgrandparent(G,C)  :- grandchild(C,P1), parent(G,P1).
ancestor(A,C)          :- parent(A,C); parent(P,C), ancestor(A,P).

l1([1,2,3,4,5]).
l2([5,4,3,2,1]).

ismember(X,[X|_]).
ismember(X,[_|Tail]) :- ismember(X,Tail).
ishead(X,[X|_]).
istail([X],X).
istail([_|Tail],X) :- istail(Tail,X).
aretwoadjacent(X,Y,[X,Y|_]).
aretwoadjacent(X,Y,[_|Tail]) :- aretwoadjacent(X,Y,Tail).
arethreeadjacent(X,Y,Z,[X,Y,Z|_]).
arethreeadjacent(X,Y,Z,[_|Tail]) :- arethreeadjacent(X,Y,Z,Tail).
appendlists([],L1,L2).
appendlists([X|Tail],L2,[X,Tail2]) :- appendlists(Tail,L2,Tail2).
removeelem(X,[X|Tail],Tail).
removeelem(X,[Head|Tail],[Head,Tail2]) :- removeelem(X,Tail,Tail2).
appendelem([],X,[X]).
appendelem([X|Tail],Y,[X|Tail2]) :- appendelem(Tail,Y,Tail2).
insertelem(X,L,Expanded) :- removeelem(X,Expanded,L).
getlength([],0).
getlength([_|Tail],Length) :- getlength(Tail,Count), Length is 1 + Count.
reverselist([],[]).
reverselist([Head|Tail],X) :- reverselist(Tail,Y), appendelem(Y,Head,X).
ispalindrome(List) :- reverselist(List,X), X=List.
showlist([]) :- nl.
showlist([Head|Tail]) :- write(Head), tab(1), showlist(Tail).

nocheck(_,[]).
nocheck(X/Y,[X1/Y1 | Tail]) :- 
	X=\=X1, 
	Y=\=Y1, 
	abs(Y1-Y) =\= abs(X1-X), 
	nocheck(X/Y,Tail).

legal([]).
legal([X/Y | Tail]) :-
	legal(Rest),
	member(X,[1,2,3,4,5,6,7,8]),
	member(Y,[1,2,3,4,5,6,7,8]),
	nocheck(X/Y, Tail).

eightqueens(X) :-
	X = [1/_,2/_,3/_,4/_,5/_,6/_,7/_,8/_],
	legal(X).




