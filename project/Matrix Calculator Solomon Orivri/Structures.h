#ifndef STRUCTURES
#define STRUCTURES

#include <vector>

/**
 *An enum of operations for function execution
 **/
enum class operation { add = 0, subtract, multiply, determinant, inverse, cofactor, transpose, not_supported };

/**A structure that stores the variables extracted from the console
 **/
struct cmdArgs
{
    std::string inputAFile;
    std::string inputBFile;
    std::string outputFile;
    std::string OperationType;
};

/**The function reads the string input(-operation) from user and allocates the correct enum type
 *@param std:: string &Operation    memory address holding string of the operation to be performed
 *@return operation r               returns an enum type with a specific operation to be performed
**/
operation convert(std::string& Operation);

/**The function reads the string input(-operation) from user and allocates the correct enum type
 *@param int arg            memory address holding string of the operation to be performed
 *@param char* argv[]       pointer to an array of strings holding values inputted from the console switches
 *@cmdArgs& cmdArgs         ampersand with the memory address to struct for storage of extracted values
 *@return cmdArgs           Returns a struct with assigned values
 **/
cmdArgs ReadcmdArgs(int argc, char* argv[], cmdArgs& cmdArgs);

#endif