#!/usr/bin/env python3
# ========================================
# Competitive Programming Template (Python)
# Author: [Your Name]
# ========================================

import sys
import math
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right
from itertools import combinations, permutations, accumulate
from functools import lru_cache, reduce

# ============ FAST I/O ============
def read_int():
    return int(sys.stdin.readline())

def read_ints():
    return map(int, sys.stdin.readline().split())

def read_int_list():
    return list(map(int, sys.stdin.readline().split()))

def read_str():
    return sys.stdin.readline().strip()

def read_str_list():
    return sys.stdin.readline().split()

# ============ CONSTANTS ============
INF = float('inf')
MOD = 10**9 + 7
EPS = 1e-9

# ============ MATH UTILITIES ============
def mod_pow(base, exp, mod):
    """Fast modular exponentiation"""
    result = 1
    base %= mod
    while exp > 0:
        if exp & 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp >>= 1
    return result

def mod_inv(a, mod):
    """Modular inverse using Fermat's Little Theorem"""
    return mod_pow(a, mod - 2, mod)

def gcd(a, b):
    """Greatest Common Divisor"""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Least Common Multiple"""
    return a * b // gcd(a, b)

def is_prime(n):
    """Primality test"""
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

def sieve(n):
    """Sieve of Eratosthenes"""
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(math.sqrt(n)) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return [i for i in range(n + 1) if is_prime[i]]

# ============ MAIN SOLUTION ============
def solve():
    """Solve one test case"""
    # Your solution here
    pass

def main():
    """Main function"""
    t = read_int()  # Number of test cases
    # t = 1  # Uncomment for single test case
    
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
