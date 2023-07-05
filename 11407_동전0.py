N, K = map(int, input().split())
coin_len = N

coin_list = []

while coin_len:
    coin_list.append(int(input()))
    coin_len -= 1

local = 0
total = 0

for i in range(coin_list.__len__() - 1, -1, -1):

    if total == K:
        break
    if coin_list[i] > K - total:
        continue
    else:
        if i != coin_list.__len__() - 1:
            temp = coin_list[i+1]//coin_list[i]   

            for j in range(temp, -1, -1):
                if coin_list[i] * j <= K - total:
                    total += coin_list[i] * j
                    local += j
                    break
        else:
            temp = K // coin_list[i]

            for j in range(temp, -1, -1):
                if coin_list[i]*j <= K:
                    total += coin_list[i] * j
                    local += j
                    break

print(local)
