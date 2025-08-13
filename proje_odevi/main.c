#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdarg.h>
#include <time.h>

#define MAX 100

//char isim[],char calgi[],int *guc,int *ceviklik,int *dayaniklilik,int *karizma,int *toplayicilik,int *can,int *tokluk,int *uyku,int *hijyen,int *eglence,int *moral,int *para,int *tecrube,int *seviye

void sarki_soyle(char isim[],char calgi[],int* uyku,int* eglence,int* tokluk,int *akil)//uyku
{
    printf("%s tum gece ates basinda %s'yi kullanarak sarki soyluyor...\n\n",isim,calgi);

    (*uyku)=(*uyku)+50;
    (*eglence)=(*eglence)+30;
    (*tokluk)=(*tokluk)-40;
    (*akil)+=40;

    if(*tokluk<=0)
    {
        *tokluk=0;
        printf("%s'nin karni ac.",isim);
    }

    kontrol(3,uyku,eglence,akil);

    printf("\n\nDegisen Degerler:\n\nUyku: %d\nEglence: %d\nTokluk: %d\n",*uyku,*eglence,*tokluk);
    printf("%s koye geri donuyor...",isim);
    Sleep(4000);

    return;
}

void nehirde_yikan(char isim[],int *hijyen,int *uyku,int *tokluk) //uyku tokluk hijyen
{
    printf("%s nehirde yikanmaya karar veriyor.",isim);

    (*hijyen)=(*hijyen)+50;
    (*uyku)=(*uyku)+20;
    (*tokluk)=(*tokluk)-20;

    if(*tokluk<=0)
    {
        *tokluk=0;
        printf("%s cok ac.",isim);
    }


    kontrol(2,hijyen,uyku);

    printf("Degisen Degerler:\n\nHijyen: %d\nUyku: %d\nTokluk: %d\n",*hijyen,*uyku,*tokluk);
    printf("%s koye geri donuyor...",isim);
    Sleep(4000);

    return;

}

void cadirda_uyu(char isim[],int *uyku,int *tokluk) //uyku
{
    printf("%s cadirda uyumaya karar veriyor.\n\n",isim);

    (*uyku)-=50;
    (*tokluk)-=50;

    kontrol(2,uyku,tokluk);

    printf("Degisen Degerler:\n\nUyku: %d\nTokluk: %d\n",*uyku,*tokluk);
    printf("%s koye geri donuyor...",isim);
    Sleep(4000);

    return;
}

void koye_don(char isim[],int *tokluk,int *uyku,int *eglence)
{
    printf("\n\n%s ne yapacagina karar veremedigi icin koyune geri donuyor.\nBu durum %s'yi pek mutlu etmemis gibi.",isim,isim);

    (*tokluk)-=50;
    (*uyku)-=50;
    (*eglence)-=20;

    //tum degerler azaldigi icin kontrol fonksiyonuna gerek yok.
    if(*tokluk<=0)
    {
        *tokluk=0;
        printf("\n%s'nin karni ac.",isim);
    }

    if(*uyku<=0)
    {
        *uyku=0;
        printf("\n%s'nin uykusu var.",isim);
    }


    if(*eglence<=0)
    {
        *eglence=0;
        printf("\n%s'nin cani cok sikkin.",isim);
    }

    printf("\n\n\Degisen Degerler:\n\nUyku: %d\nTokluk: %d\nEglence: %d",*uyku,*tokluk,*eglence);
    Sleep(4000);

}

void kamp_git(char isim[],char calgi[],int *tokluk,int *uyku,int *hijyen,int *eglence,int *akil)
{
    int sec;

    printf("%s kamp alanina gidiyor...",isim);
    Sleep(4000);
    printf("\n%s simdi ne yapmali?\n\n",isim);

    printf("\n\n1-)Kamp atesinin basinda %s'yi calarak sarki soyleme\n2-)Nehirde yikanma\n3-)Cadirda uyuma\n4-)Koy meydanina donme\nTercih:",calgi);
    scanf("%d",&sec);

    switch(sec)
    {
    case 1:
        sarki_soyle(isim,calgi,uyku,eglence,tokluk,akil);
        return;

    case 2:
        nehirde_yikan(isim,hijyen,uyku,tokluk);
        return;

    case 3:
        cadirda_uyu(isim,uyku,tokluk);
        return;

    case 4:
        koye_don(isim,tokluk,uyku,eglence);
        return;

    default:
        printf("Gecersiz islem secenegi!!!\nAna menuye donuluyor.");

        return;

    }


}

void yara_sar(char isim[],int *can)
{
    printf("%s sifacidan yaralarini sarmasini istiyor.\nSifaci %s'nin saglik durumunu kontrol edecek.\n",isim,isim);

    Sleep(2000);

    printf("\n%s'nin cani: %d\n",isim,(*can));

    if(*can<30)
    {
        *can=*can+50;
        printf("Sifaci %s'nin yaralarini sariyor...",isim);
        Sleep(2000);
        printf("%s'nin canin son hali: %d\n",isim,(*can));
    }

    else
    {
        printf("Sifaci %s'ye saglik durumunun iyi oldugunu bildiriyor.\n%s'nin sarilmaya degecek kadar agir yaralari yok.",isim,isim);
        printf("Ana menuye donuluyor...");
        Sleep(4000);
    }

    kontrol(1,can);
    printf("Degisen Degerler:\n\nCan: %d",*can);
    Sleep(4000);
    printf("%s koye geri donuyor...",isim);
}

void merhem_sur(char isim[],int *can)
{
    printf("%s sifacidan merhem surmesini istiyor.\nSifaci %s'nin saglik durumunu kontrol edecek.",isim,isim);

    Sleep(2000);

    printf("\n%s'nin cani: %d\n",isim,(*can));

    if(*can<85)
    {
        *can=*can+20;
        printf("Sifaci %s'ye merhem suruyor...",isim);
        Sleep(2000);
        printf("%s'nin canin son hali: %d\n",isim,(*can));
    }

    else
    {
        printf("Sifaci %s'ye saglik durumunun iyi oldugunu bildiriyor.\n%s'nin merhem surulmeye degecek yaralari yok.",isim,isim);
        printf("Ana menuye donuluyor...");
        Sleep(4000);
    }

    kontrol(1,can);
    printf("Degisen Degerler:\n\nCan: %d",*can);
    Sleep(4000);
    printf("%s koye geri donuyor...",isim);
}


