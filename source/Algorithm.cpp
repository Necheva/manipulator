#pragma once
#include"../include/TVector.h"
#include"../include/TMatrix.h"
static class Algorithm
{

public:
	static TVector Gauss(TMatrix D, TVector V)
	{
		int n = 3;
		double **a = new double*[n];
		double * y = new double[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = new double[n];
			for (int j = 0; j < n; j++)
			{
				a[i][j]=D.GetMatrix(i,j);
			}
		}
		for (int i = 0; i < n; i++)
		{
			y[i] = V[i];
		}
		double * x = gauss(a, y, n);
		TVector Result(3);
		for (int i = 0; i < n; i++)
		{
			Result[i] = x[i];
		}
		return Result;
	}

	static double * gauss(double **a, double *y, int n)
	{
		double *x, max;
		int k, index;
		const double eps = 0.00001;
		x = new double[n];
		k = 0;
		while (k < n)
		{

			max = abs(a[k][k]);
			index = k;
			for (int i = k + 1; i < n; i++)
			{
				if (abs(a[i][k]) > max)
				{
					max = abs(a[i][k]);
					index = i;
				}
			}

			if (max < eps)
			{

				cout << "Ðåøåíèå ïîëó÷èòü íåâîçìîæíî èç-çà íóëåâîãî ñòîëáöà ";
				cout << index << " ìàòðèöû A" << endl;
				return 0;
			}
			for (int j = 0; j < n; j++)
			{
				double temp = a[k][j];
				a[k][j] = a[index][j];
				a[index][j] = temp;
			}
			double temp = y[k];
			y[k] = y[index];
			y[index] = temp;

			for (int i = k; i < n; i++)
			{
				double temp = a[i][k];
				if (abs(temp) < eps) continue;
				for (int j = 0; j < n; j++)
					a[i][j] = a[i][j] / temp;
				y[i] = y[i] / temp;
				if (i == k)  continue;
				for (int j = 0; j < n; j++)
					a[i][j] = a[i][j] - a[k][j];
				y[i] = y[i] - y[k];
			}
			k++;
		}

		for (k = n - 1; k >= 0; k--)
		{
			x[k] = y[k];
			for (int i = 0; i < k; i++)
				y[i] = y[i] - a[i][k] * x[k];
		}
		return x;
	}
};
