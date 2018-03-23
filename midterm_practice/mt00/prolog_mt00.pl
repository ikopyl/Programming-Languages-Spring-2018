% practicing Prolog MT00

population('China', 1347).
population('India', 1210).
population('USA', 314).
population('Indonesia', 237).
population('Brasil', 193).
population('Japan', 127).

area('China', 9.5).
area('India', 2.9).
area('USA', 9.1).
area('Indonesia', 1.8).
area('Brasil', 8.4).
area('Japan', 0.36).

density([Country, Density]) :-
    population(Country, Population),
    area(Country, Area),
    Density is Population / Area.

makelist(CDList) :-
    findall(X, density(X), CDList).


% auxiliary definition
maxlist([X], X).
maxlist([H|T], Max) :-
    maxlist(T, Tmax),
    Max is max(H, Tmax), !.


% auxiliary definition
minlist([X], X).
minlist([H|T], Min) :-
    minlist(T, Tmin),
    Min is min(H, Tmin), !.


listmax([Cmax, Dmax]) :-
    findall(D, density([_, D]), Keys),
    maxlist(Keys, Dmax),
    density([Cmax, Dmax]), !.


listmin([Cmin, Dmin]) :-
    findall(D, density([_, D]), Keys),
    minlist(Keys, Dmin),
    density([Cmin, Dmin]), !.


maxden(Cmax, Dmax) :-
    listmax([Cmax, Dmax]).
maxden() :-
    maxden(Cmax, Dmax),
    display(Cmax),
    nl,
    display(Dmax).


minden(Cmin, Dmin) :-
    listmin([Cmin, Dmin]).
minden() :-
    minden(Cmin, Dmin),
    display(Cmin),
    nl,
    display(Dmin).

