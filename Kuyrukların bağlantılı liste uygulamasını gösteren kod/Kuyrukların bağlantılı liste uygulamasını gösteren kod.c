#include <stdio.h>
#include <stdlib.h>

struct DugumDegeri {
    int veriDegeri;
    struct DugumDegeri* sonraki;
};

struct DugumDegeri* ilkDugumDegeri = NULL;

void kuyrugaElemanEkleme(int veriDegeri) {
    struct DugumDegeri* yeniDugumDegeri = (struct DugumDegeri*)malloc(sizeof(struct DugumDegeri));
    yeniDugumDegeri->veriDegeri = veriDegeri;
    yeniDugumDegeri->sonraki = ilkDugumDegeri;
    ilkDugumDegeri = yeniDugumDegeri;
    printf("Girmis oldugunuz %d degeri kuyruga eklendi.\n\n", veriDegeri);
}

void kuyruktanElemanSilme() {
    if (ilkDugumDegeri == NULL) {
        printf("Kuyruk bos oldugu icin islem gerceklestirelemedi.Lutfen tekrar deneyiniz.\n");
        return;
    }
    struct DugumDegeri* sonDugumDegeri = ilkDugumDegeri;
    struct DugumDegeri* oncekiDugumDegeri = NULL;
    while (sonDugumDegeri->sonraki != NULL) {
        oncekiDugumDegeri = sonDugumDegeri;
        sonDugumDegeri = sonDugumDegeri->sonraki;
    }
    if (oncekiDugumDegeri == NULL) {
        ilkDugumDegeri = NULL;
    } else {
        oncekiDugumDegeri->sonraki = NULL;
    }
    printf("%d degeri kuyruktan silindi.\n\n", sonDugumDegeri->veriDegeri);
    free(sonDugumDegeri);
}

void kuyruktaElemanGoruntuleme() {
    if (ilkDugumDegeri == NULL) {
        printf("Kuyrukta hicbir eleman yok.Kuyruk bos.\n\n");
        return;
    }
    struct DugumDegeri* DugumDegeri = ilkDugumDegeri;
    printf("Kuyruktaki elemanlar: ");
    while (DugumDegeri != NULL) {
        printf("%d ", DugumDegeri->veriDegeri);
        DugumDegeri = DugumDegeri->sonraki;
    }
    printf("\n\n");
}

int main() {
    int secenek, veriDegeri;
    printf("Yapmak istediginiz secenegi seciniz:\n\n");
    while (1) {
        printf("1-Yeni bir eleman ekle\n2-Kuyruktan eleman sil\n3-Kuyrukta olan elemanlari goster\n4-Programdan cikis yap\n");
        printf("Seciminiz:");
        scanf("%d", &secenek);
        switch (secenek) {
            case 1:
                printf("Eklenecek elemani girin: ");
                scanf("%d", &veriDegeri);
                kuyrugaElemanEkleme(veriDegeri);
                break;
            case 2:
                kuyruktanElemanSilme();
                break;
            case 3:
                kuyruktaElemanGoruntuleme();
                break;
            case 4:
            	printf("Programdan cikis yapildi.");
                return 0;
            default:
                printf("Gecersiz bir tuslama yaptiniz.Lutfen tekrar deneyiniz.\n\n");
                break;
        }
    }
    return 0;
} 
