# Bai5Lab2-UIT-IT002

Repository này chứa các bài thực hành OOP bằng C++ cho Lab 2.

## Nội dung hiện có

- `Bai1Lab2.cpp`: Cài đặt lớp `PhanSo` với các chức năng khởi tạo, rút gọn, so sánh, cộng/trừ/nhân/chia, sao chép và tìm phân số lớn nhất.
- `Bai5Lab2.cpp`: Cài đặt lớp `NhanVien` và `CongTy` để quản lý nhân viên, tính lương, tìm kiếm/cập nhật theo mã nhân viên, tìm lương cao nhất và số sản phẩm thấp nhất.
- `LAB2.sln` + `LAB2/LAB2.vcxproj`: Project Visual Studio hiện đang build file `LAB2/LAB2.cpp` (nội dung tương ứng bài quản lý nhân viên).

## Yêu cầu môi trường

- Trình biên dịch C++ hỗ trợ C++17 (ví dụ `g++` hoặc Visual Studio 2022).

## Build và chạy nhanh bằng g++

Từ thư mục gốc repository:

```bash
g++ -std=c++17 Bai1Lab2.cpp -o Bai1Lab2
./Bai1Lab2

g++ -std=c++17 Bai5Lab2.cpp -o Bai5Lab2
./Bai5Lab2
```

## Chạy bằng Visual Studio

1. Mở `LAB2.sln`.
2. Chọn cấu hình build mong muốn (Debug/Release, x86/x64).
3. Build và Run project `LAB2`.

