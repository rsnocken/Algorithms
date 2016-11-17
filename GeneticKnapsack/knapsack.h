//
//  knapsack.h
//  GeneticKnapSack
//
//  Created by Robert Snocken on 17/11/2016.
//  Copyright (c) 2016 RS. All rights reserved.
//

#ifndef __GeneticKnapSack__knapsack__
#define __GeneticKnapSack__knapsack__

#include "item.h"
#include <vector>
#include "shelf.h"

class knapsack
{
private:
    std::vector<bool> content;
    const long total_capacity;
    long capacity_used;
    long value;
    shelf * p_shelf;
    long count;
    
public:
    knapsack(long total_capacity, shelf * Shelf);
    ~knapsack();
    
    bool add(long idx);
    bool remove(long idx);
    void mutate(long num_mutations);
    void fill_up();
    bool is_full() const;
    void display() const;
    long get_value() const;
    
    knapsack cross_swap(knapsack& B) const;
    
};

#endif /* defined(__GeneticKnapSack__knapsack__) */