void sifahane_git(char isim[],int *can,int *tokluk,int *uyku,int *hijyen,int *eglence)
{
    int sec;

    printf("%s sifahaneye gidiyor...",isim);
    Sleep(4000);

    printf("\n%s simdi ne yapmali?\n\n",isim);

    printf("1-)Sifacidan yaralarini sarmasini iste(+50 can)\n2-)Sifacidan merhem surmesini iste(+30 can)\n3-)Koy meydanina donme(-20 moral)\nTercih:");
    scanf("%d",&sec);

    switch(sec)
    {
    case 1:
        yara_sar(isim,can);
        return;

    case 2:
        merhem_sur(isim,can);
        return;

    case 3:
        koye_don(isim,tokluk,uyku,eglence);
        return;

    default:
        printf("Gecersiz islem secenegi!!!");
        return;

    }


}

void yiyecek_al(char isim[],int *para,int *karizma)
{
    printf("%s handan yiyecek almaya karar veriyor.\nHanda olan yiyecekler su sekilde:\n1-)Ekmek(5 altin)\n2-)Ayva(15 altin)\n3-)Beyti Sarma(40 altin)\n",isim);

    int ekmek=5,ayva=15,beyti=50;

    int sec;
    int sayi;

    printf("Hangi yiyecekten almak istiyorsunuz?\nTercih:");
    scanf("%d",&sec);


    while(sec<0 || sec>3)
    {
        printf("Oyle bir secenek bulunmamakta.Tekrar karar veriniz.");
        scanf("%d",&sec);
    }

    printf("\nKac tane almak istiyorsunuz?\nTercih:");
    scanf("%d",&sayi);

    if(sec==1)
    {
        printf("\n%d tane ekmek almaya karar verdiniz.",sayi);

        if((*para)>sayi*ekmek)
        {

            if((*karizma)>70)
            {
                printf("Hanci %s gibi bir halk kahramanindan yemek icin para almayi kabul etmedi.\nYemege ucret odenmedi.");
                printf("Yemeginizi aldiniz.Kalan paraniz:%d",*para);
            }

            else
            {
                *para=*para-(sayi*ekmek);
                printf("Yemeginizi aldiniz.Kalan paraniz:%d",*para);
            }

        }

        else
        {
            printf("Paraniz yemegi almaya yetmedi.");
            return;
        }
    }

    else if(sec==2)
    {
        printf("%d tane ayva almaya karar verdiniz.",sayi);

        if((*para)>sayi*ayva)
        {
            if((*karizma)>70)
            {
                printf("Hanci %s gibi bir halk kahramanindan yemek icin para almayi kabul etmedi.\nYemege ucret odenmedi.");
                printf("Yemeginizi aldiniz.Kalan paraniz:%d",*para);
            }
            else
            {
                *para=*para-(sayi*ayva);
                printf("Yemeginizi aldiniz.Kalan paraniz:%d",*para);
            }

        }

        else
        {
            printf("Paraniz yemegi almaya yetmedi.");
            return;
        }
    }

    else if(sec==3)
    {
        printf("%d tane beyti almaya karar verdiniz.",sayi);

        if((*para)>sayi*beyti)
        {
            if((*karizma)>70)
            {
                printf("Hanci %s gibi bir halk kahramanindan yemek icin para almayi kabul etmedi.\nYemege ucret odenmedi.");
                printf("Yemeginizi aldiniz.Kalan paraniz:%d",*para);
            }

            else
            {

            }
            *para=*para-(sayi*beyti);
            printf("Yemeginizi aldiniz.Kalan paraniz:%d",*para);
        }

        else
        {
            printf("Paraniz yemegi almaya yetmedi.");
            return;
        }

    }

    kontrol(2,para,karizma);
    printf("\nDegisen Degerler:\n\nPara: %d\nKarizma\n\n",*para,*karizma);
    Sleep(4000);
    printf("%s koye geri donuyor...",isim);

}

void icecek_al(char isim[],int *para,int *karizma)
{
    printf("%s handan icecek almaya karar veriyor.\nHanda olan icecekler su sekilde:\n1-)Su(3 altin)\n2-)Ayran(8 ayran)\n3-)Portakal Suyu(20 altin)\n\n",isim);

    int su=3,ayran=8,portakal=20;

    int sec;
    int sayi;

    printf("Hangi icecekten almak istiyorsunuz?\nTercih:");
    scanf("%d",&sec);


    while(sec<0 || sec>3)
    {
        printf("Oyle bir secenek bulunmamakta. Tekrar karar veriniz:");
        scanf("%d",&sec);
    }

    printf("\nKac tane almak istiyorsunuz?\nTercih:");
    scanf("%d",&sayi);

    if(sec==1)
    {
        printf("%d tane su almaya karar verdiniz.",sayi);

        if((*para)>sayi*su)
        {
            if((*karizma)>70)
            {
                printf("Hanci %s gibi bir halk kahramanindan icecek icin para almayi kabul etmedi.\nIcecege ucret odenmedi.");
                printf("Iceceginizi aldiniz.Kalan paraniz:%d",*para);
            }

            else
            {
                (*para)=(*para)-(sayi*su);
                printf("Iceceginizi aldiniz.Kalan paraniz:%d",*para);
            }

        }

        else
        {
            printf("Paraniz icecegi almaya yetmedi.");
            return;
        }
    }

    else if(sec==2)
    {
        printf("%d tane ayran almaya karar verdiniz.",sayi);

        if((*para)>(sayi*ayran))
        {
            if((*karizma)>70)
            {
                printf("Hanci %s gibi bir halk kahramanindan icecek icin para almayi kabul etmedi.\nIcecege ucret odenmedi.");
                printf("Iceceginizi aldiniz.Kalan paraniz:%d",*para);
            }

            else
            {
                (*para)=(*para)-(sayi*ayran);
                printf("Iceceginizi aldiniz. Kalan paraniz:%d",*para);
            }

        }

        else
        {
            printf("Paraniz icecegi almaya yetmedi.");
            return;
        }
    }

    else if(sec==3)
    {
        printf("%d tane portakal suyu almaya karar verdiniz.",sayi);

        if((*para)>(sayi*portakal))
        {
            if((*karizma)>70)
            {
                printf("Hanci %s gibi bir halk kahramanindan icecek icin para almayi kabul etmedi.\nIcecege ucret odenmedi.");
                printf("Iceceginizi aldiniz.Kalan paraniz:%d",*para);
            }

            else
            {
                (*para)=(*para)-(sayi*portakal);
                printf("Iceceginizi aldiniz. Kalan paraniz:%d",*para);
            }

        }

        else
        {
            printf("Paraniz icecegi almaya yetmedi.");
            return;
        }

    }

    kontrol(2,*para,*karizma);
    printf("Degisen Degerler:\n\nPara: %d\nKarizma: %d\n\n",*para,*karizma);
    Sleep(4000);
    printf("%s koye geri donuyor...",isim);

}

