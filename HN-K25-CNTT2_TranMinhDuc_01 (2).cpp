#include <stdio.h>
#include <math.h>
#define MAX 100

int main() {
    int arr[MAX];
    int n, choice;
    int i, j, temp, isPrime;
    int sum, indexAdd, valueAdd, indexDel, x, oddN, evenN;
    int minIndex = i;
    float avg;
    int flag08;

    do {
        printf("1. Nhap so luong va gia tri tung phan tu cho mang.\n");
        printf("2. In ra cac gia tri phan tu trong mang.\n");
        printf("3. In cac so la so nguyen to co trong mang.\n");
        printf("4. Tim gia tri nho nhat trong mang.\n");
        printf("5. Them moi mot phan tu vao vi tri cu the.\n");
        printf("6. Xoa phan tu tai vi tri bat ki trong mang.\n");
        printf("7. Sap xep mang theo thu tu tang dan.\n");
        printf("8. Kiem tra su ton tai cua phan tu co trong mang.\n");
        printf("9. In mang sao cho toan bo so le dung truoc, so chan dung sau.\n");
        printf("10.Sap xep mang theo thu tu nguoc lai.\n");
        printf("11.Thoat Menu.\n");
        printf("Moi ban chon option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so luong phan tu cua mang (toi da %d): ", MAX);
                scanf("%d", &n);
                if (n < 1 || n > MAX) {
                    printf("So luong phan tu khong hop le!\n");
                    n = 0;
                    break;
                }
                for (i = 0; i < n; i++) {
                    printf("Nhap phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                if (n == 0){
                    printf("Mang rong!\n");
                }else {
                    printf("Mang hien tai: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", arr[i]);
                    printf("\n");
                }
                break;

            case 3:
				if(n == 0){
					printf("Mang rong!\n");
				}else{
					printf("Cac phan tu trong hien tai la: ");
					for(i=0;i<n;i++){
						printf("%d ",arr[i]);
					}
					printf("Cac  phan tu la so nguyen to trong mang la: ");
					for(i=0;i<n;i++){
						if(arr[i]<2)
						continue;
						
						isPrime = 1;
						
						for(j=2;j<sqrt(arr[i]);j++){
							if(arr[i]%j==0){
								isPrime = 0;
								break;
							}
						}
						if(isPrime == 1){
							printf("%d",arr[i]);
						}
					}
				}
            
            case 4:
            	if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                    for (i = 0; i < n - 1; i++) {
                        for (j = i + 1; j < n; j++) {
                            if (arr[j] < arr[minIndex])
                                minIndex = j;
                        }
                        temp = arr[i];
                        arr[i] = arr[minIndex];
                        arr[minIndex] = temp;
                    }

                printf("Gia tri nho nhat trong mang: ");
                printf("%d ", arr[0]);
                printf("\n");
                break;

            case 5:
                printf("Nhap vi tri muon chen (0 -> %d): ", n);
                scanf("%d", &indexAdd);
                if (indexAdd < 0 || indexAdd > n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                printf("Nhap gia tri muon chen: ");
                scanf("%d", &valueAdd);
                for (i = n; i > indexAdd; i--)
                    arr[i] = arr[i - 1];
                arr[indexAdd] = valueAdd;
                n++;
                printf("Da chen thanh cong!\n");
                break;

            case 6:
                if (n == 0) {
                    printf("Mang rong, khong co gi de xoa!\n");
                    break;
                }
                printf("Nhap vi tri muon xoa (0 -> %d): ", n - 1);
                scanf("%d", &indexDel);
                if (indexDel < 0 || indexDel >= n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                for (i = indexDel; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
                printf("Da xoa phan tu o vi tri %d thanh cong!\n", indexDel);
                break;

            case 7:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                    for (i = 0; i < n - 1; i++) {
                        for (j = i + 1; j < n; j++) {
                            if (arr[j] < arr[minIndex])
                                minIndex = j;
                        }
                        temp = arr[i];
                        arr[i] = arr[minIndex];
                        arr[minIndex] = temp;
                    }

                printf("Mang sau khi sap xep tang dan: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 8:
                if (n == 0) {
                    printf("Mang rong, khong co gi de tim!\n");
                    break;
                }
                printf("Nhap gia tri muon tim kiem: ");
                scanf("%d", &x);
                flag08 = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == x) {
                        printf("Gia tri %d duoc tim thay tai vi tri arr[%d].\n", x, i);
                        flag08 = 1;
                    }
                }
                if (flag08 == 0)
                    printf("Khong tim thay gia tri %d trong mang.\n", x);
                break;

            case 9:
                printf("\nCac so chan la: ");
    			for (i = 0; i < n; i++) {
        			if (arr[i] % 2 == 0)
            		printf("%d ", arr[i]);
    }

    			printf("\nCac so le la: ");
    				for (i = 0; i < n; i++) {
        			if (arr[i] % 2 != 0)
            			printf("%d ", arr[i]);
    }

    			for (i = 0; i < n; i++) {
        		if (arr[i] % 2 == 0)
            	evenN++;
        		else
            	oddN++;
    }

			printf("\nTong so luong so chan la: %d", evenN);
    		printf("\nTong so luong so le la: %d", oddN);
            case 10: 
                for (i = 0; i < n / 2; i++) {
        		int j = n - 1 - i;
        		temp = arr[i];
        		arr[i] = arr[j];
        		arr[j] = temp;
    			}

    			printf("\nMang sau khi dao nguoc la: ");
    			for (i = 0; i < n; i++) {
       				printf("%d ", arr[i]);
    				}
                
            case 11:
                printf("Thoat Menu.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }

    } while (choice != 11);

    return 0;
}

