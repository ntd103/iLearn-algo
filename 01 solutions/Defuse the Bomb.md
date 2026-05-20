---
difficulty: Easy
tags:
  - dsa/Problem
  - algorithm
  - sliding-window
  - leetcode
  - Math/Modulo
  - circular-array
lastReviewed: 2026-05-19
reviewCount: 0
status: solved
---
# Defuse the Bomb

>[!question]+ [Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb/description/)
>You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.
To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.
If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].
Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

```
Example 1:

Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
Example 2:

Input: code = [1,2,3,4], k = 0
Output: [0,0,0,0]
Explanation: When k is zero, the numbers are replaced by 0. 
Example 3:

Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.
```

```ad-hint
title: Thuật toán

1. Tạo một mảng resultcó cùng độ dài để codelưu trữ các giá trị đã giải mã.
2. Nếu k là 0, trả về result, vì tất cả giá trị phải bằng 0.
3. Đặt giá trị ban đầu startvà endchỉ số dựa trên k.
	- Nếu k > 0:
		- Đặt start= 1 và end = k.
	- Nếu k < 0:
		- Đặt start thành code.length - |k|và end thành code.length - 1.
4. Tính tổng các phần tử ban đầu từ start đến end.
5. Lặp qua từng chỉ mục i trong code:
	- Lưu trữ dòng điện sum trong result[i].
	- Cập nhật sum bằng cách trừ phần tử tại start và thêm phần tử tại end + 1, sử dụng modulo để xử lý việc bao quanh mảng.
	- Tăng start thêm end 1 để trượt cửa sổ sang phải.
6. Trả về result mảng có các giá trị đã giải mã.
```

![](https://i.imgur.com/IIK6hQ8.png)
![](https://i.imgur.com/8w5HuEj.png)
![](https://i.imgur.com/4Fj9X5x.png)
![](https://i.imgur.com/S3SlnVP.png)
![](https://i.imgur.com/sUhRkFp.png)

Sliding window:
- tính tổng cho một lượt trượt
- lặp lại bằng cách thêm phần tử mới, trừ phần tử đầu


```java
class Solution {
    public int[] decrypt(int[] code, int k) {
        int[] res = new int[code.length];
        if (k == 0) return res;
        //Define the initial window and initial sum
        int start = 1, end = k, sum = 0;
        if (k < 0) {//If k < 0, the starting point will be end of the array.
            k = -k;
            start = code.length - k;
            end = code.length - 1;
        }
        for (int i = start; i <= end; i++) sum += code[i];
        //Scan through the code array as i moving to the right, update the window sum.
        for (int i = 0; i < code.length; i++) {
            res[i] = sum;
            sum -= code[(start++) % code.length];
            sum += code[(++end) % code.length];
        }
        return res;
    }
}
```

```cpp
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if (k == 0) return vector<int>(n, 0);
        vector<int> res(n, 0);
        int sum = 0;
        int start = k > 0 ? 1 : n + k; //n - k âm để quay ngược lại
        int end = k > 0 ? k : n - 1;

		//tính phần tử đầu
        for (int i = start; i <= end; i++) {
	        sum += code[i % n]; //nếu trường hợp mảng vòng cần i > n
	    }
	    //sliding window: thêm bớt cho các phần tử tiếp
        for (int i = 0; i < n; i++) {
            res[i] = sum;
            //tăng end trước tính rồi mới tăng start
            sum += code[(++end) % n] - code[(start++) % n];
        }
        return res;
    }
};
```

```ad-example
Bước 1: Khởi tạo start, end, và tính tổng ban đầu
Giả sử bạn có mảng code = [2, 4, 9, 3] với n = 4, và k = 2 (tính tổng các phần tử tiếp theo, k > 0).

Tính giá trị start và end:
Với k = 2, start = 1 và end = 2 (vì k > 0).
Tính tổng ban đầu (sum):
Lặp qua các phần tử từ start = 1 đến end = 2:
sum += code[1] = 4
sum += code[2] = 4 + 9 = 13
Sau khi vòng lặp này, sum = 13.
Bước 2: Sliding Window (cập nhật sum)
Sau khi tính xong tổng ban đầu, bạn sẽ di chuyển qua từng phần tử của mảng, đồng thời cập nhật tổng theo phương thức sliding window:

Lặp qua các phần tử trong mảng (n lần):

Lần đầu (i = 0):

res[0] = sum = 13
Cập nhật sum:
sum += code[(++end) % n] - code[(start++) % n]
end tăng lên thành 3 (end = 3), start tăng lên thành 2 (start = 2).
Cập nhật sum: sum = sum + code[3] - code[1] = 13 + 3 - 4 = 12
Lần thứ hai (i = 1):

res[1] = sum = 12
Cập nhật sum:
end tăng lên thành 4 (end = 4, nhưng vì mảng có 4 phần tử, end % n = 0), start tăng lên thành 3 (start = 3).
Cập nhật sum: sum = sum + code[0] - code[2] = 12 + 2 - 9 = 5
Lần thứ ba (i = 2):

res[2] = sum = 5
Cập nhật sum:
end tăng lên thành 1 (end = 1), start tăng lên thành 4 (start = 4, nhưng start % n = 0).
Cập nhật sum: sum = sum + code[1] - code[3] = 5 + 4 - 3 = 6
Lần thứ tư (i = 3):

res[3] = sum = 6
Cập nhật sum:
end tăng lên thành 2 (end = 2), start tăng lên thành 5 (start = 5, nhưng start % n = 1).
Cập nhật sum: sum = sum + code[2] - code[0] = 6 + 9 - 2 = 13
Kết quả cuối cùng:
Sau khi hoàn thành các vòng lặp, bạn có kết quả trong mảng res là:

res = [13, 12, 5, 6]
```
