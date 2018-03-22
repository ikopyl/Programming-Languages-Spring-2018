% Prolog MT prep

male(tom, 35).
male(peter, 65).
female(ann, 65).


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
