#include <iostream>
#include <fstream>
#include <string>

#ifndef TXT_READER_H
#define TXT_READER_H


inline std::string read_from_txt(const std::string& filename) // function for processing every line and check if file is readable or not  
{
    std::ifstream file(filename);
    std::string function;


    if (file.is_open()) 
    {
        int counter = 0;
        std::cout << "file is opened. the content of the file:" << std::endl << std::endl;
        while (getline(file, function))
        {
            std::getline(file, function); // actually, we are interested only in the 1st line, where the function will be discribed
            //std::cout << function << std::endl; // read&output each line
            counter += 1;
        }
        file.close();
        if (counter == 0)
        {
            std::cerr << "ERROR. File exsits, but no valiable information contained..."; // error handling
        }
    }
    else //error handling
    {
        std::cerr << "ERROR. Unable to open file" << std::endl;
    }
    return function;

}


#endif // TXT_READER_H
