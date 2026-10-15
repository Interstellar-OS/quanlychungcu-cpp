#include "thuvien/canho.h"
#include "thuvien/cudan.h"
#include "thuvien/menuvahamxuly.h"

int main(){
    CanHoPtr danhsachcanho;
    KhoiTaoDanhSachCanHo(danhsachcanho);
    KhoiTaoDuLieuMau(danhsachcanho);

    int chon;
    while(true){
        system("cls");
        MenuChinh();
        chon = NhapSo("Chon: ");
        if(chon == 0) {
            cout << "Tam biet" << endl;
            break;
        }
        else if(chon == 1){
            XoaManHinh();
            XuLy1(danhsachcanho);
        }
        else if(chon == 2){
            XoaManHinh();
            XuLy2(danhsachcanho);
        }
        else if(chon == 3){
            XoaManHinh();
            XuLy3(danhsachcanho);
        }
        else if(chon == 4){
            XoaManHinh();
            XuLy4(danhsachcanho);
        }
        else if(chon == 5){
            XoaManHinh();
            XuLy5(danhsachcanho);
        }
        else if(chon == 6){
            XoaManHinh();
            XuLy6(danhsachcanho);
        }
        else if(chon == 7){
            XoaManHinh();
            XuLy7(danhsachcanho);
        }
        else if(chon == 8){
            XoaManHinh();
            XuLy8();
        }
        else if(chon == 9){
            XoaManHinh();
            XuLy9();
        }
        else if(chon == 10){
            XoaManHinh();
            XuLy10();
        }
        else if(chon == 11){
            XoaManHinh();
            XuLy11();
        }
        else{
            cout << "(!) Lua chon khong hop le !" << endl;
        }
        DungChuongTrinh();
    }

    GiaiPhongDanhSachCanHo(danhsachcanho);
    return 0;
}