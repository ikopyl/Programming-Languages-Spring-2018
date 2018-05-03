%

from(sfo, dallas, 250).
from(sfo, altlanta, 320).
from(sfo, toronto, 400).
from(sfo, detroit, 430).
from(sfo, london, 1600).
from(sfo, paris, 1850).
from(dallas, london, 450).
from(dallas, paris, 700).
from(atlanta, toronto, 250).
from(atlanta, london, 420).
from(atlanta, paris, 730).
from(toronto, london, 300).
from(toronto, paris, 480).
from(detroit, london, 480).
from(detroit, paris, 666).
from(london, paris, 130).


find_route(X, Y, C) :-
    from(X, Y, C).      % base case

find_route(X, Y, C) :-
    from(X, I, C1),
    find_route(I, Y, C2),
    C is C1 + C2.

find_cost(X, Y, L) :-
    findall(C, find_route(X, Y, C), L).

listmin([X], X).
listmin([H|T], Min) :-
    listmin(T, Tmin),
    Min is min(H, Tmin).

mincost(X, Y) :-
    find_cost(X, Y, L),
    listmin(L, Min),
    write('Travel from '),
    write(X),
    write(' to '),
    write(Y), nl,
    write('All possible costs: '),
    write(L), nl,
    write('Minimum cost = '),
    write(Min), !.
