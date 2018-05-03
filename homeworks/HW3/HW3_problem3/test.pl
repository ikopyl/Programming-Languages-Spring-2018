%
s(Queens, [Queen|Queens]) :- 
    member(Queen, [1,2,3,4,5,6,7,8]),
    noattack(Queen, Queens, 1).

% goal([_,_,_,_,_,_,_,_]).

noattack(_, [], _) :- !.
noattack(Y, [Y1|Ylist], N) :-   
    Y =\= Y1,

    abs(Y1-Y) =\= N,
    %    Y1-Y =\= N,
    %    Y-Y1 =\= N,

    N1 is N + 1,
    noattack(Y, Ylist, N1).

solve(N,[N]) :- 
    goal(N).

solve(N, [N|Sol1]) :- s(N,N1),
                      solve(N1,Sol1).

