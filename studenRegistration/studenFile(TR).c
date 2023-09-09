#include <stdio.h>
#include <stdlib.h>


struct ogrenci{
	int no;
	char ad[50];
	char bolum[30];
};

void ogrenciEkle(FILE*);
void kayitDuzenle(FILE*);
void ogrenciAra(FILE*);
void kayitSil(FILE*);
void kayitListele(FILE*);
void kayitDegis(FILE *);

struct ogrenci ogrenciBos={0,"",""};

int main(int argc, char *argv[]) {
	
	int secim,i;
	FILE *ogrenciptr;

	if((ogrenciptr=fopen("ogrenci.txt","w"))==NULL)
	printf("dosya acilamadi...");
	for(i=1;i<=100;i++)
	{
		fwrite(&ogrenciBos,sizeof(struct ogrenci),1,ogrenciptr);
	}
	
	fclose(ogrenciptr);
	
	ogrenciptr=fopen("ogrenci.txt","r+");
	printf("1-ogrenci eklemek icin\n2-ogrenci no arama\n3-kayit sil\n4-kayit duzenle\n5-kayitlari listele\n6-kayit yer degistirme\n7-cikis\nislem?: ");
	scanf("%d",&secim);
	
	while(secim!=7)
	{
	
	switch(secim){
	
	case 1:ogrenciEkle(ogrenciptr);break;
	case 2:ogrenciAra(ogrenciptr);break;
	case 3:kayitSil(ogrenciptr);break;
	case 4:kayitDuzenle(ogrenciptr);break;
	case 5:kayitListele(ogrenciptr);break;
	case 6:kayitDegis(ogrenciptr);break;
	}
	printf("1-ogrenci eklemek icin\n2-ogrenci no arama\n3-kayit sil\n4-kayit duzenle\n5-kayitlari listele\n6-kayit yer degistirme\n7-cikis\nislem?: ");
	scanf("%d",&secim);
	}
	fclose(ogrenciptr);
	
	return 0;
}
void ogrenciEkle(FILE*ogrenciptr)
{
	int ogrenciNo,adet,i;
	struct ogrenci yeniKayit={0,"",""};
	printf("kac ogrenci eklenecek?\n");
	scanf("%d",&adet);
	
	for(i=0;i<adet;i++)
	{
		printf("eklenecek %d.ogrencinin nosunu giriniz: ",i+1);
		scanf("%d",&ogrenciNo);
		fseek(ogrenciptr,(ogrenciNo-1)*sizeof(struct ogrenci),SEEK_SET);	
		fread(&yeniKayit,sizeof(struct ogrenci),1,ogrenciptr);
		if(yeniKayit.no!=0){
		printf("bu kayit zaten mevcut");
		}	
		else
		{
			
			yeniKayit.no=ogrenciNo;
			printf("ogrenci adi girin: ");
			scanf("%s",yeniKayit.ad);
			printf("ogrenci bolumu girin: ");
			scanf("%s",yeniKayit.bolum);
		
			fseek(ogrenciptr,(ogrenciNo-1)*sizeof(struct ogrenci),SEEK_SET);
			fwrite(&yeniKayit,sizeof(struct ogrenci),1,ogrenciptr);
		}
	}
	
}
void ogrenciAra(FILE *ogrenciptr)
{
	int ogrenciNo;
	
	struct ogrenci ogrenciKontrol={0,"",""};
	printf("aranacak ogrencinin nosunu giriniz: ");
	scanf("%d",&ogrenciNo);
	
	
		fseek(ogrenciptr,((ogrenciNo-1)*sizeof(struct ogrenci)),SEEK_SET);
		fread(&ogrenciKontrol,sizeof(struct ogrenci),1,ogrenciptr);
	
		if(ogrenciKontrol.no==ogrenciNo)
		{
			printf("ogrencinin bilgileri: \n");	
			printf("%d - %s - %s",ogrenciKontrol.no,ogrenciKontrol.ad,ogrenciKontrol.bolum);
		}
		else
		printf("ogrenci bulunamadi...");
		rewind(ogrenciptr);
	
}
void kayitListele(FILE *ogrenciptr)
{
	rewind(ogrenciptr);
	struct ogrenci ogrenciBos={0,"",""};
	printf("ogrenci no - ogrenci ad - ogrenci bolum\n");
	while(!feof(ogrenciptr))
	{
		fread(&ogrenciBos,sizeof(struct ogrenci),1,ogrenciptr);
		if(ogrenciBos.no!=0)
		printf("%d - %s - %s",ogrenciBos.no,ogrenciBos.ad,ogrenciBos.bolum);
		
	}
	printf("\nislem tamamlandi...\n");
	
}

void kayitDuzenle(FILE *ogrenciptr)
{
	
	int ogrenciNo;
	rewind(ogrenciptr);
	
	printf("Duzenlenecek ogrenci nosunu giriniz: ");
	scanf("%d",&ogrenciNo);
	
	
		fseek(ogrenciptr,(ogrenciNo-1)*sizeof(struct ogrenci),SEEK_SET);
		fread(&ogrenciBos,sizeof(struct ogrenci),1,ogrenciptr);
		if(ogrenciBos.no==ogrenciNo)
		{
			fseek(ogrenciptr,(ogrenciNo-1)*sizeof(struct ogrenci),SEEK_SET);//!read yaptýðýn için bir adým kaydý dikkat et1!!!!
			printf("ogrencinin yeni bilgilerini girin:\n");
			printf("ad: ");
			scanf("%s",ogrenciBos.ad);
			printf("bolum: ");
			scanf("%s",ogrenciBos.bolum);
			
			fwrite(&ogrenciBos,sizeof(struct ogrenci),1,ogrenciptr);
		}
		else
		printf("aradiginiz ogrenci kayitli degil...");
		
	
	rewind(ogrenciptr);
	printf("\nislem tamamlandi...\n");
}

void kayitSil(FILE *ogrenciptr)
{
	int ogrenciNo;
	struct ogrenci bosOgrenci={0,"",""};
	printf("kaydi silinecek hastanin nosunu giriniz: ");
	scanf("%d",&ogrenciNo);
	fseek(ogrenciptr,sizeof(struct ogrenci)*(ogrenciNo-1),SEEK_SET);
	fwrite(&bosOgrenci,sizeof(struct ogrenci),1,ogrenciptr);
	printf("\nislem tamamlandi...\n");
}
void kayitDegis(FILE *ogrenciptr)
{
	int no1,no2;
	
	struct ogrenci bos1={0,"",""},bos2={0,"",""};
	
	printf("lutfen degistirmek istediginiz ogrencinin nosunu giriniz: ");
	scanf("%d",&no1);
	
	printf("lutfen degistirmek istediginiz 2.ogrencinin nosunu giriniz: ");
	scanf("%d",&no2);
	
	fseek(ogrenciptr,sizeof(struct ogrenci)*(no1-1),SEEK_SET);
	fread(&bos1,sizeof(struct ogrenci),1,ogrenciptr);
	
	fseek(ogrenciptr,sizeof(struct ogrenci)*(no2-1),SEEK_SET);
	fread(&bos2,sizeof(struct ogrenci),1,ogrenciptr);
	
	fseek(ogrenciptr,sizeof(struct ogrenci)*(no1-1),SEEK_SET);
	fwrite(&bos2,sizeof(struct ogrenci),1,ogrenciptr);
	
	fseek(ogrenciptr,sizeof(struct ogrenci)*(no2-1),SEEK_SET);
	fwrite(&bos1,sizeof(struct ogrenci),1,ogrenciptr);
	
	printf("islem tamamlandi...");
}

