//
//  item.cpp
//  GeneticKnapSack
//
//  Created by Robert Snocken on 17/11/2016.
//  Copyright (c) 2016 RS. All rights reserved.
//

#include "item.h"

item::item()
{
    
}

item::item(long size, long value):
size(size),
value(value)
{
    
}

item::~item()
{
    
}

long item::get_size() const
{
    return size;
}

long item::get_value() const
{
    return value;
}

double item::get_density() const
{
    return double(value) / double(size);
}