#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <memory>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <tuple>
#include <chrono>
#include "txt_processing.cpp"
#include "txt_reader.cpp"
#include "latex_writer.cpp"



int main() 
{
    //reading input file
    std::string filename;
    std::cout << "Enter full name of file and number of string, where's the function located: ";
    std::cin >> filename;
    bool txt_correctness = false;
    for (int i = 0; i < filename.size(); ++i) // here we checked if you forgot about the extension
    {
        if (filename[i] == '.')
        {
            txt_correctness = true;
            break;
        }
        else if (filename.size() - 1 == i)
        {
            filename += ".txt";
            txt_correctness = true;
            break;
        }
    }
    read_from_txt(filename); // out the content of file to show it

    
    // taylor expansion (write into the console desired degree and point)
    int term = 10;
    double point = 1;
    std::string functionName = "f(x)";  // name of function, which will be decomposed
    std::cout << "Enter the desired number of terms of the Taylor series(natural number): " << std::endl;
    //std::cin >> term;
    std::cout << "Enter the point of expansion(real number): " << std::endl;
    //std::cin >> point;
    std::cout << "Enter the name of function(f(x) or another):  " << std::endl;
    //std::cin >> functionName;

    std::string function = read_from_txt(filename); // declaration input function from txt file
    auto result = taylor_decomposition(function, functionName, point, term);
    std::cout << "Sum: " << result.first << std::endl;
    std::cout << "Terms: ";
    for (const auto& term : result.second)
    {
        std::cout << term << " ";
    }
    std::cout << std::endl;

    std::vector<double> eval_points = {0.0, 1.0, -1.0, 2.0}; // input x in f(x), if it's necessary

    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm* local_time = std::localtime(&now_c);// convert to local time format
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d_%H-%M", local_time);

    std::string file_name = std::string(buffer) + ".tex";// create file name using the formatted time

    generateLatex(result.first, result.second, functionName, function, point, term, eval_points);

    std::string command = "pdflatex " + file_name;

    system(command.c_str());
    std::ofstream file(file_name);

    return 0;
}




