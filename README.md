# GCOVHP2

<div align="center">
  <img src="https://github.com/user-attachments/assets/8d69fa45-cca3-4987-8ca4-d798888290bd" alt="neon-zeta-greek-symbol" width="300"/>
</div>

## Description
In this project, we worked on the ZETA function homework provided by Justin. In this assignment, we had to write a function to determine whether a number is prime and then calculate how many prime numbers are smaller than the given one. For example, if we specify a range between 2 and 6, the function determines the count of prime numbers within that range (e.g. 5 and 3). The function sums the total number of prime numbers found. Note that when large numbers are provided, the process takes more than 1 second due to the time required to find all the primes.

## Roles
- **Optimizer Prime:** Justin provided the homework code and solved it initially, then worked on optimizing the code.
- **EdgeLord:** Ansh was responsible for creating multiple tests to ensure that the code ran correctly and smoothly.
- **Glord:** Oscar implemented Gcov to test and benchmark the code.
- **GitWizard:** Omar handled writing the documentation and organizing the project.

## Optimization
We explored a few ideas to increase performance:

1. **Vector Optimization:**  
   Our initial idea was to pass the vector by reference to speed up compilation. When passing the vector by value, the runtime was 46791ms; however, after switching to pass-by-reference, the runtime increased to 53103ms. This indicated that because multiple functions continuously modified the vector, passing by reference actually increased the workload.

2. **Code Minimization:**  
   The second idea was to reduce the code by removing unnecessary functions and loops. After revising the code, we discovered that our `Calculate` function contained two redundant arguments: `int min` and `int primeAmount`. Removing these two arguments improved the runtime to 46736ms, a slight but positive change.
