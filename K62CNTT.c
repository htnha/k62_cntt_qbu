// C program for writing
// struct to file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int DEBUG = 0;
void debug(char* message){
    if (DEBUG == 1){
        printf("%s\n",message);
    }
}



// a struct to read and write
struct tt
{
    char ten[20];
    float gia;
    char mvc[20];
    float p;
    float q;
    char diachi[20];
    char ngaygui[20];
    char ngaynhan[20];

} donhang;

void nhap()
{
    printf( "\n Nhap ten: "); fflush(stdin); gets(donhang.ten);
    printf( " Nhap gia: "); scanf("%f", &donhang.gia);
    printf( " Nhap ma van chuyen: "); fflush(stdin); gets(donhang.mvc);
    printf( " Nhap trong luong: "); scanf("%f", &donhang.p);
    donhang.q=donhang.gia*donhang.p;
    printf( " Phi van chuyen la: %f\n", donhang.q);
    printf( " Nhap dia chi: "); fflush(stdin); scanf("%s",donhang.diachi);
    printf( " Nhap ngay gui: "); fflush(stdin); scanf("%s",donhang.ngaygui);
    printf(" Nhap ngay nhan: "); fflush(stdin); scanf("%s",donhang.ngaynhan);
}
void gi(char danhsach[])
{
    FILE * fptr;
    fptr=fopen("donghang.txt","w");

    debug("Da moi file");

    fprintf(fptr,"%s", donhang.ten);
    fprintf(fptr,"\t");
    fprintf(fptr,"%f", donhang.gia);
    fprintf(fptr,"\t");
    fprintf(fptr,"%s", donhang.mvc);
    fprintf(fptr,"\t");
    fprintf(fptr,"%f", donhang.p);
    fprintf(fptr,"\t");
    fprintf(fptr,"%f", donhang.q);
    fprintf(fptr,"\t");
    fprintf(fptr,"%s", donhang.diachi);
    fprintf(fptr,"\t");
    fprintf(fptr,"%s", donhang.ngaygui);
    fprintf(fptr,"\t");
    fprintf(fptr,"%s", donhang.ngaynhan);
    fprintf(fptr,"\n");
    fclose(fptr);
    debug("Da dong file");
}

int main ()
{
    char danhsach[]="donhang.txt";
    nhap();
    gi(danhsach);

    FILE *f2;
    char * line = NULL;
    size_t len=0;
    ssize_t read;
    f2=fopen("/Users/mac/CLionProjects/ReadFile/cmake-build-debug/donghang.txt", "r");
    if(f2 == NULL) {
        printf("File bi null");
        exit(1);
    }
    while ((read = getline(&line, &len, f2 )) != -1)
    {
        printf("--------%zu:\n",read);
        printf("%s",line);
    }

    fclose (f2);
    return 0;
}
