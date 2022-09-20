#include <iostream>
#include<vector>

#include "Matrix.h"
#include "LoadingMatrix.h"
#include "Structures.h"
#include "Manipulators.h"



int main(int argc, char* argv[])
{
    cmdArgs cmdArgs;
    ReadcmdArgs(argc, argv, cmdArgs);

    std::vector<std::vector<double>> A = read_matrix(cmdArgs.inputAFile);
    std::vector<std::vector<double>> B = read_matrix(cmdArgs.inputBFile);

    operation type = convert(cmdArgs.OperationType);
    switch (type)
    {
    case operation::add:
        // compares the height or columns of matrix A to the rows or size of matrix B to see if they are equal before performing the operation
        if ((A.size() == B.size()) && (A[0].size() == B[0].size()))
        {
            save_solution(Add(A, B), cmdArgs.outputFile);
        }
        else
        {
            std::string error = "The matrix cannot be added - difference in size";
            save_solution(error, cmdArgs.outputFile);
        }
        break;

    case operation::subtract:
        if ((A.size() == B.size()) && (A[0].size() == B[0].size()))
        {
            save_solution(Subtract(A, B), cmdArgs.outputFile);
        }
        else
        {
            std::string error = "The matrix cannot be subtracted - difference in size";
            save_solution(error, cmdArgs.outputFile);
        }
        break;

    case operation::multiply:
        // compares the rows of matrix A to the cols of matrix B to see if they are equal before performing the operation
       /*multiply*/
        if (A[0].size() != B.size()) // compares the height or columns of matrix A to the rows or size of matrix B to see if they are equal before performing the operation
        {
            std::string error = "The matrix cannot be multiplied - difference in size";
            save_solution(error, cmdArgs.outputFile);
        }
        else
        {
            save_solution(Multiply(A, B), cmdArgs.outputFile);
        }
        break;

    case operation::determinant:
        if (A.size() == A[0].size())
        {
            save_solution(Determinant(A), cmdArgs.outputFile);
        }
        else
        {
            std::string error = "The matrix is not a square matrix and has no determinant";
            save_solution(error, cmdArgs.outputFile);
        }
        
        break;

    case operation::inverse:
        if (Determinant(A) == 0)//check for determinant
        {
            std::string error = "Detminant is equals 0";
            save_solution(error, cmdArgs.outputFile);
        }
        else
        {
            std::vector<std::vector<int>> solution(A.size(), std::vector<int>(A.size()));
            if (A.size() != A[0].size())//check if it has a cofactor
            {
                std::string error = "Matrix is not quadratic and thus has no cofactor";
                save_solution(error, cmdArgs.outputFile);
            }
            else
            {
                save_solution(Inverse(A), cmdArgs.outputFile);
            }
        }

        break;

    case operation::cofactor:
        if (A.size() != A[0].size())
        {
            std::string error = "Matrix is not quadratic";
            save_solution(error, cmdArgs.outputFile);
        }
        else
        {
            save_solution(Cofactor(A), cmdArgs.outputFile);
        }
        break;

    case operation::transpose:
        save_solution(Transpose(A), cmdArgs.outputFile);
        break;

    case operation::not_supported:
        std::string error = "operation not available";
        save_solution(error, cmdArgs.outputFile);
        break;

    }

}


