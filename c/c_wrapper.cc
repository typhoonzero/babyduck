#include <Eigen/Core>
#include <unsupported/Eigen/CXX11/Tensor>
#include "c_wrapper.h"

using TensorFloat1D = Eigen::Tensor<float, 1>;

// internal wrapping for eigen Tensor oprations
Tensor TensorCreateFloat1D(const size_t size) {
  TensorFloat1D* t = new TensorFloat1D(size);
  return (Tensor)t;
}

void TensorFreeFloat1D(Tensor t) {
  if (t != NULL) {
    delete static_cast<TensorFloat1D*>(t);
    t = NULL;
  }
}

float* data(Tensor t) {
  return static_cast<TensorFloat1D*>(t)->data();
}
size_t size(Tensor t) {
  return static_cast<TensorFloat1D*>(t)->size();
}

size_t TensorRankFloat1D(Tensor t) {
  TensorFloat1D* tensor = static_cast<TensorFloat1D*>(t);
  return tensor->rank();
}

size_t TensorGetDimFloat1D(Tensor t, const size_t dim) {
  TensorFloat1D* tensor = static_cast<TensorFloat1D*>(t);
  return tensor->dimension(dim);
}

void TensorSetZeroFloat1D(Tensor t) {
  TensorFloat1D* tensor = static_cast<TensorFloat1D*>(t);
  tensor->setZero();
}

void TensorSetFloat1D(Tensor t, float val, const size_t index) {
  TensorFloat1D* tensor = static_cast<TensorFloat1D*>(t);
  (*tensor)(index) = val;
}

// Basic element wise operations
// FIXME: aware of copy overhead
// Unary Element Wise
Tensor NegativeFloat1D(Tensor a) {
  TensorFloat1D* tensor = new TensorFloat1D();
  *tensor = -(*static_cast<TensorFloat1D*>(a));
  return (Tensor)tensor;
}

Tensor SqrtFloat1D(Tensor a) {
  TensorFloat1D* tensor = new TensorFloat1D();
  *tensor = static_cast<TensorFloat1D*>(a)->sqrt();
  return (Tensor)tensor;
}

Tensor RsqrtFloat1D(Tensor a) {
  TensorFloat1D* tensor = new TensorFloat1D();
  *tensor = static_cast<TensorFloat1D*>(a)->rsqrt();
  return (Tensor)tensor;
}

Tensor SquareFloat1D(Tensor a) {
  TensorFloat1D* tensor = new TensorFloat1D();
  *tensor = static_cast<TensorFloat1D*>(a)->square();
  return (Tensor)tensor;
}

Tensor InverseFloat1D(Tensor a) {
  TensorFloat1D* tensor = new TensorFloat1D();
  *tensor = static_cast<TensorFloat1D*>(a)->inverse();
  return (Tensor)tensor;
}

Tensor ExpFloat1D(Tensor a) {
  TensorFloat1D* tensor = new TensorFloat1D();
  *tensor = static_cast<TensorFloat1D*>(a)->exp();
  return (Tensor)tensor;
}

Tensor LogFloat1D(Tensor a) {
  TensorFloat1D* tensor = new TensorFloat1D();
  *tensor = static_cast<TensorFloat1D*>(a)->log();
  return (Tensor)tensor;
}

Tensor AbsFloat1D(Tensor a) {
  TensorFloat1D* tensor = new TensorFloat1D();
  *tensor = static_cast<TensorFloat1D*>(a)->abs();
  return (Tensor)tensor;
}

Tensor PowFloat1D(Tensor a, float exponent) {
  TensorFloat1D* tensor = new TensorFloat1D();
  *tensor = static_cast<TensorFloat1D*>(a)->pow(exponent);
  return (Tensor)tensor;
}

Tensor ScaleFloat1D(Tensor a, float scale) {
  TensorFloat1D* tensor = new TensorFloat1D();
  *tensor = (*static_cast<TensorFloat1D*>(a)) * scale;
  return (Tensor)tensor;
}

// Binary Element Wise
Tensor AddFloat1D(Tensor a, Tensor b) {
  // return &((*static_cast<TensorFloat1D*>(a)) + (*static_cast<TensorFloat1D*>(b)));
  return a;
}

Tensor MinusFloat1D(Tensor a, Tensor b) {
  return a;
}
Tensor MulFloat1D(Tensor a, Tensor b) {
  return a;
}
Tensor DivideFloat1D(Tensor a, Tensor b) {
  return a;
}