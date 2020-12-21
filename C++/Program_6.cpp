//
//  main.cpp
//  CSC240
//
//  Created by Austin Spencer on 1/29/20.
//  Copyright © 2020 Austin Spencer. All rights reserved.
//

#include <iostream>

#include <math.h>

using namespace std;

int isUpperCase (char c){
    return (c >= 'A' && c <= 'Z');
}

int isLowerCase(char c){
    return (c >= 'a' && c <= 'z');
}


char toLowerCase(char c) {
    
    if(isUpperCase(c)){
        return c - ('A' - 'a');
    }
    else{
        return c;
    }
    
}

void count(string message,int counters[])
{
    int tally = 0;
    int i, in, index;
    for (i = 0; i < 26; ++i)
    {
        counters[i] = 0;
    }
    for (in = 0; message[in] != '\0'; ++in)
    {
        
        if (isUpperCase(message[in])){
            index = toLowerCase(message[in])-'a';
        }
        
        else{
            index = message[in]-'a';
        }
        
        
        
        
        if(index >= 0 && index <= 26){
            counters[index] = (counters[index] + 1);
            ++tally;
        }
    }
}

void table(int counters[], double tally){
    int i;
    char letter;
    int total = 0;
    string wait;
    //float frequency = 0.0;
    for (i = 0; i < 26; ++i){
        total = total + counters[i];
    }
    cout << "letter count frequency" << endl;
    for(i = 0; i < 26; ++i){
        letter = 'a' + i;
        cout << letter << "     " << counters[i] << "      "
        << counters[i]/tally*100 << "%" << endl;
    }
    
    
}

int main()
{
    char message[502];
    
    double tally = 0;
    cout << "enter a string: ";
    
    gets(message);
    message[501] = '\0';
    int in;
    for (in = 0; message[in] != '\0'; ++in){
        if(isUpperCase(message[in]))
            ++tally;
        if (isLowerCase(message[in]))
            ++tally;
    }
    cout << tally << endl;
    
    int counters[26];
    
    
    count(message, counters);
    
    table(counters, tally);
    
        
    
    
    return 0; // End my program
    
    
}


