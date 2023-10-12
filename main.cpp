/**
 ******************************************************************************
 *
 *   Copyright (C) 2023, Kulikova Alyona, IU8-11M, variant.5
 *
 ******************************************************************************
 *
 * @name Laboratory No. 2
 *
 * @file main.cpp
 *
 * <b>Modification History</b>
 *
 *   Date        Name        Description
 *
 ******************************************************************************
 * encoding:   UTF-8 BOM
 * tab size:   4
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

//#define CONST_A -2
//#define CONST_B 4
#define CONST_E 0.1

/**
* @brief optimal_passive_method
* Returns the value of the function at a given point
*
* @param x
*
* @return result unimodal function -cos(0.5 * x) - 1
*/
double unimodal_function(double x);

/**
* @brief multimodal_function
* Returns the value of the function at a given point
*
* @param x
*
* @return result multimodal function (-cos(0.5 * x) - 1) * (sin(5 * x))
*/
double multimodal_function(double x);

/**
* @brief random_range
* random range
*
* @param [a, b]
*
* @return result random range
*/
double random_range(const double a, const double b) {
    return a + rand() * 1./RAND_MAX * (b - a);
}

/**
* @brief print_line
* print line
*
* @param iteration, T, value, function value
*
* @return null
*/
void print_line(const int iteration, const double T,
               const double value, const double function_value) {
    std::cout
         << iteration
         << "\t" << T
         << "\t" << value
         << "\t" << function_value
         << "\n";
}

/**
* @brief simulated_annealing_method
* simulated annealing method
*
* @param a, b, func
*
* @return auto
*/
template<class Function>
auto simulated_annealing_method(const double a, const double b, Function func) {
    std::cout
         << "N"
         << "\t" << "T"
         << "\t" << "x"
         << "\t" << "f(x)"
         << '\n' << std::string(55, '-') << '\n';

    const double T_min = .01;
    double T_i = 10000.;
    double x_i = random_range(a, b);
    int i = 0;
    while (T_i > T_min) {
        ++i;
        double x_new = random_range(a, b);
        double delta_f = func(x_new) - func(x_i);
        if (delta_f <= 0) {
            x_i = x_new;
        } else {
            double randomProb = random_range(0, 1);
            double probability = exp(-delta_f/T_i);
            if (randomProb < probability) {
                x_i = x_new;
            }
        }
        print_line(i, T_i, x_i, func(x_i));
        T_i *= .95;
    }

    return std::pair{x_i, func(x_i)};
}

/**
* @brief info
* info
*
* @return null
*/
void info() {
    std::cout << "=========================\nKULIKOVA ALYONA IU8-11M\n";
    std::cout << "LAB #3\n";
    std::cout << "variant #5\n";
    std::cout << "=========================\n";

}

const double CONST_A = -2;
const double CONST_B = 4;

int main() {
    info();

    srand(time(nullptr)); // from rand

    // 1
    std::cout
            << "\n **** Function: (-cos(0.5 * x) - 1) , interval: ["
            << CONST_A
            << ","
            << CONST_B
            << "] **** \n\n";

    auto result_1 = simulated_annealing_method(CONST_A, CONST_B, unimodal_function);
    std::cout << "Result: Xmin = " << result_1.first
         << ", Fmin = " << result_1.second << '\n';
    // 2
    std::cout
            << "\n **** Function: (-cos(0.5 * x) - 1) * sin(5 * x), interval: ["
            << CONST_A
            << ","
            << CONST_B
            << "] **** \n\n";
    auto result_2 = simulated_annealing_method(CONST_A, CONST_B, multimodal_function);
    std::cout << "Result: Xmin = " << result_2.first
         << ", Fmin = " << result_2.second << '\n';

    return 0;
}
