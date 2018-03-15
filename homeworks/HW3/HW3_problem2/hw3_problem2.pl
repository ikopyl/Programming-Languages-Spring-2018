% Operations on lists.

% append list1 to list2 producing list3
% Base case: if List1 is empty list, then result is List2.
% Otherwise, if List1 is not empty, chop the head from both 
% List1 & List3 until you approach the base case.
append1([], L2, L2).
append1([H|T1], L2, [H|T3]) :-
    append1(T1, L2, T3).

% auxiliary definition
prefix(Prefix, List) :-
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


% delete element from a list


% append element to a list
append_element(X, List, ListPlusX) :-
    append1(List, [X], ListPlusX).


% insert element in a list


% compute the length of a list


% reverse a list


% check whether a list is a palindrome


% display a list
