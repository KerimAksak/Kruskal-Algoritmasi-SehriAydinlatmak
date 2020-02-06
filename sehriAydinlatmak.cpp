//ABDÜLKERÝM AKSAK
//030117042
//NOT sehirplani.txt OLARAK DOSYA OKUMA YAPILMAKTADIR!
#include <iostream>
#include <stdio.h>

#include <fstream> 
#include <vector>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;

void listAtama();//list<int> cityplan; listesine genel olarak dosyayý atama yapan fonksiyon.
void maliyetAtama();//vector<int> vecMaliyet; vectorune maliyetleri atayan fonksiyon.
void kenarAtama();//vector< pair <int,int> > vecKenar; vectorune kenar ikililerini atayan fonksiyon.

//Dongu olup olmadýðýný kontrol eden fonksiyonlar.
int kavsakUzerindeGezinme(int x);
void donguKontrol(int x, int y);

list<int> cityplan;//.txt dosyasýný genel olarak tutacak liste.
list<int> lst;
vector<int> dongu;//donguyu kontrol edecek vector

vector<int> vecMaliyet;//.txt dosyasýndaki tüm maliyet listesi.
vector< pair <int,int> > vecKenar;//.txt dosyasýndaki tüm kenar listesi.
vector< pair <int, pair<int, int> > > vecToplam;//kenar ve maliyetleri tek baþýna tutan vector

int kenarSayisi=0;
int dugumSayisi=0;
int maliyetTasarruf=0;
int maliyet=0;

int main() {
	listAtama();//list<int> cityplan; listesine .txt dosyasýný atanmasý.
	maliyetAtama();//vector<int> vecMaliyet; vectorune maliyetlerin atanmasý.
	kenarAtama();//vector< pair <int,int> > vecKenar; vectorune kenar ikililerinin atanmasý.
		     
	for(int i=0;i<kenarSayisi;i++){
		vecToplam.push_back(make_pair(vecMaliyet[i],make_pair(vecKenar[i].first,vecKenar[i].second)));//Tüm veriler tek bir vektor içine toplanýyor.
	}
	sort(vecToplam.begin(),vecToplam.end());//Maliyet listesi için sýralama iþlemi gerçekleþtirilir.
	
 	/*--------------------------------------------------------------------------------------------------
    Döngü mantýðý;
    	Örnek olarak 0,1,2,3 düðümleri arasýnda 0-1/0-2/1-2/1-3 ikilileri verilsin.
    	Görüldüðü üzere 0-1/0-2/1-2 ikilileri bir döngü oluþturmaktadýr.
    	
    	Öncelikle döngü kontolu iki fonksiyon ve bir vektor yardýmýyla yapýlmaktadýr.
    	
    		1.	for(int i=0;i<dugumSayisi;++i)
       				 dongu.push_back(i);
       				 
       			>dongu vectoru ile düðüm sayýsý kadar veri oluþturup her veriye kendi indisi atanmýþtýr.
    		Bu sayede tüm düðümler tekil durumda bulunmaktadýr.
    		
    		2. int kavsakUzerindeGezinme(int x);
    		 	
    		 	Fonksiyon ile dongu vectorune baþka bir düðüm eklenmiþ mi diye while döngüsüyle kontrol edilir.
    		 	Eðer kontrol saðlanmazsa verilen x deðeri geri döndürülür.
    		 	Kontrol saðlanýrsa daha önce baðlanmýþ olan düðümü geri döndürür.
    		
    		3.void donguKontrol(int x, int y);
    			
    			int kavsakUzerindeGezinme(int x); fonksiyonu ile gelen deðerler i ve j deðiþkenlerine atanýr.
    			x deðiþkenine sahip indise y deðiþkeni baðlanýr. Ana düðüm olarak her zaman ilk deðiþken ele alanýr.
    			
    ---------------------------------------------------------------------------------------------------------------------------*/
 
 	for(int i=0;i<dugumSayisi;++i) //Dongu karþýlaþtýrmadan önce dugum listesi ayarlannýyor.
        dongu.push_back(i);
        
	for(int i=0;i<kenarSayisi;i++){
		if(kavsakUzerindeGezinme(vecToplam[i].second.first) != kavsakUzerindeGezinme(vecToplam[i].second.second)){
            donguKontrol(vecToplam[i].second.first, vecToplam[i].second.second);
            lst.push_back(vecToplam[i].second.first);
			lst.push_back(vecToplam[i].second.second);
			maliyetTasarruf=maliyetTasarruf+(vecToplam[i].first);
        }
        maliyet=maliyet+(vecToplam[i].first);
	}
	
	while(!lst.empty()){
		cout<<lst.front();
		lst.pop_front();
		cout<<"-"<<lst.front()<<endl;
		lst.pop_front();
	}
	
	cout<<"Toplam maliyet = "<<maliyetTasarruf<<" AOA Lirasi"<<endl;
	cout<<"Toplam kazanc = "<<maliyet-maliyetTasarruf<<" AOA Lirasi"<<endl;
	
	return 0;
}

//.txt dosyasýndaki kenar&maliyet deðerlerini listeye atýyoruz.
void listAtama(){
	int x;
	fstream dosya;
	dosya.open("sehirplani.txt");
	while (dosya>>x){
		for(int i=0;i<kenarSayisi*3+2;i++){
		cityplan.push_back(x);
		break;}	
	}
	dosya.close();
	
	dugumSayisi=cityplan.front();//dugum sayýsýnýn atanmasý
	cityplan.pop_front(); //.txt dosyasýndaki düðüm sayýsýný attýk.
	kenarSayisi=cityplan.front();//kenar sayýsýnýn atanmasý
	cityplan.pop_front(); //.txt dosyasýndaki kenar sayýsýný attýk.
}

//.txt dosyasýndaki maliyetleri vecMaliyet vektorune taþýyan fonksiyon.
void maliyetAtama(){
	list<int>::iterator it=cityplan.begin();
	it++;//Ýlk maliyet deðerine ulaþmak için iteraturu 2 adým ilettettik.
	it++;
	for(int i=0;i<kenarSayisi;i++){
		vecMaliyet.push_back(*it);//Maliyet deðerlerini vecMaliyet vektörüne atadýk.
		it++;//Ýlk maliyetten sonra .txt dosyasýnda 3 adým iteratoru ilerlettik.
		it++;
		it++;
	}
}

//.txt dosyasýndaki kenarlarý, vecKenar vektorune taþýyan fonksiyon.
void kenarAtama(){
	list<int>::iterator it=cityplan.begin();
	for(int i=0;i<kenarSayisi*2;i++){
		int a=*it;
		it++;
		int b=*it;
		it++;
		it++;
		vecKenar.push_back(make_pair(a,b));	
	}
}

//Dongu olup olmadýðýný için kullanýlan fonksiyonlar
int kavsakUzerindeGezinme(int x){
	while(x != dongu[x]){
	    dongu[x] = dongu[dongu[x]];
	    x = dongu[x];
	}
    return x;
}
void donguKontrol(int x, int y){
   int i = kavsakUzerindeGezinme(x);
   int j = kavsakUzerindeGezinme(y);
   dongu[i] = dongu[j];
}


