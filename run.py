n = int(input())
divisors = [i for i in range(1, n + 1) if n % i == 0]
print(sum(divisors))