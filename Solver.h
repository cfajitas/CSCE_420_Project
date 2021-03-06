//Cory Fleitas
//CSCE 420-500
//Due: April 28, 2016
//Solver.h

#ifndef SOLVER_H
#define SOLVER_H

#include<iostream>
#include<fstream>
#include<vector>
#include<bitset>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "Problem.h"
#include "Gate.h"
#include "Circuit.h"

using namespace std;

//This class contains the series of primes to multiply, and a vector of possible solutions

class Solver
{
private:
    vector<Problem> problems;
    vector<Circuit> circuits;
    vector<int> limits;
    int gateLimit;
    int solutionLoc;
public:
    Solver(int gl);
    void addProblem(Problem p);
    void runGenetic();
    void runAStar();
    void addNewGates(int k);
    void mutate();
    void randomDelete();
    void crossover(int k);
    void shrink();
    void addGatesAstar();
    void revert();
    void cull();
    void calcFitness();
    void runSortFitness();
    int checkSolution();
    int getSolutionLocation();
    void print(string file);
    void print();
    //static bool is used for STL sort when arranging by fitness
    static bool sortFitness(const Circuit &l, const Circuit &r)
    {
    	return l.getFitness() > r.getFitness();
    }
};
#endif