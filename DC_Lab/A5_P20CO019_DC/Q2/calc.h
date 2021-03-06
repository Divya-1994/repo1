/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CALC_H_RPCGEN
#define _CALC_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct numbers {
	int a;
	int b;
};
typedef struct numbers numbers;

#define CALC_PROG 0x4562877
#define CALC_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define add 1
extern  int * add_1(numbers *, CLIENT *);
extern  int * add_1_svc(numbers *, struct svc_req *);
#define sub 1
extern  int * sub_1(numbers *, CLIENT *);
extern  int * sub_1_svc(numbers *, struct svc_req *);
#define mul 1
extern  int * mul_1(numbers *, CLIENT *);
extern  int * mul_1_svc(numbers *, struct svc_req *);
#define div 1
extern  int * div_1(numbers *, CLIENT *);
extern  int * div_1_svc(numbers *, struct svc_req *);
extern int calc_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define add 1
extern  int * add_1();
extern  int * add_1_svc();
#define sub 1
extern  int * sub_1();
extern  int * sub_1_svc();
#define mul 1
extern  int * mul_1();
extern  int * mul_1_svc();
#define div 1
extern  int * div_1();
extern  int * div_1_svc();
extern int calc_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_numbers (XDR *, numbers*);

#else /* K&R C */
extern bool_t xdr_numbers ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CALC_H_RPCGEN */
