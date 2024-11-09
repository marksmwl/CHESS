// FINANCE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Board.hpp"

void perform_action(int name[], int size);
void sort_arr(int nums[], int size);

int main()
{
    int my_name[] = { 1,2,3,4, 5, 6, 7, 8 };
    int size_of_arr = sizeof(my_name) / sizeof(int);
    //perform_action(my_name, size_of_arr);

    int rand_nums[] = { 56, 1 , 6, 4, 1 ,88, 9, 4, 2 ,1 };
    int size = sizeof(rand_nums) / sizeof(rand_nums[0]);
    sort_arr(rand_nums, size);
    
}
