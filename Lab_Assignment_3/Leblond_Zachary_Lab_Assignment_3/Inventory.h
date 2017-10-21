/* 
 * File:   Inventory.h
 * Author: Zachary Leblond
 *
 * Created on October 11, 2017, 3:40 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

const int size = 20;
struct Inventory
{
    char item[size];
    int qty;
    int wCost;
    int rCost;
    char date[9];
};

#endif /* INVENTORY_H */

