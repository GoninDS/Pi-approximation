#include <thread>
#include <vector>
#include <iostream>
#include <string>
#include <random>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct private_data {
  int total_in_circle;
  int thread_number;
  int thread_count;
};

/**
 * @brief Creates the threads, executes them and joins them
 * 
 * @param thread_cout The amount of threads
 */
double handle_threads(int number_amount, int& thread_count);
/**
 * @brief Generates points from [0,1[ with a standard distribution
 * 
 * @param points Vector that contains if the points are in or outside of the circle
 * @param number_amount The amount of numbers used for the simulation
 */
void generate_points(int number_amount, private_data* private_data);
/**
 * @brief Checks if the x and y values are inside the circle
 * 
 * @param x_value The x value for the point
 * @param y_value The y value for the point
 * @return true The point is in the circle
 * @return false The point is out of the circle
 */
bool calculate_position(double& x_value, double& y_value);
/**
 * @brief Approximates pi with the amount of points calculated in the circle
 * 
 * @param points Contains the vector that contains if the points are in or outside of the circle
 * @return double The answer with the approximated pi
 */
double approximate_pi(int& number_amount, double& total_in_circle);
/**
 * @brief Show the obtained results in the command line
 * 
 * @param pi The variable containing the approximation
 */
void show_results(double& pi);