def quickSort(array):
    if array == []:
        return []
    else:
        pivot = array[0]
        duplicates = 0
        lessThan = []
        greaterThan = []
        for i in range(0, len(array)):
            if array[i] < pivot:
                lessThan.append(array[i])
            elif array[i] > pivot:
                greaterThan.append(array[i])
            else:
                duplicates += 1

    return quickSort(lessThan) + [pivot]*duplicates + quickSort(greaterThan)

array = [10, 80, 30, 90, 40, 50, 70, 10]
print(quickSort(array))