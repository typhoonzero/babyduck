
#include "runtime.h"
#include "cgocall.h"

#pragma dataflag 16
static void *cgocall = runtime·cgocall;
#pragma dataflag 16
void *·_cgo_runtime_cgocall = &cgocall;


#pragma dynimport _wrap_Swig_free_tensor_63fb5c629924b55c _wrap_Swig_free_tensor_63fb5c629924b55c ""
#pragma cgo_import_static _wrap_Swig_free_tensor_63fb5c629924b55c
extern void _wrap_Swig_free_tensor_63fb5c629924b55c(void*);
uintptr ·_wrap_Swig_free_tensor_63fb5c629924b55c = (uintptr)_wrap_Swig_free_tensor_63fb5c629924b55c;




#pragma dynimport _wrap_Swig_malloc_tensor_63fb5c629924b55c _wrap_Swig_malloc_tensor_63fb5c629924b55c ""
#pragma cgo_import_static _wrap_Swig_malloc_tensor_63fb5c629924b55c
extern void _wrap_Swig_malloc_tensor_63fb5c629924b55c(void*);
uintptr ·_wrap_Swig_malloc_tensor_63fb5c629924b55c = (uintptr)_wrap_Swig_malloc_tensor_63fb5c629924b55c;




