/*
 * Hanoi.cxx
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


#include <iostream>

#define PR      (void)printf(
#define PE      (void)fprintf(stderr,

#define ALLO(x) { if((x = (int *)malloc((n+3) * sizeof(int))) == NULL) {\
                  PE #x " allocation failed!\n"); exit(1); }}


int main(int argc, char *argv[])
{
 int i, *a, *b, *c, *p, *fr, *to, *sp, n, n1, n2;

 n = atoi(argv[1]);
 n1 = n+1;
 n2 = n+2;
 ALLO(a)
 ALLO(b)
 ALLO(c)

 a[0] = 1; b[0] = c[0] = n1;
 a[n1] = b[n1] = c[n1] = n1;
 a[n2] = 1; b[n2] = 2; c[n2] = 3;
 
 for(i=1; i<n1; i++) {
   a[i] = i; b[i] = c[i] = 0;
 }

 fr = a;
 if(n&1) { to = c; sp = b; }
 else    { to = b; sp = c; }

 while(c[0]>1) {
  i=fr[fr[0]++];
  std::cout << " Move the disk " << i << " from  "<< fr[n2] << "  to  " << to[n2];
  p=sp;
  if((to[--to[0]] = i)&1) {
    sp=to;
    if(fr[fr[0]] > p[p[0]]) { to=fr; fr=p; }
    else to=p;
  } else { sp=fr; fr=p; }
 }
}
