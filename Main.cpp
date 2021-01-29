//1/28/2021
//Jeremiah Heck
//Carimus Coding Challenge in C++

// Climbing Stairs
// You're a rebel scout on the ice planet, Hoth. While killing time waiting for the Empire to find your base, you ride your trusty Tauntaun around the plant. 
// You wander upon a very tall ice staircase leading up a mountainside that takes n steps to reach. 
// Having plenty of time on your hands, you decide you want to figure out how many ways are there to reach the top. 
// The catch is that for each step, your Tauntauan can only climb 1 or 2 steps at a given time.

// Your job is to write a function 'climbingStairs' that will return the total number of ways you can reach the top.
// 'climbingStairs' should take the following parameter:
// •	totalSteps: an integer, total n steps to the top.
// Constraints:
// •	0 <= totalSteps < infinity
// •	For each given step, you can only take 1 or 2 steps at a time
// Sample Input:
// •	Given: 2
// •	Output: 2
// o	There are two ways to the top (1 + 1) and (2).
// Sample Input:
// •	Given: 3
// •	Output: 3
// o	There are three ways to the top (1 + 1 + 1), (1 + 2), and (2 + 1).

#include<iostream>
#include <vector>


//function prototypes
int climbingStairs(const int&);
int factorial(std::vector<int>&);

int main(int argc, char* argv[]) {
    int totalSteps;
    char again;
    bool terminateProgram = false;
    do {

        std::cout << "Enter how many steps you have to get to the top please:" << std::endl;
        //take in number
        
        if  ((std::cin >> totalSteps) && totalSteps > 0) {
            int totalPermutations = climbingStairs(totalSteps);
            std::cout << "This is the amount of ways to the top!:" << totalPermutations << std::endl;
            std::cout << std::endl;
        } else {
            std::cout << std::endl;
            std::cout << "Positive numbers only please." << std::endl;
            std::cout << std::endl;
            std::cin.clear();
            std::cin.ignore(1, '\n');
        }
        std::cout << "Press 'x' to quit. Or any other character to continue." << std::endl;
        std::cout << std::endl;
        if  (!(std::cin >> again)) {
            std::cout << std::endl;
            std::cin.clear();
            std::cin.ignore(1, '\n');
        } else if (again == 'x') {
            terminateProgram = true;
        }
    } while (terminateProgram == false);
    std::cout << "Thank you!" << std::endl;
    std::cout << std::endl;
    return 0;
}

//function definitions
int climbingStairs(const int& totalSteps) {
    //this returns the lowest amount of combos os 1 & 2 possible for the given number.
    int lowestBound = (totalSteps % 2) + totalSteps / 2;
    // This is the max amount of twos (minus one if odd).
    int maxTwos = lowestBound - (totalSteps % 2);

    //these are our possible step amounts every given action
    int littleStep = 1;
    int bigStep = 2;

    int ways = 0;

    for (int elements = totalSteps; elements >= lowestBound; --elements) {
        //grab the emount of little and big steps possible, starting at the most big
        int amountOfBigSteps = maxTwos;
        int amountOflittleSteps = (totalSteps - (amountOfBigSteps * bigStep)) / littleStep;

        //make sure that it isnt all one element
        if (amountOflittleSteps > 0 && amountOfBigSteps > 0) {
            int slots = amountOflittleSteps + amountOfBigSteps;
            //factorials and combination formula
            //we have to be careful to be sure to eliminate the proper factorials!
            //NOTE:: our combined sets will always be smaller than or equal to the number of slots

            int largestSet = 0;
            int smallestSet = 0;

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
                std::vector<int> factorialNumerators;
                for (int multiply = largestSet + 1; slots >= multiply; ++multiply) {
                    factorialNumerators.push_back(multiply);
                }
                //multiply the numbers in the vector
                int numerator = factorial(factorialNumerators);

                std::vector<int> factorialDenominators;
                for (int multiply = smallestSet; smallestSet <= multiply; --multiply) {
                    factorialDenominators.push_back(multiply);
                }
                //multiply the numbers in the vector
                int denominator = factorial(factorialDenominators);

                //divide, then add
                ways += numerator / denominator;
            }
            else {
                //this means there is only one of "2" or "1"
                //be careful, one could be zero 
                if (smallestSet == 1 && largestSet == 1) {
                    ways += smallestSet + largestSet;
                } else if (smallestSet == 1 || largestSet == 1) {
                    ways += smallestSet + largestSet;
                } else if (smallestSet == 0 || largestSet == 0) {
                    ways += smallestSet + largestSet;
                } else { 
                    ways += smallestSet * largestSet;
                }
            }
        }
        else {
            //this means the elements are all little steps
            ways++;
        }
        //change amount of big steps
        maxTwos--;
    }
    return ways;
}

//takes in a vector pf numbers and multiplies them, simulating a factorial
int factorial(std::vector<int>& factorialNumerators) {
    int product = 1;
    for (auto it = factorialNumerators.begin(); it != factorialNumerators.end(); ++it) {
        product *= *it;
    }
    return product;
}