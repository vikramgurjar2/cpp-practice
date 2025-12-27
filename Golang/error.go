package main

import (
	"fmt"
	"strconv"
)

type user struct {
	message string
	error   string
}

func sendmessagetospouse(u user) (string, error) {
	if u.error != "" {
		return "", fmt.Errorf("error occurred: %v", u.error)
	}
	return u.message, nil
}

type divideError struct {
	dividend float32
}

func (d divideError) Error() string {
	return fmt.Sprintf("cannot divide %v by zero", d.dividend)
}
func divide(dividend, divisor float32) (float32, error) {
	if divisor == 0 {
		return 0, divideError{dividend: dividend}
	} else {

		return dividend / divisor, nil
	}
}

func main() {

	i, err := strconv.Atoi("12")

	if err != nil {
		fmt.Println("Error here is:", err)
	} else {
		fmt.Println("Value:", i)
	}

	u1 := user{message: "hello", error: ""}
	u2 := user{message: "hello", error: "spouse not found"}

	msg, err := sendmessagetospouse(u1)
	if err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Println("Message sent:", msg)
	}
	msg, err = sendmessagetospouse(u2)
	if err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Println("Message sent:", msg)
	}

}
