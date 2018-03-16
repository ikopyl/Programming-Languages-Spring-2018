% 8 Queens problem. 
% I hereby declare my intellectual bankruptcy 
% as of 03/16/2018. Predicates nocheck and legal are
% intellectual property of Adam Brooks Webber,
% and a courtesy of Professor Jozo Dujmovic.

% assembling the pieces from the slides:

% nocheck(X/Y,L) takes a queen X/Y and a list
% of other queens. Succeed if and only if the
% X/Y queen holds none of the others in check
%nocheck(_, []).
%nocheck(X/Y, [X1/Y1 | Rest]) :-
%    %    X =\= X1,
%    Y =\= Y1,
%    abs(Y1-Y) =\= abs(X1-X),
%    nocheck(X/Y, Rest).

% nocheck(Y, [Y1 | Rest]) :-
%     N is 1,
%     nocheck(Y, [Y1 | Rest], N).
nocheck(_, [], _) :- !.
nocheck(Y, [Y1 | Rest], N) :-
    Y =\= Y1,

    %    Y1-Y =\= N,
    %    Y-Y1 =\= N,

    abs(Y1-Y) =\= N,
    N1 is N + 1,
    nocheck(Y, Rest, N1).


legal([], _).
legal([Y | Rest], NumList) :-
    %print(Y),
    %print(Rest),
    legal(Rest, NumList),
    member(Y, NumList),
    nocheck(Y, Rest, 1).


eight_queens(N, L) :-
    natural_number(N),
    %    print(N),
    numlist(1, N, NumList),
    %print(NumList),
    %print(L),
    legal(L, NumList).


natural_number(0).
natural_number(N) :- 
    M is N - 1, 
    natural_number(M).


len(L, N) :-
    len(L, 0, N).
len([], N, N).
len([_|Tail], N0, N) :-
    N1 is N0 + 1,
    len(Tail, N1, N).


goal([ _, _, _, _, _, _, _, _]).
