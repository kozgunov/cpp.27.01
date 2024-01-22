#include <iostream>
#include <fstream>
#include <string>

#ifndef TXT_READER_H
#define TXT_READER_H

void read_from_txt(const std::string& filename);

inline void read_from_txt(const std::string& filename) // function for processing every line and check if file is readable or not  
{
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) 
    {
        std::cout << "file is opened. the content of the file:" << std::endl << std::endl;
        while (getline(file, line)) 
        {
            std::cout << line << std::endl; // read&output each line
        }
        file.close();
    }
    else //error handling
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}





#endif // TXT_READER_H
