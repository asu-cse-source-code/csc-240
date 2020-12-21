% CSC240 - Successful Workout Attempt
% Austin Spencer
% May 4, 2020
% Program 13

% assign the state that will start the program

start_state(gym_entrance).

% define the edges of the finite state diagram

next_state(gym_entrance,a,gym_entrance).
next_state(gym_entrance,b,weight_room) 
  :-  stored_answer(have_motivation,yes).
next_state(gym_entrance,b,gym_entrance) 
  :-  stored_answer(have_motivation,no).
next_state(gym_entrance,c,get_phone).
next_state(gym_entrance,d,tanning_bed).

next_state(get_phone,a,get_phone).
next_state(get_phone,b,gym_entrance).
next_state(get_phone,c,gym_entrance).

next_state(tanning_bed,a,tan).
next_state(tanning_bed,b,tanning_bed).
next_state(tanning_bed,c,gym_entrance).


% code to be executed at the beginning...

display_intro :- 
  write('You need a successful workout...'),nl,nl,
  write('It is a month before summer.'),nl,
  write('You have been enjoying winter and baggy clothes,'),nl,
  write('but now you need to get in shape '),nl,
  write('You are at the gym now, '),nl,
  write(' but you realize that you '),
     write('have no motivation.' ),nl.

initialize :-
  asserta(stored_answer(moves,0)),
  asserta(stored_answer(have_motivation,no)),
  asserta(stored_answer(music_on_phone,yes)).

% code to be executed at the end...

goodbye :-
  stored_answer(moves,Count),
  write( 'You made this many moves...' ),
  write( Count ), nl,
  write( 'Have a nice day'), nl.


% code to be executed upon reaching each state

show_state(gym_entrance) :- 
  write( 'At the gym entrance' ), nl,
  write( 'Do you want to...'), nl,
  write( '(a) Talk with front desk'),nl,
  write( '(b) Go into the weight room'),nl,
  write( '(c) Pull out your phone'),nl,
  write( '(q) Quit the program'),nl.

show_state(get_phone) :-
  stored_answer(music_on_phone,yes),
  write( 'You opened your phone and see all of your apps'),nl,
  write( 'Do you want to...'), nl,
  write( '(a) Text your friends'),nl,
  write( '(b) Put down the phone'),nl,
  write( '(c) Turn on your workout playlist from Spotify'),nl,
  write( '(q) Quit the program'),nl.

show_state(get_phone) :-
  stored_answer(music_on_phone,no),
  write( 'There is no music on your phone'),nl,
  write( 'Do you want to...'), nl,
  write( '(a) Text some more'),nl,
  write( '(b) Put down the phone'),nl,
  write( '(q) Quit the program'),nl.

show_state(tan) :-
  write( 'You are in front of the tanning room' ),nl,
  write( 'with a tanning bed open.' ),nl,
  write( 'Do you want to...'), nl,
  write( '(a) Start tanning'),nl,
  write( '(b) Watch TV in the tanning room'),nl,
  write( '(c) Go back to the gym entrance'),nl,
  write( '(q) Quit the program'),nl.




% final states do not display a menu 
%  - they automatically quit ('q')

show_state(weight_room) :- 
  write( 'In the weight room.' ), nl,
  write( 'You are getting a successful workout in.' ), nl.

show_state(tan) :-
  write( 'You are now tanning '),
    write('you will now be tan and out of shape.' ),nl,
  write( 'Maybe you will now at least avoid a burn. '),nl.

get_choice(weight_room,q).
get_choice(tan,q).



% code to be executed for each choice of action from each state...

show_transition(gym_entrance,a) :- 
  write( 'You made some friends, but you '),
      write('are not getting a successful workout in.'),nl.
show_transition(gym_entrance,b) :- 
  stored_answer(have_motivation,yes),
  write( 'You go into the weight room feeling energized.'),nl.
show_transition(gym_entrance,b) :- 
  stored_answer(have_motivation,no),
  write( 'You do not have motivation, '),nl.
show_transition(gym_entrance,c) :- 
  write( 'You get on your phone '),
       write('and see your home screen...'),nl.
show_transition(gym_entrance,d) :-
  write( 'You walk over to '),
        write('the tanning room...'),nl.

show_transition(get_phone,a) :-
  write( 'Your friends are talking about, '),
      write('how fun the beach will be this summer.' ),nl.
show_transition(get_phone,b) :-
  write( 'Your phone is back in your pocket.' ),nl.
show_transition(get_phone,c) :-
  write( 'You turn on your music' ),nl,
  retract(stored_answer(music_on_phone,yes)),
  asserta(stored_answer(music_on_phone,no)),
  retract(stored_answer(have_motivation,no)),
  asserta(stored_answer(have_motivation,yes)).

show_transition(tan,a) :-
  write( 'The tanning bed works really well!' ),nl.
show_transition(tan,b) :-
  write( 'I do not feel much better though..' ),nl.
  
show_transition(tan,c) :-
  write( 'Well, that was a waste of time.' ),nl.



show_transition(gym_entrance,fail) :- 
  write( 'a,b,c,d, or q' ),nl.
show_transition(get_phone,fail) :- 
  stored_answer(music_on_phone,yes),
  write( 'a,b,c, or q' ),nl.
show_transition(get_phone,fail) :- 
  stored_answer(music_on_phone,no),
  write( 'a,b, or q' ),nl.

