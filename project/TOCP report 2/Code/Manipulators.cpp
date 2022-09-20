#include<sstream>
#include <algorithm>
#include <iomanip>

#include "Manipulators.h"

double roundDouble(double& solution, int& precise)
{
    std::stringstream ss;
    ss << std::setprecision(precise) << solution;
    return stod(ss.str());
}

std::string Removehash(std::string& line, std::string& hash) {
    const auto pos = line.find(hash);
    if (pos != std::string::npos) {
        line = line.substr(0, pos);
    }
    return line;
}

std::string Replace(std::string& line, char& delim)
{
    replace(line.begin(), line.end(), delim, ' ');
    return line;
}
