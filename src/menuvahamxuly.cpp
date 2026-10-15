#include "lib/menuvahamxuly.h"
#include "lib/canho.h"
#include "lib/hoadon.h"
#include "lib/saoluuvanapdulieu.h"
#include "lib/thongke.h"

void Banner(){
    string banner = R"(┌──────────────────────────────┐
│      ĐỒ ÁN TIN HỌC HK1       │
│ GVHD: Nguyễn Trường An       │
│ SVTH: Trần Minh Gia Bảo      │
│ Đề tài: Quản Lý Chung Cư C++ │
└──────────────────────────────┘
)";
    cout << banner << endl;
}

void MenuChinh(){
    Banner();
    cout << "MENU QUAN LY CHUNG CU " << "\n\n";
    cout << "[01] Quan ly can ho (them / xoa / sua)" << endl;
    cout << "[02] Hien thi danh sach can ho" << endl;
    cout << "[03] Them cu dan moi vao can ho (them theo so luong)" << endl;
    cout << "[04] Chuyen cu dan di" << endl;
    cout << "[05] Tim kiem can ho theo cu dan" << endl;
    cout << "[06] Loc" << endl;
    cout << "[07] Sap xep can ho" << endl;
    cout << "[08] Xem hoa don hang thang" << endl;
    cout << "[09] Thu phi (danh dau da dong)" << endl;
    cout << "[10] Thong ke" << endl;
    cout << "[11] Thong tin luu du lieu tu dong" << endl;
    cout << "[00] Thoat chuong trinh" << endl;
}

void BannerTamBiet(){
    string banner = R"(
  _______       __  __   ____ _____ ______ _______ 
 |__   __|/\   |  \/  | |  _ \_   _|  ____|__   __|
    | |  /  \  | \  / | | |_) || | | |__     | |   
    | | / /\ \ | |\/| | |  _ < | | |  __|    | |   
    | |/ ____ \| |  | | | |_) || |_| |____   | |   
    |_/_/    \_\_|  |_| |____/_____|______|  |_|   
                                                   
                                                   
)";
    cout << banner << endl;
}

