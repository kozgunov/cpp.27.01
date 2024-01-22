#include <iostream>
#include <vector>
#include <cmath>


// nth degree of derivative of polynomials around point p with coefs
inline double nth_derivative(const std::vector<float>& coefs, int n, double p) // maximal approximation achieved here 
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
inline double taylor_series(const std::vector<float>& coefs, double p, int terms)
{
    double sum = 0.0;
    for (int i = 0; i < terms; i++) {
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
    std::vector<float> coefficients = {1000, 10, 20, -25}; // ordered from lowest degree to highest

    double taylorCoeffs = taylor_series(coefficients, expansionPoint, terms);

    std::cout << "Result: " << taylorCoeffs << std::endl;
    std::cout << "Taylor decomposition finished" << std::endl;

    return 0;
}

