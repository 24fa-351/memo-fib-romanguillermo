#include <stdio.h>
#include <stdlib.h>

// Recursive Fibonacci function
long long int fib_r_core(long long int n) {
   if (n <= 1) return n;
   return fib_r_core(n - 1) + fib_r_core(n - 2);
}

// Iterative Fibonacci function
long long int fib_i_core(long long int n) {
   if (n <= 1) return n;
   long long int prev = 0, curr = 1, next;
   for (long long int i = 2; i <= n; i++) {
      next = prev + curr;
      prev = curr;
      curr = next;
   }
      return curr;
}

//Memoization
long long int fib_r(long long int n) {
   static long long int memo[100] = {0};
   if (n <= 1) return n;
   if (memo[n] == 0) {
      memo[n] = fib_r(n - 1) + fib_r(n - 2);
   }
   return memo[n];
}

long long int fib_i(long long int n) {
   static long long int memo[100] = {0};
   if (n <= 1) return n;
   memo[0] = 0;
   memo[1] = 1;
   for (long long int i = 2; i <= n; i++) {
      memo[i] = memo[i - 1] + memo[i - 2];
   }
   return memo[n];
}


long long int main(long long int argc, char *argv[]) {

   // Variable Assignments
   long long int firstInt = atoi(argv[1]);
   char method = argv[2][0];

   // Calculations
   long long int N = firstInt - 1;

   long long int fibNum;

   if (method == 'r') {
      fibNum = fib_r(N);
   } else if (method == 'i') {
      fibNum = fib_i(N);
   }

   // Output
   printf("%lld\n", fibNum);
   return 0;
}
