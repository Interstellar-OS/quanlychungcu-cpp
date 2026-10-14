// Header cư dân

#include "thuvienchung.h"

struct CuDan {
    string hoten;
    string cccd;
    string sodienthoai;
    bool lachuho;
    CuDan* link;
};

typedef CuDan* CuDanPtr;

// khởi tạo danhsach = NULL lúc đầu 
void KhoiTaoDanhSachCuDan(CuDanPtr& danhsach);
// Khởi tạo 1 node cư dân để nối vào dslk
CuDanPtr KhoiTaoCuDan(CuDan& cudanmoi);
// Hàm nhập thông tin 1 cư dân 
CuDan NhapCuDan();
// Hàm nhập thông tin nhiều cư dân (trong 1 phòng - là thành viên gia đình với nhau)
void NhapDanhSachCuDan(CuDanPtr& danhsach);
void ThemCuoiDanhSachCuDan(CuDanPtr& danhsach, CuDanPtr cudan);
void XuatDanhSachCuDan(CuDanPtr& danhsach);
CuDanPtr TimTheoCCCD(CuDanPtr& danhsach, string cccd);
CuDanPtr TimTheoChuHo(CuDanPtr& danhsach);
// tách dùng cho chuyển phòng cho cư dân mà ko xóa cư dân 
CuDanPtr TachCuDan(CuDanPtr& danhsach);
bool XoaCuDan(CuDanPtr& danhsach);
void GiaiPhongDanhSachCuDan(CuDanPtr& danhsach);
