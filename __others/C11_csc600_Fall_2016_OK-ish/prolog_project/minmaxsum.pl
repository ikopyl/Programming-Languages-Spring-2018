minmaxlist([X],X,X).
minmaxlist([X|T],Max,Min) :- 	minmaxlist(T,Nmax,Nmin),
								Max is max(X,Nmax),
								Min is min(X,Nmin).
								
sum([H|T],Sum) :- minmaxlist([H|T],Max,Min),
				Sum is Min + Max.
				  