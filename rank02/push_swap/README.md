# Push Swap 🃏🔄

The **Push Swap** project is a sorting algorithm challenge where the goal is to sort a stack of integers using a limited set of operations. The challenge lies in implementing a highly efficient sorting algorithm with a minimal number of moves. 

## Project Overview

You are given two stacks, `a` and `b`. Stack `a` is initialized with a random number of integers, while stack `b` starts empty. Your goal is to sort the stack `a` using a predefined set of operations that move values between the two stacks or rearrange elements within the stacks.

## Features

- **Efficient Sorting**: The primary goal is to sort the stack with the least number of operations.
- **Instruction Set**: Only specific operations are allowed to manipulate the stacks.
- **Scalability**: The program is designed to handle various input sizes, including edge cases with small numbers of elements or very large stacks.

## Allowed Operations

The allowed operations are:

- **`sa`**: Swap the first two elements of stack `a`. Do nothing if there is only one or no elements.
- **`sb`**: Swap the first two elements of stack `b`. Do nothing if there is only one or no elements.
- **`ss`**: Perform `sa` and `sb` simultaneously.
- **`pa`**: Push the top element of stack `b` to stack `a`. Do nothing if `b` is empty.
- **`pb`**: Push the top element of stack `a` to stack `b`. Do nothing if `a` is empty.
- **`ra`**: Rotate stack `a` upwards (shift all elements up by one, with the first element moving to the last position).
- **`rb`**: Rotate stack `b` upwards.
- **`rr`**: Perform `ra` and `rb` simultaneously.
- **`rra`**: Reverse rotate stack `a` (shift all elements down by one, with the last element moving to the first position).
- **`rrb`**: Reverse rotate stack `b`.
- **`rrr`**: Perform `rra` and `rrb` simultaneously.

## Checker Bonus 🧩✅

The **checker** program is a companion to `push_swap` that verifies whether the list of operations outputted by `push_swap` correctly sorts the stack. This bonus allows you to run both programs together to ensure that the operations produced by `push_swap` result in a sorted stack.

### How It Works

The `checker` program reads a sequence of operations from the standard input and applies them to the stack. It then checks if stack `a` is sorted and stack `b` is empty. Based on this, it returns one of the following outputs:

- **OK**: If the stack `a` is correctly sorted in ascending order and stack `b` is empty.
- **KO**: If the stack `a` is not sorted, or stack `b` is not empty.
- **Error**: If an invalid operation is provided or an error occurs during the execution.





