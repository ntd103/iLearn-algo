---
difficulty: Easy
tags:
  - dsa/Problem
  - fundamental
  - algorithm
lastReviewed: 2026-05-19
reviewCount: 0
status: solved
---
>[!question]+ Palindrome number
>Given a positive integer 𝑛, check whether the number 𝑛 is a symmetrical number. Symmetrical numbers are numbers that read the same from left to right (excluding meaningless zeros at the beginning) and from right to left.
>For example, the number 12321 is a symmetrical number, 1221 is a symmetrical number, 5656 is not a symmetrical number, 100 is not a symmetrical number.
>Input Format
>
A single line is a positive integer 𝑛 (𝑛 <= 10^6)
>
>Output Format
If n is a symmetrical number, print "YES", otherwise print "NO".
>
>Do not print "".

# My code

```cpp
#include <iostream>

using namespace std;

bool 

int main() {
    string n;
    cin >> n;
    int i = 0;
    
    bool flag = true;

    while(i < n.size() - 1 - i) {
        if (n[i] != n[n.size() - 1 - i]) {
            flag = false;
            break;
        }
        i++;
    }

    if (flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
```

>Note:
>- chú ý nhầm n.size  với chỉ số n.size không phải là chỉ số cuối vì mảng bắt đầu từ 0
>- chú ý break
>- phải đặt flag để k bị cout trong loop

```cpp
#include <iostream>

using namespace std;

int Reverse(int n) {
    int digit, reverse = 0;

    while (n != 0) {
        digit = n % 10;
        n /= 10;
        reverse = reverse * 10 + digit;
    }

    return reverse;
}

int main() {
    int n;
    cin >> n;

    if (Reverse(n) == n) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
```

>Note:
>- Chú ý nếu làm hàm bool Palidrome() thì phải đảm bảo reverse phải so sánh đúng với  giá trị n đâu, tức sao lưu giá  trị n đầu

