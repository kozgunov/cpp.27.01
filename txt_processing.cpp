#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <cmath>
#include <utility>

// nth degree of derivative of polynomials around point p with coefs
inline double nth_derivative(const std::vector<double>& coefs, int n, double p) // maximal approximation achieved here 
{
    double derivative = 0.0;

    for (int i = n; i < coefs.size(); ++i)
    {
        double term = coefs[i];
        for (int j = 0; j < n; ++j)
        {
            term *= (i - j);
        }
        derivative += term * std::pow(p, i - n);
    }

    return derivative;
}

// function to compute Taylor series expansion of a polynomial around a point
inline std::pair<double, std::vector<double>> taylor_sum(const std::vector<double>& coefs, double p, int term)
{
    double sum = 0.0;
    std::vector<double> terms(term, 0.0);
    for (int i = 0; i < term; ++i) // 10 - is degree of taylor decomposition (term=10)
    {
        double term = (nth_derivative(coefs, i, p) * std::pow(p, i)) / std::tgamma(i + 1);
        sum += term;
        terms[i] = term;
        std::cout << sum << " - sum " << term << " - term" << std::endl;

    }
    return std::make_pair(sum, terms);
}


inline std::pair<double, std::vector<double>> taylor_decomposition(const std::string& function, const std::string& functionName, double expansionPoint, int term)
{
    std::cout << "Taylor decomposition started" << std::endl;

    std::regex term_regex("([+-]?\\d*)\\*?x\\^?(\\d*)"); // init standard math operations.
    std::smatch match;
    std::string temp_function = function;
    std::vector<double> coefficients(term, 0.0); // init coefficients with zeros. ordered from lowest degree to highest

    // Parse the function and extract coefficients
    while (std::regex_search(temp_function, match, term_regex)) 
    {
        //int power = match[2].str().empty() ? 1 : std::stoi(match[2].str()) ;
        int power = match[2].str().empty() ? (match[1].str().empty() ? 0 : 1) : std::stoi(match[2].str());
        double coeff = match[1].str().empty() ? 1.0 : std::stod(match[1].str());

        if (power < term) 
        {
            coefficients[power] = coeff;
        }

        temp_function = match.suffix().str(); // proceed to the next match
    }

    std::pair<double, std::vector<double>> taylorResult = taylor_sum(coefficients, expansionPoint, term);
    double sum = taylorResult.first;
    std::vector<double> terms = taylorResult.second;

    std::cout << "Result: " << sum << std::endl;
    std::cout << "Taylor decomposition finished" << std::endl;

    return std::make_pair(sum, terms);
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
