"""
metadata:
src = https://www.hackerrank.com/challenges/ctci-merge-sort/problem
status = no md, upload to youtube
"""


def merge_count_inversions(left, right):
    result = []
    i = j = 0
    inv_count = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]: # Lưu ý phải có dấu = thể hiện không có nghịch đảo ở đây
            result.append(left[i])
            i += 1
        else:
            # right[j] < left[i] → nghịch đảo với tất cả phần tử còn lại bên trái
            result.append(right[j])
            inversions = len(left) - i
            inv_count += inversions
            j += 1

    # Thêm phần tử còn lại
    result.extend(left[i:])
    result.extend(right[j:])
    return result, inv_count


def merge_sort_count_inversions(arr):
    # Base case
    if len(arr) <= 1:
        return arr, 0

    # Chia đôi
    mid = len(arr) // 2

    # Đệ quy
    left, left_inv = merge_sort_count_inversions(arr[:mid])
    right, right_inv = merge_sort_count_inversions(arr[mid:])

    # Merge và đếm cross inversions
    merged, cross_inv = merge_count_inversions(left, right)
    total_inv = left_inv + right_inv + cross_inv
    return merged, total_inv


# lst = [64, 25, 12, 22, 11, 90, 3, 45, 1, 88, 33, 77, 5, 99, 2]

lst = [2, 1, 3, 1, 2]

print(f"Dãy số gốc: {lst}")
print(f"Độ dài: {len(lst)} phần tử")

# Thực hiện thuật toán
sorted_result, total_inversions = merge_sort_count_inversions(lst[:])

print(f"Dãy đã sắp xếp: {sorted_result}")
print(f"Tổng số cặp nghịch đảo: {total_inversions}")
