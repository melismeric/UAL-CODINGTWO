//
//  personObject.cpp
//  test
//
//  Created by Melis Meriç on 14.01.2022.
//  Copyright © 2022 Melis Meriç. All rights reserved.
//

#include "characterObject.hpp"
#include <ctime>

float character::attack(float strength, int dice) {
    return dice + strength;
}
