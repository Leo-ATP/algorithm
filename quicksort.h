#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "./common.h"
using namespace std;

int partition(vector<int> &v, int st, int ed);
void quicksort(vector<int> &v, int st,int ed);
#endif
