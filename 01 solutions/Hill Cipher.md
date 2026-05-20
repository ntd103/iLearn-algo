---
difficulty: 
tags:
  - dsa/Problem
  - algorithm
  - cipher
  - cryptography
lastReviewed: 2026-05-19
reviewCount: 0
status: solved
---
>[!question]+

# Hill Cipher


```pseudocode
function encrypt(plaintext, K):
    text = convert_to_numbers(plaintext)
    n = size of matrix K
    cipher = []
    for i = 0 to length of text / n:
        block = text[i * n : (i + 1) * n]
        encrypted_block = matrix_multiply(K, block) % 26
        cipher.append(convert_to_letters(encrypted_block))
    return cipher

function matrix_multiply(A, B):
    result = []
    for row in A:
        sum = 0
        for i = 0 to length of row:
            sum += row[i] * B[i]
        result.append(sum)
    return result
```

```cpp
const int N = 26; // Số lượng chữ cái trong bảng chữ cái

// Hàm tìm nghịch đảo của một số mod N
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Nếu không tìm được nghịch đảo
}

// Hàm nhân ma trận với vector
vector<int> matrix_multiply(const vector<vector<int>>& K, const vector<int>& block) {
    vector<int> result(K.size(), 0);
    for (int i = 0; i < K.size(); i++) {
        for (int j = 0; j < K[i].size(); j++) {
            result[i] = (result[i] + K[i][j] * block[j]) % N;
        }
    }
    return result;
}

// Hàm chuyển văn bản thành vector số
vector<int> convert_to_numbers(const string& text) {
    vector<int> numbers;
    for (char ch : text) {
        if (isalpha(ch)) {
            numbers.push_back(toupper(ch) - 'A');
        }
    }
    return numbers;
}

// Hàm chuyển vector số thành văn bản
string convert_to_letters(const vector<int>& numbers) {
    string text = "";
    for (int num : numbers) {
        text += (num + 'A');
    }
    return text;
}

// Hàm tính định thức của ma trận mod N
int determinant(const vector<vector<int>>& K) {
    return (K[0][0] * K[1][1] - K[0][1] * K[1][0]) % N;
}

// Hàm tính ma trận nghịch đảo mod N
vector<vector<int>> inverse_matrix(const vector<vector<int>>& K) {
    int det = determinant(K);
    int inv_det = modInverse(det, N); // Nghịch đảo định thức mod N
    vector<vector<int>> inv(K.size(), vector<int>(K[0].size()));
    inv[0][0] = (K[1][1] * inv_det) % N;
    inv[0][1] = (-K[0][1] * inv_det) % N;
    inv[1][0] = (-K[1][0] * inv_det) % N;
    inv[1][1] = (K[0][0] * inv_det) % N;

    // Đảm bảo các giá trị trong ma trận nghịch đảo là trong phạm vi mod N
    for (int i = 0; i < K.size(); i++) {
        for (int j = 0; j < K[i].size(); j++) {
            inv[i][j] = (inv[i][j] + N) % N;
        }
    }

    return inv;
}

// Hàm mã hóa văn bản
string encrypt(const string& text, const vector<vector<int>>& K) {
    vector<int> numbers = convert_to_numbers(text);
    string encrypted = "";
    for (size_t i = 0; i < numbers.size(); i += 2) {
        vector<int> block = {numbers[i], numbers[i + 1]};
        vector<int> encrypted_block = matrix_multiply(K, block);
        encrypted += convert_to_letters(encrypted_block);
    }
    return encrypted;
}

// Hàm giải mã văn bản
string decrypt(const string& text, const vector<vector<int>>& K) {
    vector<int> numbers = convert_to_numbers(text);
    string decrypted = "";
    vector<vector<int>> K_inv = inverse_matrix(K);
    for (size_t i = 0; i < numbers.size(); i += 2) {
        vector<int> block = {numbers[i], numbers[i + 1]};
        vector<int> decrypted_block = matrix_multiply(K_inv, block);
        decrypted += convert_to_letters(decrypted_block);
    }
    return decrypted;
}
```


