% Operations on lists.

% append list1 to list2 producing list3
% Base case: if List1 is empty list, then result is List2.
% Otherwise, if List1 is not empty, chop the head from both 
% List1 & List3 until you approach the base case.
append1([], L2, L2).
append1([H|T1], L2, [H|T3]) :-
    append1(T1, L2, T3).

% auxiliary definition
prefix1(Prefix, List) :-
    append1(Prefix, _, List).

% auxiliary definition
suffix(Suffix, List) :-
    append1(_, Suffix, List).

% auxiliary definition
% sublist is a prefix of a suffix of a list
sublist(Sublist, List) :-
    prefix(Sublist, Suffix),
    suffix(Suffix, List).

% membership testing (checks if an element is a member of a list)
member1(X, List) :-
    sublist([X], List).

% first element of the list
first_element(X1, List) :-
    prefix([X1], List).

% last element of the list
last_element(Xn, List) :-
    suffix([Xn], List).

% two adjacent elements in the list
two_adjacent(X, Y, List) :-
    sublist([X, Y], List).

% three adjacent elements in the list
three_adjacent(X, Y, Z, List) :-
    sublist([X, Y, Z], List).

% auxiliary definition
select1(X, [X|Xs], Xs).
select1(X, [Y|Ys], [Y|Zs]) :-
    select1(X, Ys, Zs).

% delete an element from a list (delete 1 occurrence)
del1(X, List, Result) :-
    select1(X, List, Result).

% delete element from a list (delete all occurrences)
del_all(_, [], []).
del_all(H, [H|T], Result) :-
    del_all(H, T, Result).
del_all(X, [H|T1], [H|T2]) :-
    H=\=X,
    del_all(X, T1, T2).


% append element to a list
append_element(X, List, Result) :-
    append1(List, [X], Result).


% insert element in a list
insert_element(X, List, Result) :-
    select1(X, Result, List).


% compute the length of a list
len(L, N) :-
    len(L, 0, N).
len([], N, N).
len([_|Tail], N0, N) :-
    N1 is N0 + 1,
    len(Tail, N1, N).


% reverse a list in linear time:
reverse1(List, Reversed) :-
    reverse1(List, [], Reversed).
reverse1([], Reversed, Reversed).
reverse1([H|T], Acc, Reversed) :-
    reverse1(T, [H|Acc], Reversed).


% check whether a list is a palindrome
palindrome(List) :-
    reverse1(List, List).


% display a list
puts([]).
puts([H|T]) :-
    write(H),
    write(' '),
    puts(T).

