import numpy as np
import sys

def load_matrix(filename):
    return np.loadtxt(filename)

def main():
    A = load_matrix("matrix_A10.txt")
    B = load_matrix("matrix_B10.txt")
    C_cpp = load_matrix("matrix_C10.txt")

    C_python = np.matmul(A, B)

    if C_cpp.shape != C_python.shape:
        print("FAILED: different matrix sizes")
        return

    diff = np.abs(C_cpp - C_python)
    max_error = np.max(diff)

    tolerance = 1e-5

    if max_error < tolerance:
        print("SUCCESS: matrices match")
        print("Max error:", max_error)
    else:
        print("FAILED: matrices differ")
        print("Max error:", max_error)

if __name__ == "__main__":
    main()
