/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bin.h
 * Author: Zachary Leblond
 *
 * Created on October 4, 2017, 7:16 PM
 */

#ifndef BIN_H
#define BIN_H

const int parts = 10;

struct Bin {
    string part;
    int numPrt;
};

Bin bins[parts] = { {"Valve          ", 10}, {"Bearing          ", 5}, 
{"Bushing          ", 15}, {"Coupling          ", 21}, {"Flange          ", 7}, 
{"Gear          ", 5}, {"GearHousing          ", 5}, {"VacummGripper          ",
25}, {"Cable          ", 18}, {"Rod          ", 12} };


#endif /* BIN_H */

