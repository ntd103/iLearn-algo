# loops

```cpp
while (cin >> a, a){
}
//Thực hiện các lệnh, lệnh sau cùng sẽ là điều kiện
```

# vector

## Init

```cpp
vector <kiểu> tên_biến;
```

Khởi tạo giá trị

```cpp
vector <kiểu> biến{"val1", "val2"};
```

Tạo số lượng, int mặc định là 0, string mặc định là empty string

```cpp
vector <kiểu> biến (kích_thước, giá_trị_khởi_tạo) // buộc có size, init value k có thì về default
```

## Assign

```cpp
vector <kiểu> biến1 = biến2;
vector <kiểu> biến1 (biến2);
```

## vector operations

```cpp
v.empty() //check rỗng
v.size() //size
v.push_back // thêm cuối
v[n] //phần tử vị trí n
v1 == v2 // 2 vector bằng nhau nếu cùng size và phần tử giống nhau, còn không so sánh theo từ điển


