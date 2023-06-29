N = int(input())
count_zero = [0]
num_list = []

fibo_list = [0] * 41
zero_list = [0] * 41

while N:
    num_list.append(int(input()))
    N-=1  

# 실제로 fibonacci 함수를 통해 계산하면 시간 초과 발생.
# def fibonacci(n : int):
#     if n == 0:        
#         return 0
#     elif n == 1:        
#         return 1
#     else:
#         if n == 2:
#             count_zero[0] += 1
#             return 1
#         else:
#             return fibonacci(n-1) + fibonacci(n-2)        

fibo_list[0] = 0
fibo_list[1] = 1

zero_list[0] = 1
zero_list[1] = 0

for i in range(0, fibo_list.__len__()):
    if i==0 | i ==1:
        continue
    fibo_list[i] = fibo_list[i-1]+fibo_list[i-2]
    zero_list[i] = zero_list[i-1]+zero_list[i-2]

for num in num_list:
    if num == 0:
        print("1 0")
    elif num == 1:
        print("0 1")
    else:
        print(str(fibo_list[num-1])+" "+str(fibo_list[num]))
