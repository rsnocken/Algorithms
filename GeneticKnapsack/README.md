# A Genetic Algorithm for the Knapsack Problem

## Problem description

The Knapsack problem is a classic problem in discrete optimisation. There is a number of objects available for selection. Each object has a value and a size (or alternatively a mass). The user has a knapsack with a fixed capacity. The user must select the items that maximise the value of the full knapsack. If the number of items is sufficiently large it becomes infeasible to do an exhaustive search.

## Genetic algorithms

Genetic algorithms follow as set of heuristics that are inspired by evolution. The over-arching idea is to perform an intelligent search of the solution space.

1. We 'create' a population of solutions to the problem. These are often chosen randomly but, we can also add 'good' solutions to improve the initial gene pool.
2. We implement a 'cross swap' function that combines solutions to form new solutions. This immitates reproduction in lifeforms. Unlike in nature, we can cross swap all individuals with each other.
3. We 'mutate' a percentage of the population. This immitates mutation of genes that occurs in evolution.
4. We select the 'best' remaining individuals. The immitates the process of natural selection.

Steps 2-4 could be called a generation. We will usually let the algorithm run for several generations.

For any given problem we need to devise bespoke methods for creating an initial population, cross swap, mutation and selection. There is a lot of scope for different implementations. The idea of the algorithm is to chance upon specific combinations that really work well together. These combinations should the survive to the next generation and may mutate, recombine and continue to improve.

## Outline of implementation

1. The initial population is created by filling the knapsacks at random.
2. To combine two parent knapsacks we create a child knapsack. We randomly select an item, if that item is in either parent knapsack we add it to the child knapsack. We repeat this until the child knapsack is full. We also check if any further items would fit in the child knapsack.
3. To mutate a given knapsack we remove 2 items and randomly refill it (the number 2 can be changed in the code).
4. We calculate the mean value of the knapsacks in a population and only the knapsacks whose value is greater than this mean are selected to survive.

Generally, we expect better results the more generations we allow but due to the inherent randomness this may not be the case. For example, the best knapsack in a generation may mutate and lose value.

## Results

The code compares the genetic algorithm to random search. The number of random knapsacks can be tuned so that we can compare random search versus genetic search given certain amounts of time.

Sample output 1:

- Genetic best: 320
- Genetic time: 112502093131
- Random best:  195
- Random time:  120691586335

Sample output 2:

- Genetic best: 454
- Genetic time: 1074021194379
- Random best:  199
- Random time:  1207363674633

## Notes

If you want to run the program yourself there is a selection of parameters to make simple changes. However, the number of items should be sufficiently larger than the capacity of the knapsacks to make sure that a knapsack cannot simply carry all items. The next important parameter is the target_size_of_population. As implemented, in a generation, the algorithm will increase the population via cross swap until it is larger than this number and then decrease by selection until it is smaller. In the worst case, the algorithm has to create target_size_of_population squared new knapsacks.

