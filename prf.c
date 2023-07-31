/*
   SipHash reference C implementation
   Copyright (c) 2012-2021 Jean-Philippe Aumasson
   <jeanphilippe.aumasson@gmail.com> Copyright (c) 2012 Daniel J. Bernstein
   <djb@cr.yp.to>

   To the extent possible under law, the author(s) have dedicated all copyright
   and related and neighboring rights to this software to the public domain
   worldwide. This software is distributed without any warranty.
   You should have received a copy of the CC0 Public Domain Dedication along
   with this software. If not, see
   <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#include "halfsiphash.h"
#include "siphash.h"
#include "vectors.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


size_t lengths[4] = {8, 16, 4, 8};

int main(){

	int run_times = 20, total_time = 0;
    clock_t  start, stop;
    double duration;

    uint8_t in[64], out[16], k[16];

    for (int i = 0; i < 16; ++i)
        k[i] = i;
    
    printf("use SipHash-2-4-64 \n");

	for(int i = 0; i < run_times; i++){
		start = clock();
        // generate random number
        for (int i = 0; i < 64; ++i) {
            in[i] = i;
            int len = lengths[0];
            siphash(in, i, k, out, len);
        } 
        //
        stop = clock(); 
		duration = ((double)(stop - start)*1000.0)/CLOCKS_PER_SEC;
		total_time += duration;
		printf( "%d PRF %f ms\n", i+1, duration );  
	}
	printf( "Average Run Time: PRF %f ms\n", total_time/run_times ); 

    printf("use SipHash-2-4-128 \n");

    total_time = 0;
	for(int i = 0; i < run_times; i++){
		start = clock();
        // generate random number
        for (int i = 0; i < 64; ++i) {
            in[i] = i;
            int len = lengths[1];
            siphash(in, i, k, out, len);
        }
        //
        stop = clock(); 
		duration = ((double)(stop - start)*1000.0)/CLOCKS_PER_SEC;
		total_time += duration;
		printf( "%d PRF %f ms\n", i+1, duration );  
	}
	printf( "Average Run Time: PRF %f ms\n", total_time/run_times ); 


    return 0;

}