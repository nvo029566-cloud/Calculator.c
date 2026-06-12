# 🧮 Máy Tính Cầm Tay (Handheld Calculator) — C Language

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg)](#)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](#-license)

Một ứng dụng máy tính dòng lệnh (CLI) viết bằng **C**, hỗ trợ **22 chức năng** từ phép tính cơ bản đến nâng cao (lượng giác, logarithm, số học), kèm hệ thống **lưu lịch sử tính toán ra file**. Dự án được thiết kế theo kiến trúc **module hóa** (mỗi nhóm chức năng nằm trong file riêng), phù hợp cho mục đích học tập lập trình C.

---

## 📑 Mục lục

- [Tính năng](#-tính-năng)
- [Cấu trúc dự án](#-cấu-trúc-dự-án)
- [Yêu cầu hệ thống](#️-yêu-cầu-hệ-thống)
- [Cài đặt & Biên dịch](#-cài-đặt--biên-dịch)
- [Hướng dẫn sử dụng](#-hướng-dẫn-sử-dụng)
- [Lịch sử tính toán](#-lịch-sử-tính-toán)
- [Sơ đồ luồng chương trình](#-sơ-đồ-luồng-chương-trình)
- [Lưu ý & Giới hạn](#️-lưu-ý--giới-hạn)
- [Hướng phát triển](#-hướng-phát-triển-tiếp-theo)
- [Tác giả](#-tác-giả)
- [License](#-license)

---

## ✨ Tính năng

### ➕ Cơ bản

| Lựa chọn | Chức năng | Ví dụ |
|:---:|---|---|
| 1 | Cộng (a + b) | `5 + 3 = 8` |
| 2 | Trừ (a − b) | `5 − 3 = 2` |
| 3 | Nhân (a × b) | `5 × 3 = 15` |
| 4 | Chia (a ÷ b) | `6 ÷ 3 = 2` |

### 🔢 Toán học

| Lựa chọn | Chức năng | Ví dụ |
|:---:|---|---|
| 5 | Căn bậc 2 | `√16 = 4` |
| 6 | Giai thừa (n!) | `5! = 120` |
| 7 | Lũy thừa (aᵇ) | `2³ = 8` |
| 8 | Kiểm tra số nguyên tố | `7 → là số nguyên tố` |
| 9 | Ước chung lớn nhất (GCD) | `GCD(12, 18) = 6` |
| 10 | Bội chung nhỏ nhất (LCM) | `LCM(4, 6) = 12` |

### 📐 Lượng giác *(đơn vị: độ)*

| Lựa chọn | Chức năng |
|:---:|---|
| 11 | Sine |
| 12 | Cosine |
| 13 | Tangent |

### 🎯 Làm tròn

| Lựa chọn | Chức năng | Ví dụ |
|:---:|---|---|
| 14 | Làm tròn thông thường | `3.6 → 4` |
| 15 | Làm tròn lên (ceil) | `3.1 → 4` |
| 16 | Làm tròn xuống (floor) | `3.9 → 3` |

### 📊 Logarithm

| Lựa chọn | Chức năng |
|:---:|---|
| 17 | Logarithm tự nhiên (ln) |
| 18 | Logarithm cơ số 10 (log₁₀) |

### ✅ Kiểm tra

| Lựa chọn | Chức năng | Ví dụ |
|:---:|---|---|
| 19 | Kiểm tra số chẵn / lẻ | `4 → chẵn` |
| 20 | Kiểm tra số hoàn hảo | `28 → là số hoàn hảo` |

### 🕘 Lịch sử

| Lựa chọn | Chức năng |
|:---:|---|
| 21 | Xem lịch sử tính toán |
| 22 | Xóa lịch sử |
| **0** | **Thoát chương trình** |

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
├── lichSu.txt      # File lưu lịch sử (tự động tạo khi chạy)
└── README.md       # Tài liệu mô tả dự án
```

> 💡 Mỗi module (`calculator`, `advanced`, `history`) có file `.h` riêng để khai báo prototype, giúp tách biệt rõ ràng giữa giao diện và cài đặt — đúng nguyên tắc lập trình hướng module trong C.

---

## 🛠️ Yêu cầu hệ thống

| Thành phần | Yêu cầu |
|---|---|
| Hệ điều hành | Windows (sử dụng `windows.h` và `SetConsoleOutputCP(65001)` để hiển thị tiếng Việt UTF-8) |
| Compiler | GCC (MinGW-w64) hoặc MSVC |
| Thư viện chuẩn | `stdio.h`, `stdlib.h`, `string.h`, `ctype.h`, `math.h`, `windows.h` |

> ⚠️ Trên Linux/macOS, cần loại bỏ hoặc thay thế các đoạn gọi `windows.h` / `SetConsoleOutputCP` để chương trình biên dịch được (xem [Lưu ý & Giới hạn](#️-lưu-ý--giới-hạn)).

---

## 🚀 Cài đặt & Biên dịch

### 1. Clone repository

```bash
git clone https://github.com/<username>/<repo-name>.git
cd <repo-name>
```

### 2. Biên dịch bằng GCC

```bash
gcc main.c calculator.c advanced.c history.c -o main -lm
```

> Cờ `-lm` cần thiết để liên kết thư viện toán học (`math.h`) — dùng cho căn bậc 2, lượng giác, logarithm, lũy thừa...

### 3. Chạy chương trình

```bash
./main
```

Hoặc trên Windows:

```bash
main.exe
```

---

## 📖 Hướng dẫn sử dụng

Sau khi chạy, chương trình hiển thị menu với 22 chức năng. Người dùng chỉ cần:

1. Nhập **số tương ứng** với chức năng muốn dùng (0–22)
2. Nhập các giá trị đầu vào theo hướng dẫn trên màn hình
3. Xem kết quả — kết quả tính toán hợp lệ sẽ tự động được ghi vào `lichSu.txt`
4. Lặp lại hoặc nhập `0` để thoát chương trình

**Ví dụ phiên làm việc:**

```
===== MÁY TÍNH CẦM TAY =====
1. Cộng        2. Trừ
3. Nhân        4. Chia
5. Căn bậc 2   ...
0. Thoát
=============================
Nhập lựa chọn: 1
Nhập số thứ nhất: 45
Nhập số thứ hai: 25
Kết quả: 45.00 + 25.00 = 70.00
Đã lưu vào lịch sử.
```

---

## 📝 Lịch sử tính toán

Mỗi phép tính **thành công** sẽ được tự động lưu vào file `lichSu.txt` (cùng thư mục với file thực thi), theo định dạng:

```
Cong = 70.00
Tru = -144.00
Nhan = 15.00
```

- **Lựa chọn 21**: hiển thị toàn bộ nội dung `lichSu.txt` ra màn hình
- **Lựa chọn 22**: xóa toàn bộ nội dung lịch sử (ghi đè file rỗng)

> Các phép tính bị lỗi (chia cho 0, căn của số âm, log của số không dương...) **sẽ không** được ghi vào lịch sử.

---

## 🔄 Sơ đồ luồng chương trình

```
┌─────────────┐
│   main()    │
└──────┬──────┘
       │
       ▼
┌─────────────────────┐
│  Hiển thị menu (0-22)│◄──────────────┐
└──────┬───────────────┘               │
       │                                │
       ▼                                │
┌─────────────────────┐                │
│ Nhập lựa chọn        │                │
└──────┬───────────────┘                │
       │                                │
       ▼                                │
┌─────────────────────────────┐         │
│ switch(luaChon)              │         │
│  ├─ 1-4   → calculator.c     │         │
│  ├─ 5-20  → advanced.c       │         │
│  ├─ 21-22 → history.c        │         │
│  └─ 0     → Thoát            │         │
└──────┬────────────────────────┘        │
       │ (kết quả hợp lệ)                │
       ▼                                  │
┌─────────────────────┐                  │
│ Ghi vào lichSu.txt   │──────────────────┘
└─────────────────────┘
```

---

## ⚠️ Lưu ý & Giới hạn

- **Chia cho 0**: chương trình thông báo lỗi và **không** ghi vào lịch sử.
- **Căn bậc 2 của số âm**: trả về lỗi, không tính toán.
- **Giai thừa (n!)**: chỉ chấp nhận số nguyên **không âm**.
  - ⚠️ Hàm `gt()` hiện dùng kiểu `int` cho biến trung gian — với `n` lớn (n > 12) có thể bị **tràn số (overflow)**. Nên đổi sang `long long` để mở rộng phạm vi tính toán an toàn (lên đến `20!`).
- **Logarithm**: chỉ hợp lệ với số dương (`x > 0`).
- **Tính tương thích hệ điều hành**: các lệnh `windows.h`/`SetConsoleOutputCP` chỉ chạy trên Windows. Để chạy trên Linux/macOS, cần bọc các đoạn này trong `#ifdef _WIN32 ... #endif` hoặc loại bỏ.

---

## 🔮 Hướng phát triển tiếp theo

- [ ] Khắc phục tràn số trong hàm giai thừa bằng `long long` hoặc kiểu `double` cho `n` lớn
- [ ] Hỗ trợ đa nền tảng (Linux/macOS) thông qua `#ifdef`
- [ ] Thêm chức năng tính phần trăm (%)
- [ ] Thêm bộ nhớ tạm (memory: M+, M-, MR, MC)
- [ ] Cho phép xuất lịch sử ra file CSV để dễ phân tích
- [ ] Viết unit test cho các module `calculator` và `advanced`

---

## 👤 Tác giả

Dự án được viết bằng ngôn ngữ **C**, theo phong cách lập trình **hướng module** (modular programming), phù hợp cho mục đích học tập và thực hành cấu trúc dữ liệu, giải thuật cơ bản trong C.

---

## 📄 License

Dự án được phát hành theo giấy phép **MIT** — tự do sử dụng, sửa đổi và phân phối cho mục đích học tập và phi thương mại.
