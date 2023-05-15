#include "main.h"

int main(int argc, char ** argv) {
  if (argc == 3) {
    int number_amount = std::stoi(argv[1]);
    int thread_count = std::stoi(argv[2]);

    // Begin the time recording
    std::chrono::_V2::system_clock::time_point start
        = std::chrono::high_resolution_clock::now();
    // Do the simulation
    double total_in_circle = handle_threads(number_amount, thread_count);
    double pi = approximate_pi(number_amount, total_in_circle);
    // End the time recording
    std::chrono::_V2::system_clock::time_point end
        = std::chrono::high_resolution_clock::now();
    // Elapsed time
    std::chrono::duration<double> elapsed_time
        = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    show_results(pi, elapsed_time);
  } else {
    std::cerr << 
        "Please only insert the amount of numbers for the simulation and the thread count"
        << std::endl;
  }
  return 0;
}

double handle_threads(int number_amount, int& thread_count) {
  // Vector containing the threads
  std::vector<std::thread> threads;
  // Private data for each thread
  std::vector<private_data> private_data_vector(thread_count);
  // Creates the threads
  for (int i = 0; i < thread_count; ++i) {
    // Create the private data
    private_data_vector[i].thread_number = i;
    private_data_vector[i].thread_count = thread_count;
    // Generate the seed
    private_data_vector[i].seed = std::random_device()();
    // Create the thread
    threads.push_back(std::thread(generate_points, number_amount, &private_data_vector[i]));
  }
  double total_in_circle = 0.0;
  // Joins the threads
  for (int i = 0; i < thread_count; ++i) {
    threads[i].join();
    total_in_circle += private_data_vector[i].total_in_circle;
  }
  return total_in_circle;
}

void generate_points(int number_amount, private_data* private_data) {
  // Calculate the respective block
  int start = private_data->thread_number * (number_amount / private_data->thread_count) +
      MIN(private_data->thread_number, number_amount % private_data->thread_count);
  int end = (private_data->thread_number + 1) * (number_amount / private_data->thread_count) +
      MIN(private_data->thread_number + 1, number_amount % private_data->thread_count);
  // Standard mersenne_twister_engine
  std::mt19937 generator(private_data->seed);
  // Set the distribution in the range [0,1[
  std::uniform_real_distribution<double> distribution(0.0,1.0);
  double x_value = 0.0;
  double y_value = 0.0;
  bool in_circle = false;
  for (int i = start; i < end; ++i) {
    // Generate the random points
    x_value = distribution(generator);
    y_value = distribution(generator);
    // Calculate if it is in the circle
    in_circle = calculate_position(x_value, y_value);
    // Add to count
    if (in_circle) {
      ++private_data->total_in_circle;
    }
  }
}

bool calculate_position(double& x_value, double& y_value) {
  bool answer = false;
  double x_squared = x_value * x_value;
  double y_squared = y_value * y_value;
  if (x_squared + y_squared <= 1) {
    answer = true;
  }  
  return answer;
}

double approximate_pi(int& number_amount, double& total_in_circle) {
  double total_points = (double)(number_amount);
  double pi = 0.0;
  pi = (double)(4.0 * total_in_circle / total_points);
  return pi;
}

void show_results(double& pi, std::chrono::duration<double>& elapsed_time) {
  std::cout << "EXECUTION TIME: " << elapsed_time.count() << "s" << std::endl;
  std::cout << "PI APPROXIMATION: " << pi << std::endl;
}