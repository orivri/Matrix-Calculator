
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstddef>
#include<vector>
#include <cstdlib>
#include<random>
#include<chrono>
#include <algorithm>
#include <iomanip>

#include"Manipulators.h"


const double random_value()
{
    static std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
    static std::normal_distribution<double> distro(50, 1);
    return distro(engine);
}

void Create_matrix(std::string& file_name, int nrows,  int ncols)
{
    std::ofstream file(file_name); //ofstream + open
    if (file) //is it open?
    {
        file << "#" << nrows << ";" << ncols << '\n';
        for (int r = 0; r < nrows; r++) 
        {
            for (int c = 0; c < ncols; c++)
            {
                file << random_value();
                if (c < (ncols - 1))
                    file << ";";
            }
            file << std::endl;
        }
        file.close();
    }
    std::cout << " A matrix of rows" << nrows << " and " << ncols << " has been printed  to : " << file_name<< '\n';
}

void debugMatrix(std::vector<std::vector<double>> vect)
{
    for (auto i = 0; i < vect.size(); i++)
    {
        for (auto j = 0; j < vect[0].size(); j++)
        {
            std::cout <<"[" << vect[i][j] <<"]"<< " ";
        }
        std::cout << std::endl;
    }
}

std::vector< std::vector<double>> read_matrix(std::string source)
{
    std::string hash = "#";
    char delim = ';';
    std::vector<std::vector <double>> matrix;
    std::ifstream file(source);// input file stream + open
    if (file)
    {
        std::string line; //string type
        while (!file.eof())
        {

            while (getline(file, line))
            {
               
                    line = Removehash(line, hash);
                    if (line.empty()) continue;
                    line = Replace(line, delim);
                    
                std::stringstream ss;
                ss << line;

                std::vector<double> row;
                double number = 0.0;

                while (ss >> number)
                {

                    row.push_back(number);
                }

                matrix.push_back(row);
            }
            
            file.close();
            std::cout << std::endl;
        }
    }
    else
        std::cout << "Unable to open file." << '\n';

    //std::cout << "A Matrix of size has been read file. " << source << " ";
    return matrix;
}

void save_solution(std::vector<std::vector<double>> solution, std::string & outputFile)
{
    std::ofstream file(outputFile, std::ios::app);
    if (file)
    {
        file << "#" << solution.size() << ";" << solution[0].size()<< '\n';
        double d = 0;
        for (size_t i = 0; i < solution.size(); i++)
        {
            for (size_t j = 0; j < solution[0].size(); j++)
            {
                d = solution[i][j];
                file << d;
                if (j < (solution[0].size() - 1))
                    file << ";";
            }
            file << std::endl;
        }
        file.close();
    }
    std::cout << " The solution has been saved to the file: " <<outputFile << '\n';
}

void save_solution(double solution, std::string& outputFile)
{
    int precise = 2;
    double d = roundDouble(solution, precise);
    std::ofstream file(outputFile, std::ios::app);
    if (file)
    {
        double d = solution;
        file << d << " ";
        file << '\n';
        std::cout << " The solution has been saved to the file: " << outputFile;
    }
        file.close();
}

void save_solution(std::string input, std::string& outputFile)
{
    std::ofstream file(outputFile, std::ios::app);
    if (file)
    {
        std::string solution = input;
        file << solution << '\n';
        file.close();
    }
    std::cout << " The solution has been saved to the file:" << outputFile << '\n';
}


