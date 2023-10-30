import random
def insertionSort(array):
    """Increasing order"""
    for i in range(1, len(array)):
        for j in range(0, i):
            if array[i] < array[j]:
                temp = array[i]
                array[i] = array[j]
                array[j] = temp

    return array

array = [random.randint(0, 100) for i in range(0, 100)]
print(array)
print(insertionSort(array))
