#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

/**The function calculates the determinate of a matrix and returns a solution
  *@param std::vector<std::vector<double>> A               a vector of vector matrix containing the values read from file
  *@return int Determinant                                 returns the value of the determinant
  **/
double Determinant(std::vector<std::vector<double>> A);

/**The function calculates the addition of two matrix and returns a solution to the file
  *@param const std::vector<std::vector<int>>A             first matrix from file
  *@param const std::vector<std::vector<int>> B            second matrix from file
  *@return std::vector<std::vector<int>> solution          solution from the add operation
  **/
std::vector<std::vector<double>> Add( std::vector<std::vector<double>> A, std::vector<std::vector<double>> B);

/** The function calculates the difference of two matrix and returns a solution to the file
  *@param const std::vector<std::vector<int>> matrix1       first matrix from file
  *@param const std::vector<std::vector<int>> matrix2       second matrix from file
  *@param std::string& outputFile                           pointer to the file where output solution from the operation is saved
  **/
std::vector<std::vector<double>> Subtract( std::vector<std::vector<double>> A, std::vector<std::vector<double>> B);

/** The function multiplies two matrix and returns a matrix of vector containing the solution to the file
  *@param const std::vector<std::vector<int>> A            first Vector of matrix to be multiplied
  *@param const std::vector<std::vector<int>> B            second vector of matrix to be multiplied
  *@param std::string& outputFile                           pointer to the file where output solution from the operation is saved
  **/
std::vector<std::vector<double>> Multiply(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B);

/**
  *The function takes a matrix and returns the matrix transpose to the file
  *@param const std::vector<std::vector<int>> matrix       The input matrix to be transposed
  *@return std::vector<std::vector<int>> solution          returns the matrix  transpose
  **/
std::vector<std::vector<double>> Transpose( std::vector<std::vector<double>> A);

/**
  *The function takes a matrix and returns the cofactor of the matrix
  *@param const std::vector<std::vector<int>> matrix       The input matrix to be transposed
  *@return std::vector<std::vector<int>> solution          returns the cofactor matrix
  **/
std::vector<std::vector<double>> Cofactor(std::vector<std::vector<double>>A);

/**
  *The function calculates the inverse of a matrix and returns a matrix of vector containing the solution
  *@param const std::vector<std::vector<int>> matrix         The input matrix
  *@param std::string& outputFile                             pointer to the file where output solution from the operation is saved
  **/
std::vector<std::vector<double>> Inverse(std::vector<std::vector<double>> A);

#endif

