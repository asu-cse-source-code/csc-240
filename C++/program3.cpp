
program3.cpp
//  CSC240
//
//  Created by Austin Spencer on 1/29/20.
//  Copyright © 2020 Austin Spencer. All rights reserved.
//

#include <iostream>

#include <math.h>

using namespace std;


void calculationOfMonths(int initialPop, double growthRate, int carryingCap, int goalPop, int table)
{
    double bunniesOld, oldPop, bunniesNew, newPop;
    int totalMonths;
    oldPop = initialPop;
    totalMonths = 0;
    if (table == 0)
    {
        cout << "  Month Population" << endl;
        do
        {
            cout << "\t" << totalMonths << "\t" << oldPop << endl;
            bunniesOld = oldPop/carryingCap;
            bunniesNew = bunniesOld + (growthRate * bunniesOld * (1 - bunniesOld));
            newPop = round(bunniesNew * carryingCap);
            oldPop = newPop;
            totalMonths++;
        }while(oldPop < goalPop);
    }
    else
    {
        do
        {
            bunniesOld = oldPop/carryingCap;
            bunniesNew = bunniesOld + (growthRate * bunniesOld * (1 - bunniesOld));
            newPop = round(bunniesNew * carryingCap);
            oldPop = newPop;
            totalMonths++;
        }while(oldPop <= goalPop);
        cout << endl << "The population reaches " << goalPop << " after " << totalMonths << " months" << endl << endl;
    }
    

}


void calculationOfBunnies(int initialPop, double growthRate, int carryingCap, int timeframe, int table)
{
    double bunniesOld, oldPop, bunniesNew, newPop, i;
    
    oldPop = initialPop;
    if (table == 0)
    {
        cout << "  Month Population" << endl;
        for(i = 0; i <= timeframe; i++)
        {
            cout << "\t" << i << "\t" << oldPop << endl;
            bunniesOld = oldPop/carryingCap;
            bunniesNew = bunniesOld + (growthRate * bunniesOld * (1 - bunniesOld));
            newPop = round(bunniesNew * carryingCap);
            oldPop = newPop;
        }
    }
    else
    {
        for(i = 1; i <= timeframe; i++)
        {
            bunniesOld = oldPop/carryingCap;
            bunniesNew = bunniesOld + (growthRate * bunniesOld * (1 - bunniesOld));
            newPop = round(bunniesNew * carryingCap);
            oldPop = newPop;
        }
        cout << endl << round(oldPop) << " bunnies after " << timeframe << " months" << endl << endl;
    }
}

void numberOfBunnies(int initialPop, double growthRate, int carryingCap, int table)
{
    int timeframe;
    do
    {
        cout << endl << "How many months from now would you like to see the bunny population? :  " ;
        cin >> timeframe;
        cout << endl << endl;
    } while (timeframe <= 0);
    
    calculationOfBunnies(initialPop, growthRate, carryingCap, timeframe, table);
    
}

void numberOfMonths(int initialPop, double growthRate, int carryingCap, int table)
{
    int goalPop;
    
    do
    {
        cout << endl << "Please enter the number of bunnies you want to have in the population and I will tell you how many months until you can expect that many bunnies :  " ;
        cin >> goalPop;
        cout << endl << endl;
    } while (goalPop < initialPop && goalPop >= carryingCap);//I dont understand why this is not working properly
    
    calculationOfMonths(initialPop, growthRate, carryingCap, goalPop, table);
    
}

int questionChoice(int initialPop, double growthRate, int carryingCap)
{
    int question, keepGoing, table;
    do
    {
        do
        {
            cout << endl << "Enter 0 if you like to know how many bunnies are in the population after X amount of months.. "<< endl << "Enter 1 if you would like to know how many months to get to X amount of bunnies : ";
            cin >> question;
            cout << endl << endl;
        } while (question < 0 || question > 1);
        
        do
        {
            cout << endl << "Would you like to see a table when you get your results? Enter 0 for yes or 1 for no! : ";
            cin >> table;
        } while (table < 0 || table > 1);
        
        if (question == 0)
        {
            numberOfBunnies(initialPop, growthRate, carryingCap, table);
        }
        else
        {
            numberOfMonths(initialPop, growthRate, carryingCap, table);
        }
        cout << endl << "If you want to stop asking questions about this farm enter 0, if you want to keep asking enter a different number :";
        cin >> keepGoing;
    }while(keepGoing !=0);
    
    cout << endl << endl << "Enter 0 if you dont want to ask about another farm, if you do want to, enter any other number? ";
    cin >> keepGoing;
    
    if (keepGoing == 0){
        return 0;
    }
    else {
        do
        {
            cout << endl << "Please enter the carrying capacity of bunnies on the new farm! : " ;
            cin >> carryingCap;
        } while (carryingCap <= 0);
        questionChoice(initialPop, growthRate, carryingCap);
    }
    cout << endl << "Thanks for using my bunny growth population program! Hope you learned a lot! Good-bye!" << endl;
    return 0;
}


int main()
{
    int initialPop, carryingCap;
    double growthRate, birthRate, deathRate;
    
    
    
    cout << "This program will calculate the population growth of bunnies on any farm!" << endl << "I just need some quick information first and then you can ask questions!" << endl;
    
    do
    {
        cout << endl << "Please enter the carrying capacity of bunnies on the farm! : " ;
        cin >> carryingCap;
    } while (carryingCap <= 0);
    
    do
    {
        cout << endl << "Please enter the inital population of bunnies! : " ;
        cin >> initialPop;
    } while (initialPop < 0);
    
    do
    {
        cout << endl << "Please enter the birth rate of bunnies as a percentage, but please leave the % sign out! : " ;
        cin >> birthRate;
    } while (initialPop < 0);
    
    do
    {
        cout << endl << "Please enter the death rate of bunnies! : " ;
        cin >> deathRate;
    } while (deathRate < 0 && deathRate > 1);
    
    growthRate = (birthRate - deathRate)/100;
    
    questionChoice(initialPop, growthRate, carryingCap);
    
    
    return 0; // End my program
    
    
}

