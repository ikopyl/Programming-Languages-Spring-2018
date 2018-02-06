%Facts
teaches(sosnick,210.01).
teaches(sosnick,210.02).
teaches(kulkarni,210.03).
teaches(sterling,210.04).
teaches(webster,210.05).
teaches(sladek,210.05).
teaches(ta,211.01).
teaches(wong,211.01).
teaches(wong,220.01).
teaches(wong,220.02).
teaches(kelly,220.03).
teaches(kulkarni,230.01).
teaches(tomasevich,230.02).
teaches(sosnick,256.01).
teaches(tomasevich,300.01).
teaches(tomasevich,300.02).
teaches(dujmovic,340.01).
teaches(yang,340.02).
teaches(sosnick,412.01).
teaches(wong,412.01).
teaches(sosnick,412.02).
teaches(wong,412.02).
teaches(yoon,413.01).
teaches(yoon,413.02).
teaches(kelly,415.01).
teaches(wall,510.01).
teaches(wall,520.01).
teaches(dujmovic,600.01).
teaches(petkovic,640.01).
teaches(dujmovic,641.01).
teaches(roberts,667).
teaches(murphy,675.01).

freshman(210.01).
freshman(210.02).
freshman(210.03).
freshman(210.04).
freshman(210.05).
freshman(211.01).

sophomore(220.01).
sophomore(220.02).
sophomore(220.03).
sophomore(230.01).
sophomore(230.02).
sophomore(256.01).
sophomore(340.01).
sophomore(340.02).
sophomore(412.01).
sophomore(412.02).

junior(300.01).
junior(300.02).
junior(413.01).
junior(413.02).
junior(415.01).
junior(510.01).
junior(510.02).
junior(520.01).

senior(600.01).
senior(640.01).
senior(641.01).
senior(667).
senior(675.01).

morning(210.01).
morning(210.02).
morning(210.04).
morning(220.01).
morning(220.02).
morning(340.01).
morning(412.02).
morning(413.01).

afternoon(210.03).
afternoon(210.05).
afternoon(211.01).
afternoon(220.03).
afternoon(230.01).
afternoon(230.02).
afternoon(256.01).
afternoon(300.01).
afternoon(300.02).
afternoon(340.02).
afternoon(412.01).
afternoon(413.02).
afternoon(415.01).
afternoon(510.01).
afternoon(520.01).
afternoon(600.01).
afternoon(640.01).
afternoon(641.01).
afternoon(667).
afternoon(675.01).

tth(256.01).
tth(340.02).
tth(413.01).
tth(413.02).
tth(510.01).
tth(520.01).

mwf(210.01).
mwf(210.02).
mwf(210.03).
mwf(220.01).
mwf(220.02).
mwf(230.01).
mwf(340.01).
mwf(600.01).
mwf(641.01).
mwf(675.01).

%Rules
teaches_freshman(X) :- teaches(X,C), freshman(C).
teaches_sophomore(X) :- teaches(X,C), sophomore(C).
teaches_junior(X) :- teaches(X,C), junior(C).
teaches_senior(X) :- teaches(X,C), senior(C).
teaches_morning(X) :- teaches(X,C), morning(C).
teaches_afternoon(X) :- teaches(X,C), afternoon(C).
teaches_whole_day(X) :- teaches(X,C1), morning(C1), teaches(X,C2), afternoon(C2).
works_mwf(X) :- teaches(X,C), mwf(C).
works_tth(X) :- teaches(X,C), tth(C).
teaches_three_classes(X) :- teaches(X,C1), teaches(X,C2), teaches(X,C3),
	C1\=C2, C2\=C3, C1\=C3.
















