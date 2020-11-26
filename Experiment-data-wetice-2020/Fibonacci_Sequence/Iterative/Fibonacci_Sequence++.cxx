/*
 * testC++.cxx
 * 
 * Copyright 2020  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
 
int fibo_iter(int n)
{
    int previous = 1;
    int current = 1;
    int next = 1;
    for (int i = 3; i <= n; ++i) 
    {
        next = current + previous;
        previous = current;
        current = next;
    }
    return next;
}

int main(int argc, char **argv)
{
    int n;
    sscanf(argv[1], "%d" , &n);
    std::cout <<"The Fibonacci of "<< n <<" is "<< fibo_iter(n);
    return 0;
}

