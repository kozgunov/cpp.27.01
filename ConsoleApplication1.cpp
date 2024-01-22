#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <memory>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "txt_processing.cpp"
//#include "txt_reader.cpp"


int main() 
{
    //reading input file
    //std::string filename;
    //std::cout << "Enter full name of file and number of string, where's the function located: ";
    //std::cin >> filename;
    //read_from_txt(filename); // reading function
    
    // taylor expansion (write into the console desired degree and point)
    int degree = 10;
    double point = 1;
    
    std::cout << "Enter the desired degree of the Taylor series: ";
    //std::cin >> degree;

    std::cout << "Enter the point of expansion: ";
    //std::cin >> point;

    taylor_example(point, degree);
    


    return 0;
}

