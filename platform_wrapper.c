
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 2
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void platform_Outputs_wrapper(const real_T *u0,
			real_T *y0,
			const real_T *xC,
			const real_T *p0, const int_T p_width0,
			const real_T *p1, const int_T p_width1)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
y0[0]=xC[0];
y0[1]=xC[1];
y0[2]=xC[2];
y0[3]=xC[3];
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Derivatives function
 *
 */
void platform_Derivatives_wrapper(const real_T *u0,
			real_T *y0,
			real_T *dx,
			real_T *xC,
			const real_T *p0, const int_T p_width0,
			const real_T *p1, const int_T p_width1)
{
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_BEGIN --- EDIT HERE TO _END */
real_T m,J,Ca,h,k,g=9.81;
real_T x,xdot,theta,thetadot;

x=xC[0]; xdot=xC[2]; theta=xC[1];thetadot=xC[3];
m=p1[0];J=p1[1];Ca=p1[2];h=p1[3];k=p1[4];
   
dx[0]=xdot;
dx[1]=thetadot;
dx[2]=(-m*g*sin(theta)-Ca*xdot+m*x*thetadot*thetadot-h*x+u0[1])/m;
dx[3]=(-k*theta-m*x*(g*cos(theta)+2*xdot*thetadot)-u0[0])/(J+m*x*x);
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_END --- EDIT HERE TO _BEGIN */
}

