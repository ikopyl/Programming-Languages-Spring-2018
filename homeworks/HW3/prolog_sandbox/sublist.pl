% recursive definitions of sublist prerequisites: prefix & suffix: 

prefix([], _).
prefix([X|Xs], [X|Ys]) :-
    prefix(Xs, Ys).


suffix(Xs, Xs).
suffix(Xs, [_|Ys]) :-
    suffix(Xs, Ys).


% sublist as a suffix of a prefix:
%sublist(Xs, Ys) :-
%    prefix(Ps, Ys),
%    suffix(Xs, Ps).


% sublist as a prefix of a suffix:
%sublist(Xs, Ys) :-
%    prefix(Ps, Ys),
%    suffix(Xs, Ps).

% recursive definition of sublist:
% preferred solution:
sublist(Xs, Ys) :-
    prefix(Xs, Ys).
sublist(Xs, [_|Ys]) :-
    sublist(Xs, Ys).


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


concatenate_lists([], Ys, Ys).
concatenate_lists([X|Xs], Ys, [X|Zs]) :-
    concatenate_lists(Xs, Ys, Zs).

% ?- concatenate_lists(X,Y, [1,2]).
% X = [],
% Y = [1, 2] ;
% X = [1],
% Y = [2] ;
% X = [1, 2],
% Y = [] ;



