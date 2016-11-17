//
//  shelf.h
//  GeneticKnapSack
//
//  Created by Robert Snocken on 17/11/2016.
//  Copyright (c) 2016 RS. All rights reserved.
//

#ifndef __GeneticKnapSack__shelf__
#define __GeneticKnapSack__shelf__

#include "item.h"
#include <vector>

class shelf
{
public:
    std::vector<item> items;
    
    shelf(long N);
    ~shelf();
    
    long size() const;
};

#endif /* defined(__GeneticKnapSack__shelf__) */
