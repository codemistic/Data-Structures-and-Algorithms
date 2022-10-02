
def display(string_to_print):
    stdout.write(str(string_to_print) + "\n")
 
 
def fast_exp(base, power):
    result = 1
    while power > 0:
        if power % 2 == 1:
            result = (result * base) % m
        power = power // 2
        base = (base * base) % m
    return result
 

# n**0.5 complexity 
def prime_factors(n):  
    factors = dict()
    for i in range(2, math.ceil(math.sqrt(n)) + 1):
        while n % i == 0:
            if i in factors:
                factors[i] += 1
            else:
                factors[i] = 1
            n = n // i
    if n > 2:
        factors[n] = 1
    return (factors)
 
 
def all_factors(n):
    return set(reduce(list.__add__,([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0)))
 
 
def fibonacci_modP(n, MOD):
    if n < 2: return 1
    return (cached_fn(fibonacci_modP, (n + 1) // 2, MOD) * cached_fn(fibonacci_modP, n // 2, MOD) + cached_fn(fibonacci_modP, (n - 1) // 2, MOD) * cached_fn(fibonacci_modP, (n - 2) // 2, MOD)) % MOD
 
 
def factorial_modP_Wilson(n, p):
    if (p <= n):
        return 0
    res = (p - 1)
    for i in range(n + 1, p):
        res = (res * cached_fn(InverseEuler, i, p)) % p
    return res
 
 
def binary(n, digits=20):
    b = bin(n)[2:]
    b = '0' * (digits - len(b)) + b
    return b
 
 
def is_prime(n):
    """Returns True if n is prime."""
    if n < 4:
        return True
    if n % 2 == 0:
        return False
    if n % 3 == 0:
        return False
    i = 5
    w = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += w
        w = 6 - w
    return True
 
#  Sieve of Eratosthenes 
def sieve(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while p * p <= n:
        if prime[p]:
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1
    return prime
    
#  O(nlog(logn))
 


factorial_modP = []
 
 
def warm_up_fac(MOD):
    global factorial_modP, fac_warm_up
    if fac_warm_up: return
    factorial_modP = [1 for _ in range(fac_warm_up_size + 1)]
    for i in range(2, fac_warm_up_size):
        factorial_modP[i] = (factorial_modP[i - 1] * i) % MOD
    fac_warm_up = True
 
 
def InverseEuler(n, MOD):
    return pow(n, MOD - 2, MOD)

def nCk(n, k): 
    if(k > n - k): 
        k = n - k 
    res = 1
    for i in range(k): 
        res = res * (n - i) 
        res = res / (i + 1) 
    return res 
 
def nCr(n, r, MOD):
    global fac_warm_up, factorial_modP
    if not fac_warm_up:
        warm_up_fac(MOD)
        fac_warm_up = True
    return (factorial_modP[n] * (
            (pow(factorial_modP[r], MOD - 2, MOD) * pow(factorial_modP[n - r], MOD - 2, MOD)) % MOD)) % MOD
 
 
def test_print(*args):
    if testingMode:
        print(args)
 
 
def display_list(list1, sep=" "):
    stdout.write(sep.join(map(str, list1)) + "\n")
 
 
def display_2D_list(li):
    for i in li:
        print(i)
 
 
def prefix_sum(li):
    sm = 0
    res = []
    for i in li:
        sm += i
        res.append(sm)
    return res
 
 
def get_int():
    return int(stdin.readline().strip())
 
 
def get_tuple():
    return map(int, stdin.readline().split())
 
 
def get_list():
    return list(map(int, stdin.readline().split()))
 
 
memory = dict()
 
 
def clear_cache():
    global memory
    memory = dict()
 
 
def cached_fn(fn, *args):
    global memory
    if args in memory:
        return memory[args]
    else:
        result = fn(*args)
        memory[args] = result
        return result
 
 
def ncr(n, r):
    return math.factorial(n) / (math.factorial(n - r) * math.factorial(r))
 
 
def binary_search(i, li):
    fn = lambda x: li[x] - x // i
    x = -1
    b = len(li)
    while b >= 1:
        while b + x < len(li) and fn(b + x) > 0:  # Change this condition 2 to whatever you like
            x += b
        b = b // 2
    return x
