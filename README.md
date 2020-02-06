# Kruskal Algoritmasý - Þehri Aydýnlatmak

### Problem tanýmý:
-------------
Ekonomik kriz birçok ülkeyi etkilemiþ durumda ve AOA ülkesi de bu ülkelerden biridir. Bu nedenle, AOA hükümeti giderleri azaltmak için cadde ýþýklandýrmalarýný optimize etmeye karar verdi. Þimdiye kadar tüm caddelerin bütün ýþýklarý geceleri açýk tutulurdu, maliyeti ise 1 km için 1 AOA lirasýdýr. Hükümet bazý ýþýklarý kapatmaya karar veriyor, ancak yine de güvenli ve huzurlu bir ortam oluþturmak istiyor. Bu güvenlik ortamýnýn bozulmadan tasarruf saðlanabilmesi için herhangi bir kavþaktan bir diðer kavþaða gitmek için mutlaka en az bir tane bütün ýþýklarý açýk olan bir yol (bu yol en kestirme yol olmasa bile) bulunmalýdýr. Yollar bir veya daha fazla caddeden oluþabilir. (Kavþaklar caddeleri birbirine baðlar ve caddeler çift þeritlidir, bu yüzden arabalar ayný cadde üzerinden gidiþ-geliþ yapabilirler.

Size, AOA ülkesindeki bazý þehirlere ait, kavþaklar ve aralarýndaki caddenin uzunluðunu kilometre cinsinden gösteren bir þehir planý verilecektir. Hükümetin kýsýtlarýný da göz önünde bulundurarak, bir gün içinde maksimum kaç AOA Lirasý tasarruf edilebilir?

### Þehir planý dosyasý formatý:
-------------

Bir þehir m tane kavþaktan ve n tane caddeden oluþmaktadýr. Size “cityplan.txt” adýnda bir giriþ dosyasý verilecektir. Giriþ dosyasýnýn ilk satýrý sýrasýyla m ve n deðerlerini göstermektedir. Sonraki satýrlar ise mi. ve mj. kavþaklarýný ve bu kavþaklar arasýndaki caddenin uzunluðunu gösterir (i != j).

Çýktý olarak, ýþýklý caddeleri baðlandýklarý kavþaklarla temsil edecek þekilde yazdýrýnýz. Ayrýca toplama maliyeti ve toplam kaç AOA lirasý tasarruf edildiðini yazdýrýnýz.

(Tab ile ayýrýlmýþtýr)
Giriþ dosyasý formatý: 
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

Çýktý formatý: 
0 1 
0 3 
1 4 
2 4 
3 5
4 6
Toplam maliyet = 39 AOA Lirasý
Toplam kazanç = 50 AOA Lirasý