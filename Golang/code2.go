package main

import "fmt"

func isprime(n int) bool {
	for j := 3; j*j < n+1; j++ {
		if n%j == 0 {
			return false
		}
	}
	return true
}

func prime(num int) {
	if num < 2 {
		fmt.Print("")
	} else {
		fmt.Print(2)

		for i := 3; i < num+1; i++ {
			if i%2 == 0 {
				continue
			}
			if isprime(i) {
				fmt.Print(" ", i)
			}

		}
	}

}

////higher order functions

func add(a, b int) int {
	return a + b
}

func aggregate(a, b, c int, add func(int, int) int) int {
	return add(add(a, b), c)
}

func main() {
	fmt.Println("Hello, World!")

	mymap := map[string]int{
		"two":   2,
		"three": 3,
		"four":  4,
		"five":  5,
	}
	mymap["one"] = 1

	for keys := range mymap {
		fmt.Println(keys)
	}
	fmt.Println(aggregate(6, 55, 66, add))
    fmt,
	prime(100)
}
