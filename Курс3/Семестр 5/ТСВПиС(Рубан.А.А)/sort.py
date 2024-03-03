current_size = 1


def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(len(arr) - 1):
            if arr[j] > arr[j + 1]:
              arr[j], arr[j + 1] = arr[j + 1], arr[j]

def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]


def merge_sort_iterative(arr):
  global current_size
  
  n = len(arr)

  

  while current_size < n:
    left = 0
    for i in range(len(arr)):
      if(current_size > 1):
        if i % (current_size) == 0 and i != 0:
          print("|", end= " ")
      print(arr[i], end=" ")
    print()
    while left < n - 1:

      mid = min((left + current_size - 1), (n - 1))
      right = min((left + 2 * current_size - 1), (n - 1))
      merge(arr, left, mid, right)
      left = left + current_size * 2
    current_size = current_size * 2


def merge(arr, left, mid, right):
  n1 = mid - left + 1
  n2 = right - mid
  L = [0] * n1
  R = [0] * n2

  for i in range(n1):
    L[i] = arr[left + i]

  for i in range(n2):
    R[i] = arr[mid + 1 + i]

  i = j = 0
  k = left

  while i < n1 and j < n2:
    if L[i] <= R[j]:
      arr[k] = L[i]
      i += 1
    else:
      arr[k] = R[j]
      j += 1
    k += 1

  while i < n1:
    arr[k] = L[i]
    i += 1
    k += 1

  while j < n2:
    arr[k] = R[j]
    j += 1
    k += 1


array = [5, 2, 9, 1, 7]
print ("введённый массив : ", array)
bubble_sort(array)
print("отсортирванный массив bubble_sort : ",array)
array = [5, 2, 9, 1, 7]
print ("введённый массив : ", array)
selection_sort(array)
print("отсортирванный массив select sort : ",array)
array = [8, 3, 7, 1, 4, 5, 6, 2]
print ("введённый массив : ", array)
merge_sort_iterative(array)
print("отсортирванный массив merge sort :", array)
