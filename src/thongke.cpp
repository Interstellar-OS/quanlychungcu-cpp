#include "lib/thongke.h"

void ThongKeCanHo(CanHoPtr& danhsachcanho){
    int socantrong = 0;
    int socandangthue = 0;
    CanHoPtr p = danhsachcanho;
    while(p != NULL){
        if(p->trangthai == "Dang thue"){
            socandangthue++;
        } else {
            socantrong++;
        }
        p = p->link;
    }
    cout << "So can trong: " << socantrong << endl;
    cout << "So can dang thue: " << socandangthue << endl;
}

void ThongKeCuDan(CanHoPtr& danhsachcanho){
    int tongsocudan = 0;
    CanHoPtr p = danhsachcanho;
    while(p != NULL){
        CuDanPtr cudan = p->danhsachcudan;
        while(cudan != NULL){
            tongsocudan++;
            cudan = cudan->link;
        }
        p = p->link;
    }
    cout << "Tong so cu dan: " << tongsocudan << endl;
}

void ThongKeDoanhThu(CanHoPtr& danhsachcanho){
    double tongtienhoadon = 0;
    double tongtiendathu = 0;
    CanHoPtr p = danhsachcanho;
    while(p != NULL){
        HoaDonPtr hoadon = p->danhsachhoadon;
        while(hoadon != NULL){
            tongtienhoadon += hoadon->tongtien;
            if(hoadon->dadongtien){
                tongtiendathu += hoadon->tongtien;
            }
            hoadon = hoadon->link;
        }
        p = p->link;
    }
    cout << fixed << setprecision(0);
    cout << "Tong tien hoa don: " << tongtienhoadon << " VND" << endl;
    cout << "Tong doanh thu da thu: " << tongtiendathu << " VND" << endl;
}
