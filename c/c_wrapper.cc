#include "c_wrapper.h"
#include <unsupported/Eigen/CXX11/Tensor>

Tensor* TensorCreate(const size_t indices, const size_t dims, ...) {
    va_list valist;

    Eigen::Tensor<float, indices>* t = new Eigen::Tensor<double, indices>(dims...);
    return (void*)t;
}

void TensorFree(Tensor* t) {
  if (t != NULL) {
    delete t;
    t = NULL;
  }
}

size_t TensorRank(Tensor* t) {
  // FIXME: don't know indices to cast
  Eigen::Tensor<float, 1>* tensor = static_cast<Eigen::Tensor<float, 1>*>(t);
  return tensor->rank();
}

size_t TensorDimension(Tensor* t, const size_t dim) {
  // FIXME: don't know indices to cast
  Eigen::Tensor<float, 1>* tensor = static_cast<Eigen::Tensor<float, 1>*>(t);
  return tensor->dimension(dim);
}

void TensorSetZero(Tensor* t) {
  Eigen::Tensor<float, 1>* tensor = static_cast<Eigen::Tensor<float, 1>*>(t);
  tensor->setZero();
}

void TensorSet(Tensor* t, float val, const size_t... dims) {
  Eigen::Tensor<float, 1>* tensor = static_cast<Eigen::Tensor<float, 1>*>(t);
  (*tensor)(dims...) = val;
}
