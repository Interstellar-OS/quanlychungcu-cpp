// Các hàm phụ

#ifndef HAMPHU_H
#define HAMPHU_H

#include "thuvienchung.h"
#include "canho.h"
#include "cudan.h"

int NhapSo(string loinhac);
string NhapChuoi(string loinhac);
void DungChuongTrinh();
void XoaManHinh();
void ThemCanHoMau(CanHoPtr& danhsachcanho, string tencanho, int tang);
void ThemCuDanMau(CanHoPtr& danhsachcanho, string tencanho, string hoten, string cccd, string sodienthoai, bool lachuho);
void KhoiTaoDuLieuMau(CanHoPtr& danhsachcanho);

#endif