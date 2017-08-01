package tensor

import (
	"reflect"
)

type Tensor struct {
	// elements is the
	Elements   []interface{}
	TypeHolder interface{}
	Shape      []int
}

func (t *Tensor) Type() {
	return reflect.TypeOf(t.TypeHolder)
}
