#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Shop{
	int id;
	char name[100];
	float importPrice, sellingPrice;
	int quantity;
};
void addProduct(struct Shop *s, int *size, float *revenuePtr){
	printf("\nNhap ID san pham: ");
	scanf("%d", &s[(*size) - 1].id);
	fflush(stdin);
	printf("Nhap ten san pham: ");
	fgets(s[(*size) - 1].name, 100, stdin);
	s[(*size) - 1].name[strlen(s[(*size) - 1].name) - 1] = '\0';
	printf("Nhap gia nhap: ");
	scanf("%f", &s[(*size) - 1].importPrice);
	printf("Nhap gia ban: ");
	scanf("%f", &s[(*size) - 1].sellingPrice);
	printf("Nhap so luong: ");
	scanf("%d", &s[(*size) - 1].quantity);
	printf("\n");
}
void printProduct(struct Shop *s, int *sizePtr){
	printf("\nCac san pham hien co\n");
	printf("--------------------\n");
	for(int i = 0 ; i < *sizePtr; i++){
		printf("ID: %d", s[i].id);
		printf("\nTen san pham: %s", s[i].name);
		printf("\nGia ban: %.2f", s[i].sellingPrice);
		printf("\nSo luong: %d", s[i].quantity);
		printf("\n--------------------\n");
	}
}
void editProduct(struct Shop *s, int *size){
	int id, found = 0;
	printf("\nNhap ID san pham can chinh sua: ");
	scanf("%d", &id);
	fflush(stdin);
	for(int i = 0; i < *size; i++){
		if(id == s[i].id){
			printf("\nNhap ten san pham: ");
			fgets(s[i].name, 100, stdin);
			s[i].name[strlen(s[i].name)- 1] ='\0';
			printf("\nNhap gia nhap: ");
			scanf("%f", &s[i].importPrice);
			printf("\nNhap gia ban: ");
			scanf("%f", &s[i].sellingPrice);
			printf("\nNhap so luong: ");
			scanf("%d", &s[i].quantity);
			found = 1;
		}
	}
	if(found == 0){
		printf("\nSan pham khong ton tai\n\n");
	}
	else{
		printf("\nSua hoan tat\n\n");
	}
}
void sortByPrice(struct Shop *s, int *size){
	char sortPrice;
	printf("\na. Tang dan\n");
	printf("\nb. Giam dan\n\n");
	fflush(stdin);
	scanf("%c", &sortPrice);
	switch(sortPrice){
		case 'a':
			for(int i = 0; i < *size - 1; i++){
				for(int j = 0; j < *size - i - 1; j++){
					if(s[j].sellingPrice > s[j+1].sellingPrice){
						struct Shop temp = s[j];
						s[j] = s[j+1];
						s[j+1] = temp;
					}
				}
			}
			printf("\nSap xep hoan tat\n\n");
			break;
		case 'b':
			for(int i = 0; i < *size - 1; i++){
				for(int j = 0; j < *size - i - 1; j++){
					if(s[j].sellingPrice < s[j+1].sellingPrice){
						struct Shop temp = s[j];
						s[j] = s[j+1];
						s[j+1] = temp;
					}
				}
			}
			printf("\nSap xep hoan tat\n\n");
			break;
		default:
			printf("\nChuc nang khong hop le\n\n");
			break;
	}
}
void searchProduct(struct Shop *s, int *size){
	int id, found = 0;
	printf("\nNhap ID san pham: ");
	scanf("%d", &id);
	for(int i = 0; i < *size; i++){
		if(id == s[i].id){
			printf("\nID: %d", s[i].id);
			printf("\nTen san pham: %s", s[i].name);
			printf("\nGia nhap : %.2f", s[i].importPrice);
			printf("\nGia ban: %.2f", s[i].sellingPrice);
			printf("\nSo luong: %d", s[i].quantity);
			printf("\n\n");
			found = 1;
		}
	}
	if(found == 0){
		printf("\nID khong ton tai\n\n");
	}
}
void sellProduct(struct Shop *s, int *size, float *revenuePtr){
	int id, found = 0, quantity;
	printf("\nNhap ID san bam muon ban: ");
	scanf("%d", &id);
	for(int i = 0; i < *size; i++){
		if(id == s[i].id){
			found = 1;
			printf("\nNhap so luong san pham: ");
			scanf("%d", &quantity);
			if(s[i].quantity <= 0){
				printf("\nSan pham da het vui long nhap them\n\n");
			}
			else if(quantity > s[i].quantity){
				printf("\nKhong du so san pham\n\n");
			}
			else{
				(*revenuePtr) += quantity * s[i].sellingPrice;
				s[i].quantity -= quantity;
				printf("\nBan thanh cong\n\n");
			}
		}
	}
	if(found == 0){
		printf("\nID san pham khong ton tai\n\n");
	}
}
void checkProduct(struct Shop *s, int *size, float *revenuePtr, int choice){
	if((*size) == 0){
		printf("\nKhong co san pham nao ton tai\n\n");
	}
	else{
		switch(choice){
			case 2:
				printProduct(s, size);
				break;
			case 3:
				break;
			case 4:
				editProduct(s, size);
				break;
			case 5:
				sortByPrice(s, size);
				break;
			case 6:
				searchProduct(s, size);
				break;
			case 7:
				sellProduct(s, size, revenuePtr);
				break;
		}
	}
}
int main(){
	float revenue = 0;
	float *revenuePtr = &revenue;
	int choice, size = 0;
	int *sizePtr = &size;
	struct Shop *s = (struct Shop *)calloc(0, sizeof(struct Shop));
	do{
		printf("1. Nhap so luong va thong tin san pham\n");
		printf("2. Hien thi danh sach san pham\n");
		printf("3. Nhap san pham\n");
		printf("4. Cap nhat thong tin san pham\n");
		printf("5. Sap xep theo gia\n");
		printf("6. Tim kiem san pham\n");
		printf("7. Ban san pham\n");
		printf("8. Doanh thu hien tai\n");
		printf("9. Thoat\n");
		printf("Nhap chuc nang: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				(*sizePtr)++;
				s = realloc(s, (*sizePtr)*sizeof(struct Shop));
				addProduct(s, sizePtr, revenuePtr);
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				checkProduct(s, sizePtr, revenuePtr, choice);
				break;
			case 8:
				printf("\nDoanh thu cua ban la: %.2f\n\n", revenue);
				break;
			case 9:
				printf("\nThoat thanh cong\n\n");
				break;
			default:
				printf("\nChuc nang khong ton tai\n\n");
				break;
		}
	}
	while(choice != 9);
	free(s);
	return 0;
}

