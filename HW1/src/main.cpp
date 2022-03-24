//
//  main.cpp
//  test
//
//  Created by Melis Meriç on 14.01.2022.
//  Copyright © 2022 Melis Meriç. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "characterObject.hpp"

using namespace  std;

character wolfgang;

int main() {
    srand ((int)time(NULL));
    int dice;
    wolfgang.name = "Wolfgang";
    wolfgang.strength = 10.8;
    
    
    for (int i = 0; i < 10; i++) {
        dice = rand()%(20-1 + 1) + 1;
        
        cout << "Player " << wolfgang.name;
        cout << " got " << dice;
        cout << " with the dice. He attacks with " << wolfgang.attack(wolfgang.strength, dice) << " points." << endl;
    }

    return 0;
}
