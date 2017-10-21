/* 
 * File:   MovieData.h
 * Author: Zachary Leblond
 *
 * Created on October 2, 2017, 3:58 PM
 */

#ifndef MOVIEDATA_H
#define MOVIEDATA_H

struct Movies
{
    string title;
    string director;
    int year;
    int runTime;
    float cost; // Production costs 
    float yield; // First years revenues
};
#endif /* MOVIEDATA_H */

