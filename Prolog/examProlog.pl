%toxicEater( <biological-entity> ).
eats( rabbit, carrot ).
eats( spider, fly ).
eats( snake, spider ).
eats( bird, snake ).
eats( cat, bird ).
eats( cat, rabbit ).
eats( dog, cat ).

toxicity( rabbit, 3 ).
toxicity( spider, 5 ).
toxicity( snake, 34 ).
toxicity( cat, 4 ).
toxicity( bird, 8 ).
toxicity( carrot, 2 ).




%toxicEater( Predator ) :- eats( Predator, Prey ), toxicity( Prey, %ToxicLevel ), ToxicLevel > 10; eats( Prey, PreyII ), toxicity( PreyII, %ToxicLevel ), ToxicLevel > 10.

toxicEater( Predator ) :- eats( Predator, Prey ), toxicity( Prey, Toxicity ), Toxicity > 10.

toxicEater( Predator ) :- eats( Predator, Prey ), toxicEater(Prey).