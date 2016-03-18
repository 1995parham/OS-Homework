/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 18-03-2016
 * |
 * | File Name:     goroutine.go
 * +===============================================
 */
package main

import "fmt"

func main() {
	result := make(chan bool, 1)
	input := make(chan int, 1)

	go IsComplete(input, result)

	var n int
	fmt.Scanf("%d", &n)
	input <- n

	if <-result {
		fmt.Printf("True\n")
	} else {
		fmt.Printf("False\n")
	}
}

func IsComplete(input chan int, result chan bool) {
	var n int
	n = <-input
	sum := 0
	for i := 1; i < n; i++ {
		if n%i == 0 {
			sum += i
		}
	}
	if sum == n {
		result <- true
	} else {
		result <- false
	}
}
