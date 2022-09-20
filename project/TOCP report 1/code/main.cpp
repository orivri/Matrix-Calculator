#include <iostream>
#include<fstream>
#include<sstream>    
#include<cmath>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "matrix.h"

void debugMatrix(const std::vector<std::vector<int>> vect)
{
    for (std::size_t i = 0; i < vect.size(); i++)
    {
        for (std::size_t j = 0; j < vect[0].size(); j++)
        {
            std::cout << vect[i][j] << " ";
        }
        std::cout << "\n";
    }
}

const std::vector<std::vector<int>> read_matrix(std::string file_name)
{
    std::vector<std::vector <int>> matrix;
    std::ifstream file(file_name);// input file stream + open
    if (file)
    {
        std::string line; //string type
        while (getline(file, line))
        {
            //std::cout << "[" << line << "]" << " ";
            /** Extract numbers from text**/
            std::stringstream ss;
            ss << line;

            std::vector<int> row;
            int number;
            while (ss >> number)
            {
                //std::cout << "[" << number << "]";
                row.push_back(number);
            }
            //std::cout << std::endl;
            std::cout << "\n";
            matrix.push_back(row);
        }
        file.close();
        std::cout << std::endl;
    }
    else
        std::cout << "Unable to open file.";

    //std::cout << "A Matrix of size has been read file. " << source << " ";
    return matrix;
}

void save_solution(const std::vector< std::vector<int>> solution, std::string& outputFile)
{
    std::ofstream file(outputFile, std::ios::app);
    if (file)
    {
        int d = 0;
        for (size_t i = 0; i < solution.size(); i++)
        {
            for (size_t j = 0; j < solution[0].size(); j++)
            {
                d = solution[i][j];
                file << "[" << d << "]" << " ";
            }
        }
        file << "\n-----------------------------------------\n";
        file.close();
    }
    std::cout << " The solution has been saved to the file: " << outputFile;
}

void save_solution(int solution, std::string& outputFile)
{
    std::ofstream file(outputFile, std::ios::app);
    if (file)
    {
        int d = solution;
        file << d << " ";
        file << "\n-----------------------------------------\n";
        file << std::endl;
        std::cout << " The solution has been saved to the file: " << outputFile;
        file.close();
    }
}

void save_solution(std::string input, std::string& outputFile)
{
    std::ofstream file(outputFile, std::ios::app);
    if (file)
    {
        std::string solution = input;
        file << solution;
        file << "\n-----------------------------------------\n";
        file << std::endl;
        std::cout << " The solution has been saved to the file:" << outputFile;
        file.close();
    }
}

