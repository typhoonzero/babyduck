/* File : eigen.i */
%module tensor

%{
#include <unsupported/Eigen/CXX11/Tensor>
%}

/* Let's just grab the original header file here */
%include "unsupported/Eigen/CXX11/Tensor"

/* Now instantiate some specific template declarations */
%template(TensorFloat1D) Eigen::Tensor<float, 1>;
%template(TensorFloat2D) Eigen::Tensor<float, 2>;
%template(TensorFloat3D) Eigen::Tensor<float, 3>;
%template(TensorFloat4D) Eigen::Tensor<float, 4>;
%template(TensorFloat5D) Eigen::Tensor<float, 5>;
%template(TensorFloat5D) Test<float>;
