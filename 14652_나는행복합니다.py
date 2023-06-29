num_list = list(map(int, input().split()))

n = num_list[0]
m = num_list[1]
k = num_list[2]

print(str(k//m)+" "+str(k%m))
