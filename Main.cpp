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
//(1+1+1+1) ---------- (1+2+1) (2+1+1) (1+1+2) -------------(2+2)
//(1+1+1+1+1) ---------- (1+2+1) (2+1+1) (1+1+2) -------------(2+2)

#include<iostream>

int climbingStairs(int totalSteps) {
    return totalSteps += 1;
}

int main(int argc, char *argv[]) {
    int totalSteps;
    std::cout << "Enter how many steps you have to get to the top please:" << std::endl;
    std::cin >> totalSteps;
    int totalPermutations = climbingStairs(totalSteps);
    std::cout << totalPermutations;
}
