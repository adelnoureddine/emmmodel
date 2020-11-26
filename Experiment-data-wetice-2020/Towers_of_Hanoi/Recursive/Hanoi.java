/*
 * Hanoi.java
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

public class Hanoi {
	    public static void hanoi(int n, String from, String temp, String to) {
	        if (n == 0) return;
	        hanoi(n-1, from, to, temp);
	        System.out.println("Move the disk " + n + " from " + from + " to " + to);
	        hanoi(n-1, temp, from, to);
	    }

	    public static void main(String[] args) {
		int n = Integer.parseInt(args[0]);
	        hanoi(n, "A", "B", "C");
	    }
}
