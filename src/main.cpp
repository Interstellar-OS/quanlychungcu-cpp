#include "lib/canho.h"
#include "lib/cudan.h"
#include "lib/hamphu.h"
#include "lib/menuvahamxuly.h"
#include "lib/saoluuvanapdulieu.h"

int main(){
    CanHoPtr danhsachcanho;
    KhoiTaoDanhSachCanHo(danhsachcanho);
    if(!exists("data")){
        KhoiTaoDuLieuMau(danhsachcanho);
        // Gia lap cac can dang thue da o 1 nam va tao hoa don 12 thang gan nhat.
        KhoiTaoDanhSachHoaDonChoPhongDangThue(danhsachcanho);
        if(!LuuDuLieu(danhsachcanho)){
            cout << "(!) Khong the tao du lieu trong thu muc data" << endl;
            GiaiPhongDanhSachCanHo(danhsachcanho);
            return 1;
        }
    } else if(!NapDuLieu(danhsachcanho)){
        cout << "(!) Thu muc data ton tai nhung khong doc duoc du lieu" << endl;
        return 1;
    } else if(!LuuDuLieu(danhsachcanho)){
        cout << "(!) Khong the cap nhat dinh dang du lieu" << endl;
        GiaiPhongDanhSachCanHo(danhsachcanho);
        return 1;
    }

    system("cls");
    Banner();
    cout << "Thu muc du lieu: " << THUMUCGOC << endl;
    cout << "Du lieu duoc tu dong nap moi vong menu va tu dong luu sau moi thao tac" << endl;
    DungChuongTrinh();

    int chon;
    while(true){
        if(!NapDuLieu(danhsachcanho)){
            cout << "(!) Khong nap duoc du lieu tu thu muc data" << endl;
        }
        system("cls");
        MenuChinh();
        chon = NhapSo("Chon: ");
        if(chon == 0) {
            system("cls");
            BannerTamBiet();
            break;
        }
        else if(chon == 1){
            XoaManHinh();
            XuLyMenu1(danhsachcanho);
        }
        else if(chon == 2){
            XoaManHinh();
            XuLyMenu2(danhsachcanho);
        }
        else if(chon == 3){
            XoaManHinh();
            XuLyMenu3(danhsachcanho);
        }
        else if(chon == 4){
            XoaManHinh();
            XuLyMenu4(danhsachcanho);
        }
        else if(chon == 5){
            XoaManHinh();
            XuLyMenu5(danhsachcanho);
        }
        else if(chon == 6){
            XoaManHinh();
            XuLyMenu6(danhsachcanho);
        }
        else if(chon == 7){
            XoaManHinh();
            XuLyMenu7(danhsachcanho);
        }
        else if(chon == 8){
            XoaManHinh();
            XuLyMenu8(danhsachcanho);
        }
        else if(chon == 9){
            XoaManHinh();
            XuLyMenu9(danhsachcanho);
        }
        else if(chon == 10){
            XoaManHinh();
            XuLyMenu10(danhsachcanho);
        }
        else{
            cout << "(!) Lua chon khong hop le !" << endl;
        }
        if(chon != 0 && !LuuDuLieu(danhsachcanho)){
            cout << "(!) Tu dong luu du lieu that bai" << endl;
        }
        DungChuongTrinh();
    }

    GiaiPhongDanhSachCanHo(danhsachcanho);
    return 0;
}
