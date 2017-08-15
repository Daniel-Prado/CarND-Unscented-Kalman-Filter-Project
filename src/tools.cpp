#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  // <DPR>
  VectorXd rmse(4);
  rmse << 0,0,0,0;
  
  // we need to check that the inputs are valid:
  // - estimate vector size is not zero AND
  // - estimate vector size is equal to ground_truth vector size.
  if (estimations.size() != ground_truth.size()
      || estimations.size() == 0){
    cout << "Invalid estimation or ground_truth data" << endl;
    return rmse;
  }
  
  //accumulate squared residuals
  for(unsigned int i=0; i < estimations.size(); ++i){
    VectorXd residual = estimations[i]-ground_truth[i];
    
    //coeficient-wise multiplication
    residual = residual.array() * residual.array();
    rmse += residual;
  }
  
  //calculate the mean
  rmse = rmse / estimations.size();
  
  //calculate the squared root
  rmse = rmse.array().sqrt();
  
  //return the result
  return rmse;

 	//</DPR>

}