#include <iostream>
#include <vector>
#include <cmath>


// nth degree of derivative of polynomials around point p with coefs
inline double nth_derivative(const std::vector<double>& coefs, int n, double p) // maximal approximation achieved here 
{
    double derivative = 0.0;

    for (int i = n; i <= coefs.size()-1; i++)
    {
        double term = coefs[i];
        for (int j = 0; j < n; j++)
        {
            term *= (i - j);
        }
        derivative += term * std::pow(p, i - n);
    }

    return derivative;
}

// function to compute Taylor series expansion of a polynomial around a point
inline double taylor_sum(const std::vector<double>& coefs, double p)
{
    double sum = 0.0;
    for (int i = 0; i < 10; i++) // 10 - is degree of taylor decomposition 
    {
        double term = nth_derivative(coefs, i, p) / std::tgamma(i + 1);
        sum += term * std::pow(p, i);
        std::cout << sum << " - sum " << term << " - term" << std::endl;

    }
    return sum;
}


inline double taylor_example(double expansionPoint, int terms)
{
    std::cout << "Taylor decomposition started" << std::endl;
    // example for polynomial: 10 + 1x + 10x^3
    std::vector<double> coefficients = {1000, 10, 20, -25}; // ordered from lowest degree to highest

    double taylorCoeffs = taylor_sum(coefficients, expansionPoint);

    std::cout << "Result: " << taylorCoeffs << std::endl;
    std::cout << "Taylor decomposition finished" << std::endl;

    return 0;
}

// alternative way, using newton-raphson method
/*


std::vector<double> taylor_coefs(const std::vector<double>& coefficients, double point, int terms) {
    std::vector<double> taylorCoefficients(terms, 0);

    for (int i = 0; i < terms; i++) {
        taylorCoefficients[i] = nth_derivative(coefficients, i, point) / std::tgamma(i + 1);
    }

    return taylorCoefficients;
}

// Function to evaluate the polynomial at a given point
double evaluate_polynomial(const std::vector<double>& coefficients, double x) {
    double result = 0.0;
    for (int i = 0; i < coefficients.size(); i++) {
        result += coefficients[i] * std::pow(x, i);
    }
    return result;
}

// Function to find the root of the polynomial using the Newton-Raphson method
double newton_raphson(const std::vector<double>& coefficients, double initialGuess, double tolerance = 1e-6, int maxIterations = 1000) {
    double x = initialGuess;
    double h = evaluate_polynomial(coefficients, x) / evaluate_polynomial(taylor_coefs(coefficients, x, coefficients.size()), x);

    int iteration = 0;
    while (std::abs(h) >= tolerance && iteration < maxIterations) {
        h = evaluate_polynomial(coefficients, x) / evaluate_polynomial(taylor_coefs(coefficients, x, coefficients.size()), x);
        x = x - h;
        iteration++;
    }

    return x;
}
*/
