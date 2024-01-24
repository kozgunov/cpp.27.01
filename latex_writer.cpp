#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <sstream>


inline void generateLatex(double first, std::vector<double> second, const std::string& functionName, std::string function, double point, int terms, const std::vector<double>& eval_points)
{

    std::ofstream file("test19.tex");

    file << "\\documentclass{article}\n";
    file << "\\usepackage{amsmath}\n\n";
    file << "\\begin{document}\n";
    file << "\\title{Taylor Series Expansion}\n";
    file << "\\author{Nikita Kozgunov}\n";
    file << "\\date{\\today}\n";
    file << "\\maketitle\n\n";

    // Introduction
    file << "\\section{Introduction}\n";
    file << "This document presents the results of a Taylor series expansion computation. ";
    file << "The program computes the Taylor series expansion of a given function, ";
    file << "around a specified point, up to a certain number of terms.\n\n";

    // General Formula
    file << "\\section{Taylor Series Expansion}\n";
    file << "The Taylor series expansion of a function $f(x)$ around a point $a$ is given by:\n";
    file << "\\[ f(x) = f(a) + f'(a)(x - a) + \\frac{f''(a)}{2!}(x - a)^2 + \\cdots + \\frac{f^{(n)}(a)}{n!}(x - a)^n + \\cdots \\]\n\n";

    // Input data
    file << "\\section{Function, Point, and Terms}\n";
    file << "The function " << functionName << " used for the Taylor series expansion is:\n" << function << ".\n";
    file << "The point of expansion is " << point << ", and the number of terms is " << terms << ".\n\n";

    // Result
    file << "\\section{Result}\n";
    file << "The sum of the Taylor series expansion is:";
    file << "\\[" << functionName << "(" << function << ") = " << first << "\\]\n"; // sum 
    file << "The terms into the Taylor expansion are:";

    std::ostringstream ss;

    ss << "\\[" << functionName << "(" << function << ") = " << first;

    for (size_t i = 0; i < second.size(); ++i) 
    {
        ss << " + " << second[i] << "x^{" << i << "}";
    }

    ss << "\\]";

    file << ss.str();


    // evaluation at Points
    file << "\\section{Function Evaluation at Specific Points(not complete)}\n";
    file << "The function values at specific points are:\n";
    file << "\\begin{itemize}\n";
    for (size_t i = 0; i < eval_points.size(); ++i) {
        file << "\\item At point " << i << ": " << eval_points[i] << "\n";
    }
    file << "\\end{itemize}\n";

    file << "\\end{document}\n";

    file.close();
}


