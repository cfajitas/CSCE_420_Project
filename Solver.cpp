#include "Solver.h"

Solver::Solver()
{
    nums=0;
}

void Solver::addNum(bitset<16> p, bitset<16> q, bitset<32> n, int pl, int ql, int nl)
{
    pvec.push_back(p);
    qvec.push_back(q);
    nvec.push_back(n);
    plimits.push_back(pl);
    qlimits.push_back(ql);
    nlimits.push_back(nl);
    ++nums;
}


void calcFitness()
{
    
}

bool Solver::sortFitness(const Circuit &l, const Circuit &r)
{
    return l.getFitness() < r.getFitness();
}