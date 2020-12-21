% basic finite state machine engine

go :-
	intro,
	start_state(X),
	show_state(X),
	get_choice(X,Y),
	go_to_next_state(X,Y).

intro :-
	display_intro,
	clear_stored_answers,
	initialize.

go_to_next_state(_,q) :-
	goodbye,!.

go_to_next_state(S1,Cin) :-
	next_state(S1,Cin,S2),
	show_transition(S1,Cin),
	show_state(S2),
	stored_answer(moves,K),
	OneMoreMove is K + 1,
	retract(stored_answer(moves,_)),
	asserta(stored_answer(moves,OneMoreMove)),
	get_choice(S2,Cnew),
	go_to_next_state(S2,Cnew).

go_to_next_state(S1,Cin) :-
	\+ next_state(S1,Cin,_),
	show_transition(S1,fail),
	get_choice(S1,Cnew),
	go_to_next_state(S1,Cnew).

get_choice(_,C) :-
    write('Next entry (letter followed by a period)? '),
    read(C).

% case knowledge base - user responses

:- dynamic(stored_answer/2).

% procedure to get rid of previous responses
% without abolishing the dynamic declaration

clear_stored_answers :- retract(stored_answer(_,_)),fail.
clear_stored_answers.


