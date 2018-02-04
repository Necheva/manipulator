#include"../include/TVector.h"
#include"../include/TMatrix.h"
static TVector Gauss(TMatrix D, TVector V);
static double * gauss(double **a, double *y, int n)
