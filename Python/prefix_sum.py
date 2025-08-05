arr = [4, 42, 2, 6, 6]


for i in range(1, len(arr)):

    arr[i] = arr[i - 1] + arr[i]


print(arr)
