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

#include<stdio.h>
#include<stdlib.h>

#include "linear_regression.h"

//main code can be considered as a test code for evaluating on dummy data
int main()
{

	//Data preparation
	//train data
	const float X[] = {1, 2, 4, 3, 5}; //pred
	const float Y[] = {1, 3, 3, 2, 5}; //act


	int n_pts = sizeof(X)/sizeof(X[0]);

	//Preprocessing

	//1. Calculate mean and variance
	float mean_x = get_mean(X, n_pts);
	float mean_y = get_mean(Y, n_pts);

	float var_x  = get_var(X, mean_x, n_pts);
	float var_y  = get_var(Y, mean_y, n_pts);

	printf("mean x - %0.3f, var x - %0.3f \n", mean_x, var_x);
	printf("mean y - %0.3f, var y - %0.3f \n", mean_y, var_y);

	//2. Calculate Covariance
	float covXY = covariance(X, mean_x, Y, mean_y, n_pts);

	printf("Covariance XY - %0.3f \n", covXY);

	//Estimating Coefficients
	// y = b1*x + b0 or more popular y = m*x + c
	float b1 = covXY / var_x;
	float b0 = mean_y - b1*mean_x;

	printf("b1 - %f, b0 - %f\n", b1, b0);

	//Prediction - assuming the above steps used training data to compute b1 and b0,
	//we can directly use them to predict through equation yhat = b1*x_in + b0, where x_in will be input

	//test data
	float x_in[5] = {1, 2, 4, 3, 5}; //dummy values
	float y_act[5] = {1, 3, 3, 2, 5}; //modified slightly compared to training data
	float y_hat[5];
	int t_pts = 5;

	predict_points(x_in, y_hat, b1, b0, t_pts);

	float rmse_val = rmse_metric(y_act, y_hat, t_pts);
	printf("rmse val - %f\n", rmse_val);
	
	return 0;
}
