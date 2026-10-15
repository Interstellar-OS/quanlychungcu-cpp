// Header cư dân

#ifndef CUDAN_H
#define CUDAN_H

#include "thuvienchung.h"

struct CuDan {
    string hoten;
    string cccd;
    string sodienthoai;
    bool lachuho;
    CuDan* link;
};

typedef CuDan* CuDanPtr;

bool KiemTraRongDanhSachCuDan(CuDanPtr& danhsach);
// khởi tạo danhsach = NULL lúc đầu 
void KhoiTaoDanhSachCuDan(CuDanPtr& danhsach);
// Khởi tạo 1 node cư dân để nối vào dslk
CuDanPtr KhoiTaoCuDan(CuDan& cudanmoi);
// Hàm nhập thông tin 1 cư dân 
CuDan NhapCuDan();
// Hàm nhập thông tin nhiều cư dân (trong 1 phòng - là thành viên gia đình với nhau)
void NhapDanhSachCuDan(CuDanPtr& danhsach, int soluong);
void ThemCuoiDanhSachCuDan(CuDanPtr& danhsach, CuDanPtr cudanmoi);
void XuatDanhSachCuDan(CuDanPtr& danhsach);
CuDanPtr TimTheoCCCD(CuDanPtr& danhsach, string cccd);
CuDanPtr TimTheoChuHo(CuDanPtr& danhsach, string tenchuho);
// tách dùng cho chuyển phòng cho cư dân mà ko xóa cư dân 
CuDanPtr TachCuDan(CuDanPtr& danhsach, string cccd);
bool XoaCuDan(CuDanPtr& danhsach);
void GiaiPhongDanhSachCuDan(CuDanPtr& danhsach);

#endif