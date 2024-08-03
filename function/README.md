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

- Definition: Holds multiple values in one variable (e.g., arrays, structs).

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