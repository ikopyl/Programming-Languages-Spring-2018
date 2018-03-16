% recursive definitions of sublist prerequisites: prefix & suffix: 

append1([], Ys, Ys).
append1([X|Xs], Ys, [X|Zs]) :-
    append1(Xs, Ys, Zs).

%prefix([], _).
%prefix([X|Xs], [X|Ys]) :-
%    prefix(Xs, Ys).

prefix(Xs, Ys) :-
    append1(Xs, _, Ys).


%suffix(Xs, Xs).
%suffix(Xs, [_|Ys]) :-
%    suffix(Xs, Ys).

suffix(Xs, Ys) :-
    append1(_, Xs, Ys).


% sublist as a suffix of a prefix:
%sublist(Xs, Ys) :-
%    prefix(Ps, Ys),
%    suffix(Xs, Ps).


% sublist as a prefix of a suffix:
%sublist(Xs, Ys) :-
%    prefix(Xs, Ss),
%    suffix(Ss, Ys).

% recursive definition of sublist:
% preferred solution:
%sublist(Xs, Ys) :-
%    prefix(Xs, Ys).
%sublist(Xs, [_|Ys]) :-
%    sublist(Xs, Ys).

% sublist as suffix of a prefix, using append
% the same result as in the recursive definition
sublist(Xs, AsXsBs) :-
    append1(_, XsBs, AsXsBs),
    append1(Xs, _, XsBs).

% sublist as prefix of a suffix, using append
%sublist(Xs, AsXsBs) :-
%    append1(AsXs, _, AsXsBs),
%    append1(_, Xs, AsXs).


% HW3.2 answers:

% membership testing:
member(X, [X|_]).
member(X, [_|Ys]) :-
    member(X, Ys).


% alternative solution of membership testing:
%member(X, Xs) :-
%    sublist([X], Xs).


% experimenting with natural numbers
% check out the lecture slides too
% natural_number(0).
% natural_number(s(X)) :-
%     natural_number(X).
% 
% 
% plus(0,X,X) :-
%     natural_number(X).
% plus(s(X), Y, s(Z)) :-
%     plus(X,Y,Z).



% ?- concatenate_lists(X,Y, [1,2]).
% X = [],
% Y = [1, 2] ;
% X = [1],
% Y = [2] ;
% X = [1, 2],
% Y = [] ;

% append element X to list L IFF there exist 
% list Lx such that [L1,L2, ... , Ln, X, []]
append_element(X, L, Lx) :-
    append1(L,[X], Lx).
    
natural_number(s(0), 0).
natural_number(s(s(X)), N) :- natural_number(s(X), S), N is S + 1.


