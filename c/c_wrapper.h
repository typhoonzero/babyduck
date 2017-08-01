#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
  // a c wrapper for eigen tensor library
  // NOTE: default value type is float
  typedef void* Tensor;
  WRAPPER Tensor* TensorCreate(const size_t indices, const size_t dims, ...);
  WRAPPER void TensorFree(Tensor* t);

  // general functions for Tensor
  WRAPPER size_t TensorRank(Tensor* t);
  WRAPPER size_t TensorGetDim(Tensor* t, const size_t dim);
  WRAPPER void TensorSetZero(Tensor* t);
  WRAPPER void TensorSet(Tensor* t, float val, const size_t dims, ...);

#ifdef __cplusplus
}
#endif
