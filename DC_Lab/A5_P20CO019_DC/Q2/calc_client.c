/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calc.h"


void
calc_prog_1(char *host, int x, int y)
{
	CLIENT *clnt;
	int  *result_1;
	numbers  add_1_arg;
	int  *result_2;
	numbers  sub_1_arg;
	int  *result_3;
	numbers  mul_1_arg;
	int  *result_4;
	numbers  div_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, CALC_PROG, CALC_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	add_1_arg.a=x;
    add_1_arg.b=y;
	result_1 = add_1(&add_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	} else{
        printf("Result:%d\n", *result_1 );
    }

	sub_1_arg.a=x;
    sub_1_arg.b=y;
	result_2 = sub_1(&sub_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	} else{
        printf("Result:%d\n", *result_2 );
    }

	mul_1_arg.a=x;
    mul_1_arg.b=y;
	result_3 = mul_1(&mul_1_arg, clnt);
	if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
        printf("Result:%d\n", *result_3 );
    }

	div_1_arg.a=x;
    div_1_arg.b=y;
	result_4 = div_1(&div_1_arg, clnt);
	if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
           printf("Result:%d\n", *result_4 );
    }
	

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 4) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	calc_prog_1 (host, atoi(argv[2]), atoi(argv[3]));
exit (0);
}
