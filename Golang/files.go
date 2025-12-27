package main

import (
	"fmt"
	"os"
)

func main() {
	file, err := os.Open("index.txt")
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	fileInfo, err := file.Stat()
	if err != nil {
		fmt.Println("Error getting file info:", err)
		return
	}
	var size int64 = fileInfo.Size()
	fmt.Println("File size:", size)
	fmt.Println("File name:", fileInfo.Name())

}
