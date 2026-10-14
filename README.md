# Đồ án tin học 

CHƯƠNG TRÌNH QUẢN LÝ CHUNG CƯ CONSOLE (CLI) C++ BẰNG CẤU TRÚC DỮ LIỆU DANH SÁCH LIÊN KẾT ĐƠN 

- Tác giả      : TRẦN MINH GIA BẢO 
- Ngày bắt đầu : 14/10/2026
- Hạn nộp      : CUỐI HỌC KỲ 1 
- Đề tài       : QUẢN LÝ CHUNG CƯ 

---

- Menu 10 tính năng cơ bản của chương trình

1. Quan ly can ho (them / xoa / sua)
   - 1.1 Them can ho
   - 1.2 Xoa can ho
   - 1.3 Sua can ho

2. Hien thi danh sach can ho
   - 2.1 Hien thi danh sach can ho
   - 2.2 Hien thi danh sach can ho (kem chu ho)

3. Them cu dan moi vao can ho (them theo so luong)

4. Chuyen cu dan di (xoa cu dan khoi can ho cu va them vao can ho moi)
   - 4.1 Chuyen cu dan sang can khac

5. Tim kiem can ho theo cu dan
   - 5.1 Tim can ho theo ten can ho
   - 5.2 Tim can ho theo ten chu ho
   - 5.3 Tim can ho theo CCCD chu ho

6. Loc
   - 6.3 Loc can ho theo tang
   - 6.4 Loc theo trang thai (trong / dang thue)

7. Sap xep can ho
   - 7.1 Theo ten xuoi
   - 7.2 Theo ten nguoc

8. Tao va xem hoa don hang thang
   - 8.1 Tao hoa don cho 1 can
   - 8.2 Tao hoa don cho tat ca can

9. Thu phi (danh dau da dong)
   - 9.1 Danh dau da dong
   - 9.2 Xem hoa don da/chua dong

10. Thong ke
    - 10.1 So can trong / da thue
    - 10.2 Tong so cu dan
    - 10.3 Tong doanh thu

11. Luu / doc file
    - 11.1 Luu du lieu
    - 11.2 Doc du lieu

00. Thoat chuong trinh

---

Cấu trúc thư mục dự án

```txt
├── src
│   ├── thuvien
│   │   ├── canho.h
│   │   ├── cudan.h
│   │   ├── hoadon.h
│   │   ├── saoluuvanapdulieu.h
│   │   ├── thongke.h
│   │   └── thuvienchung.h
│   ├── canho.cpp
│   ├── cudan.cpp
│   ├── hoadon.cpp
│   ├── main.cpp
│   ├── saoluuvanapdulieu.cpp
│   └── thongke.cpp
├── .gitignore
├── NOTICE.md
├── README.md
└── run.cpp
``` 

---

Mô phỏng quy trình vận hành của danh sách liên kết đơn 

```txt
head
  |
  v
+-----------------------+      +-----------------------+      +-----------------------+      +-----------------------+
|                       |      |                       |      |                       |      |                       |
|                       |      |                       |      |                       |      |                       |
| [ |*]-->[ |*]--> NULL |----->| [ |*]-->[ |*]--> NULL |----->| [ |*]-->[ |*]--> NULL |----->| [ |*]-->[ |*]--> NULL |-----> NULL
|                       |      |                       |      |                       |      |                       |
|                       |      |                       |      |                       |      |                       |
+-----------------------+      +-----------------------+      +-----------------------+      +-----------------------+
         Node 1                         Node 2                         Node 3                         Node 4
```

- Với danh sách cư dân chỉ tính trong 1 phòng (căn)
- Với danh sách căn hộ sẽ chứa trong đó 1 danh sách cư dân 
- Không có danh sách liên kết tất cả thành viên trong chung cư với nhau
=> Nghĩa là danh sách căn hộ là danh sách chính liên kết nhiều căn hộ với nhau, trong mỗi căn hộ sẽ có danh sách dân cư (là gia đình/thành viên) của căn hộ đó 