void handa_konser(char isim[],char calgi[],int *hijyen,int *para,int *karizma,int *ozgvn,int *tecrube) //20 tecrube puani      kazanilan para=10+karizma*hijyen/100
{
    printf("%s handa konser vermeye karar veriyor.\nHanci hijyen durumunu kontrol edecek.\n\n",isim);
    Sleep(2000);
    printf("%s'nin aktif hijyeni: %d\n\n",isim,(*hijyen));

    if((*hijyen)<20)
    {
        printf("%s hijyen durumu uygun olmadigi icin sarki soyleyemiyor.\nBelki baska zaman.\n\n",isim);
        (*ozgvn)=(*ozgvn)-25;
        printf("Yeni Degerler:\n\nOzguven: %d\n",*ozgvn);
    }

    else
    {
        printf("%s tum gece %s'yi calarak handa konser veriyor...\n\n",isim,calgi);
        Sleep(4000);
        (*para)=(*para)+(10+((*karizma)*(*hijyen)/100));
        (*tecrube)=(*tecrube)+20;
        (*ozgvn)=(*ozgvn)+10;

        kontrol(2,tecrube,ozgvn);
        printf("Yeni Degerler:\n\nPara: %d\nTecrube: %d\nOzguven: %d\n\n",*tecrube,*ozgvn);
       // printf("Gecenin sonunda kazanilan para: %d\n\nToplam paraniz: %d",10+((*karizma)*(*karizma)/100),(*para));
    }

    printf("%s koye geri donuyor...",isim);
    Sleep(4000);
}

void han_git(char isim[],char calgi[],int *karizma,int *tokluk,int *uyku,int *hijyen,int *eglence,int *ozguven,int* tecrube,int* para)
{
    int sec;

    printf("%s hana gidiyor...",isim);
    Sleep(4000);

    (*eglence)=(*eglence)+7;

    printf("\n%s simdi ne yapmali?\n\n",isim);

    printf("1-)Yiyecek satin alma ve yeme\n2-)Icecek satin alma ve icme\n3-)%s'yi calma ve sarki soyleme\nTercih:",calgi);
    scanf("%d",&sec);

    switch(sec)
    {

    case 1:
        yiyecek_al(isim,para,karizma);
        return;

    case 2:
        icecek_al(isim,para,karizma);
        return;

    case 3:
        handa_konser(isim,calgi,hijyen,para,karizma,ozguven,tecrube);
        return;

    default:
        printf("Gecersiz islem secenegi!!!Ana menuye donuluyor.");
        return;

    }


}

void bitki_ve_av(char isim[],int *tokluk,int *can,int *toplayicilik) //sifali bitki bulma sansi=toplayicilik*4/100
{
    int bitki_sansi;
    int hayvan_sansi;
    int meyve_sansi;

    int sec;

    srand(time(0));

    int rastgele_sayi=rand()%100;
    bitki_sansi=(((*toplayicilik)*4)/100);

    hayvan_sansi=(bitki_sansi)/2;

    printf("Bitki bulma sansin: %d\n",bitki_sansi);
    printf("Av bulma sansin: %d\n",hayvan_sansi);
    printf("Hangisini yapmak istersiniz:\n1-)Bitki Ara\n2-)Av Ara\n3-)Meyve Ara\n\nTercih:");
    scanf("%d",&sec);

    switch(sec)
    {
    case 1:

        printf("%s bitki ariyor...",isim);

        if((*can)<100)
        {
            if(bitki_sansi>rastgele_sayi)
            {
                printf("%s sifali bitki buldu.\n\n",isim);
                (*can)+=10;
                kontrol(1,can);
                printf("Canin guncel hali: %d\n",(*can));
            }
        }

        else
        {
            printf("%s'nin cani full oldugu icin islem gerceklestirilemedi.",isim);


        }
        printf("\n%s koye geri donuyor...",isim);
        Sleep(4000);

        kontrol(2,can,toplayicilik);
        return;

    case 2:

    printf("%s ava cikiyor...",isim);

        if((*tokluk)<100)
        {
            if(hayvan_sansi>rastgele_sayi)
            {
                printf("%s av buldu.\n\n",isim);
                (*tokluk)+=50;
                kontrol(1,tokluk);
                printf("Canin guncel hali: %d\n",(*tokluk));
            }
        }

        else
        {
            printf("%s'nin cani full oldugu icin islem gerceklesmedi.",isim);

        }
        printf("\n%s koye gidiyor...",isim);
        Sleep(4000);

        kontrol(2,toplayicilik,tokluk);
        return;

    case 3:

           printf("%s meyve toplamaya gidiyor...",isim);

            if((*tokluk)<100)
            {
                if(meyve_sansi>100)
                {
                    printf("%s meyve buldu.\n\n",isim);
                    (*can)+=10;
                    kontrol(1,can);
                    printf("Canin guncel hali: %d\n",(*can));
                }
            }

            else
            {
                printf("%s'nin cani full oldugu icin islem gerceklesmedi.",isim);

            }

            printf("\n%s koye gidiyor...",isim);
            Sleep(4000);

            kontrol(2,toplayicilik,tokluk);
            return;

    }


}
                                                //*****while(karakterin cani==0||haydutlarin cani==0)*****
                                                //savastan kacilir ya da savasilir
                                                //rakibe verilen hasar=4*saldiranin gucu

                                                //alinan hasar=rakibe verilen hasar-(rakibe verilen hasar*4*savunmanin dayanikliligi/100-1)
                                                    //can=can-alinan hasar
