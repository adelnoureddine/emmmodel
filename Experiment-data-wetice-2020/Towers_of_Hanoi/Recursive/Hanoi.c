/*
 * Hanoi.c
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

#include <stdio.h>
#include <stdlib.h>
void hanoi(char dep, char dest, char temp, int n)
{
	if(n==1)
	{
		printf ("Move the disk %d from %c to $c",n, dep, dest);
	}
	else
	{
		hanoi( dep, temp, dest, n-1);
		hanoi( dep, dest, temp, 1);
		hanoi(temp, dest,  dep, n-1);	
	}
}

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	hanoi( 'A','C','B',n);
    return 0;
}
