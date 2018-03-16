% Facts:

m([
    'Prince Andrew of Greece and Denmark',
    'King George VI',
    'Prince Philip',
    'Antony Armstrong-Jones',
    'Prince Charles',
    'Mark Philips',
    'Prince Andrew',
    'David Armstrong-Jones',
    'Prince Edward',
    'Peter Philips',
    'Jasper Cable-Alexander',
    'Prince William',
    'Prince Harry',
    'James, Viscount Severn'
]).

f([
    'Princess Alice of Battenberg',
    'Elizabeth the Queen Mother',
    'Queen Elizabeth II',
    'Princess Margaret',
    'Someone else',
    'Princess Diana',
    'Princess Anne',
    'Polly Higson',
    'Sarah Margaret Ferguson',
    'Sophie Helen Rhys-Jones',
    'Lady Sarah Chatto',
    'Zara Tindall',
    'Lady Frances von Hofmannsthal',
    'Princess Beatrice',
    'Princess Eugenie',
    'Lady Louise Windsor'
]).

family([
    'Prince Andrew of Greece and Denmark',
    'Princess Alice of Battenberg',
    [
        'Prince Philip'
    ]
]).

family([
    'King George VI',
    'Elizabeth the Queen Mother',
    [
        'Queen Elizabeth II',
        'Princess Margaret'
    ]
]).

family([
    'Prince Philip',
    'Queen Elizabeth II',
    [
        'Prince Charles',
        'Princess Anne',
        'Prince Andrew',
        'Prince Edward'
    ] 
]).

family([
    'Antony Armstrong-Jones',
    'Princess Margaret',
    [
        'David Armstrong-Jones',
        'Lady Sarah Chatto'
    ]
]).

family([
    'Antony Armstrong-Jones',
    'Someone else',
    [
        'Polly Higson',
        'Jasper Cable-Alexander',
        'Lady Frances von Hofmannsthal'
    ]
]).

family([
    'Prince Charles',
    'Princess Diana',
    [
        'Prince William',
        'Prince Harry'
    ]
]).

family([
    'Mark Philips',
    'Princess Anne',
    [
        'Peter Philips',
        'Zara Tindall'
    ]
]).

family([
    'Prince Andrew',
    'Sarah Margaret Ferguson',
    [
        'Princess Beatrice',
        'Princess Eugenie'
    ]
]).

family([
    'Prince Edward',
    'Sophie Helen Rhys-Jones',
    [
        'Lady Louise Windsor',
        'James, Viscount Severn'
    ]
]).

% Rules:

% X is male if it is a member of a list m.
male(X) :-
    m(List),
    member(X, List), !.     % the first match would suffice

% Y is female if it is a member of a list f.
female(Y) :-
    f(List),
    member(Y, List), !.

%% parent is either a first or second element of the list family
%parent(X) :-
%    family([X,_|_]), !;
%    family([_,X|_]), !.

parent(X, Child) :-
    family([X, _, Children]),
    member(Child, Children);
    family([_, X, Children]),
    member(Child, Children).
parent(X) :-
    parent(X, _), !.

% X is father if X is a parent and is male.
father(X) :-
    parent(X),
    male(X).

% Y is a mother if Y is a parent and is female.
mother(Y) :-
    parent(Y),
    female(Y).

% X and Y are siblings2 if they have both parents in common
siblings2(X, Y) :-
    family([_,_,Children]),
    member(X, Children),
    member(Y, Children),
    X \= Y.

% X and Y are siblings1 if they come from 
% different families, but have 1 parent in common.
siblings1(X, Y) :-
    family([Father,_,Children1]),
    family([Father,_,Children2]),
    Children1 \= Children2,
    member(X, Children1),
    member(Y, Children2).

siblings1(X, Y) :-
    family([_,Mother,Children1]),
    family([_,Mother,Children2]),
    Children1 \= Children2,
    member(X, Children1),
    member(Y, Children2).

% X is brother1 to Y if X is sibling1 to Y and is male.
brother1(X, Y) :-
    siblings1(X, Y),
    male(X).

% Y is sister1 to Y if X is sibling1 to Y and is female.
sister1(X, Y) :-
    siblings1(X, Y),
    female(X).

% X is brother2 to Y if X is sibling2 to Y and is male.
brother2(X, Y) :-
    siblings2(X, Y),
    male(X).

% X is sister2 to Y if X is sibling2 to Y and is female.
sister2(X, Y) :-
    siblings2(X, Y),
    female(X).

% X and Y are cousins if a Parent of X is a sibling2 to a Parent of Y
cousins(X, Y) :-
    parent(Parent1, X),
    parent(Parent2, Y),
    siblings2(Parent1, Parent2).

% X is uncle of Y if X is a brother of a parent of Y
uncle(X, Y) :-
    brother2(X, Parent),
    parent(Parent, Y).

% X is aunt of Y if X is a sister of a parent of Y
aunt(X, Y) :-
    sister2(X, Parent),
    parent(Parent, Y).

% child X of Y if Y is a father of X
child(X, Y) :-
    parent(Y, X).

% X is grandchild of Y if Y is a parent of a parent of X.
grandchild(X, Y) :-
    parent(Parent, X),
    parent(Y, Parent).

% X is grandson of Y if X is grandchild of Y and is male.
grandson(X, Y) :-
    grandchild(X, Y),
    male(X).

% X is a granddaughter of Y if X is granddaughter of Y and if female.
granddaughter(X, Y) :-
    grandchild(X, Y),
    female(X).

% X is a grandparent of Y if X is a parent of a parent of Y
grandparent(X, Y) :-
    parent(X, Parent),
    parent(Parent, Y).

% X is a greatgrandparent of Y if X is a parent of a grandparent of Y
greatgrandparent(X, Y) :-
    parent(X, Parent),
    grandparent(Parent, Y).



