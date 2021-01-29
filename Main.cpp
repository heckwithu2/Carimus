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
#include "bigint.hpp"

#include "ClimbingStairs.hpp"

#include <iostream>
#include <vector>



int main(int argc, char* argv[]) {
    long long totalSteps;
    char again;
    bool terminateProgram = false;
    do {

        std::cout << "Enter how many steps you have to get to the top please:" << std::endl;
        //take in number

        if ((std::cin >> totalSteps) && totalSteps > 0) {
            //instantiate class with number
            hothMountain mountain(totalSteps);
            //compute the combinations
            bigint totalPermutations = mountain.climbingStairs();
            std::cout << "This is the amount of ways to the top!:" << totalPermutations << std::endl;
            std::cout << std::endl;
        }
        else {
            std::cout << std::endl;
            std::cout << "Positive numbers only please." << std::endl;
            std::cout << std::endl;
            std::cin.clear();
            std::cin.ignore(1, '\n');
        }
        std::cout << "Press 'x' to quit. Or any other character to continue." << std::endl;
        std::cout << std::endl;
        //make sure user input is valid
        if (!(std::cin >> again)) {
            std::cout << std::endl;
            std::cin.clear();
            std::cin.ignore(1, '\n');
        }
        else if (again == 'x') {
            terminateProgram = true;
        }
        //determined if user wants to quit the program or not
    } while (terminateProgram == false);
    std::cout << "Thank you!" << std::endl;
    std::cout << std::endl;
    return 0;
}
