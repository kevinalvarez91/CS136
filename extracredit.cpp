#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int POPULATION_SIZE = 100;
const int MAX_GENERATIONS = 100;
const double MUTATION_RATE = 0.1;

// Define the fitness function (sphere function)
double fitness(double x) {
    return x * x;
}

int main() {
    srand(time(nullptr));

    std::vector<double> population(POPULATION_SIZE);

    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i] = (rand() % 20000 - 10000) / 100.0; // Initialize with random values between -100 and 100
    }

    for (int generation = 0; generation < MAX_GENERATIONS; generation++) {
        // Evaluate fitness for each individual
        for (double& individual : population) {
            individual = fitness(individual);
        }

        // Sort by fitness (ascending order)
        std::sort(population.begin(), population.end());

        // Select the fittest individuals
        int selectionSize = POPULATION_SIZE * 0.2; // Select top 20%
        population.erase(population.begin() + selectionSize, population.end());

        // Crossover and mutation
        while (population.size() < POPULATION_SIZE) {
            int parent1 = rand() % selectionSize;
            int parent2 = rand() % selectionSize;
            double child = (population[parent1] + population[parent2]) / 2;
            
            if (rand() % 100 < MUTATION_RATE * 100) {
                child += (rand() % 200 - 100) / 100.0; // Mutation
            }

            population.push_back(child);
        }
    }

    std::cout << "Optimal solution: " << population[0] << " (Fitness: " << fitness(population[0]) << ")" << std::endl;

    return 0;
}
