#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif
// c wrapper for eigen tensor library
// because eigen is based on templates, below code must have
// data type and dimenssions as a part of function name
// 
// type to store tensor
typedef void * Tensor;

// FIXME: use size_t as indexing type

// Float 1D functions
EIGEN_WRAPPER Tensor CreateFloat1D(const size_t indices);
EIGEN_WRAPPER void FreeFloat1D(Tensor t);

EIGEN_WRAPPER float* data(Tensor t);
EIGEN_WRAPPER size_t size(Tensor t);
EIGEN_WRAPPER size_t RankFloat1D(Tensor t);
EIGEN_WRAPPER size_t GetDimFloat1D(Tensor t, const size_t dim);
EIGEN_WRAPPER void SetZeroFloat1D(Tensor t);
EIGEN_WRAPPER void SetFloat1D(Tensor t, float val, const size_t index);


// Basic element wise operations
// Unary Element Wise
EIGEN_WRAPPER Tensor NegativeFloat1D(Tensor a);
EIGEN_WRAPPER Tensor SqrtFloat1D(Tensor a);
EIGEN_WRAPPER Tensor RsqrtFloat1D(Tensor a);
EIGEN_WRAPPER Tensor SquareFloat1D(Tensor a);
EIGEN_WRAPPER Tensor InverseFloat1D(Tensor a);
EIGEN_WRAPPER Tensor ExpFloat1D(Tensor a);
EIGEN_WRAPPER Tensor LogFloat1D(Tensor a);
EIGEN_WRAPPER Tensor AbsFloat1D(Tensor a);
EIGEN_WRAPPER Tensor PowFloat1D(Tensor a, float exponent);
EIGEN_WRAPPER Tensor ScaleFloat1D(Tensor a, float scale);

// Binary Element Wise
EIGEN_WRAPPER Tensor AddFloat1D(Tensor a, Tensor b);
EIGEN_WRAPPER Tensor MinusFloat1D(Tensor a, Tensor b);
EIGEN_WRAPPER Tensor MulFloat1D(Tensor a, Tensor b);
EIGEN_WRAPPER Tensor DivideFloat1D(Tensor a, Tensor b);

#ifdef __cplusplus
}
#endif
