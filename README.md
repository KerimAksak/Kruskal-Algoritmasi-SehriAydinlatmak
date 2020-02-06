# Kruskal Algoritması - Şehri Aydınlatmak

### Problem tanımı:
-------------
Ekonomik kriz birçok ülkeyi etkilemiş durumda ve AOA ülkesi de bu ülkelerden biridir. Bu nedenle, AOA hükümeti giderleri azaltmak için cadde ışıklandırmalarını optimize etmeye karar verdi. Şimdiye kadar tüm caddelerin bütün ışıkları geceleri açık tutulurdu, maliyeti ise 1 km için 1 AOA lirasıdır. Hükümet bazı ışıkları kapatmaya karar veriyor, ancak yine de güvenli ve huzurlu bir ortam oluşturmak istiyor. Bu güvenlik ortamının bozulmadan tasarruf sağlanabilmesi için herhangi bir kavşaktan bir diğer kavşağa gitmek için mutlaka en az bir tane bütün ışıkları açık olan bir yol (bu yol en kestirme yol olmasa bile) bulunmalıdır. Yollar bir veya daha fazla caddeden oluşabilir. (Kavşaklar caddeleri birbirine bağlar ve caddeler çift şeritlidir, bu yüzden arabalar aynı cadde üzerinden gidiş-geliş yapabilirler.

Size, AOA ülkesindeki bazı şehirlere ait, kavşaklar ve aralarındaki caddenin uzunluğunu kilometre cinsinden gösteren bir şehir planı verilecektir. Hükümetin kısıtlarını da göz önünde bulundurarak, bir gün içinde maksimum kaç AOA Lirası tasarruf edilebilir?

### Şehir planı dosyası formatı:
-------------

Bir şehir m tane kavşaktan ve n tane caddeden oluşmaktadır. Size “cityplan.txt” adında bir giriş dosyası verilecektir. Giriş dosyasının ilk satırı sırasıyla m ve n değerlerini göstermektedir. Sonraki satırlar ise mi. ve mj. kavşaklarını ve bu kavşaklar arasındaki caddenin uzunluğunu gösterir (i != j).

Çıktı olarak, ışıklı caddeleri bağlandıkları kavşaklarla temsil edecek şekilde yazdırınız. Ayrıca toplama maliyeti ve toplam kaç AOA lirası tasarruf edildiğini yazdırınız.

(Tab ile ayırılmıştır)
Giriş dosyası formatı: 
7 11

0 1 7 

0 3 5

1 2 8

1 3 9 

1 4 7

2 4 5 

3 4 15 

3 5 6 

4 5 8

4 6 9

5 6 10


Çıktı formatı: 
0 1 

0 3 

1 4 

2 4 

3 5

4 6
Toplam maliyet = 39 AOA Lirası
Toplam kazanç = 50 AOA Lirası
