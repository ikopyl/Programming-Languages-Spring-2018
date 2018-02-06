male(grandson).
age(grandson,22).
female(mom).
age(mom,50).
female(granddaughter).
age(granddaughter,24).
female(grandmother).
age(grandmother,78).

parent(mom,granddaughter).
parent(mom,grandson).
parent(grandmother,mom).

is_male(A) :-  male(A).
is_female(A) :- female(A).

grandparent(A,B) :- parent(A,T),parent(T,B).
grandchild(A,B) :- grandparent(B,A).

grandchildren(A,Age) :- findall(X,grandparent(A,X),List), oldest(List,Age).

oldest([X],Y) :- age(X,Y).
oldest([X|T],Age) :- oldest(T,Nage),age(X,A), Age is max(Nage,A).

oldestgchild(A,Name) :- grandchildren(A,Age), age(Name,Age).