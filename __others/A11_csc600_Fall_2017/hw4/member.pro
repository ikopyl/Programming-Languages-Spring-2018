%Facts
demolist([a,b,c,d,e]).

%Rules
member1(X,[X|_]).
member1(X,[_|T]) :- member1(X,T).

firstelement(X,[X|_]).
lastelement(X,[X]).
lastelement(X,[_|T]) :- lastelement(X,T).

adjacent(X,Y,[X,Y|_]).
adjecent(X,Y,[_|T]) :- adjecent(X,Y,T).

append1([],L2,L2).
append1([X|T1],L2,[X|T3]) :- append1(T1,L2,T3).

delete(X,[X|T],T).
delete(X,[H|T],[H|T1]) :- delete(X,T,T1).

insert(X,L,XL) :- delete(X,XL,L).

len([], 0).
len([_|T],N) :- len(T, N1), N is 1 + N1.

reverse([],[]).
reverse([H|T], Rev) :- reverse(T, RT), append1(RT,[H],Rev).

palindrome(L1) :- reverse(L1, Rev), Rev == L1.

display([]).
display([X|T]) :- write(X), write(' '), display(T).