void orman(char isim[],int *guc,int *ceviklik,int *dayaniklilik,int *karizma,int *toplayicilik,int *can,int *tecrube,int *seviye,int *akil,int *ozguven,int *para) // 15-25 altin     30 tecrube
{

    srand(time(0));

    int h_guc,h_cevik,h_day,h_can;

    int ust=5;
    int alt=0;

    h_guc=(rand()%(ust-alt+1))+alt;
    h_cevik=(rand()%(ust-alt+1))+alt;
    h_day=(rand()%(ust-alt+1))+alt;
    h_can=rand()%101;

    int sec;

    printf("%s issiz ormanda dolasirken orman haydutlari ile karsilasti.\n\n\nHaydutlarin ozellikleri:\n\nGuc: %d\nCeviklik: %d\nDayaniklilik: %d\nCan: %d\n\nHaydutlar 50 altin verirse %s'nin yolundan cekileceklerini soyluyorlar.\n\n0-)Kabul etmeme\n1-)Kabul etme\nTercih:",isim,h_guc,h_cevik,h_day,h_can,isim);
    scanf("%d",&sec);


if(sec==0 || sec==1)
    {

       if(sec==0) //savas
        {
        printf("Haydutlar bu karardan memnun degil.\nBu kararin sonucunda kellenizi alacaklarini soyluyorlar.\n\n");


        int alinan_hasar_k,verilen_hasar_k; //k->kullanici
        int alinan_hasar_h,verilen_hasar_h; //h->haydut

        verilen_hasar_k=4*(*guc);
        alinan_hasar_k=verilen_hasar_h-(verilen_hasar_h*4*h_day/100)-1; //kullanici

        verilen_hasar_h=4*h_guc;
        alinan_hasar_h=verilen_hasar_k-(verilen_hasar_k*4*(*dayaniklilik)/100)-1; //haydut


        while((*can)!=0 || h_can!=0) //can=can-alinan hasar
            {

        if(verilen_hasar_k<verilen_hasar_h) //karakter
        {
            *can=*can-(3*alinan_hasar_h);
            h_can=h_can-(2*alinan_hasar_k);

            if((*can)==0 || (*can)<0)
                {
                printf("Savas sona erdi.\n");
                printf("%s oldu.\nOyun sonlandiriliyor.",isim);
                exit(0);
                }

            if(h_can==0 || h_can<0)
                {
                    printf("Savas sona erdi.\n");
                    printf("Haydutlarin cogunlugu oldu.\nArkalarina bile bakmadan kacisiyorlar.");

                    (*tecrube)+=30;
                    (*para)+=15;
                    (*akil)-=30;

                    if(*akil<0)
                        *akil==0;

                    break;
                }

        }

        if(verilen_hasar_h<verilen_hasar_k)
        {
            h_can=h_can-(3*alinan_hasar_k);
            *can=*can-(2*alinan_hasar_h);

            if((*can)==0 || (*can)<0)
                {
                printf("Savas sona erdi.\n");
                printf("%s oldu.\nOyun sonlandiriliyor.",isim);
                exit(0);
                }

            if(h_can<=0)
                {
                    printf("Savas sona erdi.\n");
                    printf("Haydutlarin cogunlugu oldu.\nArkalarina bile bakmadan kacisiyorlar.");

                    (*tecrube)+=30;
                    (*para)+=15;
                    (*akil)-=30;

                    if(*akil<0)
                        *akil==0;

                    break;
                }

        }



            printf("Kalan canlar:\n\n %s: %d\tHaydutlar: %d",isim,(*can),h_can);

            printf("\n\nSavasa devam mi?\n\n0-)Hayir\n1-)Evet\n\nTercih:");
            scanf("%d",&sec);

            if(sec==0)
            {
                printf("\n%s kaciyor.",isim);
                break;
            }

            else  if(sec==1) //savasa devam
            {

                continue;
            }

            else
            {
                printf("\nDengesiz bir saldiri denemesi %s'nin olumune sebep oldu.\nOyun sonlandiriliyor...",isim);
                exit(0);
            }

        }//savas ani

        if(*akil<=0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                if(*can<=0)
                    {
                        printf("%s gorduklerine ve yasadiklarina dayanamadi ve hayatina son verdi.\nOyun sonlandiriliyor.",isim);
                        exit(0);
                    }

            (*ozguven)+=35;

        printf("\nHer seye ragmen savastan sag cikildigi icin %s'nin ozguveni artti.",isim);


                    if(*tecrube==100 || *tecrube>100)
                    {
                        (*tecrube)=100;
                        seviye_atla(guc,ceviklik,dayaniklilik,karizma,toplayicilik,tecrube,seviye);
                    }

        kontrol(1,ozguven); //Can degeri artmadigi icin 100'u gecemez,tecrube ustte kontrol edildigi icin parametre olarak verilmedi
        kontrol2(3,guc,ceviklik,dayaniklilik);

        printf("Degisen Degerler:\n\nCan:%d\nAkil Sagligi: %d\nOzguven: %d\n\n",(*can),(*akil),(*ozguven));
        printf("%s koye geri donuyor...",isim);
        Sleep(4000);
        return;


        }//savas sureci



        else //kac
        {

       int kacma_sansi=4*(*ceviklik)/100;

       int sans;

       sans=rand()%100;

       if(kacma_sansi>sans)
            {
                printf("%s basarili bir sekilde haydutlardan kacti ve issiz ormanin derinliklerine saklandi.\nBu talihsiz kosusturmanin kendisine iyi bir tecrube olduguna inaniyor ama bu akil sagligini geri getirmeyecek.\n",isim);
                (*tecrube)+=20;
                (*akil)-=20;

                kontrol(1,tecrube);

                if(*akil<0 || *akil==0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("\n%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("\n%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                printf("Degisen Degerler:\n\nCan: %d\nTecrube: %d\nAkil Sagiligi: %d\n",(*can),(*tecrube),(*akil));

                return;
            }

       else if(kacma_sansi==sans)
            {
                printf("%s haydutlardan kacti ama canini zor kurtardi.",isim);
                (*akil)-=30;

                if(*akil<0 || *akil==0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                printf("Degisen Degerler:\n\nCan: %d\nAkil Sagiligi: %d\n",(*can),(*akil));
                return;
            }

       else
            {
                printf("Haydutlar 50 altininizi harac olarak aldi.\n");

                (*para)=(*para)-50;
                (*akil)-=40;

                if(*akil<0 || *akil==0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                if((*para)<0)
                {
                    (*para)=0;
                }

                printf("Degisen Degerler:\n\nCan: %d\nAkil Sagiligi: %d\n",(*can),(*akil));

                printf("Kalan paraniz: %d\n\n",(*para));

                printf("%s sessiz sedasiz koy meydanina donuyor...",isim);
                Sleep(4000);
                return;
            }


        }
    }

else //kararsizlik
    {
        printf("Issiz ormandaki kararsiz gecen birkac dakikadan sonra haydutlar %s'ye saldirarak canini almayi harac kesmeye tercih ediyorlar.\n%s haydutlar tarafindan hatali kararindan dolayi vahsice katlediliyor.",isim,isim);
        printf("Oyun sonlandiriliyor...");
        exit(0);
    }



}

void kayalik(char isim[],int *guc,int *ceviklik,int *dayaniklilik,int *karizma,int *toplayicilik,int *can,int *tecrube,int *seviye,int *akil,int *ozguven,int *para) // 30-50 altin       60 tecrube
{

    srand(time(0));

    int h_guc,h_cevik,h_day,h_can;

    int ust=12;
    int alt=0;

    h_guc=(rand()%(ust-alt+1))+alt;
    h_cevik=(rand()%(ust-alt+1))+alt;
    h_day=(rand()%(ust-alt+1))+alt;
    h_can=rand()%101;

    int sec;

    printf("%s keskin kayaliklarda dolasirken orman haydutlari ile karsilasti.\n\n\nHaydutlarin ozellikleri:\n\nGuc: %d\nCeviklik: %d\nDayaniklilik: %d\nCan: %d\nHaydutlar 50 altin verirse %s'nin yolundan cekileceklerini soyluyorlar.\n\n0-)Kabul etmeme\n1-)Kabul etme\nTercih:",isim,h_guc,h_cevik,h_day,h_can,isim);
    scanf("%d",&sec);


if(sec==0 || sec==1)
    {

       if(sec==0) //savas
        {
        printf("Haydutlar bu karardan memnun degil.\nBu kararin sonucunda kellenizi alacaklarini soyluyorlar.\n\n");


        int alinan_hasar_k,verilen_hasar_k; //k->kullanici
        int alinan_hasar_h,verilen_hasar_h; //h->haydut

        verilen_hasar_k=4*(*guc);
        alinan_hasar_k=verilen_hasar_h-(verilen_hasar_h*4*h_day/100)-1; //kullanici

        verilen_hasar_h=4*h_guc;
        alinan_hasar_h=verilen_hasar_k-(verilen_hasar_k*4*(*dayaniklilik)/100)-1; //haydut


        while((*can)!=0 || h_can!=0) //can=can-alinan hasar
            {

        if(verilen_hasar_k<verilen_hasar_h) //karakter
        {
            *can=*can-(3*alinan_hasar_h);
            h_can=h_can-(2*alinan_hasar_k);

            if((*can)==0 || (*can)<0)
                {
                printf("Savas sona erdi.\n");
                printf("%s oldu.\nOyun sonlandiriliyor.",isim);
                exit(0);
                }

            if(h_can==0 || h_can<0)
                {
                    printf("Savas sona erdi.\n");
                    printf("Haydutlarin cogunlugu oldu.\nArkalarina bile bakmadan kacisiyorlar.");

                    (*tecrube)+=30;
                    (*para)+=15;
                    (*akil)-=30;

                    if(*akil<0)
                        *akil==0;

                    break;
                }

        }

        if(verilen_hasar_h<verilen_hasar_k) //haydut
        {
            h_can=h_can-(3*alinan_hasar_k);
            *can=*can-(2*alinan_hasar_h);

            if((*can)==0 || (*can)<0)
                {
                printf("Savas sona erdi.\n");
                printf("%s oldu.\nOyun sonlandiriliyor.",isim);
                exit(0);
                }

            if(h_can<=0)
                {
                    printf("Savas sona erdi.\n");
                    printf("Haydutlarin cogunlugu oldu.\nArkalarina bile bakmadan kacisiyorlar.");

                    (*tecrube)+=30;
                    (*para)+=15;
                    (*akil)-=30;

                    if(*akil<0)
                        *akil==0;

                    break;
                }

        }



            printf("Kalan canlar:\n\n%s: %d\tHaydutlar: %d",isim,(*can),h_can);

            printf("\n\nSavasa devam mi?\n\n0-)Hayir\n1-)Evet\n\nTercih:");
            scanf("%d",&sec);

            if(sec==0)
            {
                printf("\n%s kaciyor...\n\n",isim);
                break;
            }

            else  if(sec==1) //savasa devam
            {

                continue;
            }

            else
            {
                printf("\nDengesiz bir saldiri denemesi %s'nin olumune sebep oldu.\nOyun sonlandiriliyor...",isim);
                exit(0);
            }

        }//savas ani

        if(*akil<=0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                if(*can<=0)
                    {
                        printf("\n\n\n%s gorduklerine ve yasadiklarina dayanamadi ve hayatina son verdi.\nOyun sonlandiriliyor.",isim);
                        exit(0);
                    }

            (*ozguven)+=35;

        printf("\nHer seye ragmen savastan sag cikildigi icin %s'nin ozguveni artti.",isim);


                    if(*tecrube==100 || *tecrube>100)
                    {
                        (*tecrube)=100;
                        seviye_atla(guc,ceviklik,dayaniklilik,karizma,toplayicilik,tecrube,seviye);
                    }

        kontrol(1,ozguven); //Can degeri artmadigi icin 100'u gecemez,tecrube ustte kontrol edildigi icin parametre olarak verilmedi
        kontrol2(3,guc,ceviklik,dayaniklilik);

        printf("Degisen Degerler:\n\nCan:%d\nAkil Sagligi: %d\nOzguven: %d\n\n",(*can),(*akil),(*ozguven));
        printf("%s koye geri donuyor...",isim);
        Sleep(4000);
        return;


        }//savas sureci



        else //kac
        {

       int kacma_sansi=4*(*ceviklik)/100;

       int sans;

       sans=rand()%100;

       if(kacma_sansi>sans)
            {
                printf("%s basarili bir sekilde haydutlardan kacti ve keskin kayaliklar arasindaki magaraya saklandi.\nBu talihsiz kosusturmanin kendisine iyi bir tecrube olduguna inaniyor ama bu akil sagligini geri getirmeyecek.\n",isim);
                (*tecrube)+=20;
                (*akil)-=20;

                kontrol(1,tecrube);

                if(*akil<0 || *akil==0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("\n%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("\n%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                printf("Degisen Degerler:\n\nCan: %d\nTecrube: %d\nAkil Sagiligi: %d\n",(*can),(*tecrube),(*akil));

                return;
            }

       else if(kacma_sansi==sans)
            {
                printf("%s haydutlardan kacti ama canini zor kurtardi.",isim);
                (*akil)-=30;

                if(*akil<0 || *akil==0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                printf("Degisen Degerler:\n\nCan: %d\nAkil Sagiligi: %d\n",(*can),(*akil));
                return;
            }

       else
            {
                printf("Haydutlar 50 altininizi harac olarak aldi.\n");

                (*para)=(*para)-50;
                (*akil)-=40;

                if(*akil<0 || *akil==0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                if((*para)<0)
                {
                    (*para)=0;
                }

                printf("Degisen Degerler:\n\nCan: %d\nAkil Sagiligi: %d\n",(*can),(*akil));

                printf("Kalan paraniz: %d\n\n",(*para));

                printf("%s sessiz sedasiz koy meydanina donuyor...\nOlanlari kimse bilmeyecek.",isim);
                Sleep(4000);
                return;
            }


        }
    }

else //kararsizlik
    {
        printf("Keskin kayaliklardaki kararsiz gecen birkac dakikadan sonra haydutlar %s'ye saldirarak canini almayi harac kesmeye tercih ediyorlar.\n%s haydutlar tarafindan hatali kararindan dolayi vahsice katlediliyor.",isim,isim);
        printf("Oyun sonlandiriliyor...");
        exit(0);
    }


}
void vadi(char isim[],int *guc,int *ceviklik,int *dayaniklilik,int *karizma,int *toplayicilik,int *can,int *tecrube,int *seviye,int *akil,int *ozguven,int *para) // 55-75 altin      90 tecrube
{

    srand(time(0));

    int h_guc,h_cevik,h_day,h_can;

    int ust=25;
    int alt=0;


    h_guc=(rand()%(ust-alt+1))+alt;
    h_cevik=(rand()%(ust-alt+1))+alt;
    h_day=(rand()%(ust-alt+1))+alt;
    h_can=rand()%101;

    int sec;

    printf("%s akarsu vadisinde dolasirken orman haydutlari ile karsilasti.\n\n\nHaydutlarin ozellikleri:\n\nGuc: %d\nCeviklik: %d\nDayaniklilik: %d\nCan: %d\n\nHaydutlar 50 altin verirse %s'nin yolundan cekileceklerini soyluyorlar.\n\n0-)Kabul etmeme\n1-)Kabul etme\nTercih:",isim,h_guc,h_cevik,h_day,h_can,isim);
    scanf("%d",&sec);


if(sec==0 || sec==1)
    {

       if(sec==0) //savas
        {
        printf("Haydutlar bu karardan memnun degil.\nBu kararin sonucunda kellenizi alacaklarini soyluyorlar.\n\n");


        int alinan_hasar_k,verilen_hasar_k; //k->kullanici
        int alinan_hasar_h,verilen_hasar_h; //h->haydut

        verilen_hasar_k=4*(*guc);
        alinan_hasar_k=verilen_hasar_h-(verilen_hasar_h*4*h_day/100)-1; //kullanici

        verilen_hasar_h=4*h_guc;
        alinan_hasar_h=verilen_hasar_k-(verilen_hasar_k*4*(*dayaniklilik)/100)-1; //haydut


        while((*can)!=0 || h_can!=0) //can=can-alinan hasar
            {

        if(verilen_hasar_k<verilen_hasar_h) //karakter
        {
            *can=*can-(3*alinan_hasar_h);
            h_can=h_can-(2*alinan_hasar_k);

            if((*can)==0 || (*can)<0)
                {
                printf("Savas sona erdi.\n");
                printf("%s oldu.\nOyun sonlandiriliyor.",isim);
                exit(0);
                }

            if(h_can==0 || h_can<0)
                {
                    printf("Savas sona erdi.\n");
                    printf("Haydutlarin cogunlugu oldu.\nArkalarina bile bakmadan kacisiyorlar.");

                    (*tecrube)+=30;
                    (*para)+=15;
                    (*akil)-=30;

                    if(*akil<0)
                        *akil==0;

                    break;
                }

        }

        if(verilen_hasar_h<verilen_hasar_k) //haydut
        {
            h_can=h_can-(3*alinan_hasar_k);
            *can=*can-(2*alinan_hasar_h);

            if((*can)==0 || (*can)<0)
                {
                printf("Savas sona erdi.\n");
                printf("%s oldu.\nOyun sonlandiriliyor.",isim);
                exit(0);
                }

            if(h_can<=0)
                {
                    printf("Savas sona erdi.\n");
                    printf("Haydutlarin cogunlugu oldu.\nArkalarina bile bakmadan kacisiyorlar.");

                    (*tecrube)+=30;
                    (*para)+=15;
                    (*akil)-=30;

                    if(*akil<0)
                        *akil==0;

                    break;
                }

        }



            printf("Kalan canlar:\n\n %s: %d\tHaydutlar: %d",isim,(*can),h_can);

            printf("\n\nSavasa devam mi?\n\n0-)Hayir\n1-)Evet\n\nTercih:");
            scanf("%d",&sec);

            if(sec==0)
            {
                printf("\n%s kaciyor.",isim);
                break;
            }

            else  if(sec==1) //savasa devam
            {

                continue;
            }

            else
            {
                printf("\nDengesiz bir saldiri denemesi %s'nin olumune sebep oldu.\nOyun sonlandiriliyor...",isim);
                exit(0);
            }

        }//savas ani

        if(*akil<=0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                if(*can<=0)
                    {
                        printf("%s gorduklerine ve yasadiklarina dayanamadi ve hayatina son verdi.\nOyun sonlandiriliyor.",isim);
                        exit(0);
                    }

            (*ozguven)+=35;

        printf("\nHer seye ragmen savastan sag cikildigi icin %s'nin ozguveni artti.",isim);


                    if(*tecrube==100 || *tecrube>100)
                    {
                        (*tecrube)=100;
                        seviye_atla(guc,ceviklik,dayaniklilik,karizma,toplayicilik,tecrube,seviye);
                    }

        kontrol(1,ozguven); //Can degeri artmadigi icin 100'u gecemez,tecrube ustte kontrol edildigi icin parametre olarak verilmedi
        kontrol2(3,guc,ceviklik,dayaniklilik);

        printf("Degisen Degerler:\n\nCan:%d\nAkil Sagligi: %d\nOzguven: %d\n\n",(*can),(*akil),(*ozguven));
        printf("%s koye geri donuyor...",isim);
        Sleep(4000);
        return;


        }//savas sureci



        else //kac
        {

       int kacma_sansi=4*(*ceviklik)/100;

       int sans;

       sans=rand()%100;

       if(kacma_sansi>sans)
            {
                printf("%s basarili bir sekilde haydutlardan kacti ve akarsu vadisindeki harabelere saklandi.\nBu talihsiz kosusturmanin kendisine iyi bir tecrube olduguna inaniyor ama bu akil sagligini geri getirmeyecek.\n",isim);
                (*tecrube)+=20;
                (*akil)-=20;

                kontrol(1,tecrube);

                if(*akil<0 || *akil==0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                printf("Degisen Degerler:\n\nCan: %d\nTecrube: %d\nAkil Sagiligi: %d\n",(*can),(*tecrube),(*akil));

                return;
            }

       else if(kacma_sansi==sans)
            {
                printf("%s haydutlardan kacti ama canini zor kurtardi.",isim);
                (*akil)-=30;

                if(*akil<0 || *akil==0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                printf("Degisen Degerler:\n\nCan: %d\nAkil Sagiligi: %d\n",(*can),(*akil));
                return;
            }

       else
            {
                printf("Haydutlar 50 altininizi harac olarak aldi.\n");

                (*para)=(*para)-50;
                (*akil)-=40;

                if(*akil<0 || *akil==0)
                    {
                        if(*akil<0)
                        {
                            *akil=0;
                            printf("%s aklini kaciriyor.",isim);

                            *can-=20;
                        }

                        else
                        {
                            printf("%s aklini kacirmak uzere.",isim);

                            *can-=15;
                        }

                    }

                if((*para)<0)
                {
                    (*para)=0;
                }

                printf("Degisen Degerler:\n\nCan: %d\nAkil Sagiligi: %d\n",(*can),(*akil));

                printf("Kalan paraniz: %d\n\n",(*para));

                printf("%s sessiz sedasiz koy meydanina donuyor...\nOlanlari kimse bilmeyecek.",isim);
                Sleep(4000);
                return;
            }


        }
    }

else //kararsizlik
    {
        printf("Akarsu vadisindeki kararsiz gecen birkac dakikadan sonra haydutlar %s'ye saldirarak canini almayi harac kesmeye tercih ediyorlar.\n%s haydutlar tarafindan hatali kararindan dolayi vahsice katlediliyor.",isim,isim);
        printf("Oyun sonlandiriliyor...");
        exit(0);
    }

}

int macera(char isim[],int *guc,int *ceviklik,int *dayaniklilik,int *karizma,int *toplayicilik,int *can,int *tokluk,int *uyku,int *eglence,int *tecrube,int *seviye,int *akil,int *ozguven,int *para)
{
    int sec;

    printf("%s maceraya cikmaya karar veriyor...",isim);
    Sleep(4000);

    printf("\n%s simdi ne yapmali?\n\n",isim);

    printf("1-)Yakin cevreden sifali bitki topla ve avlan\n2-)Ormani kesfe cik(kolay)\n3-)Kayaliklari kesfe cikma(orta)\n4-)Vadiyi kesfe cikma(zor)\n5-)Koy meydanina donme\nTercih:");
    scanf("%d",&sec);

    switch(sec)
    {
    case 1:
        bitki_ve_av(isim,tokluk,can,toplayicilik);
        break;

    case 2:
        orman(isim,guc,ceviklik,dayaniklilik,karizma,toplayicilik,can,seviye,akil,ozguven,tecrube,para);
        break;

    case 3:
        kayalik(isim,guc,ceviklik,dayaniklilik,karizma,toplayicilik,can,seviye,akil,ozguven,tecrube,para);
        break;

    case 4:
        vadi(isim,guc,ceviklik,dayaniklilik,karizma,toplayicilik,can,seviye,akil,ozguven,tecrube,para);
        break;

    case 5:
        koye_don(isim,uyku,tokluk,eglence);
        break;

    default:
        printf("Gecersiz islem secenegi!!!\nAna menuye donuluyor.");
        return;

    }
}


void seviye_atla(char isim[],int *guc,int *ceviklik,int *dayaniklilik,int *karizma,int *toplayicilik,int *tecrube,int *seviye)
{
    if(tecrube==100)
    {
        printf("%s'nin seviyesi arttiriliyor...",isim);
        (*seviye)++;
        *tecrube=0;
        Sleep(3000);

        int sec;

        printf("Beceriler:\n\n");
        printf("Guc: %d\nCeviklik: %d\nDayaniklilik: %d\nKarizma: %d\nToplayicilik: %d\n\n",(*guc),(*ceviklik),(*dayaniklilik),(*karizma),(*toplayicilik));

        //Harcanmasi icin 5 puan verilecek ve bu puanlar ozelliklere dagitilacak
        for(int i=5;i>0;i--)
        {
            printf("%d puaniniz var.\nHangi ozelligi guclendirmek istersiniz?\n\n1-)Guc\n2-)Ceviklik\n3-)Dayaniklilik\n4-)Karizma\n5-)Toplayicilik\n6-)Cikis");
            scanf("%d",&sec);

            switch(sec)
            {
            case 1:
                    printf("Guc arttirildi.\nGuc: %d",((*guc)+1));
                    (*guc)++;

                break;

            case 2:
                    printf("Ceviklik arttirildi.\nCeviklik: %d",((*ceviklik)+1));
                    (*ceviklik)++;

                break;

            case 3:
                    printf("Dayaniklilik arttirildi.\nDayaniklilik: %d",((*dayaniklilik)+1));
                    (*dayaniklilik)++;

                break;

            case 4:
                    printf("Karizma arttirildi.\nKarizma: %d",((*karizma)+1));
                    (*karizma)++;

                break;

            case 5:
                    printf("Toplayicilik arttirildi.\nToplayicilik: %d",((*toplayicilik)+1));
                    (*toplayicilik)++;

                break;

            case 6:
                    printf("Islem iptal.\nAna menuye donuluyor.");

                return;

            default:

                    printf("Gecersiz islem secenegi!!!\n");

                break;
            }

        }

        kontrol2(5,guc,ceviklik,dayaniklilik,karizma,toplayicilik); //max 25 olabilirler


        return;

    }

    else
    {
        printf("Karakterin durumu seviye atlamaya uygun degil.");
        printf("Ana menuye donuluyor...");
        Sleep(1500);
    }

}

void durumu_goster(char isim[],int *guc,int *ceviklik,int *dayaniklilik,int *karizma,int *toplayicilik,int *can,int *tokluk,int *uyku,int *hijyen,int *eglence,int *akil,int *ozguven,int *para,int *tecrube,int *seviye)
{
    if((*tecrube)==100)
    {
        printf("%s seviye atlamaya hazir",isim);
      //  seviye_atla(isim,tecrube,seviye);
    }

    printf("%s'nin durumu:\n\n\n",isim);

    printf("Beceriler:\n\n");
    printf("Guc: %d\nCeviklik: %d\nDayaniklilik: %d\nKarizma: %d\nToplayicilik: %d\n\n",(*guc),(*ceviklik),(*dayaniklilik),(*karizma),(*toplayicilik));//pointerlarla temel durum yazdirilacak

    printf("Temel nitelikler:\n\n");
    printf("Can: %d\nTokluk: %d\nUyku: %d\nHijyen: %d\nEglence: %d\n\n",(*can),(*tokluk),(*uyku),(*hijyen),(*eglence));

    printf("Akil Sagligi: %d\nOzguven: %d\n",(*akil),(*ozguven));

    printf("Para: %d\n",(*para));

    printf("Tecrube: %d\nSeviye: %d",(*tecrube),(*seviye));



    if((*can)<20)
    {
        printf("%s'nin saglik durumu iyi durumda degil.\n***Sifahaneye gitmesi gerekiyor.***\n",isim);
        return;
    }

    return;
}

void oyunu_kapat()
{
    int sec;
    printf("Oyundan cikmak istediginize emin misiniz?\n0-Hayir\n1-)Evet\n\nTercih:");
    scanf("%d",&sec);


            if(sec==0 || sec==1)
            {
                if(sec==0)
                {
                    printf("Ana menuye donuluyor...");

                }

                else
                {
                    printf("Oyun sonlandirildi.");
                    exit(0);

                }
            }

            else
            {
                while(sec<0 || sec>1)
                {
                    printf("\nSeciminiz hatali,lutfen tekrar deneyiniz:");
                    scanf("%d",&sec);
                }

                if(sec==0 || sec==1)
                {
                    if(sec==0)
                    {
                        printf("\nAna menuye donuluyor...");
                        Sleep(2000);

                    }

                    else
                    {
                        printf("Oyun sonlandirildi.");
                        exit(0);
                    }
                }
            }



}

void kontrol(int count, ...)
{
    va_list args;
    va_start(args,count);

    for(int i=0;i<count;i++)
    {
        int *ptr=va_arg(args,int *);

            if(*ptr>MAX)
            {
                *ptr=MAX;
            }
    }

        va_end(args);
}

void kontrol2(int count, ...)
{
    va_list args;
    va_start(args,count);

    for(int i=0;i<count;i++)
    {
        int *ptr=va_arg(args,int *);

            if(*ptr>25)
            {
                *ptr=25;
            }
    }

    va_end(args);
}


//para-->100 altin

//beceriler->guc,ceviklik,dayaniklilik,karizma,toplayicilik hepsi 3'ten baslayacak (en fazla 25 olabilirler)
//temel nitelikler(ihtiyaclar)->can,tokluk,uyku,hijyen,eglence,akil_sagligi,ozguven (0-100) arasi olabilir
int main()
{
    int guc=3,ceviklik=3,dayaniklilik=3,karizma=3,toplayicilik=3; //max 25
    int *gc,*cvklk,*dynkllk,*krzm,*tplyclk; //atama islemlerinde karismamasi icin pointerlar'in yazimi farkli yapilmistir.

    gc=&guc;
    cvklk=&ceviklik;
    dynkllk=&dayaniklilik;
    krzm=&karizma;
    tplyclk=&toplayicilik;


    int can,tokluk,uyku,hijyen,eglence,akil,ozguven=30;
    int *cn,*tklk,*uyu,*hjyn,*eglen,*akl,*ozgvn;

    srand(time(0));

    int ust=100,alt=20;

    can=(rand()%(ust-alt+1))+alt;
    tokluk=(rand()%(ust-alt+1))+alt;
    uyku=(rand()%(ust-alt+1))+alt;
    hijyen=(rand()%(ust-alt+1))+alt;
    eglence=(rand()%(ust-alt+1))+alt;
    akil=(rand()%(ust-alt+1))+alt;

    cn=&can;
    tklk=&tokluk;
    uyu=&uyku;
    hjyn=&hijyen;
    eglen=&eglence;
    akl=&akil;
    ozgvn=&ozguven;

    int para=100;
    int *p_para;

    p_para=&para;

    int tecrube=0,seviye=0;
    int *tcrb,*svy;

    tcrb=&tecrube;
    svy=&seviye;

    printf("Toplumun gururu olan bir sanatci ve onun maceraci dunyasina hos geldiniz!!!\nOyuna baslayabilmeniz icin karakter bilgilerini girmeniz gerekmektedir.\n\n");

    char isim[MAX];

    char calgi[MAX];

    int secenek;

    printf("Lutfen karakterinizin adini giriniz:");
    gets(isim);

    printf("\nKarakterinizin adi:%s",isim);

    printf("\n\n\nLutfen karakterinizin calgisinin adini giriniz:");
    gets(calgi);

    printf("\n%s'nin calgisinin adi:%s",isim,calgi);

    printf("\n\nHer sey tamam olduguna gore artik oyuna gecmeye hazirsiniz.\nOyunda tercihler yapmaniz gerekmektedir.\nBu tercihleri menu ekranina bakarak yapabilirsiniz.\n");

    printf("Yapacaginiz her tercih oyunun ilerleyisini ve %s'nin becerilerini ve temel niteliklerini etkileyecektir.\nBaslangic icin becerilerin hepsi 3'tur.",isim);
    printf("Temel nitelikler ise 0-100 arasi olacak sekilde bilgisayar tarafindan ayarlanacaktir.");
    Sleep(4000);
    printf("Iste %s'nin temel nitelikleri:",isim);

    printf("\n\n\nAKTIF DURUM:\n\n");

    printf("Beceriler:\n");
    printf("Guc: %d\nCeviklik: %d\nDayaniklilik: %d\nKarizma: %d\nToplayicilik: %d\n\n\n",*gc,*cvklk,*dynkllk,*krzm,*tplyclk);

    printf("Temel Nitelikler:\n");
    printf("Can: %d\nTokluk: %d\nUyku: %d\nHijyen: %d\nEglence: %d\nAkil Saglligi: %d\nOzguven: %d\n",can,tokluk,uyku,hijyen,eglence,akil,ozguven);

    printf("\nPara: %d\n\nTecrube: %d\nSeviye: %d",*p_para,*tcrb,*svy);

    while(1)
    {
        printf("\n\nMENU\n\n");
        printf("1-)Kamp alanina git\n2-)Sifahaneye git\n3-)Hana git\n4-)Maceraya atil\n5-)Seviye atla\n6-)Durumu goster\n7-)Oyundan cik\n\nTercih:");
        scanf("%d",&secenek);

        switch(secenek)
        {

        case 1:
            //kampa git
        kamp_git(isim,calgi,tklk,uyu,hjyn,eglen,akl);

            break;

        case 2:
            //sifahaneye git
        sifahane_git(isim,cn,tklk,uyu,hjyn,eglen);

            break;

        case 3:
            //hana git
        han_git(isim,calgi,krzm,tklk,uyu,hjyn,eglen,ozgvn,tcrb,p_para);

            break;

        case 4:
            //maceraya git
      macera(isim,gc,cvklk,dynkllk,krzm,tplyclk,cn,tklk,uyu,eglen,tcrb,svy,akl,ozgvn,p_para);

            break;

        case 5:
            //seviye atla
        seviye_atla(isim,guc,cvklk,dynkllk,krzm,tplyclk,tcrb,svy);
            break;

        case 6:
            //durumu goster
        durumu_goster(isim,gc,cvklk,dynkllk,krzm,tplyclk,cn,tklk,uyu,hjyn,eglen,akl,ozgvn,p_para,tcrb,svy);
            break;

        case 7:
            //oyunu kapa
        oyunu_kapat();
            break;

        default:
            printf("Gecersiz islem secenegi!!!");
            break;

        }//switch-case

    }//while

    return 0;
}//main
