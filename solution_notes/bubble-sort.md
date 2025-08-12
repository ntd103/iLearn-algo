---
difficulty: Easy
tags:
  - dsa/Problem
  - algorithm/Sorting
---
# bubble-sort

>[!question]+ Sắp xếp nổi bọt
>Tối ưu bubble sort với 
>- flag để theo dõi còn inversion không
>- chạy for trong tới n - i - j để bớt duyệt các elm lớn nhất đã được xếp đúng vị trí 


```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
	    bool swapped = false;
        // Giảm phạm vi kiểm tra vì phần tử cuối cùng đã đúng vị trí
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Nếu không có sự hoán đổi nào, mảng đã sắp xếp xong
        if (!swapped) break;
    }
}
```

