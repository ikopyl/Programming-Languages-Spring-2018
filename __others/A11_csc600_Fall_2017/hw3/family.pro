%Facts
is_male(taikai).
is_male(namihei).
is_male(kaihei).
is_male(taizou).
is_male(toshio).
is_male(norisuke).
is_male(katuo).
is_male(masuo).
is_male(sakeo).
is_male(ikura).
is_male(tarao).
is_male(norio).

is_female(nagie).
is_female(fune).
is_female(okoze).
is_female(nanako).
is_female(kaoru).
is_female(taiko).
is_female(wakame).
is_female(sazae).

is_parent_of(sazae,tarao).
is_parent_of(masuo,tarao).
is_parent_of(sakeo,norio).
is_parent_of(taiko,ikura).
is_parent_of(norisuke,ikura).
is_parent_of(nagie,norisuke).
is_parent_of(kaihei,kaoru).
is_parent_of(namihei,wakame).
is_parent_of(fune,wakame).
is_parent_of(namihei,katuo).
is_parent_of(fune,katuo).
is_parent_of(namihei,sazae).
is_parent_of(fune,sazae).
is_parent_of(toshio,nanako).
is_parent_of(taikai,nagie).
is_parent_of(taikai,kaihei).
is_parent_of(taikai,namihei).

%Rules
mother(M,C) :- is_parent_of(M,C), is_female(M).
father(F,C) :- is_parent_of(F,C), is_male(F).

sibling1(X,Y) :- is_parent_of(A,X), is_parent_of(A,Y), X\=Y.
brother1(X,Y) :- sibling1(X,Y), is_male(X), is_male(Y).
sister1(X,Y) :- sibling1(X,Y), is_female(X), is_female(Y).

sibling2(X,Y) :- is_parent_of(A,X), is_parent_of(A,Y),
	is_parent_of(B,X), is_parent_of(B,Y), X\=Y, A\=B.
brother2(X,Y) :- sibling2(X,Y), is_male(X), is_male(Y).
sister2(X,Y) :- sibling2(X,Y), is_female(X), is_female(Y).

cousin(X,Y) :- is_parent_of(A,X), is_parent_of(B,Y), sibling1(A,B).
uncle(U,C) :- is_parent_of(X,C), sibling1(X,U), is_male(U).
aunt(A,C) :- is_parent_of(X,C), sibling1(X,A), is_female(A).
grandparent(G,C) :- is_parent_of(X,C), is_parent_of(G,X).
grandmother(G,C) :- grandparent(G,C), is_female(G).
grandfather(G,C) :- grandparent(G,C), is_male(G).
grandchild(C,G) :- grandparent(G,C).

greatgrandparent(G,C) :- is_parent_of(X,C), is_parent_of(Y,X), is_parent_of(G,Y).
ancestor(A,C) :- greatgrandparent(A,C).

