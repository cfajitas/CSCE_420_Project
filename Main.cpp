#include<iostream>
#include<fstream>
#include<bitset>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "Problem.h"
#include "Gate.h"
#include "Circuit.h"
#include "Solver.h"
#include "Factorize.h"

using namespace std;

int getSize(int num);

int main()
{
    srand(time(NULL));
    string temp = "";
    cout<<"Please Enter Input file:\n";
    getline(cin,temp);
    string file = temp;
    cout<<"Please Enter:\n1 for Genetic\n2 for Astar\nAnything else will exit\n";
    getline(cin,temp);
    ifstream in(file);
    int A = 0;
    int B = 0;
    int C = 0;
    Solver solve(10000);
    while(in>>A>>B>>C)
    {
        int sizeP = getSize(A);
        int sizeQ = getSize(B);
        int sizeN = getSize(C);
        Problem temp(A,B,C,sizeP,sizeQ,sizeN);
        solve.addProblem(temp);
    }
    in.close();
    if(temp == "1")
    {
        cout<<"\nRunning Genetic Algorithm\n";
        solve.runGenetic();
    }
    else if(temp == "2")
    {
        cout<<"\nRunning AStar Algorithm\n";
        solve.runAStar();
    }
    else
    {
        cout<<"Exiting\n";
        return 0;
    }
    string outFile = file+"_Output.txt";
    solve.print(outFile);
    solve.print();
    cout<<"\nFactoring Solution\n";
    Factorize factor(outFile);
    factor.factorCircuit();
    factor.print();
    return 0;
}

int getSize(int num)
{
    bitset<30> temp(num);
    for(int i=29;i>=0;--i)
    {
        if(temp[i])
        {
            return i;
        }
    }
    return 0;
}