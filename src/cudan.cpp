#include "lib/cudan.h"
#include "lib/hamphu.h"

static bool Lachuoichicoso(string chuoi){
    if(chuoi.empty()){
        return false;
    }
    for(char kitu : chuoi){
        if(kitu < '0' || kitu > '9'){
            return false;
        }
    }
    return true;
}

bool KiemTraRongDanhSachCuDan(CuDanPtr &danhsach){
    return danhsach == NULL;
}

void KhoiTaoDanhSachCuDan(CuDanPtr &danhsach){
    danhsach = NULL;
}

CuDanPtr KhoiTaoCuDan(CuDan &cudanmoi){
    CuDanPtr p = new CuDan();
    p->hoten = cudanmoi.hoten;
    p->cccd = cudanmoi.cccd;
    p->sodienthoai = cudanmoi.sodienthoai;
    p->lachuho = cudanmoi.lachuho;
    p->link = NULL;
    return p;
}

CuDan NhapCuDan(){
    CuDan cudanmoi;
    cudanmoi.hoten = NhapChuoi("(?) Nhap ho ten: ");
    cudanmoi.cccd = NhapChuoi("(?) Nhap CCCD: ");
    while(!Lachuoichicoso(cudanmoi.cccd)){
        cout << "(!) CCCD chi duoc chua chu so" << endl;
        cudanmoi.cccd = NhapChuoi("(?) Nhap lai CCCD: ");
    }
    cudanmoi.sodienthoai = NhapChuoi("(?) Nhap so dien thoai: ");
    while(!Lachuoichicoso(cudanmoi.sodienthoai)){
        cout << "(!) So dien thoai chi duoc chua chu so" << endl;
        cudanmoi.sodienthoai = NhapChuoi("(?) Nhap lai so dien thoai: ");
    }
    int lachuho = NhapSo("(?) La chu ho? (1 = Co, 0 = Khong): ");
    while(lachuho != 0 && lachuho != 1){
        cout << "(!) Chi chon 1 hoac 0" << endl;
        lachuho = NhapSo("(?) La chu ho? (1 = Co, 0 = Khong): ");
    }
    cudanmoi.lachuho = (lachuho == 1);
    return cudanmoi;
}

void NhapDanhSachCuDan(CuDanPtr &danhsach, int soluong){
    int dadhem = 0;
    while(dadhem < soluong){
        cout << "Nhap cu dan thu " << dadhem + 1 << endl;
        CuDan cudanmoi = NhapCuDan();
        bool dacochuho = false;
        CuDanPtr p = danhsach;
        while(p != NULL){
            if(p->lachuho){
                dacochuho = true;
                break;
            }
            p = p->link;
        }
        if(cudanmoi.lachuho && dacochuho){
            cout << "(!) Can ho da co chu ho" << endl;
            int themthanhvien = NhapSo("(?) Ban co muon them nguoi nay lam thanh vien khong? (1 = Co, 0 = Khong): ");
            while(themthanhvien != 0 && themthanhvien != 1){
                cout << "(!) Chi chon 1 hoac 0" << endl;
                themthanhvien = NhapSo("(?) Ban co muon them lam thanh vien khong? (1 = Co, 0 = Khong): ");
            }
            if(themthanhvien == 0){
                cout << "(-) Khong them cu dan" << endl;
                break;
            }
            cudanmoi.lachuho = false;
        }
        CuDanPtr khoitaocudanmoi = KhoiTaoCuDan(cudanmoi);
        ThemCuoiDanhSachCuDan(danhsach, khoitaocudanmoi);
        dadhem++;
    }
}

void ThemCuoiDanhSachCuDan(CuDanPtr &danhsach, CuDanPtr cudanmoi){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        danhsach = cudanmoi;
        return;
    }
    CuDanPtr p = danhsach;
    while(p->link != NULL){
        p = p->link;
    }
    p->link = cudanmoi;
}

void XuatDanhSachCuDan(CuDanPtr& danhsach){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        cout << "(Chua co cu dan)" << endl;
        return;
    }
    CuDanPtr p = danhsach;
    while(p != NULL){
        if(p->lachuho){
            cout << "[Chu ho]: ";
        } 
        cout << p->hoten << " | "
             << p->cccd << " | "
             << p->sodienthoai << " | "
             << endl;
        p = p->link; 
    }
}

CuDanPtr TimTheoCCCD(CuDanPtr &danhsach, string cccd){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        return NULL;
    }
    CuDanPtr p = danhsach;
    while(p != NULL){
        if(p->cccd == cccd){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

CuDanPtr TimTheoChuHo(CuDanPtr& danhsach, string tenchuho){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        cout << "(Chua co cu dan)" << endl;
        return NULL;
    }
    CuDanPtr p = danhsach;
    while(p != NULL){
        if(p->hoten == tenchuho && p->lachuho){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

CuDanPtr TachCuDan(CuDanPtr& danhsach, string cccd){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        cout << "(Chua co cu dan)" << endl;
        return NULL;
    }
    CuDanPtr truoc = NULL;
    CuDanPtr p = danhsach;
    while(p != NULL){
        if(p->cccd == cccd){
            if(truoc == NULL){
                danhsach = p->link;
            } else{
                truoc->link = p->link;
            }
            p->link = NULL;
            return p;
        }
        p = p->link;
    }
    return NULL;
}

bool XoaCuDan(CuDanPtr &danhsach, string cccd){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        cout << "(Chua co cu dan)" << endl;
        return false;
    }
    CuDanPtr p = TachCuDan(danhsach, cccd);
    if(p == NULL){
        return false;
    }
    delete p;
    return true;
}

void GiaiPhongDanhSachCuDan(CuDanPtr &danhsach){
    while(danhsach != NULL){
        CuDanPtr danhsachtam = danhsach;
        danhsach = danhsach->link;
        delete danhsachtam;
    }
}