int Determinant(std::vector<std::vector<int>> A)
{
    int d = 0;
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

void Add(const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B, std::string& outputFile)
{
    auto nrows =A.size();
    auto ncols =A[0].size();
    std::vector<std::vector<int>> solution(nrows, std::vector<int>(ncols));

    for (int j = 0; j < nrows; ++j) {
        for (int i = 0; i < ncols; ++i)
        {
            solution[j][i] =A[j][i] + B[j][i];
        }
    }
    save_solution(solution, outputFile);
}

void Subtract(const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B, std::string& outputFile)
{
    auto nrows = A.size();
    auto ncols = A[0].size();
    std::vector<std::vector<int>> solution(nrows, std::vector<int>(ncols));

    for (int j = 0; j < ncols; ++j) {
        for (int i = 0; i < nrows; ++i)
        {
            solution[i][j] = A[i][j] - B[i][j];
        }
    }
    save_solution(solution, outputFile);
}

void Multiply(const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B, std::string& outputFile)
{
    auto n = A.size();
    auto m = A[0].size();
    auto p = B[0].size();
    std::vector<std::vector<int>> C(n, std::vector<int>(p, 0));
    for (int j = 0; j < p; ++j) {
        for (int k = 0; k < m; ++k) {
            for (int i = 0; i < n; ++i) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
  
    /* for (auto i = 0; i < (A.size()); i++) {
         for (auto j = 0; j < (B[0].size()); j++)
             std::cout << C[i][j] << " ";
         std::cout << std::endl;*/
    save_solution(C, outputFile);
}

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>> A)
{

    //Transpose-matrix: height = width(matrix), width = height(matrix)
    std::vector<std::vector<int>> solution(A[0].size(), std::vector<int>(A.size()));

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

std::vector<std::vector<int>> Cofactor(const std::vector<std::vector<int>> A)
{
    std::vector<std::vector<int>> C(A.size(), std::vector<int>(A.size()));
    std::vector<std::vector<int>> subVect(A.size() - 1, std::vector<int>(A.size() - 1));
    for (std::size_t i = 0; i < A.size(); i++)
    {
        for (std::size_t j = 0; j < A[0].size(); j++)
        {
            int p = 0;
            for (std::size_t x = 0; x < A.size(); x++)
            {
                if (x == i)
                {
                    continue;
                }
                int q = 0;

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
            int d = Determinant(subVect);
            C[i][j] = pow(-1, i + j) * d;
        }
    }
    return C;
}

void Inverse(const std::vector<std::vector<int>> A, std::string& outputFile)
{
    int det = Determinant(A);
    if (det == 0)//check for determinant
    {
        std::string error = "Detminant is equals 0";
        save_solution(error, outputFile);
    }
    else
    {
        std::vector<std::vector<int>> solution(A.size(), std::vector<int>(A.size()));
        if (A.size() != A[0].size())//check if it has a cofactor
        {
            std::string error = "Matrix is not quadratic and thus has no cofactor";
            save_solution(error, outputFile);
        }
        else
        {
            solution = Transpose(Cofactor(A));
            for (size_t i = 0; i < A.size(); i++)
            {
                for (size_t j = 0; j < A.size(); j++)
                {
                    solution[i][j] *= (1 / det);
                }
            }
        }
        save_solution(solution, outputFile);
    }
}
/**An Enum class of operations
 *@param add
 *@param subtract
 *@param multiply
 *@param determinant
 *@param inverse
 *@param cofactor
 *@param transpose
 *@param random
 **/
enum class operation { add = 0, subtract, multiply, determinant, inverse, cofactor, transpose, random };

/**The function takes a string input and compares with default parameters to get the operation type
 *@param std::string& perform   pointer with the string function
 *@return operation convert
 **/
operation convert(std::string& perform)
{
    operation r = operation::random;

    std::string parameter = perform;

    if (parameter == "add")
    {
        r = operation::add;
    }
    if (parameter == "subtract")
    {
        r = operation::subtract;
    }
    if (parameter == "transpose")
    {
        r = operation::transpose;
    }
    if (parameter == "multiply")
    {
        r = operation::multiply;
    }
    if (parameter == "inverse")
    {
        r = operation::inverse;
    }
    if (parameter == "determinant")
    {
        r = operation::determinant;
    }
    if (parameter == "cofactor")
    {
        r = operation::cofactor;
    }
    if (parameter == " ")
    {
        r = operation::random;
    }
    return r;
}

int main(int argc, char* argv[])
{
    std::string inputAFile = "#3;3";
    std::string inputBFile = "#3;2";
    std::string outputFile = "solution";
    std::string perform = "inverse";

    
    if (argc == 9)
    {
        for (int i = 1; i < argc; i++)
        {
            std::string parameter(argv[i]);

            if (parameter == "-a")
            {
                //getline(std::cin, inputAFile);
                inputAFile = argv[i + 1];
                i++;
            }
            if (parameter == "-b")
            {
                //getline(std::cin, inputBFile);
                inputBFile = argv[i + 1];
                i++;
            }
            if (parameter == "-o")
            {
                //getline(std::cin, outputFile);
                outputFile = argv[i + 1];
                i++;
            }
            if (parameter == "-operation")
            {
                perform = argv[i + 1];
                i++;
            }
        }

    }
    const std::vector<std::vector<int>> A = read_matrix(inputAFile);
    const std::vector<std::vector<int>> B = read_matrix(inputBFile);
    operation type = convert(perform);
    switch (type)
    {
    case operation::add:
        // compares the height or columns of matrix A to the rows or size of matrix B to see if they are equal before performing the operation
        if ((A.size() == B.size()) && (A[0].size() == B[0].size()))
        {
            Add(A, B, outputFile);
        }
        else
        {
            std::string error = "The matrix cannot be added - difference in size";
            save_solution(error, outputFile);
        }
        break;

    case operation::subtract:
        if ((A.size()== B.size()) && (A[0].size() == B[0].size()))
        {
            Subtract(A, B, outputFile);
        }
        else
        {
            std::string error = "The matrix cannot be subtracted - difference in size";
            save_solution(error, outputFile);
        }
        break;

    case operation::multiply:
        // compares the rows of matrix A to the cols of matrix B to see if they are equal before performing the operation
       /*multiply*/
        if (A[0].size() != B.size()) // compares the height or columns of matrix A to the rows or size of matrix B to see if they are equal before performing the operation
        {
            std::string error = "The matrix cannot be multiplied - difference in size";
            save_solution(error, outputFile);
        }
        else
        {
            Multiply(A, B, outputFile);
        }
        break;

    case operation::determinant:
        save_solution(Determinant(A), outputFile);
        break;

    case operation::inverse:
        Inverse(A, outputFile);
        break;

    case operation::cofactor:
        if (A.size() != A[0].size())
        {
            std::string error = "Matrix is not quadratic";
            save_solution(error, outputFile);
        }
        else 
        {
            save_solution(Cofactor(A), outputFile);
        }
        
        break;

    case operation::transpose:
        save_solution(Transpose(A), outputFile);
        break;

    case operation::random:
        std::string error = "operation not available";
        save_solution(error, outputFile);
        break;
    }

}


