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

import java.util.*;
public class Hanoi
{
    private int nDisks; 
    
    public Hanoi(int nDisks){
        this.nDisks=nDisks;
    }
    
    public void execute(){
        int n=nDisks;
        int limit = (int)Math.pow(2,n)-1; 
        for(int i=0;i<limit;i++){
            int disk = disk(i); 
            int source = ( movements(i,disk)*direction(disk,n))%3; 
            int destination = (source + direction(disk,n))%3; 
            move(disk,source,destination);
        }      
    }
    private int disk(int i) { 
        int C, x= i+1; 
        for(C=0;x%2==0;C++){ 
            x/=2;
        }
        return C;
    }
    private int movements(int i, int d) {
        while(d--!=0)
            i/=2;
        return (i+1)/2;
    }
    private int direction(int d,int n) {
        return 2 - (n + d)%2;
    }
    private void move(int disk, int source, int destination) {
        System.out.println("Move the disk " + (disk+1)+ " from " + (source+1) + " to " + (destination+1));
    }
    
    public static void main(String[] args){
       int n = Integer.parseInt(args[0]);
       Hanoi toh=new Hanoi(n);
       toh.execute();
    }
}
