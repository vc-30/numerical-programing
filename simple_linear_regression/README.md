####	  This code is an example of solving simple linear regression problem.
####	  It was implemented by referring https://machinelearningmastery.com/implement-simple-linear-regression-scratch-python/ original code is in python.
####	  To understand the detailed derivation of b1 and b0 one can refer - 
####	  http://mathworld.wolfram.com/LeastSquaresFitting.html equation (27) and (28) are what is being used here

####	  Steps to use it on your own data - 
####	  1) Calculate mean and variance for training data, using "get_mean" & "get_var" function.
####	  2) Calculate Covariance between X and Y, using "covariance" function.
####	  3) Get the coefficient as:
####	  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;b1 = covXY / var_x - (covXY and var_x will be calculated in step 1 and 2)
####	  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;b0 = mean_y - b1 * mean_x
####	  4) Now you have the model ready, use test input (x_act) value to predict y_hat, using "predict_points" function
####	  5) Using y_act and y_hat rmse error, using "rmse_metric" function.

All the functions are available in ./include/linear_regression.h
