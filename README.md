 # GCOVHP2
<div align="center">
  <img src="https://github.com/user-attachments/assets/8d69fa45-cca3-4987-8ca4-d798888290bd" alt="neon-zeta-greek-symbol" width="300"/>
</div><br><br>
Description:
<br>
In this project, we worked on the ZETA function homework that Justin provided. In this HW we had to write a function that finds whether a number is prime and then calculates how many prime numbers are smaller than the one given. So if we give a range of prime numbers like 2 and 6 it calculates how many prime numbers exist between them so 5 and 3. The function gets how many prime numbers exist adds gives the total number of prime numbers. So when given big numbers it takes time to find all the prime numbers which takes more than 1 second.

<br>
<br>

Roles:
<br>
Optimizer Prime: Justin had the vital role of providing us with the HW code and then solving it. After solving it his main job was attempting to optimize the code.
EdgeLord: Ansh had the task of providing multiple tests within the code to ensure that the code was running correctly and smoothly. 
Glord: Oscar had the job of implementing Gcov so that we could test and benchmark the code.
GitWizard: Omar had the job of writing the documentation for the project and helping with its organization.
<br>
<br>

Optimization:
<br>
We had a few ideas to increase performance and the first one was to optimize the vectos. Our initial idea was to pass the vector through by reference to increase the compilation speed. Initially, we had a runtime of 46791ms when we ran the vector by value, and after we changed it to run by reference the runtime increased to 53103ms. Clearly this idea did not succeed in optimizing the code, we realized that we had multiple functions that continuously changed the vector so running it by refrence increased the workload of the code. 
<The second idea we agreed on was to minimize the code by removing useless functions and loops. We revised the code and came to the conclusion that we had 2 useless arguments within our Calculate function, which were the int min and int primeAmount. After removing these two arguments our runtime changed to 46736ms, which is a slight improvement but an improvement nonetheless.
