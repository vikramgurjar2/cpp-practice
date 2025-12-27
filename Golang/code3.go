package main

import (
	"fmt"
	"time"
)

func producer(ch chan<- int) {
	for i := 0; i < 20; i++ {
		fmt.Printf("Produced: %d\n", i)
		ch <- i
		time.Sleep(20 * time.Millisecond)
	}
	close(ch)
}

func consumer(ch <-chan int) {
	for num := range ch {

		fmt.Printf("Consumed: %d\n", num)
		time.Sleep(300 * time.Millisecond) // Simulate work

	}

}

func main() {

	ch := make(chan int, 4)
	go producer(ch)
	consumer(ch)

}
