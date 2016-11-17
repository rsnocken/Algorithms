//
//  shelf.cpp
//  GeneticKnapSack
//
//  Created by Robert Snocken on 17/11/2016.
//  Copyright (c) 2016 RS. All rights reserved.
//

#include "shelf.h"
#include <vector>
#include <iostream>

shelf::shelf(long N)
{
    long s, v;
    
    for (long i = 0; i < N; ++i)
    {
        s = (random() % 10) + 1; // make sure items have positive size
        v = (random() % 10);
        items.push_back(item(s, v));
    }
}

shelf::~shelf()
{
    
}

long shelf::size() const
{
    return items.size();
}

