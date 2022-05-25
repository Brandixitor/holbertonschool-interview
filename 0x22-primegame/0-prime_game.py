#!/usr/bin/python3
'''
Maria and Ben are playing a game. Given a set of integers starting from 1 up
to and including n, they take turns choosing a prime number from the set and
removing that number and its multiples from the set. The player that cannot
make a move loses the game.
'''


def get_primes(nums):
    '''
    Use Sieve of Eratosthenes to get primes
    '''
    n = max(nums)
    if n < 1:
        return None
    prime_cnt = [0] * len(nums)
    prime = [True for _ in range(n + 1)]
    p = 2
    prime[0] = prime[1] = False
    while (p * p <= n):
        if prime[p]:
            for j in range(p * 2, n + 1, p):
                prime[j] = False
        p += 1
    for i in range(len(nums)):
        cnt = 0
        for j in range(nums[i] + 1):
            if (prime[j]):
                cnt += 1
        prime_cnt[i] = cnt
    return prime_cnt


def isWinner(x, nums):
    '''
    Prime Game
    '''
    if x <= 0 or nums is None or min(nums) < 0:
        return None
    prime_cnt = get_primes(nums)
    if prime_cnt is None:
        return None
    loses = 0
    for i in prime_cnt:
        if i % 2 == 0:
            loses += 1
    if x < 2 * loses:
        return "Ben"
    if x == 2 * loses:
        return None
    return "Maria"
