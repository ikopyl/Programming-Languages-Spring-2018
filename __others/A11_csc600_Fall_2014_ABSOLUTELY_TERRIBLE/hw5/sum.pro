sum(List, MinPlusMax) :- maxlist(List, Max), minlist(List,Min), X is Max+Min.
maxlist([X],X).
maxlist([H|T],Max) :- maxlist(T,Tmax), Max is max(H,Tmax).
minlist([X]|X).
minlist(List,Min) :- minlist(T, Tmin), Min is min(H, Min).