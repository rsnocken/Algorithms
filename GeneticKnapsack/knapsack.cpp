//
//  knapsack.cpp
//  GeneticKnapSack
//
//  Created by Robert Snocken on 17/11/2016.
//  Copyright (c) 2016 RS. All rights reserved.
//

#include "knapsack.h"
#include <iostream>

knapsack::knapsack(long capacity, shelf * Shelf):
total_capacity(capacity),
capacity_used(0),
value(0),
count(0),
p_shelf(Shelf)
{
    
    long N = p_shelf->size();
    
    for (long i = 0; i < N; ++i)
    {
        content.push_back(0);
    }
}

knapsack::~knapsack()
{
    
}

bool knapsack::add(long idx)
{
    if (content[idx] == 1)
    {
        return false;
    }
    
    item A = p_shelf->items[idx];
    
    if (capacity_used + A.get_size() > total_capacity)
    {
        return false;
    }
    
    content[idx] = 1;
    capacity_used += A.get_size();
    value += A.get_value();
    count++;
    
    return true;
}

bool knapsack::remove(long idx)
{
    if (content[idx] == 0)
    {
        return false;
    }
    
    item A = p_shelf->items[idx];
    
    content[idx] = 0;
    capacity_used -= A.get_size();
    value -= A.get_value();
    
    count--;
    
    return true;
}

void knapsack::mutate(long num_mutations)
{
    long N = content.size();
    
    for (long i = 0; i < num_mutations; ++i)
    {
        while( !(this->remove(random() % N)) )
        {
        }
    }
    
    this->fill_up();
    
}

void knapsack::fill_up()
{
    long N = content.size();
    // try to add random elements to the knapsack until it is full
    
    
    
    while (this->is_full() == false)
    {
        long el = random() % N;
        //std::cout << el << std::endl;
        this->add(el);
    }
    
}

bool knapsack::is_full() const
{
    long spare_capacity = total_capacity - capacity_used;
    
    long N = content.size();
    
    for (long i = 0; i < N; ++i)
    {
        if (p_shelf->items[i].get_size() <= spare_capacity)
        {
            return false;
        }
    }
    
    return true;
    
}

knapsack knapsack::cross_swap(knapsack& B) const
{
    knapsack C(total_capacity, p_shelf);
    long N = content.size();
    
    for (long el = 0; el < N; ++el)
    {
        if (this->content[el] == 1)
        {
            C.add(el);
            continue;
        }
        
        if (B.content[el] == 1)
        {
            C.add(el);
            continue;
        }
        
    }
    
    C.fill_up();
    
    return C;
}

void knapsack::display() const
{
    for (auto x : content)
    {
        std::cout << x;
    }
    
    std::cout << std::endl;
    
}

long knapsack::get_value() const
{
    return value;
}
