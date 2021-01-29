//1/29/2021
//Jeremiah Heck
//Carimus Coding Challenge in C++
#pragma once
#ifndef CLIMBINGSTAIRS_HPP_
#define CLIMBINGSTAIRS_HPP_

#include <iostream>
#include <vector>
#include "bigint.hpp"

class hothMountain {
private:
    long long totalSteps;
public:
    //constructers
    hothMountain(long long);
    //methods
    bigint climbingStairs();
    //friends
    friend long long factorial(std::vector<long long>&);
};

//method definitions
hothMountain::hothMountain(long long _totalSteps) {
    totalSteps = _totalSteps;
}

long long factorial(std::vector<long long>& factorialNumerators) {
    long long product = 1;
    for (auto it = factorialNumerators.begin(); it != factorialNumerators.end(); ++it) {
        product *= *it;
    }
    return product;
}

bigint hothMountain::climbingStairs() {
    //this returns the lowest amount of combos os 1 & 2 possible for the given number.
    long long lowestBound = (totalSteps % 2) + totalSteps / 2;
    // This is the max amount of twos (minus one if odd).
    long long maxTwos = lowestBound - (totalSteps % 2);

    //these are our possible step amounts every given action
    int littleStep = 1;
    int bigStep = 2;

    bigint ways = 0;

    for (long long elements = totalSteps; elements >= lowestBound; --elements) {
        //grab the emount of little and big steps possible, starting at the most big
        long long amountOfBigSteps = maxTwos;
        long long amountOflittleSteps = (totalSteps - (amountOfBigSteps * bigStep)) / littleStep;

        //make sure that it isnt all one element
        if (amountOflittleSteps > 0 && amountOfBigSteps > 0) {
            long long slots = amountOflittleSteps + amountOfBigSteps;
            //factorials and combination formula
            //we have to be careful to be sure to eliminate the proper factorials!
            //NOTE:: our combined sets will always be smaller than or equal to the number of slots

            long long largestSet = 0;
            long long smallestSet = 0;

            //first identify the larger "set" of actions
            if (amountOfBigSteps > amountOflittleSteps) {
                largestSet = amountOfBigSteps;
                smallestSet = amountOflittleSteps;
            }
            else {
                //they are either even, or the little is the larger set
                largestSet = amountOflittleSteps;
                smallestSet = amountOfBigSteps;
            }

            // make sure there is more than one element of each set, otherwise no factorials needed
            if (largestSet != 1 && smallestSet != 1) {
                //get our factorials
                std::vector<long long> factorialNumerators;
                for (long long multiply = largestSet + 1; slots >= multiply; ++multiply) {
                    factorialNumerators.push_back(multiply);
                }
                //multiply the numbers in the vector
                long long numerator = factorial(factorialNumerators);

                std::vector<long long> factorialDenominators;
                for (long long multiply = smallestSet; smallestSet <= multiply; --multiply) {
                    factorialDenominators.push_back(multiply);
                }
                //multiply the numbers in the vector
                long long denominator = factorial(factorialDenominators);

                //divide, then add
                long long diffInt = numerator / denominator;
                bigint diff(diffInt);
                ways = ways + diff;
            }
            else {
                //this means there is only one of "2" or "1"
                //be careful, one could be zero
                bigint smallestSetBig(smallestSet);
                bigint largestSetBig(largestSet);
                if (smallestSet == 1 && largestSet == 1) {
                    ways = ways + smallestSetBig + largestSetBig;
                }
                else if (smallestSet == 1 || largestSet == 1) {
                    ways = ways + smallestSetBig + largestSetBig;
                }
                else if (smallestSet == 0 || largestSet == 0) {
                    ways = ways + smallestSetBig + largestSetBig;
                }
                else {
                    ways = ways * smallestSetBig;
                    ways = ways * largestSetBig;
                }
            }
        }
        else {
            //this means the elements are all little steps
            bigint one(1);
            ways = ways + one;
        }
        //change amount of big steps
        maxTwos--;
    }
    return ways;
}

#endif