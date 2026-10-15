#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main(){
    if(!exists("bin")){
        cout << "Chưa có thư mục bin, đang tạo ..." << endl;
        create_directories("bin");
    }
    string cacfilecanbiendich = "src\\canho.cpp src\\cudan.cpp src\\hamphu.cpp src\\hoadon.cpp src\\main.cpp src\\saoluuvanapdulieu.cpp src\\thongke.cpp src\\menuvahamxuly.cpp";
    string lenhbiendich = "g++ " + cacfilecanbiendich + " -o " + " bin\\quanlychungcu.exe";
    system(lenhbiendich.c_str());
    system("bin\\quanlychungcu.exe");
    return 0;
}