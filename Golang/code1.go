package main

import (
	"fmt"
	"time"
)

type Person struct {
	Name string
	Age  int
}

type Authentication struct {
	username string
	password string
}

func len(a int, b int, c int) (length int, width int, height int) {
	length = a
	width = c
	height = b
	return
}

func (auth Authentication) user() string {
	return fmt.Sprintf("user data- %s:%s", auth.username, auth.password)
}

func main() {

	var num1 int16 = 18
	var num2 int8 = 7
	const num = 15
	t := 99
	fmt.Printf("%+v\n ", t)
	var person string = "vikram"
	fmt.Printf("%+v\n", person)

	st, pr := "vikram", 2.9
	fmt.Println("whatsup", st, pr, int16(num2)+num1)

	person1 := Person{"vikram", 23}

	fmt.Printf("%%v  : %v\n", person1)
	fmt.Printf("%%+v : %+v\n", person1)
	fmt.Printf("%%#v : %#v\n", person1)

	fmt.Printf("the length is %d and %d | the name is %s\n", num1, num1, person)

	if person1.Age > 10 {
		fmt.Printf("he is above 10\n")
	}

	l, n, _ := len(3, 55, 66)

	fmt.Printf("the values of height is: %d and width %d", l, n)

	auth := Authentication{"vikram", "1234"}
	fmt.Println(auth.user())
	fmt.Println("the channel line starts from here")
	c := make(chan int)

	go func() {
		for i := 0; i <= 10; i++ {
			time.Sleep(time.Second)
			c <- i
		}
		close(c)
	}()

	for n := range c {
		fmt.Println(n)
	}

}
