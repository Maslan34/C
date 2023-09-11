#include <stdio.h>
#include <stdlib.h>
struct hasta{
	int no;
	char ad[50];
	int yas;
	char hastalik[30];
};

void hastaEkle(FILE*);
void kayitListele(FILE*);
void hastaNoAra(FILE*);
void kayitSil(FILE*);
void kayitDuzenle(FILE *);


int main() {
	int secim,i;
	FILE *hasta;
	struct hasta hastaBos={0,"",0,""};
	
	hasta=fopen("hasta.txt","w+");
	for(i=0;i<100;i++)
	{
		fwrite(&hastaBos,sizeof(struct hasta),1,hasta);
	}
	fclose(hasta);
	
	hasta=fopen("hasta.txt","r+");
	printf("1-Hasta ekleme \n2-hasta no arama\n3-kayit sil\n4-kayit duzenle\n5-kayitlari listele\n6-cikis\nislem?: ");
	scanf("%d",&secim);
	while(secim!=6){	

	switch(secim){
	
	case 1:hastaEkle(hasta);break;
	case 2:hastaNoAra(hasta);break;
	case 3:kayitSil(hasta);break;
	case 4:kayitDuzenle(hasta);break;
	case 5:kayitListele(hasta);break;
	case 6: break;
	}
	printf("\n1-hasta eklemek icin\n2-hasta no arama\n3-kayit sil\n4-kayit duzenle\n5-kayitlari listele\n6-cikis\nislem?: ");
	scanf("%d",&secim);
	}
	fclose(hasta);
	return 0;
}
void hastaEkle(FILE*hasta)
{
	int hastaNo,adet,i;
	struct hasta yeniKayit={0,"",0,""};
	printf("kac hasta eklenecek?\n");
	scanf("%d",&adet);
	for(i=0;i<adet;i++)
	{
	
	printf("eklenecek %d.hastanin no giriniz: ",i+1);
	scanf("%d",&hastaNo);
	fseek(hasta,(hastaNo-1)*sizeof(struct hasta),SEEK_SET);
	fread(&yeniKayit,sizeof(struct hasta),1,hasta);
	if(yeniKayit.no!=0)
	printf("bu kayit zaten mevcut");
	
	else
	{
		yeniKayit.no=hastaNo;
		printf("hasta adi girin: ");
		scanf("%s",yeniKayit.ad);
		printf("hastanin yasi girin: ");
		scanf("%d",&yeniKayit.yas);
		printf("hastanin hastalik sebebi girin: ");
		scanf("%s",yeniKayit.hastalik);
		fseek(hasta,(hastaNo-1)*sizeof(struct hasta),SEEK_SET);
		fwrite(&yeniKayit,sizeof(struct hasta),1,hasta);
	}
	
	}
	printf("\nislem tamamlandi...\n");
	
	rewind(hasta);

}
void hastaNoAra(FILE *hasta)
{
	int hastaNo;
	struct hasta hastaBilgi={0,"",0,""};
	
	printf("aranacak hastanin nosunu giriniz: ");
	scanf("%d",&hastaNo);
	fseek(hasta,sizeof(struct hasta)*(hastaNo-1),SEEK_SET);
	fread(&hastaBilgi,sizeof(struct hasta),1,hasta);
	
	printf("hastanin bilgileri: \n");
	
	printf("hastano: %d - hasta ad: %s - hasta yas : %d - hastalik sebebi: %s\n",hastaNo,hastaBilgi.ad,hastaBilgi.yas,hastaBilgi.hastalik);
	printf("\nislem tamamlandi...\n");
}

void kayitSil(FILE *hasta)
{
	int hastaNo;
	struct hasta bosHasta={0,"",0,""};
	printf("kaydi silinecek hastanin nosunu giriniz: ");
	scanf("%d",&hastaNo);
	fseek(hasta,sizeof(struct hasta)*(hastaNo-1),SEEK_SET);
	fwrite(&bosHasta,sizeof(struct hasta),1,hasta);
printf("\nislem tamamlandi...\n");	
}

void kayitDuzenle(FILE *hasta)
{
	
	int hastaNo;
	struct hasta YeniHasta={0,"",0,""};
	
	printf("Duzenlenecek hastanin nosunu giriniz: ");
	scanf("%d",&hastaNo);
	fseek(hasta,sizeof(struct hasta)*(hastaNo-1),SEEK_SET);
	YeniHasta.no=hastaNo;
	printf("hastanin yeni bilgilerini girin:\n");
	printf("ad: ");
	scanf("%s",YeniHasta.ad);
	printf("yas: ");
	scanf("%d",&YeniHasta.yas);
	printf("hastaligi: ");
	scanf("%s",YeniHasta.hastalik);
	fwrite(&YeniHasta,sizeof(struct hasta),1,hasta);
	printf("\nislem tamamlandi...\n");
}

void kayitListele(FILE *hasta)
{
	struct hasta hastaKontrol={0,"",0,""};
	rewind(hasta);
	printf("hasta no - hasta ad - hasta yas - hastalik sebebi\n");
	while(!feof(hasta))
	{
		fread(&hastaKontrol,sizeof(struct hasta),1,hasta);
		if(hastaKontrol.no!=0)
		printf("%d-%s-%3d-%s\n",hastaKontrol.no,hastaKontrol.ad,hastaKontrol.yas,hastaKontrol.hastalik);
	}
	printf("\nislem tamamlandi...\n");
}
