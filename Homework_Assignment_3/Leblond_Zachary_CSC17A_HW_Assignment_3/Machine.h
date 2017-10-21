/* 
 * File:   Machine.h
 * Author: Zachary Leblond
 *
 * Created on October 3, 2017, 8:24 PM
 */

#ifndef MACHINE_H
#define MACHINE_H

struct Machine {
    string name;
    float cost;
    int numleft;    
};
const int size = 5;
Machine machine[size] = { {"Cola     ", 0.75, 20}, {"RootBeer ", 
            0.75, 20}, {"LemonLime", 0.75, 20}, {"GrapeSoda ", 0.80, 20}, 
            {"CreamSoda", 0.80, 20} };

#endif /* MACHINE_H */

