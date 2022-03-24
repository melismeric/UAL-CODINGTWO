//
//  personObject.hpp
//  test
//
//  Created by Melis Meriç on 14.01.2022.
//  Copyright © 2022 Melis Meriç. All rights reserved.
//

#ifndef characterObject_hpp
#define characterObject_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class character {
    int constitution = 5;
    
public:
    string name;
    float strength;
    float attack(float strength, int dice);
};

#endif /* personObject_hpp */
