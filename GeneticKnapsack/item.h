//
//  item.h
//  GeneticKnapSack
//
//  Created by Robert Snocken on 17/11/2016.
//  Copyright (c) 2016 RS. All rights reserved.
//

#ifndef __GeneticKnapSack__item__
#define __GeneticKnapSack__item__

class item
{
private:
    long size;
    long value;
public:
    item();
    item(long size, long value);
    ~item();
    
    long get_size() const;
    long get_value() const;
    double get_density() const;
};




#endif /* defined(__GeneticKnapSack__item__) */
