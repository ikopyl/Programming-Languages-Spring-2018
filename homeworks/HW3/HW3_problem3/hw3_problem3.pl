% N Queens problem. 
% 
% Predicates nocheck and legal initially were
% intellectual property of Adam Brooks Webber,
% but I took some liberty and modified them to 
% solve n queens problem. 
%
% I also took a liberty of representing 
% the queen's position with just one number - 
% the second coordinate is implied by the index 
% of that element in the list.


% nocheck(Y,L) takes a queen Y and a list
% of other queens. Succeeds if and only if 
% the Y queen holds none of the others in 
% check.
nocheck(_, [], _) :- !.
nocheck(Y, [Y1 | Rest], N) :-
    Y =\= Y1,
    abs(Y1-Y) =\= N,
    N1 is N + 1,
    nocheck(Y, Rest, N1).


legal([], _).
legal([Y | Rest], NumList) :-
    legal(Rest, NumList),
    member(Y, NumList),
    nocheck(Y, Rest, 1).


n_queens(N, L) :-
    natural_number(N),
    numlist(1, N, NumList),
    permutation(NumList, L),
    legal(L, NumList).


natural_number(0).
natural_number(N) :- 
    M is N - 1, 
    natural_number(M).

