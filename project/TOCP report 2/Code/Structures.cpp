#include <iostream>
#include<vector>
#include"Structures.h"

enum class operation
{
    add = 0, subtract, multiply, determinant, inverse, cofactor, transpose, not_supported
};

struct cmdArgs
{
    std::string inputAFile;
    std::string inputBFile;
    std::string outputFile;
    std::string OperationType;
};

cmdArgs ReadcmdArgs(int argc, char* argv[], cmdArgs& cmdArgs)
{


    cmdArgs.inputAFile;
    cmdArgs.inputBFile;
    cmdArgs.outputFile;
    cmdArgs.OperationType;

    if (argc == 9)
    {
        for (int i = 1; i < argc; i++)
        {
            std::string parameter(argv[i]);

            if (parameter == "-a")
            {
                //getline(std::cin, inputAFile);
                cmdArgs.inputAFile = argv[i + 1];
                i++;
            }
            if (parameter == "-b")
            {
                //getline(std::cin, inputBFile);
                cmdArgs.inputBFile = argv[i + 1];
                i++;
            }
            if (parameter == "-o")
            {
                //getline(std::cin, outputFile);
                cmdArgs.outputFile = argv[i + 1];
                i++;
            }
            if (parameter == "-operation")
            {
                cmdArgs.OperationType = argv[i + 1];
                i++;
            }
        }
        return cmdArgs;
    }
    else
    {
        cmdArgs.inputAFile = "c.txt";
        cmdArgs.inputBFile = "b.txt";
        cmdArgs.outputFile = "Solution.txt";
        cmdArgs.OperationType = "determinant";
        return cmdArgs;
    }
}

operation convert(std::string& Operation)
{
    operation r = operation::not_supported;

    std::string parameter = Operation;

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
        r = operation::not_supported;
    }
    return r;
}
