is_male(emil).
is_male(eric).
is_male(eugene).
is_male(elmer).
is_male(ernesto).
is_male(elijames).
is_male(joshua).
is_male(arnell).
is_male(fernando).

is_female(loreena).
is_female(leilani).
is_female(nenita).
is_female(elyza).
is_female(lilliana).
is_female(erlinda).
is_female(jolie).

is_parent_of(fernando,ernesto).
is_parent_of(jolie,ernesto).
is_parent_of(arnell,nenita).
is_parent_of(erlinda,nenita).
is_parent_of(ernesto,emil).
is_parent_of(ernesto,eric).
is_parent_of(ernesto,eugene).
is_parent_of(ernesto,elmer).
is_parent_of(ernesto,loreena).
is_parent_of(ernesto,leilani).
is_parent_of(nenita,emil).
is_parent_of(nenita,eric).
is_parent_of(nenita,eugene).
is_parent_of(nenita,elmer).
is_parent_of(nenita,loreena).
is_parent_of(nenita,leilani).
is_parent_of(elmer,elijames).
is_parent_of(elmer,joshua).
is_parent_of(eugene,elyza).
is_parent_of(loreena,lilliana).

mother(MOTHER, CHILD) :-
	is_female(MOTHER),
    is_parent_of(MOTHER, CHILD).

father(FATHER, CHILD) :-
    is_male(FATHER),
    is_parent_of(FATHER, CHILD).

sibling1(NAME1, NAME2) :-
    is_parent_of(PARENT, NAME1),
    is_parent_of(PARENT, NAME2),
    NAME1 \= NAME2.
brother1(NAME1, NAME2) :-
    sibling1(NAME1,NAME2),
    is_male(NAME1).
sister1(NAME1, NAME2) :-
    sibling1(NAME1,NAME2),
	is_female(NAME1).

sibling2(NAME1, NAME2) :-
	is_parent_of(PARENT1, NAME1),
	is_parent_of(PARENT1, NAME2),
	is_parent_of(PARENT2, NAME1),
	is_parent_of(PARENT2, NAME2),
	NAME1 \= NAME2,
	PARENT1 \= PARENT2.
brother2(NAME1, NAME2) :-
    sibling2(NAME1,NAME2),
	is_male(NAME1).
sister2(NAME1, NAME2) :-
    sibling2(NAME1,NAME2),
	is_female(NAME1).
	

cousin(NAME1, NAME2) :-
	is_parent_of(PARENT1, NAME1),
	sibling1(PARENT1, PARENT2),
	is_parent_of(PARENT2, NAME2).
uncle(UNCLE, CHILDNAME) :-
	is_male(UNCLE),
	is_parent_of(PARENT, CHILDNAME),
	(sibling1(UNCLE, PARENT); sibling2(UNCLE, PARENT)).
aunt(AUNT, CHILDNAME) :-
	is_female(AUNT),
	is_parent_of(PARENT, CHILDNAME),
	(sibling1(AUNT, PARENT); sibling2(AUNT, PARENT)).
grandparent(GRANDPARENT, GRANDCHILD) :-
	is_parent_of(CHILD, GRANDCHILD),
	is_parent_of(GRANDPARENT, CHILD).
grandmother(GRANDMOTHER, GRANDCHILD) :-
	is_female(GRANDMOTHER),
	grandparent(GRANDMOTHER, GRANDCHILD).
grandfather(GRANDFATHER, GRANDCHILD) :-
	is_male(GRANDFATHER),
	grandparent(GRANDFATHER, GRANDCHILD).
grandchild(GRANDCHILD, GRANDPARENT) :-
	is_parent_of(CHILD, GRANDCHILD),
	is_parent_of(GRANDPARENT, CHILD).

greatgrandparent(GREATGRANDPARENT, GREATGRANDCHILD) :-
	grandparent(GRANDPARENT, GREATGRANDCHILD),
	is_parent_of(GREATGRANDPARENT, GRANDPARENT).

ancestor(ANCESTOR, CHILDNAME) :-
	is_parent_of(ANCESTOR, CHILDNAME); 
	(is_parent_of(ANCESTOR, PARENT),
	ancestor(PARENT, CHILDNAME)).
