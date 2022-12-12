package main

import "fmt"

func main() {
	var rpcErr error = NewRPCError(400, "unkown error") // typecheck_1
	err := AsErr(rpcErr)                                // typecheck_2
	fmt.Println(err)
}

func NewRPCError(code int64, msg string) error {
	return &RPCError{ // typecheck_3
		Code:    code,
		Message: msg,
	}
}

func AsErr(err error) error {
	return err
}
