#include "thuvien/cudan.h"

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
    cout << "(?) Nhap ho ten: ";
    getline(cin, cudanmoi.hoten);
    cout << "(?) Nhap CCCD: "; 
    getline(cin, cudanmoi.cccd);
    cout << "(?) Nhap so dien thoai: "; 
    getline(cin, cudanmoi.sodienthoai);
    char lachuho;
    cout << "(?) La chu ho (y/n): "; 
    cin >> lachuho;
    if(lachuho == 'y') {
        cudanmoi.lachuho = true;
    } else {
        cudanmoi.lachuho = false;
    }
    return cudanmoi;
}

void NhapDanhSachCuDan(CuDanPtr &danhsach, int soluong){
    for(int i = 0; i < soluong; i++){
        cout << "Nhap cu dan thu " << i + 1 << endl;
        CuDan cudanmoi = NhapCuDan();
        CuDanPtr khoitaocudanmoi = KhoiTaoCuDan(cudanmoi);
        ThemCuoiDanhSachCuDan(danhsach, khoitaocudanmoi);
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
    while(p->link != NULL){
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
        cout << "(Chua co cu dan)" << endl;
        return NULL;
    }
    CuDanPtr p = danhsach;
    while(p->link != NULL){
        if(p->cccd == cccd){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

CuDanPtr TimTheoChuHo(CuDanPtr& danhsach, string tenchuho){
    if(!KiemTraRongDanhSachCuDan(danhsach)){
        cout << "(Chua co cu dan)" << endl;
        return NULL;
    }
    CuDanPtr p = danhsach;
    while(p->link != NULL){
        if(p->hoten == tenchuho && p->lachuho){
            return p;
        } else {
            cout << "(!) Nguoi nay khong phai chu ho !" << endl;
            return NULL;
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
    while(p->link != NULL){
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