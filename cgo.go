package main

/*
#cgo CPPFLAGS: -I.
#cgo CXXFLAGS: -std=c++0x -pedantic-errors -Wall -fno-strict-aliasing
#cgo LDFLAGS: -lstdc++

#cgo CPPFLAGS: -I .

#include "api.h"
*/
import "C"
import (
	"fmt"
	"unsafe"
)

func main() {
	code := make([]byte, 20)

	vm := C.makeJIT()
	res := C.run(vm, (*C.char)(unsafe.Pointer(&code[0])), C.int(len(code)))
	byts := C.GoBytes(unsafe.Pointer(res.data), C.int(res.len))

	fmt.Printf("RES=%v (%s)\n", byts, byts)

	C.freeJIT(vm)
	C.free_res(res)
}
