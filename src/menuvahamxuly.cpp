#include "thuvien/menuvahamxuly.h"
#include "thuvien/canho.h"

void MenuChinh(){
    cout << "┌───── MENU QUAN LY CHUNG CU ─────" << endl;
    cout << "│ 1. Quan ly can ho (them / xoa / sua)" << endl;
    cout << "│    - 1.1 Them can ho" << endl;
    cout << "│    - 1.2 Xoa can ho" << endl;
    cout << "│    - 1.3 Sua can ho" << endl;
    cout << "│ 2. Hien thi danh sach can ho" << endl;
    cout << "│    - 2.1 Hien thi danh sach can ho" << endl;
    cout << "│    - 2.2 Hien thi danh sach can ho (kem chu ho)" << endl;
    cout << "│    - 2.4 Hien thi danh sach chi tiet can ho" << endl;
    cout << "│ 3. Them cu dan moi vao can ho (them theo so luong)" << endl;
    cout << "│ 4. Chuyen cu dan di (xoa cu dan khoi can ho cu va them vao can ho moi)" << endl;
    cout << "│ 5. Tim kiem can ho theo cu dan" << endl;
    cout << "│    - 5.1 Tim can ho theo ten can ho" << endl;
    cout << "│    - 5.2 Tim can ho theo ten chu ho" << endl;
    cout << "│    - 5.3 Tim can ho theo CCCD chu ho" << endl;
    cout << "│ 6. Loc" << endl;
    cout << "│    - 6.3 Loc can ho theo tang" << endl;
    cout << "│    - 6.4 Loc theo trang thai (trong / dang thue)" << endl;
    cout << "│ 7. Sap xep can ho" << endl;
    cout << "│    - 7.1 Theo ten xuoi" << endl;
    cout << "│    - 7.2 Theo ten nguoc" << endl;
    cout << "│ 8. Tao va xem hoa don hang thang" << endl;
    cout << "│    - 8.1 Tao hoa don cho 1 can" << endl;
    cout << "│    - 8.2 Tao hoa don cho tat ca can" << endl;
    cout << "│ 9. Thu phi (danh dau da dong)" << endl;
    cout << "│    - 9.1 Danh dau da dong" << endl;
    cout << "│    - 9.2 Xem hoa don da/chua dong" << endl;
    cout << "│ 10. Thong ke" << endl;
    cout << "│    - 10.1 So can trong / da thue" << endl;
    cout << "│    - 10.2 Tong so cu dan" << endl;
    cout << "│    - 10.3 Tong doanh thu" << endl;
    cout << "│ 11. Luu / doc file" << endl;
    cout << "│    - 11.1 Luu du lieu" << endl;
    cout << "│    - 11.2 Doc du lieu" << endl;
    cout << "│ 00. Thoat chuong trinh" << endl;
    cout << "└─────────────────────────────────" << endl;
}

