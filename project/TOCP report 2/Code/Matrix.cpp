#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include<vector>

#include "Matrix.h"


double Determinant(std::vector<std::vector<double>> A)
{
    double d = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = (i + 1); j < A.size(); j++)
        {
            for (size_t k = (i + 1); k < A.size(); k++)
            {
                A[j][k] = A[j][k] * A[i][i] - A[j][i] * A[i][k];
                if (i != 0)
                {
                    A[j][k] /= A[i - 1][i - 1];
                }
            }
        }
    }
    d = A[A.size() - 1][A.size() - 1];
    return d;
}

std::vector< std::vector<double>> Add(std::vector<std::vector<double>> A,std::vector<std::vector<double>> B)
{
    auto nrows = A.size();
    auto ncols = A[0].size();
    std::vector<std::vector<double>> solution(nrows, std::vector<double>(ncols));

    for (size_t j = 0; j < nrows; ++j) {
        for (size_t i = 0; i < ncols; ++i)
        {
            solution[j][i] = A[j][i] + B[j][i];
        }
    }
    return solution;
}

std::vector< std::vector<double>> Subtract( std::vector<std::vector<double>> A, std::vector<std::vector<double>>B)
{
    auto nrows = A.size();
    auto ncols = A[0].size();
    std::vector<std::vector<double>> solution(nrows, std::vector<double>(ncols));

    for (size_t j = 0; j < ncols; ++j) {
        for (size_t i = 0; i < nrows; ++i)
        {
            solution[i][j] = A[i][j] - B[i][j];
        }
    }
    return solution;
}

std::vector< std::vector<double>> Multiply( std::vector<std::vector<double>> A,std::vector<std::vector<double>> B)
{
    auto n = A.size();
    auto m = A[0].size();
    auto p = B[0].size();
    std::vector<std::vector<double>> solution(n, std::vector<double>(p, 0));
    for (size_t j = 0; j < p; ++j) {
        for (size_t k = 0; k < m; ++k) {
            for (size_t i = 0; i < n; ++i) {
                solution[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return solution;
}

std::vector<std::vector<double>> Transpose( std::vector<std::vector<double>> A)
{

    //Transpose-matrix: height = width(matrix), width = height(matrix)
    std::vector<std::vector<double>> solution(A[0].size(), std::vector<double>(A.size()));

    //Filling solution-matrix
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A[0].size(); j++)
        {
            solution[j][i] = A[i][j];
        }
    } // returns the swapped rows with columns to the  vector of vector matrix solution
    return solution;
}

std::vector<std::vector<double>> Cofactor( std::vector<std::vector<double>> A)
{
    std::vector<std::vector<double>> C(A.size(), std::vector<double>(A.size()));
    std::vector<std::vector<double>> subVect(A.size() - 1, std::vector<double>(A.size() - 1));
    for (std::size_t i = 0; i < A.size(); i++)
    {
        for (std::size_t j = 0; j < A[0].size(); j++)
        {
            double p = 0;
            for (std::size_t x = 0; x < A.size(); x++)
            {
                if (x == i)
                {
                    continue;
                }
                double q = 0;

                for (size_t y = 0; y < A.size(); y++)
                {
                    if (y == j)
                    {
                        continue;
                    }
                    subVect[p][q] = A[x][y];
                    q++;
                }
                p++;
            }
            double d = Determinant(subVect);
            C[i][j] = pow(-1, i + j) * d;
        }
    }
    return C;
}

std::vector<std::vector<double>> Inverse( std::vector<std::vector<double>> A)
{
    double det = Determinant(A);
    std::vector<std::vector<double>> solution = Transpose(Cofactor(A));
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A.size(); j++)
        {
            solution[i][j] *= (1 / det);
        }
    }
    return solution;
}
