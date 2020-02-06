//ABD�LKER�M AKSAK
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

void listAtama();//list<int> cityplan; listesine genel olarak dosyay� atama yapan fonksiyon.
void maliyetAtama();//vector<int> vecMaliyet; vectorune maliyetleri atayan fonksiyon.
void kenarAtama();//vector< pair <int,int> > vecKenar; vectorune kenar ikililerini atayan fonksiyon.

//Dongu olup olmad���n� kontrol eden fonksiyonlar.
int kavsakUzerindeGezinme(int x);
void donguKontrol(int x, int y);

list<int> cityplan;//.txt dosyas�n� genel olarak tutacak liste.
list<int> lst;
vector<int> dongu;//donguyu kontrol edecek vector

vector<int> vecMaliyet;//.txt dosyas�ndaki t�m maliyet listesi.
vector< pair <int,int> > vecKenar;//.txt dosyas�ndaki t�m kenar listesi.
vector< pair <int, pair<int, int> > > vecToplam;//kenar ve maliyetleri tek ba��na tutan vector

int kenarSayisi=0;
int dugumSayisi=0;
int maliyetTasarruf=0;
int maliyet=0;

int main() {
	listAtama();//list<int> cityplan; listesine .txt dosyas�n� atanmas�.
	maliyetAtama();//vector<int> vecMaliyet; vectorune maliyetlerin atanmas�.
	kenarAtama();//vector< pair <int,int> > vecKenar; vectorune kenar ikililerinin atanmas�.
		     
	for(int i=0;i<kenarSayisi;i++){
		vecToplam.push_back(make_pair(vecMaliyet[i],make_pair(vecKenar[i].first,vecKenar[i].second)));//T�m veriler tek bir vektor i�ine toplan�yor.
	}
	sort(vecToplam.begin(),vecToplam.end());//Maliyet listesi i�in s�ralama i�lemi ger�ekle�tirilir.
	
 	/*--------------------------------------------------------------------------------------------------
    D�ng� mant���;
    	�rnek olarak 0,1,2,3 d���mleri aras�nda 0-1/0-2/1-2/1-3 ikilileri verilsin.
    	G�r�ld��� �zere 0-1/0-2/1-2 ikilileri bir d�ng� olu�turmaktad�r.
    	
    	�ncelikle d�ng� kontolu iki fonksiyon ve bir vektor yard�m�yla yap�lmaktad�r.
    	
    		1.	for(int i=0;i<dugumSayisi;++i)
       				 dongu.push_back(i);
       				 
       			>dongu vectoru ile d���m say�s� kadar veri olu�turup her veriye kendi indisi atanm��t�r.
    		Bu sayede t�m d���mler tekil durumda bulunmaktad�r.
    		
    		2. int kavsakUzerindeGezinme(int x);
    		 	
    		 	Fonksiyon ile dongu vectorune ba�ka bir d���m eklenmi� mi diye while d�ng�s�yle kontrol edilir.
    		 	E�er kontrol sa�lanmazsa verilen x de�eri geri d�nd�r�l�r.
    		 	Kontrol sa�lan�rsa daha �nce ba�lanm�� olan d���m� geri d�nd�r�r.
    		
    		3.void donguKontrol(int x, int y);
    			
    			int kavsakUzerindeGezinme(int x); fonksiyonu ile gelen de�erler i ve j de�i�kenlerine atan�r.
    			x de�i�kenine sahip indise y de�i�keni ba�lan�r. Ana d���m olarak her zaman ilk de�i�ken ele alan�r.
    			
    ---------------------------------------------------------------------------------------------------------------------------*/
 
 	for(int i=0;i<dugumSayisi;++i) //Dongu kar��la�t�rmadan �nce dugum listesi ayarlann�yor.
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

//.txt dosyas�ndaki kenar&maliyet de�erlerini listeye at�yoruz.
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
	
	dugumSayisi=cityplan.front();//dugum say�s�n�n atanmas�
	cityplan.pop_front(); //.txt dosyas�ndaki d���m say�s�n� att�k.
	kenarSayisi=cityplan.front();//kenar say�s�n�n atanmas�
	cityplan.pop_front(); //.txt dosyas�ndaki kenar say�s�n� att�k.
}

//.txt dosyas�ndaki maliyetleri vecMaliyet vektorune ta��yan fonksiyon.
void maliyetAtama(){
	list<int>::iterator it=cityplan.begin();
	it++;//�lk maliyet de�erine ula�mak i�in iteraturu 2 ad�m ilettettik.
	it++;
	for(int i=0;i<kenarSayisi;i++){
		vecMaliyet.push_back(*it);//Maliyet de�erlerini vecMaliyet vekt�r�ne atad�k.
		it++;//�lk maliyetten sonra .txt dosyas�nda 3 ad�m iteratoru ilerlettik.
		it++;
		it++;
	}
}

//.txt dosyas�ndaki kenarlar�, vecKenar vektorune ta��yan fonksiyon.
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

//Dongu olup olmad���n� i�in kullan�lan fonksiyonlar
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


