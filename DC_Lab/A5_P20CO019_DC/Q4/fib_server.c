/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "fib.h"

num *
opr_1_svc(numbers *argp, struct svc_req *rqstp)
{
	static num result;
	static int p_array[100];
	int n = argp->a;
	
	int p = 0;
	int q = 1;
	p_array[0]=p;
	p_array[1]=q;
	result.array[0] = p_array[0];
	result.array[1] = p_array[1];
	for(int i=2;i<n;i++)
	{
		p_array[i] = p_array[i-1]+p_array[i-2];
	}
	for(int i=2;i<n;i++)
	{
		result.array[i] = p_array[i];
	}
		return &result;
}