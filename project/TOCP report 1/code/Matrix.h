#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

/**
 *The function reads a matrix of random number from a file
 *@param const std::string& file_name                        pointer to the file been read from
 *@return std::vector< std::vector<double>> read_matrix      returns a vector of vector matrix containing the read matrix
 **/
const std::vector<std::vector<int>> read_matrix(std::string file_name);

/**
*The function prints a matrix on console
*@param  const std::vector<std::vector<double>> vect        vector of vector double printed to the output
**/
void debugMatrix(const std::vector<std::vector<int>> vect);

/**
 *The function saves the solution form a matrix operation to a file
 *@param const std::string& file_name                        pointer to the file been saved to
 *@param const std::vector< std::vector<double>> solution    vector of vector matrix containing the matrix to be saved to file
 **/
void save_solution(const std::vector< std::vector<int>> solution, std::string& outputFile);

/**
 *The function saves the solution form a matrix operation to a file
 *@param double solution                                     double with value to the printed to file          
 *@param  std::string& outputFile                            pointer to the file been saved to
 **/
void save_solution(int solution, std::string& outputFile);

/**
  *The function saves the solution form a matrix operation to a file
  *@param  std::string file_name                              string with error message to the printed to file
  *@param  std::string &outputFile                           pointer to the file been saved to
 **/
void save_solution(std::string input, std::string& outputFile);


/**The function calculates the determinate of a matrix and returns a solution
  *@param std::vector<std::vector<double>> A               a vector of vector matrix containing the values read from file
  *@return int Determinant                                 returns the value of the determinant
  **/
int Determinant(std::vector<std::vector<int>> A);

/**The function calculates the addition of two matrix and returns a solution to the file
  *@param const std::vector<std::vector<int>>A             first matrix from file
  *@param const std::vector<std::vector<int>> B            second matrix from file
  *@return std::vector<std::vector<int>> solution          solution from the add operation
  **/
void Add(const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B, std::string& outputFile);

/** The function calculates the difference of two matrix and returns a solution to the file
  *@param const std::vector<std::vector<int>> matrix1       first matrix from file
  *@param const std::vector<std::vector<int>> matrix2       second matrix from file
  *@param std::string& outputFile                           pointer to the file where output solution from the operation is saved
  **/
void Subtract(const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B, std::string& outputFile);

/** The function multiplies two matrix and returns a matrix of vector containing the solution to the file
  *@param const std::vector<std::vector<int>> A            first Vector of matrix to be multiplied
  *@param const std::vector<std::vector<int>> B            second vector of matrix to be multiplied
  *@param std::string& outputFile                           pointer to the file where output solution from the operation is saved
  **/
void Multiply(const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B, std::string& outputFile);

/**
  *The function takes a matrix and returns the matrix transpose to the file
  *@param const std::vector<std::vector<int>> matrix       The input matrix to be transposed
  *@return std::vector<std::vector<int>> solution          returns the matrix  transpose
  **/
std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>A);

/**
  *The function takes a matrix and returns the cofactor of the matrix
  *@param const std::vector<std::vector<int>> matrix       The input matrix to be transposed
  *@return std::vector<std::vector<int>> solution          returns the cofactor matrix
  **/
std::vector<std::vector<int>> Cofactor(const std::vector<std::vector<int>> A);


/**
  *The function calculates the inverse of a matrix and returns a matrix of vector containing the solution
  *@param const std::vector<std::vector<int>> matrix         The input matrix
  *@param std::string& outputFile                             pointer to the file where output solution from the operation is saved
  **/
void Inverse(const std::vector<std::vector<int>> A, std::string& outputFile);
#endif

