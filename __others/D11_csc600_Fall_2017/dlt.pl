%make facts for the population of each country
population(china,1347).
population(india,1210).
population(usa,314).
population(indonesia,237).
population(brazil,193).
population(japan,127).

%make facts for the area of each country
area(china,9.5).
area(india,2.9).
area(usa,9.1).
area(indonesia,1.8).
area(brazil,8.4).
area(japan,0.36).

%make the rule density(|Country, Density|) that returns a pair as a list
density([C,D]) :- population(C, P), area(C, A), D is P/A.

lastElement([Element], Element).
lastElement([_|T], Element) :- lastelement(T, Element).

adjacent(X, Y, [X, Y|_]).
adjacent(First, Second, [_|T]) :- adjacent(First, Second, T).
makelist(CDlist) :- findall([C|D], density([C|D]), CDlist).

minplusmax(List, Result) :- minL(List, Min), maxL(List, Max), Result is Min + Max.

minL([X], X).
minL([H|T], Result) :- minL(T, Minimum), Result is min(H, Minimum).

maxL([X], X).
maxL([H|T], Result) :- maxL(T, Maximum), Result is max(H, Maximum).
