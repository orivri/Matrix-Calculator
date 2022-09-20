#ifndef LOADINGMATRIX_H
#define LOADINGMATRIX

#include <vector>

/**This is the main function of the program
 *int argc  The number of entries in the argv array.
 *argv      An array of pointers to strings that contain the arguments to the program.
 **/
int main(int argc, char* argv[]);

/**
 *The function reads a matrix of random number from a file
 *@param const std::string& file_name                        pointer to the file been read from
 *@return std::vector< std::vector<double>> read_matrix      returns a vector of vector matrix containing the read matrix
 **/
std::vector< std::vector<double>> read_matrix(std::string source);

/**
*The function prints a matrix on console
*@param  const std::vector<std::vector<double>> vect        vector of vector double printed to the output
**/
void debugMatrix(const std::vector<std::vector<double>> vect);

/**
 *The function saves the solution form a matrix operation to a file
 *@param const std::string& file_name                        pointer to the file been saved to
 *@param const std::vector< std::vector<double>> solution    vector of vector matrix containing the matrix to be saved to file
 **/
void save_solution(std::vector<std::vector<double>> solution, std::string& outputFile);

/**
 *The function saves the solution form a matrix operation to a file
 *@param double solution                                     double with value to the printed to file
 *@param  std::string& outputFile                            pointer to the file been saved to
 **/
void save_solution(double solution, std::string& outputFile);

/**
  *The function saves the solution form a matrix operation to a file
  *@param  std::string file_name                              string with error message to the printed to file
  *@param  std::string &outputFile                           pointer to the file been saved to
 **/
void save_solution(std::string input, std::string& outputFile);

/**print generates and writes a matrix of random values into a file
 @param const std::string& file_name    pointer to the file been written into
 @param cconst int nrows                number of rows the matrix been written into file should have
 @param cconst int ncols                number of columns the matrix been written into file should have
  **/
void Create_matrix(std::string& file_name, int nrows, int ncols);

/**The function generates random values between 50 and 1
  *@return double distro(engine)        returns a random value of type double
 **/
const double random_value();

//void LOG(std::string message);

#endif