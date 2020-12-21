%Program 11 Corrections
%Austin Spencer
%Prolog Family Rules


%motherOf( <mother's name>, <child's name> ).
%fatherOf( <father's name>, <child's name> ).
%sonOf( <son's name>, <parent's name> ).
%daughterOf( <daughter's name>, <parent's name> ).
%siblingOf( <sibling's name>, <person's name> ).
%as well as similar rules for...auntOf,  ancestorOf, and descendentOf.
%also, add the following:
%contemporaryOf( <person>, <contemporary> ).% Alive at the same %timesuccessorOf( <ruler>, <next ruler> ).% Immediate successor on the throne



%These rules will use male and female facts as well as parent_of

%male( <name> ).
%female( <name> ).

%parentOf( <parent>, <child> ).
%lifeSpan( <name>, <birthYear>, <deathYear> ).
%ruler( <name> ).


motherOf( A, B ) :- female( A ), parentOf( A, B ).
fatherOf( A, B ) :- male( A ), parentOf( A, B ).
sonOf( A, B ) :- male( A ), parentOf( B, A ).
daughterOf( A, B ) :- female( A ), parentOf( B, A ).
siblingOf( A, B ) :- fatherOf( X, A ), fatherOf( X, B ).;
		     motherOf( X, A ), motherOf( X, B ).
auntOf( A, B ) :- female( A ), siblingOf( A, X ), parentOf( X, B ).
ancestorOf( A, B ) :- parentOf( A, B ).
ancestorOf ( A, B ) :- parentOf( A, X ), ancestorOf( X, B ). % Recursion after base


descendentOf( A, B ) :- parentOf( B, A ).
descendentOf( A, B ) :- parentOf( X, B ), descendentOf( A, X ).

contemporaryOf( A, B ) :- lifeSpan( A, X, Y ), lifeSpan( B, C, D ), X >= C, X <= D;
                          lifeSpan( A, X, Y ), lifeSpan( B, C, D ), C >= X, D <= Y;

timesuccessorOf( A, B ) :- ruler( A ), sonOf( A, B).












