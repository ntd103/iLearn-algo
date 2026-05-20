---
difficulty: Easy
tags:
  - algorithm
  - dsa/Technical
---
# random-in-cp

**Cú pháp trong c++**

>[!tip]+ random số nguyên
> `rand() % so_luong_ptu + dau_mut_trai`
> ---
> ví dụ:
> - `(a,b)` -> `rand() % (b - a - 1) + a`
> - `[a,b]` -> `rand() % (b - a + 1) + a
> - `(a, b]` -> `rand() % (b - a) + a + 1`
> - `[a, b)` -> rand() % (b - a) + a


>[!tip]+ random số thực
>- b1: Nhân các thành phần trong random_so_nguyen (~~Không nhân bên ngoài mà nhân cho số chia và phần mút~~) với số dạng 10^n với n là số phần thập phân mong muốn
>- b2: chia b1 cho 10^n
> ---
> Ví dụ: 2 số phần thập phân (thêm 2 số 0)
> `(rand() % sl_ptu_00 + mut_trai_00) / 100.0f`

>[!tip]+ random elm trong mảng
>`arr[rand() % arr.size()]`









