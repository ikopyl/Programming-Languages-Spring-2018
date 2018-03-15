% Operations on lists.

% Base case: if List1 is empty list, then result is List2.
% Otherwise, if List1 is not empty, chop the head from both 
% List1 & List3 until you approach the base case.
append1([], L2, L2).
append1([H|T1], L2, [H|T3]) :-
    append1(T1, L2, T3).

prefix(Prefix, List) :-
    append1(Prefix, _, List).

suffix(Suffix, List) :-
    append1(_, Suffix, List).

% sublist is a prefix of a suffix of a list
sublist(Sublist, List) :-
    prefix(Sublist, Suffix),
    suffix(Suffix, List).

member1(X, List) :-
    sublist([X], List).

first_element(X1, List) :-
    prefix([X1], List).

last_element(Xn, List) :-
    suffix([Xn], List).


