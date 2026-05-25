# 🧮 Máy Tính Cầm Tay - Handheld Calculator (C)

Một ứng dụng máy tính dòng lệnh viết bằng C, hỗ trợ các phép tính từ cơ bản đến nâng cao, tích hợp lưu lịch sử tính toán ra file.

---

## 📁 Cấu trúc dự án

```
.
├── main.c          # Hàm main, giao diện menu và xử lý lựa chọn
├── calculator.c    # Các phép tính cơ bản (cộng, trừ, nhân, chia)
├── calculator.h    # Header cho calculator.c
├── advanced.c      # Các hàm toán học nâng cao
├── advanced.h      # Header cho advanced.c
├── history.c       # Quản lý lịch sử tính toán (đọc/ghi/xóa file)
├── history.h       # Header cho history.c
└── lichSu.txt      # File lưu lịch sử (tự động tạo khi chạy)
```

---

## ✨ Tính năng

### Cơ bản
| Lựa chọn | Chức năng |
|----------|-----------|
| 1 | Cộng (a + b) |
| 2 | Trừ (a - b) |
| 3 | Nhân (a × b) |
| 4 | Chia (a ÷ b) |

### Toán học
| Lựa chọn | Chức năng |
|----------|-----------|
| 5 | Căn bậc 2 |
| 6 | Giai thừa (n!) |
| 7 | Lũy thừa (aᵇ) |
| 8 | Kiểm tra số nguyên tố |
| 9 | Ước chung lớn nhất (GCD) |
| 10 | Bội chung nhỏ nhất (LCM) |

### Lượng giác *(đơn vị: độ)*
| Lựa chọn | Chức năng |
|----------|-----------|
| 11 | Sine |
| 12 | Cosine |
| 13 | Tangent |

### Làm tròn
| Lựa chọn | Chức năng |
|----------|-----------|
| 14 | Làm tròn thông thường |
| 15 | Làm tròn lên (ceil) |
| 16 | Làm tròn xuống (floor) |

### Logarithm
| Lựa chọn | Chức năng |
|----------|-----------|
| 17 | Logarithm tự nhiên (ln) |
| 18 | Logarithm cơ số 10 (log₁₀) |

### Kiểm tra
| Lựa chọn | Chức năng |
|----------|-----------|
| 19 | Kiểm tra số chẵn / lẻ |
| 20 | Kiểm tra số hoàn hảo |

### Lịch sử
| Lựa chọn | Chức năng |
|----------|-----------|
| 21 | Xem lịch sử tính toán |
| 22 | Xóa lịch sử |
| 0 | Thoát chương trình |

---

## 🛠️ Yêu cầu

- **Hệ điều hành:** Windows (dùng `windows.h` và `SetConsoleOutputCP` để hiển thị tiếng Việt)
- **Compiler:** GCC (MinGW) hoặc MSVC
- **Thư viện:** `math.h`, `stdio.h`, `stdlib.h`, `string.h`, `ctype.h`

---

## 🚀 Cách biên dịch và chạy

```bash
# Biên dịch bằng GCC
gcc main.c calculator.c advanced.c history.c -o main -lm

# Chạy chương trình
./main
```

Hoặc dùng file `.exe` đã biên dịch sẵn:

```bash
main.exe
```

---

## 📝 Lịch sử tính toán

Mỗi phép tính thành công sẽ được tự động lưu vào file `lichSu.txt` ở cùng thư mục với chương trình. Ví dụ nội dung file:

```
Cong = 70.00
Tru = -144.00
Nhan = 15.00
```

Dùng lựa chọn **21** để xem và **22** để xóa lịch sử ngay trong chương trình.

---

## ⚠️ Lưu ý

- Phép chia cho 0 sẽ được thông báo lỗi, không ghi lịch sử.
- Căn bậc 2 của số âm sẽ trả về lỗi.
- Giai thừa chỉ chấp nhận số nguyên không âm.
- Logarithm chỉ hợp lệ với số dương.
- Hàm `gt()` (giai thừa) hiện dùng kiểu `int` cho biến trung gian — với n lớn có thể bị tràn số; nên đổi sang `long long` nếu cần tính giá trị lớn.

---

## 👤 Tác giả

Dự án được viết bằng ngôn ngữ C, phù hợp cho mục đích học tập và thực hành lập trình hướng module.
