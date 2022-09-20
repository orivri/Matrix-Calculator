#ifndef MANIPULATORS_H
#define  MANIPULATORS_H

/**
 *The function evaluates a line and replaces delimeters or separators with white space
 *@param std::string& line                        ampersand to address of line to be evaluated
 *@return std::string Line                        returns a string with the edited line
 **/
std::string Replace(std::string& line, char& delim);

/**
 *The function evaluates a line and extraxts line if the variable in the memory location @hash is encountered
 *@param std::string &line                        ampersand to address of line to be evaluated
 *@param std::string &hash                        variable of character that triggers an extraction of line
 *@return std::string Line                        returns a string with substring from the line
 **/
std::string Removehash(std::string& line, std::string& hash);

/**
 *The function rounds up a double to a precise double
 *@param double &solution                        ampersand to address of double been rounded
 *@param int &precise                            int of numbers the function rounds to
 *@return double                                 returns a more precise double
 **/
double roundDouble(double& solution, int& precise);

#endif 

