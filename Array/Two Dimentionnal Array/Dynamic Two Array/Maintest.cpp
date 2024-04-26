#include "DynamicTwoArray.h"

void ShowMenu(){
	printf("\t\t+---------------- Menu ----------------+\n");
	printf("\t\t| 1. Nhap ma tran so nguyen            |\n");
	printf("\t\t| 2. Tao ma tran so nguyen             |\n");
	printf("\t\t| 3. Load ma tran so nguyen            |\n");
	printf("\t\t| 4. Xuat va Ghi ma tran so nguyen     |\n");
	printf("\t\t| 5. Sap xep ma tran so nguyen         |\n");
	printf("\t\t| 6. Tong cac ptu thuoc tam giac tren  |\n");
	printf("\t\t| 0. Thoat chuong trinh                |\n");
	printf("\t\t+--------------------------------------+\n");
}
void Menu(){
	ArrPtr *a = NULL;
	int m = 0, n = 0, e, kq;
	int choose;
	char *fileIn = "input.txt";
	char *fileOut = "output.txt";
	do{
		system("cls");
		ShowMenu();
		printf("Nhap chuc nang: "); scanf("%d", &choose);
		
		switch (choose)
		{
		case 0:
			deleteArrayPoiter(a, m, n);
			break;
		case 1:
			NhapMang2ChieuSoNguyen(a, m, n);
			printf("MA TRAN VUA NHAP: \n");
			XuatMang2ChieuSoNguyen(a, m, n);
			getch();
			break;
		case 2:
			TaoMang2ChieuSoNguyen(a, m, n);
			printf("MA TRAN VUA TAO NGAU NHIEN: \n");
			XuatMang2ChieuSoNguyen(a, m, n);
			LietKeCacPhanTuLaSNT(a, m, n);
			getch();
			break;
		case 3:
			LoadMang2ChieuSoNguyen(fileIn, a, m, n);
			printf("MA TRAN VUA LOAD TU FILE: \n");
			XuatMang2ChieuSoNguyen(a, m, n);
			getch();
			break;
		case 4:
			printf("MA TRAN: \n");
			XuatMang2ChieuSoNguyen(a, m, n);
			GhiMang2ChieuSoNguyen(fileOut, a, m, n);
			getch();
			break;
		case 5:
			printf("NHAP SO COT CAN SAP XEP: "); NhapSoNguyenDuong(e);
			SapXepTrenMaTran(a, m, n, e);
			//XuatMang2ChieuSoNguyen(a, m, n);
			getch();
			break;
		case 6:
			kq = TinhTongCacPhanTuTamGiacTren(a, m, n);
			printf("TONG CAC PHAN TU THUOC TAM GIAC TREN: %d\n", kq);
			getch();
			break;
        case 7:
            printf("Cac gia tri duong tren duong cheo chinh: %d\n", DemSoDuongTrenDuongCheoChinh(a, m, n));
            getch();
            break;
        case 8:
            printf("Cac gia tri am tren duong cheo phu: %d\n", DemSoAmTrenDuongCheoPhu(a, m, n));
            getch();
            break;
		default:
			printf("Sai chuc nang. Vui long nhap lai !\n");
			getch();
			break;
		}
	} while (choose != 0);
}

int main(){
	Menu();
    // ArrPtr *a = NULL;
    // char *fileIn = "input.txt";
	// int m = 0, n = 0, e, kq;
    // LoadMang2ChieuSoNguyen(fileIn, a, m, n);
  

	return 0;
}