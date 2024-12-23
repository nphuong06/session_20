#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Books{
	int id;
	char name[50];
	char author[50];
	float price;
};
void addBooks(struct Books *b, int *size){
	printf("\n");
	for(int i = 0; i < *size; i++){
		printf("Nhap ID sach: ");
		scanf("%d", &b[i].id);
		fflush(stdin);
		printf("Nhap ten sach: ");
		fgets(b[i].name, 50, stdin);
		b[i].name[strlen(b[i].name) - 1] = '\0';
		printf("Nhap ten tac gia: ");
		fgets(b[i].author, 50, stdin);
		b[i].author[strlen(b[i].author)- 1] = '\0';
		printf("Nhap gia: ");
		scanf("%f", &b[i].price);
		printf("\n");
	}
}
void printBooks(struct Books *b, int *sizePtr){
	printf("\nCac loai sach hien co:\n");
	printf("--------------------\n");
	for(int i = 0; i < (*sizePtr); i++){
		printf("ID: %d", b[i].id);
		printf("\nTen sach: %s", b[i].name);
		printf("\nTac gia: %s", b[i].author);
		printf("\nGia tien: %.2f", b[i].price);
		printf("\n--------------------\n");
	}
	printf("\n");
}
void newBooks(struct Books *b, int *sizePtr){
	int index;
	printf("\nNhap vi tri muon them sach (0 -> %d): ", *sizePtr);
	scanf("%d", &index);
	if(index < 0 || index > *sizePtr){
		printf("\nVi tri them sach khong hop le\n\n");
	}
	else{
		(*sizePtr)++;
		b = realloc(b, (*sizePtr)* sizeof(struct Books));
		for(int i = (*sizePtr); i > index; i--){
			b[i] = b[i-1];
		}
		printf("\nNhap ID: ");
		scanf("%d", &b[index].id);
		fflush(stdin);
		printf("Nhap ten sach: ");
		fgets(b[index].name, 50, stdin);
		b[index].name[strlen(b[index].name) - 1] = '\0';
		printf("Nhap ten tac gia: ");
		fgets(b[index].author, 50, stdin);
		b[index].author[strlen(b[index].author) - 1] = '\0';
		printf("Nhap gia tien: ");
		scanf("%f", &b[index].price);
		printf("\n");
	}
}
void deleteBooks(struct Books *b, int *sizePtr){
	int id, found = 0;
	printf("\nNHap ID sach can xoa: ");
	scanf("%d", &id);
	for(int i = 0; i < (*sizePtr); i++){
		if(id == b[i].id){
			found = 1;
			for(int j = i; j < (*sizePtr) - 1; j++){
				b[j] = b[j+1];
			}
		break;
		}
	}
	if(found == 0){
		printf("\nID sach khong ton tai\n\n");
	}
	else{
		(*sizePtr)--;
		printf("\nXoa thanh cong\n\n");
	}
}
void editBooks(struct Books *b, int *sizePtr){
	int id, found = 0;
	printf("\nNhap ID can chinh sua: ");
	scanf("%d", &id);
	fflush(stdin);
	for(int i = 0; i < (*sizePtr); i++){
		if(id == b[i].id){
			found = 1;
			printf("\nNhap ten sach: ");
			fgets(b[i].name, 50, stdin);
			b[i].name[strlen(b[i].name) - 1] = '\0';
			printf("Nhap ten tac gia: ");
			fgets(b[i].author, 50, stdin);
			b[i].author[strlen(b[i].author) - 1] = '\0';
			printf("Nhap gia: ");
			scanf("%f", &b[i].price);
		}
	}
	if(found == 0){
		printf("\nID sach khong ton tai\n\n");
	}
	else{
		printf("\nChinh sau thanh cong\n\n");
	}
}
void sortByPrice(struct Books *b, int *sizePtr){
	char choice;
	printf("\na. Tang dan\n");
	printf("\nb. Giam dan\n\n");
	fflush(stdin);
	scanf("%c", &choice);
	switch(choice){
		case 'a':
			for(int i = 0; i < (*sizePtr) - 1; i++){
				for(int j = 0; j < (*sizePtr) - i - 1; j++){
					if(b[j].price > b[j+1].price){
						struct Books temp = b[j];
						b[j] = b[j+1];
						b[j+1] = temp;
					}
				}
			}
			printf("\nSap xep hoan tat\n\n");
			break;
		case 'b':
			for(int i = 0; i < (*sizePtr) - 1; i++){
				for(int j = 0; j < (*sizePtr) - i- 1; j++){
					if(b[j].price < b[j+1].price){
						struct Books temp = b[j];
						b[j] = b[j+1];
						b[j+1] = temp;
					}
				}
			}
			printf("\nsap xep thanh cong\n\n");
			break;
		default:
			printf("\nChuc nang nhap khong hop le\n\n");
			break;
	}
}
void searchByName(struct Books *b, int *sizePtr){
	char *name;
	int found = 0;
	name = (char *)calloc(50, sizeof(char));
	printf("\nNhap ten sach: ");
	fflush(stdin);
	fgets(name, 50, stdin);
	name[strlen(name) - 1] = '\0';
	for(int i = 0; i < (*sizePtr); i++){
		if(strstr(b[i].name, name) != NULL){
			printf("\nID: %d", b[i].id);
			printf("\nTen sach: %s", b[i].name);
			printf("\nTen tac gia: %s", b[i].author);
			printf("\nGia tien: %.2f", b[i].price);
			printf("\n");
			found = 1;
		}
	}
	printf("\n");
	if(found == 0){
		printf("\nTen sach khong ton tai\n\n");
	}
	free(name);
}
void checkBooks(struct Books *b, int *sizePtr, int choice){
	if((*sizePtr) == 0){
		printf("\nChua them sach vao thu vien\n\n");
	}
	else{
		switch(choice){
			case 2:
				printBooks(b, sizePtr);
				break;
			case 3:
				newBooks(b, sizePtr);
				break;
			case 4:
				deleteBooks(b, sizePtr);
				break;
			case 5:
				editBooks(b, sizePtr);
				break;
			case 6:
				sortByPrice(b, sizePtr);
				break;
			case 7:
				searchByName(b, sizePtr);
				break;
		}
	}
}
int main(){
	int size = 0, choice;
 	int *sizePtr = &size;
	struct Books *b = (struct Books*)calloc(size, sizeof(struct Books));
	do{
		printf("1. Nhap so luong va thong tin sach\n");
		printf("2. Hien thi thong tin sach\n");
		printf("3. Them sach vao vi tri\n");
		printf("4. Xoa sach theo ma\n");
		printf("5. Cap nhap thong tin theo ma sach\n");
		printf("6. Sap xep theo gia\n");
		printf("7. Tim kiem sach theo ten\n");
		printf("8. Thoat\n");
		printf("Nhap chuc nang: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nNhap so luong: ");
				scanf("%d", &size);
				if(size <= 0){
					printf("\nNhap khong hop le\n\n");
				}
				else{
					b = realloc(b, size * sizeof(struct Books));
					addBooks(b, &size);
				}
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				checkBooks(b, sizePtr, choice);
				break;
			case 8:
				printf("\nThoat thanh cong\n");
				break;
			default:
				printf("\nChuc nang khong hop le\n\n");
				break;
		}
	}
	while(choice != 8);
	free(b);
	return 0;
}

