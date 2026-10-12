#include <stdio.h>
#include <string.h>

#define MAX_PHIEU 50

int main() {
    char maPhieu[MAX_PHIEU][20] = {"PM101", "PM102", "PM103"};
    int ngayQuaHan[MAX_PHIEU] = {0, 3, 5};
    int soLuong = 3;
    int luaChon;

    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);
        while (getchar() != '\n');

        if (luaChon == 1) {
            printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
            printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
            printf("--------------------------------------------------\n");
            for (int i = 0; i < soLuong; i++) {
                long tienPhat = ngayQuaHan[i] * 5000;
                printf("%d | %s | %d ngay | %ld VND\n", i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
            }
            printf("--------------------------------------------------\n");
            printf("Tong so phieu: %d\n", soLuong);
            
        } else if (luaChon == 2) {
            if (soLuong >= MAX_PHIEU) {
                printf("Loi: Danh sach phieu muon da day, khong the them!\n");
            } else {
                printf("Nhap ma phieu muon moi: ");
                scanf("%19s", maPhieu[soLuong]);
                while (getchar() != '\n');
                
                ngayQuaHan[soLuong] = 0;
                soLuong++;
                printf("Them thanh cong!\n");
            }
            
        } else if (luaChon == 3) {
            char maTimKiem[20];
            printf("Nhap ma phieu muon can cap nhat: ");
            scanf("%19s", maTimKiem);
            while (getchar() != '\n');

            int timThay = -1;
            for (int i = 0; i < soLuong; i++) {
                if (strcmp(maPhieu[i], maTimKiem) == 0) {
                    timThay = i;
                    break;
                }
            }

            if (timThay != -1) {
                printf("Tim thay phieu muon '%s' tai vi tri index %d.\n", maTimKiem, timThay);
                int ngayMoi;
                do {
                    printf("Nhap so ngay qua han moi: ");
                    scanf("%d", &ngayMoi);
                    while (getchar() != '\n');
                    
                    if (ngayMoi < 0) {
                        printf("Loi: So ngay qua han phai >= 0. Vui long nhap lai!\n");
                    }
                } while (ngayMoi < 0);
                
                ngayQuaHan[timThay] = ngayMoi;
                printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n", maTimKiem, ngayMoi);
            } else {
                printf("Khong tim thay phieu muon co ma '%s'.\n", maTimKiem);
            }
            
        } else if (luaChon == 0) {
            printf("Thoat chuong trinh. Chao tam biet!\n");
        } else {
            printf("Lua chon khong hop le. Vui long chon lai!\n");
        }

    } while (luaChon != 0);

    return 0;
}