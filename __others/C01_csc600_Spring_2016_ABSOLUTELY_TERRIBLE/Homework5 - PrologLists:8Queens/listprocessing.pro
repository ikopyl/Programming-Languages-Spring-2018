testmember(X, [H | T]) :-
	(X = H);
	testmember(X, T).


firstelement(X, [X | _]).

lastelement(X, [X]).
lastelement(X, [_ | T]) :-
	(lastelement(X, T)).

twoadjacent(X, Y, [X, Y | _]).
twoadjacent(X, Y, [_ | T]) :-
	twoadjacent(X, Y, T).

threeadjacent(X, Y, Z, [X, Y, Z | _]).
threeadjacent(X, Y, Z, [_ | T]) :-
	threeadjacent(X, Y, Z, T).

appendlists([], LIST2, LIST2).
appendlists([H | T], LIST2, [H | TAIL]) :-
	appendlists(T, LIST2, TAIL).

deleteelement(X, [X | T], T).
deleteelement(X, [H | T], [H | TAIL]) :-
	deleteelement(X, T, TAIL).

appendelement(X, [], [X]).
appendelement(X, [H | T], [H | TAIL]) :-
	appendelement(X, T, TAIL).

insertelement(X, LIST1, NEWLIST) :-
	deleteelement(X, NEWLIST, LIST1).

listlength([], 0).
listlength([_ | T], LENGTH) :-
	listlength(T, NUM), LENGTH is NUM + 1.

reverselist([], []).
reverselist([H | T], REVERSELIST) :-
	reverselist(T, TAIL),
	append(TAIL, [H], REVERSELIST).

checkpalindrome(LIST1) :-
	reverselist(LIST1, LIST2),
	LIST1 = LIST2.

displaylist([]) :-
	nl.
displaylist([H | T]) :-
	write(H),
	displaylist(T).
