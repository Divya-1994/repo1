/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "fact.h"

int *
fact_1_svc(number *argp, struct svc_req *rqstp)
{
	static int  result = 1;

	printf("fact(%d) is called\n",argp->n);
	for(int i = argp->n; i > 0; i--)
        	result = result * i;


	return &result;
}
