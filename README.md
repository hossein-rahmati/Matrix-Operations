# Matrix Operations in C

This C project provides functionality for performing various matrix operations including calculating determinants, inverses, and solving systems of equations.

## Features

- **Determinant Calculation**: Calculate the determinant of a square matrix using the Gaussian elimination method.
- **Matrix Inverse**: Compute the inverse of a square matrix using Gaussian elimination with partial pivoting.
- **System of Equations Solver**: Solve a system of linear equations represented in matrix form (Ax = b) using matrix inversion.

## Installation

1. Clone the repository to your local machine:

```bash
gh repo clone hossein-rahmati/Matrix-Operations
```

2. Navigate to the project directory:

```bash
cd Matrix-Operations
```

3. Compile the source code using a C compiler (e.g., GCC)

## Usage
After compiling the source code, you can run the executable matrix_operations. The program provides a simple command-line interface for interacting with the matrix operations.

## Supported Operations
1. Determinant Calculation:
- Enter the dimensions of the square matrix.
- Input the elements of the matrix.
- The program will calculate and display the determinant of the matrix.
2. Matrix Inverse:
- Enter the dimensions of the square matrix.
- Input the elements of the matrix.
- If the matrix is invertible, the program will calculate and display its inverse.
3. System of Equations Solver:
- Enter the dimensions of the coefficient matrix.
- Input the elements of the coefficient matrix and the constant vector.
- If the system is solvable, the program will solve it and display the solution vector.

### Contributing
Contributions are welcome! If you have any ideas, suggestions, or bug fixes, feel free to open an issue or create a pull request.
