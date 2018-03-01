teaches(souza,210-01).
teaches(souza,210-02).
teaches(wong,220-01).
teaches(wong,220-02).
teaches(sosnick,256-01).
teaches(sosnick,256-02).
teaches(tomasevich,300-01).
teaches(tomasevich,300-02).
teaches(tomasevich,300-03).
teaches(sosnick,413-03).
teaches(dujmovic,600-01).
teaches(dujmovic,600-02).


freshman(210-01).
freshman(210-02).
sophmore(220-01).
sophmore(220-02).
sophmore(256-01).
sophmore(256-02).
junior(300-01).
junior(300-02).
junior(300-03).
junior(413-03).
senior(600-01).
senior(600-02).

morning(210-01).
morning(210-02).
morning(220-01).
morning(220-02).
morning(256-01).
afternoon(256-02).
afternoon(300-01).
afternoon(300-02).
afternoon(300-03).
morning(413-03).
morning(600-01).
afternoon(600-02).

mwf(210-01).
mwf(210-02).
mwf(220-01).
mwf(220-02).
mwf(256-01).
mwf(256-02).
mwf(300-01).
mwf(300-02).
tth(300-03).
tth(413-03).
mwf(600-01).
mwf(600-02).

teaches_freshman(A) :- teaches(A,C),freshman(C).
teaches_sophmore(A) :- teaches(A,C),sophmore(C).
teaches_junior(A) :- teaches(A,C),junior(C).
teaches_senior(A) :- teaches(A,C),senior(C).
teaches_morning(A) :- teaches(A,C),morning(C).
teaches_afternoon(A) :- teaches(A,C),afternoon(C).
teaches_whole_day(A) :- teaches(A,M),morning(M),teaches(A,N),afternoon(N).
works_mwf(A) :- teaches(A,C),mwf(C).
works_tth(A) :- teaches(A,C),tth(C).
teaches_three_classes(A) :- teaches(A,X),teaches(A,Y),teaches(A,Z),X\=Y,X\=Z,Y\=Z.
