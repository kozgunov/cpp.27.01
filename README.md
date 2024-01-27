# University project in C++
project's goal is to show the result of univrsity's education in c++.

# Project Documentation

## Introduction
This document presents the technical specification for a student course project.
The project’s objective is to create a C++ console application that reads a function from a file, expands it into a Taylor series, finds its
roots, and generates a detailed solution in a PDF file using LaTeX.

## Requirements
1. Functional Requirements:
• The application must read a mathematical function from a text file.
• The program should expand the function into a Taylor series around a given point.
• The application should find the roots of the Taylor series.
• The solution process, including the Taylor series expansion and root finding, must be formatted and presented in a LaTeX-generated PDF file.
2. Technical Requirements
• The application must be developed in C++.
• It should be operable via a command-line interface.
• Integration with LaTeX for generating the PDF report is required.
• The program must effectively handle common errors, such as file not found or incorrect function syntax.

## Evaluation criteria:
• Accuracy of the Taylor series expansion and root finding.
• Code quality, including readability, structure, and adherence to coding
standards.
• Quality and completeness of the documentation.
• Usability and reliability of the program.

## Design and Architecture
The software is designed as a console application with the following components:
1. text file reading and figuring out the function
2. taylor decomposition
3. creating and filling pdf file (using latex)

## Implementation Details
### Reading a Mathematical Function
The function is read from a file using txt_reader.cpp file, which process every line, afterward it output the content of file and close it. handle errors like empty file & existence of file.

### Taylor Series Expansion
The Taylor series is expansion is  powerful approximation algorithm, which can help to decompose every derivable function to some approximation terms and has the following formula:
"\\[ f(x) = f(a) + f'(a)(x - a) + \\frac{f''(a)}{2!}(x - a)^2 + \\cdots + \\frac{f^{(n)}(a)}{n!}(x - a)^n + \\cdots \\]\n\n"

### Root Finding
Roots of the series are found using straight forward method (or alternatively Newton-Raphson method),which is the core of this work into txt_processing.cpp:
1. figuring out the function as line 
2. taking derivative of the line with respect to signs "+", "-", "*", "/", "."(decimal number), "^"(power)
3. repeats input number via console and summirize with evualated input point via console.   

## Building and Running Instructions
To build and run the software, follow these steps:
1. create and fill .txt file with function in the first line,
2. input interested point and precision of decomposition,
3. check the pdf file into the same folder, where you ran the program.

## Examples and Usage
An example usage of the application is txt files with pre-inputed data as function and variable into the function and writting down description of the function via sign "=" in the first line.
As an example, you can use the following function:
p(x) = 5 + 3*x + 15*x^2 + 7*x^3 + 10*x^4 + 1*x^5


## Troubles, which are in process
Common issues:

- **Issue 1**: it's impossible to use some variables, except variable "x". (it's necessary to write the variable input via console/introduce the pattern of recognizing the function and vriable for decomposition)
- **Issue 2**: pdf file, where we will write down the solution, can't be created automatically, only manually (it's necessary to "filename" argument for creating latex file and pdf afterward)
- **Issue 3**: the function into the txt files can't be found, except writting them as in examples and in the 1st line only  (necessary to write down the pattern for understaing the function)
- **Issue 4**: there were considered only polynomials for Taylor decompositions (necessary to consider elementary functions also)
- **Issue 5**: the derivative takes from full expression respectively to math. signs, but it doesn't split the polynomial or another functions
- **Issue 6**: program works only via x64 config (not x86). it happens because "pdflatex" extension is not can't follow the pointed configuration.
- **Issue 7**: evaluation the points is not realized (becuase it's not necessary and it'll make the program send 3-4 times more time)

## Conclusion
In conclusion, this project was dedicated to cpp development and shows everything, that was studied during 1.5 years.
