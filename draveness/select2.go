package main

import (
	"errors"
	"fmt"
	"sync"
)

type Task struct{}

func (t *Task) Run() error {
	return errors.New("run error")
}

func (t *Task) Walk() error {
	return errors.New("walk error")
}

func main() {
	tasks := []Task{Task{}, Task{}, Task{}}
	//	for _, t := range tasks {
	//		fmt.Println(t.Run())
	//	}

	errCh := make(chan error, len(tasks))

	wg := sync.WaitGroup{}
	wg.Add(len(tasks))

	for _, t := range tasks {
		go func() {
			defer wg.Done()
			if err := t.Run(); err != nil {
				errCh <- err
			}
		}()
	}

	wg.Wait()

	for {
		select {
		case err := <-errCh:
			fmt.Println(err)
		default:
			fmt.Println("default")
			return
		}
	}
	return
}
