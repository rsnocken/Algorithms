//
//  main.cpp
//  GeneticKnapSack
//
//  Created by Robert Snocken on 17/11/2016.
//  Copyright (c) 2016 RS. All rights reserved.
//

/* Genetic algorithm approach to the knapsack problem:
 
Genetic algorithms are one of the so called bio-algorithms that are inspired by biological processes.
Genetic algorithms are inspired by the passing of genetics from parent to child; mutation; and natural
selection - together these process are often called evolution!
 
The algorithm has 4 main parts.
 
Step 1: Randomly intiate a population of solutions
Step 2: Produce offspring: we find 'a way' to combine two (or more) solutions
Step 3: We randomly mutate our solutions
Step 4: We select the best solutions and return to step 2

In the demonstration code below a genetic algorithm is used to find solutions for the knapsack problem.
The best solution is compared to the best solution from running random search for around the same amount
of time.
 
Sample output:
 Genetic best: 320
 Genetic time: 112502093131
 Random best:  195
 Random time:  120691586335

The genetic algorithm seriously outperforms random search. Essentially, the algorithm is an intelligent
search of the possible solution space.
*/



#include <iostream>
#include <vector>
#include "item.h"
#include "knapsack.h"
#include "shelf.h"


std::vector<knapsack> natural_selection(std::vector<knapsack>& Population);
std::vector<knapsack> produce_offspring(std::vector<knapsack>& Population);
std::vector<knapsack> mutate_population(std::vector<knapsack>& Population);

int main()
{
    //The shelf object represents the items that we can choice from.
    shelf Shelf(1000);
    
    
    std::vector<knapsack> Population;
    
    auto begin = std::chrono::high_resolution_clock::now();
    
    
    // Random initialization:
    for (long i = 0; i < 100; ++i)
    {
        knapsack A(100, &Shelf);
        A.fill_up();
        Population.push_back( A );
    }
    
    // Each iteration of this loop represents the passing of a generation of solutions.
    for (long i = 0; i < 20; ++i)
    {
        while (Population.size() < 1000)
        {
            Population = produce_offspring(Population);
            Population = mutate_population(Population);
        }
    
        while (Population.size() > 1000)
        {
            Population = natural_selection(Population);
        }
    
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    
    
    long best_score = 0;
    for (long i = 0; i < Population.size(); ++i)
    {
        if (Population[i].get_value() > best_score)
            best_score = Population[i].get_value();
    }
    
    std::cout << "Genetic best: " << best_score << std::endl;
    std::cout << "Genetic time: " << (end-begin).count() << std::endl;
    
    
    // Next we randomly sample many times.
    
    begin = std::chrono::high_resolution_clock::now();
    best_score = 0;
    
    for (long i = 0; i < 5000000; ++i)
    {
        knapsack A(100, &Shelf);
        A.fill_up();
        if (A.get_value() > best_score)
            best_score = A.get_value();

    }
    
    end = std::chrono::high_resolution_clock::now();
    
    std::cout << "Random best:  " << best_score << std::endl;
    std::cout << "Random time:  " << (end-begin).count() << std::endl;
    
    
    
    
    return 0;
    
}


std::vector<knapsack> natural_selection(std::vector<knapsack>& Population)
{
    std::vector<long> values;
    double sum=0;
    
    
    for (auto specimen : Population)
    {
        long value = specimen.get_value();
        sum += value;
        values.push_back(value);
    }

    double mean = sum / values.size();
    
    std::vector<knapsack> new_population;
    
    for (auto specimen : Population)
    {
        long value = specimen.get_value();
        if (double(value) > mean)
            new_population.push_back(specimen);
    }
    
    return new_population;
}

std::vector<knapsack> produce_offspring(std::vector<knapsack>& Population)
{
    long N = Population.size();
    
    for (long i = 0; i < N; ++i)
    {
        for (long j = i; j < N; ++j)
        {
            knapsack A = Population[i].cross_swap(Population[j]);
            Population.push_back(A);
        }
        
    }
    
    return Population;
}

std::vector<knapsack> mutate_population(std::vector<knapsack>& Population)
{
    long N = Population.size();
    
    for (long i = 0; i < N; ++i)
    {
        Population[i].mutate(2);
    }
    
    return Population;
    
}

