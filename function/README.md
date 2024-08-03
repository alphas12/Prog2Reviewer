# Functions and Data Types in C Programming

## Function Specification
- **Defines what the function should do.**
- **Defines what the control system should do.**

## Scalar Type
- **Definition**: A type that contains a single value.
- **In C, scalar types are**:
  - Arithmetic types (integers and floating point numbers)
  - Pointers

### Example
```c
int x = 10;
```
In this example, `x` is a scalar type because it contains a single value, which is the integer `10`.


## Aggregate Type

- **Definition**: Holds multiple values in one variable (e.g., arrays, structs).

### Example
```c
//array
int arr[5] = {1, 2, 3, 4, 5};

// struct
struct Person {
  int age;
  char name[20];
}; 
```

In this example, `arr` is an aggregate type because it holds multiple values (the integers `1, 2, 3, 4, 5`) in one variable. Similarly, `struct Person` is an aggregate type because it holds multiple values (the integer `age`, the character array `name`) in one variable.

# Function Parts

### Function Header

- **Characteristics:** 
  - Has no semicolon or curly braces.
  - The function name is followed by the return type and parameters.

###  Example 

```c
int add(int a, int b)
```
In this example, `add` is the function name, `int` is the return type, `a` and `b` are the parameters.

### Function Prototype 

- **Characteristics:** 
  - Provides a declaration of the function.
  - Ends with a semi-colon.

```c
int add(int a, int b);
```
In this example, `add` is the function name, `int` is the return type,  `a` and `b` are the parameters, and the semi-colon indicates the end of the function prototype.

### Function Definition 
- **Characteristics:**
  - Provides the actual code for the function.
  - Starts with the function header and ends with a closing curly brace.

### Example 
```c
int add(int a, int b) {
  return a + b;
}
```
In this example, `add` is the function name, `int` is the return type,
`a` and `b` are the parameters, and the function body is the code inside the
curly braces.

### Function Call
- **Characteristics:**

  - The function call causes the program to execute the statements within the function's body.

### Example
```c
int result = add(5, 7); //catch the return value;

// or

add(5, 7); //if the function doesn't return anything
```
In this example, `add` is the function name, `5` and `7` are
the arguments passed to the function, and `result` is the variable that stores the return value of the function.

## Type Mismatch 

- **Definition**: A type mismatch occurs when a variable or expression of one data type is assigned to or compared with another data type that is incompatible. This can lead to compilation errors or unexpected behavior during program execution.

### Example:
