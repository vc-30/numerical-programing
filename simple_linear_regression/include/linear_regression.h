/*
  Description:
	  This code is an example of solving simple linear regression problem.

	  It was implemented referring https://machinelearningmastery.com/implement-simple-linear-regression-scratch-python/ 
	  original code is in python.

	  To understand the detailed derivation of b1 and b0 one can refer - 
	  http://mathworld.wolfram.com/LeastSquaresFitting.html equation (27) and (28) are what is being used here

	  Steps to use it on your own data - 
	  1) Calculate mean and variance for training data, using "get_mean" & "get_var" function.
	  2) Calculate Covariance between X and Y, using "covariance" function.\
	  3) Get the coefficient as:
	  		b1 = covXY / var_x - (covXY and var_x will be calculated in step 1 and 2)
	  		b0 = mean_y - b1 * mean_x
	  4) Now you have the model ready, use test input (x_act) value to predict y_hat, 
	  	"using predict_points" function
	  5) Using y_act and y_hat rmse error, using "rmse_metric" function.

  Author: v.c.
*/

#include<math.h>

#ifndef __LINEAR_REGRESSION_H__
#define __LINEAR_REGRESSION_H__


float sum(const float *points, int n_pts) __attribute__((always_inline));

float inline sum(const float *points, int n_pts)
{
	float sum = 0;
	for(int i=0; i < n_pts; i++)
	{
		sum += points[i];
	}
	return sum;
}

float get_mean( const float *points, int n_pts)
{
	return (sum(points, n_pts)/n_pts);
}

float get_var(const float *points, float mean, int n_pts)
{
	float var_points[n_pts];
	for(int i=0; i<n_pts; i++)
	{
		var_points[i] = (points[i] - mean) * (points[i] - mean); //avoiding use of pow from math.h
	}
	return sum(var_points, n_pts);
}

float covariance(const float *points_x, float mean_x,const float *points_y, float mean_y, int n_pts)
{
	float covXY[n_pts];
	for(int i=0; i < n_pts; i++)
	{	
		covXY[i] = (points_x[i] - mean_x) * (points_y[i] - mean_y);
		// printf("%f %f %f %d\n", covXY[i],points_x[i], points_y[i], i );
	}
	return sum(covXY, n_pts);
}

void predict_points(float *x_in, float *y_hat, float b1, float b0, int pred_pts)
{
	// float y_hat[pred_pts];
	for(int i=0; i < pred_pts; i++)
	{
		y_hat[i] = b1 * x_in[i] + b0;
		printf("x_in - %f, y_hat - %f\n", x_in[i], y_hat[i]);
	}
}

float rmse_metric(float *actual, float *predicted, int n_pts)
{
	float sum_error = 0.0, mean_error = 0.0;
	for(int i=0; i < n_pts; i++)
	{
		float prediction_error = predicted[i] - actual[i];
		sum_error += prediction_error*prediction_error;
	}
	mean_error = sum_error/n_pts;
	return sqrt(mean_error);
}

#endif
