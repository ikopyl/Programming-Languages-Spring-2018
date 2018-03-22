% Prolog MT prep

male(tom, 35).
male(peter, 65).
female(ann, 65).
female(elizabeth, 37).


% find the name and the age of a person
person(Name, Age) :-
    male(Name, Age);
    female(Name, Age).


% find the maximum of a list
maxlist([X], X).    % base case
maxlist([H|T], Max) :-
    maxlist(T, Tmax),
    Max is max(H, Tmax), !.


% find the age of the oldest person
maxage(MaxAge) :-
    findall(Age, person(_, Age), AgeList),
    maxlist(AgeList, MaxAge).


% find the name of the oldest person
oldest(Name) :-
    maxage(MaxAge),
    person(Name, MaxAge).



% find the mean value of the numbers in the list
mean([X], X, 0, 0) :- !.
mean([H|T], Mean, Sum, N) :-
    T = [],
    Sum1 is Sum + H,
    N1 is N + 1,
    Mean is Sum1 / N1, !.

mean([H|T], Mean, Sum, N) :-
    Sum1 is Sum + H,
    N1 is N + 1,
    mean(T, Mean, Sum1, N1).

mean(L, Mean) :-
    mean(L, Mean, 0, 0).


% display the list of age of male members and 
% return the mean age of all male members
meanAgeM(MeanAgeM) :-
    findall(Age, male(_, Age), MaleAgeList),
    mean(MaleAgeList, MeanAgeM).

% display the list of age of female members and
% return the mean age of all female members
meanAgeF(MeanAgeF) :-
    findall(Age, female(_, Age), FemaleAgeList),
    mean(FemaleAgeList, MeanAgeF).