void XuLyMenu1(CanHoPtr& danhsachcanho){
    cout << "1. Them can ho" << endl;
    cout << "2. Xoa can ho" << endl;
    cout << "3. Sua can ho" << endl;
    int con = NhapSo("(?) Chon: ");
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
        if(XoaCanHo(danhsachcanho, ten)){
            cout << "(+) Xoa thanh cong" << endl;            
        } else{
            cout << "(!) Khong tim thay can ho" << endl;
        }
    } else if(con == 3){
        string ten = NhapChuoi("(?) Nhap ten can ho can sua: ");
        if(SuaCanHo(danhsachcanho, ten)){
            cout << "(+) Sua thanh cong" << endl;            
        } else{
            cout << "(!) Khong tim thay can ho" << endl;
        }
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu2(CanHoPtr& danhsachcanho){
    cout << "1. Hien thi danh sach can ho" << endl;
    cout << "2. Hien thi danh sach can ho (kem chu ho)" << endl;
    cout << "3. Hien thi danh sach chi tiet can ho" << endl;
    int con = NhapSo("(?) Chon: ");
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

void XuLyMenu3(CanHoPtr& danhsachcanho){
    string ten = NhapChuoi("(?) Nhap ten can ho: ");
    CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
    if(canho == NULL){
        cout << "(!) Khong tim thay can ho" << endl;
        return;
    }
    int soluong = NhapSo("(?) Nhap so luong cu dan can them: ");
    ThemCuDanVaoCanHo(canho, soluong);
}

void XuLyMenu4(CanHoPtr& danhsachcanho){
    string canhocu = NhapChuoi("(?) Nhap ten can ho hien tai: ");
    string canhomoi = NhapChuoi("(?) Nhap ten can ho moi: ");
    if(ChuyenCuDan(danhsachcanho, canhocu, canhomoi)){
        cout << "(+) Chuyen toan bo cu dan sang can ho: " << canhomoi << " thanh cong" << endl;
    } else {
        cout << "(!) Chuyen that bai (kiem tra lai ten hai can ho)" << endl;
    }
}

void XuLyMenu5(CanHoPtr& danhsachcanho){
    cout << "1. Tim theo ten can ho" << endl;
    cout << "2. Tim theo ten chu ho" << endl;
    cout << "3. Tim theo CCCD chu ho" << endl;
    int con = NhapSo("(?) Chon: ");
    CanHoPtr kq = NULL;
    if(con == 1){
        string ten = NhapChuoi("(?) Nhap ten can ho: ");
        kq = TimTheoTenCanHo(danhsachcanho, ten);
    } else if(con == 2){
        string tenchuho = NhapChuoi("(?) Nhap ten chu ho: ");
        kq = TimTheoTenChuHo(danhsachcanho, tenchuho);
    } else if(con == 3){
        string cccd = NhapChuoi("(?) Nhap CCCD chu ho: ");
        kq = TimTheoCCCDChuHo(danhsachcanho, cccd);
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

void XuLyMenu6(CanHoPtr& danhsachcanho){
    cout << "1. Loc can ho theo tang" << endl;
    cout << "2. Loc theo trang thai (trong / dang thue)" << endl;
    int con = NhapSo("(?) Chon: ");
    if(con == 1){
        int tang = NhapSo("(?) Nhap tang: ");
        LocTheoTang(danhsachcanho, tang);
    } else if(con == 2){
        int c = NhapSo("(?) Chon trang thai (1 = Trong, 2 = Dang thue): ");
        if(c == 1){
            LocTheoTrangThai(danhsachcanho, "Trong");
        } else if(c == 2){
            LocTheoTrangThai(danhsachcanho, "Dang thue");
        } else {
            cout << "(!) Lua chon khong hop le !" << endl;
        }
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu7(CanHoPtr& danhsachcanho){
    cout << "1. Sap xep ten xuoi" << endl;
    cout << "2. Sap xep ten nguoc" << endl;
    int con = NhapSo("(?) Chon: ");
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

// Muc 8: xem hoa don
void XuLyMenu8(CanHoPtr& danhsachcanho){
    cout << "1. Xem hoa don cua 1 can" << endl;
    cout << "2. Xem hoa don cua tat ca can dang thue" << endl;
    int con = NhapSo("(?) Chon: ");
    if(con == 1){
        string ten = NhapChuoi("(?) Nhap ten can ho: ");
        CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
        if(canho == NULL){
            cout << "(!) Khong tim thay can ho" << endl;
            return;
        }
        cout << "Hoa don can ho " << canho->tencanho << ":" << endl;
        XuatDanhSachHoaDon(canho->danhsachhoadon);
    } else if(con == 2){
        if(KiemTraRongDanhSachCanHo(danhsachcanho)){
            cout << "(Chua co can ho)" << endl;
            return;
        }
        CanHoPtr p = danhsachcanho;
        bool cohoadon = false;
        while(p != NULL){
            if(p->trangthai == "Dang thue"){
                cout << "Hoa don can ho " << p->tencanho << endl;
                XuatDanhSachHoaDon(p->danhsachhoadon);
                cohoadon = true;
            }
            p = p->link;
        }
        if(!cohoadon){
            cout << "(Chua co can ho dang thue)" << endl;
        }
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu9(CanHoPtr& danhsachcanho){
    cout << "1. Danh dau da dong" << endl;
    cout << "2. Xem hoa don da dong / chua dong" << endl;
    int con = NhapSo("(?) Chon: ");
    if(con == 1){
        string ten = NhapChuoi("(?) Nhap ten can ho: ");
        CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
        if(canho == NULL){
            cout << "(!) Khong tim thay can ho" << endl;
            return;
        }
        int thang = NhapSo("(?) Nhap thang hoa don: ");
        int nam = NhapSo("(?) Nhap nam hoa don: ");
        if(thang < 1 || thang > 12 || nam < 1){
            cout << "(!) Thang hoac nam khong hop le" << endl;
            return;
        }
        HoaDonPtr hoadon = TimHoaDon(canho->danhsachhoadon, thang, nam);
        if(hoadon == NULL){
            cout << "(!) Khong tim thay hoa don" << endl;
        } else if(hoadon->dadongtien){
            cout << "(!) Hoa don da duoc thanh toan luc " << hoadon->ngaydongtien << endl;
        } else {
            hoadon->dadongtien = true;
            hoadon->ngaydongtien = LayThoiGianHienTai();
            cout << "(+) Da danh dau thanh toan" << endl;
        }
    } else if(con == 2){
        cout << "1. Xem hoa don da dong" << endl;
        cout << "2. Xem hoa don chua dong" << endl;
        int trangthai = NhapSo("(?) Chon: ");
        if(trangthai != 1 && trangthai != 2){
            cout << "(!) Lua chon khong hop le !" << endl;
            return;
        }
        CanHoPtr p = danhsachcanho;
        bool cohoadon = false;
        while(p != NULL){
            HoaDonPtr hoadon = p->danhsachhoadon;
            while(hoadon != NULL){
                if(hoadon->dadongtien == (trangthai == 1)){
                    cout << "Hoa don can ho " << p->tencanho << ":" << endl;
                    XuatMotHoaDon(hoadon);
                    cohoadon = true;
                }
                hoadon = hoadon->link;
            }
            p = p->link;
        }
        if(!cohoadon){
            cout << "(Khong co hoa don phu hop)" << endl;
        }
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu10(CanHoPtr& danhsachcanho){
    cout << "1. So can trong / da thue" << endl;
    cout << "2. Tong so cu dan" << endl;
    cout << "3. Tong doanh thu" << endl;
    int con = NhapSo("(?) Chon: ");
    if(con == 1){
        ThongKeCanHo(danhsachcanho);
    } else if(con == 2){
        ThongKeCuDan(danhsachcanho);
    } else if(con == 3){
        ThongKeDoanhThu(danhsachcanho);
    } else {
        cout << "(!) Lua chon khong hop le !" << endl;
    }
}