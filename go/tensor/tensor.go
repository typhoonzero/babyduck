package tensor

// #cgo CFLAGS: -I../../c
// #include <stdlib.h>
// #include <string.h>
// #include "c_wrapper.h"
import "C"

import (
	"unsafe"
)

func cArrayToSlice(p unsafe.Pointer, len int) []byte {
	if p == nil {
		return nil
	}

	// create a Go clice backed by a C array, reference:
	// https://github.com/golang/go/wiki/cgo#turning-c-arrays-into-go-slices
	//
	// Go garbage collector will not interact with this data, need
	// to be freed properly.
	return (*[1 << 30]byte)(p)[:len:len]
}

// TODO: use dynamic type to call different C-bindings of eigen
//

// Tensor wraps internal eigen Tensor template class through a
// c wrapper
type Tensor struct {
	elements []interface{}
	// keep the eigen c wrapper's pointer here
	raw unsafe.Pointer
}

// NewTensor creates a new tensor object
func NewTensor() *Tensor {
	var raw unsafe.Pointer
	cTensor := C.CreateFloat1D()
	raw = C.data(cTensor)
	size = C.size(cTensor)
	return &Tensor{elements: cArrayToSlice(raw, size), raw: raw}
}

// Data returns a slice of raw data
func (t *Tensor) Data() []interface{} {
	return t.elements
}

// Size returns tensor size
func (t *Tensor) Size() int64 {
	return len(t.elements)
}

// Add two tensors element wise
func (t *Tensor) Add(t2 *Tensor) *Tensor {
	// FIXME: should be dynamic type
	var res unsafe.Pointer
	res = C.AddFloat1D(t.raw, t2.raw)
	return &Tensor{elements: cArrayToSlice(C.data(res), C.size(res)), raw: res}
}
