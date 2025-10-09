---
difficulty: 
tags:
  - dsa/Problem
  - algorithm
  - cryptography
---
>[!question]+

# find gcd_extend_euler

```pseudocode
MODULE extendedEuclid(a, b)
    x2 = 1, x1 = 0
    y2 = 0, y1 = 1
    WHILE b ≠ 0 DO
        q = a DIV b
        r = a MOD b
        x = x2 - q * x1
        y = y2 - q * y1
        a = b
        b = r
        x2 = x1
        x1 = x
        y2 = y1
        y1 = y
    END WHILE
    RETURN (a, x2, y2) // gcd, x, y
END MODULE
```

```cpp
int extendedEuclid(int a, int b, int &x, int &y) {
    int x2 = 1, x1 = 0, y2 = 0, y1 = 1;
    while (b != 0) {
        int q = a / b;
        int r = a % b;
        int x_temp = x2 - q * x1;
        int y_temp = y2 - q * y1;

        a = b;
        b = r;
        x2 = x1;
        x1 = x_temp;
        y2 = y1;
        y1 = y_temp;
    }
    x = x2;
    y = y2;
    return a;
}
```


**Gọn hơn với đệ quy:**

```cpp
int gcdExtended(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = gcdExtended(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}
```

**Phiên bản giảm lượng biến**

```cpp
int gcdExtended(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int gcd = gcdExtended(b, a % b, y, x);
    y -= (a / b) * x;

    return gcd;
}
```

```ad-example
title: cho a = 814, b = 187. TÌm gcd(a,b), các số nguyên x, y thỏa mãn ax + by = d


| q   | r   | x   | y   | a      | b   | $x_2$ | $x_1$ | $y_2$   | $y_1$ |
| --- | --- | --- | --- | ------ | --- | ----- | ----- | ------- | ----- |
| -   | -   | -   | -   | 814    | 187 | 1     | 0     | 0       | 1     |
| 4   | 66  | 1   | -4  | 187    | 66  | 0     | 1     | 1       | -4    |
| 2   | 55  | -2  | 9   | 66     | 55  | 1     | -2    | -4      | 9     |
| 1   | 11  | 3   | -13 | 55     | 11  | -2    | 3     | 9       | -13   |
| 5   | 0   | -17 | 74  | **11** | 0   | **3** | -17   | **-13** | 74    |
Vậy gcd(814,187) = 11 và 814 \* 3 + 187 \* -13 = 11
```

```ad-note
title: file test
[[find gcd_extend_euler.xlsx]]
```