void XuLy1(CanHoPtr& danhsachcanho){
    int con = NhapSo("(?) Chon muc con (so sau dau cham): ");
    if(con == 1){
        CanHo canhomoi = NhapCanHo();
        if(TimTheoTenCanHo(danhsachcanho, canhomoi.tencanho) != NULL){
            cout << "(!) Ten can ho da ton tai !" << endl;
        } else {
            ThemCuoiDanhSachCanHo(danhsachcanho, KhoiTaoCanHo(canhomoi));
            cout << "(+) Them can ho thanh cong" << endl;
        }
    } else if(con == 2){
        string ten = NhapChuoi("(?) Nhap ten can ho can xoa: ");
        if(XoaCanHo(danhsachcanho, ten)) cout << "(+) Xoa thanh cong" << endl;
        else cout << "(!) Khong tim thay can ho" << endl;
    } else if(con == 3){
        string ten = NhapChuoi("(?) Nhap ten can ho can sua: ");
        if(SuaCanHo(danhsachcanho, ten)) cout << "(+) Sua thanh cong" << endl;
        else cout << "(!) Khong tim thay can ho" << endl;
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}

void XuLy2(CanHoPtr& danhsachcanho){
    int con = NhapSo("(?) Chon muc con (so sau dau cham): ");
    if(con == 1){
        XuatDanhSachCanHo(danhsachcanho, false);
    } else if(con == 2){
        XuatDanhSachCanHo(danhsachcanho, true);
    } else if(con == 3){
        XuatChiTietDanhSachCanHo(danhsachcanho, true);
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}

// Muc 3 khong co muc con
void XuLy3(CanHoPtr& danhsachcanho){
    string ten = NhapChuoi("(?) Nhap ten can ho: ");
    CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
    if(canho == NULL){
        cout << "(!) Khong tim thay can ho" << endl;
        return;
    }
    int soluong = NhapSo("(?) Nhap so luong cu dan can them: ");
    ThemCuDanVaoCanHo(canho, soluong);
}

// Muc 4 khong co muc con
void XuLy4(CanHoPtr& danhsachcanho){
    string cu = NhapChuoi("(?) Nhap ten can ho cu: ");
    string cccd = NhapChuoi("(?) Nhap CCCD cu dan can chuyen: ");
    string moi = NhapChuoi("(?) Nhap ten can ho moi: ");
    if(ChuyenCuDan(danhsachcanho, cu, moi, cccd)) cout << "(+) Chuyen cu dan thanh cong" << endl;
    else cout << "(!) Chuyen that bai (kiem tra lai ten can ho / CCCD)" << endl;
}

void XuLy5(CanHoPtr& danhsachcanho){
    int con = NhapSo("(?) Chon muc con (so sau dau cham): ");
    CanHoPtr kq = NULL;
    if(con == 1){
        kq = TimTheoTenCanHo(danhsachcanho, NhapChuoi("(?) Nhap ten can ho: "));
    } else if(con == 2){
        kq = TimTheoTenChuHo(danhsachcanho, NhapChuoi("(?) Nhap ten chu ho: "));
    } else if(con == 3){
        kq = TimTheoCCCDChuHo(danhsachcanho, NhapChuoi("(?) Nhap CCCD chu ho: "));
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
        return;
    }
    if(kq != NULL){
        XuatMotCanHo(kq, true);
        XuatDanhSachCuDan(kq->danhsachcudan);
    } else {
        cout << "(!) Khong tim thay" << endl;
    }
}

void XuLy6(CanHoPtr& danhsachcanho){
    int con = NhapSo("(?) Chon muc con (so sau dau cham): ");
    if(con == 3){                                                   // 6.3
        LocTheoTang(danhsachcanho, NhapSo("(?) Nhap tang: "));
    } else if(con == 4){                                            // 6.4
        int c = NhapSo("(?) Chon trang thai (1 = Trong, 2 = Dang thue): ");
        if(c == 1) LocTheoTrangThai(danhsachcanho, "Trong");
        else LocTheoTrangThai(danhsachcanho, "Dang thue");
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}

void XuLy7(CanHoPtr& danhsachcanho){
    int con = NhapSo("(?) Chon muc con (so sau dau cham): ");
    if(con == 1){
        SapXepTenCanHoXuoi(danhsachcanho);
        cout << "(+) Da sap xep ten xuoi" << endl;
        XuatDanhSachCanHo(danhsachcanho, false);
    } else if(con == 2){
        SapXepTenCanHoNguoc(danhsachcanho);
        cout << "(+) Da sap xep ten nguoc" << endl;
        XuatDanhSachCanHo(danhsachcanho, false);
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}

// Muc 8 den 11: gan ham that sau khi lam xong hoadon, thongke, file
void XuLy8(){
    int con = NhapSo("(?) Chon muc con (so sau dau cham): ");
    if(con == 1){
        /* TaoHoaDonMotCan(...); */
    } else if(con == 2){
        /* TaoHoaDonTatCa(...); */
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}

void XuLy9(){
    int con = NhapSo("(?) Chon muc con (so sau dau cham): ");
    if(con == 1){
        /* DanhDauDaDong(...); */
    } else if(con == 2){
        /* XemHoaDon(...); */
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}

void XuLy10(){
    int con = NhapSo("(?) Chon muc con (so sau dau cham): ");
    if(con == 1){
        /* ThongKeCanTrongDaThue(...); */
    } else if(con == 2){
        /* ThongKeCuDan(...); */
    } else if(con == 3){
        /* ThongKeDoanhThu(...); */
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}

void XuLy11(){
    int con = NhapSo("(?) Chon muc con (so sau dau cham): ");
    if(con == 1){
        /* LuuFile(...); */
    } else if(con == 2){
        /* DocFile(...); */
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}