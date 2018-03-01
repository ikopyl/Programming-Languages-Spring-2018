member1(X, [X|_]).
member1(X, [_|T]) :- member1(X, T).

first_element(X, [X|_]).

adjacent(X, Y, [X,Y|_]).
adjacent(X, Y, [_|T]) :- adjacent(X, Y, T).

adjacent(X, Y, Z, [X,Y,Z|_]).
adjacent(X, Y, Z, [_|T]) :- adjacent(X, Y, Z, T).

append1([], L2, L2).
append1([X|T1], L2, [X|T3]):- append1(T1,L2,T3).

del(X, [X|T], T).
del(X, [H|T], [H|T1]) :- del(X, T, T1).

append_element([], E, [E]).
append_element([X|T1], E, [X|T3]):- append_element(T1,E,T3).

insert(X, L, XL) :- del(X, XL, L).

len([], 0).
len([_|T], N) :- len(T, N1), N is 1 + N1.

reverse([],[]).
reverse([H|T], Rev) :- reverse(T,RT),
append(RT, [H], Rev).

palindrome(L1) :- reverse(L1,L2),L1=L2.

showlist( [ ] ) :- nl.
showlist([H|T]) :- write(H), tab(1),
showlist(T).