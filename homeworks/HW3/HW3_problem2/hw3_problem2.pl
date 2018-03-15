% Operations on lists:

append1([], L2, L3).
append1([H|T1], L2, [H|T3]) :-
    append1(T1, T2, L3).

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


