# Kruskal Algoritmas� - �ehri Ayd�nlatmak

### Problem tan�m�:
-------------
Ekonomik kriz bir�ok �lkeyi etkilemi� durumda ve AOA �lkesi de bu �lkelerden biridir. Bu nedenle, AOA h�k�meti giderleri azaltmak i�in cadde ���kland�rmalar�n� optimize etmeye karar verdi. �imdiye kadar t�m caddelerin b�t�n ���klar� geceleri a��k tutulurdu, maliyeti ise 1 km i�in 1 AOA liras�d�r. H�k�met baz� ���klar� kapatmaya karar veriyor, ancak yine de g�venli ve huzurlu bir ortam olu�turmak istiyor. Bu g�venlik ortam�n�n bozulmadan tasarruf sa�lanabilmesi i�in herhangi bir kav�aktan bir di�er kav�a�a gitmek i�in mutlaka en az bir tane b�t�n ���klar� a��k olan bir yol (bu yol en kestirme yol olmasa bile) bulunmal�d�r. Yollar bir veya daha fazla caddeden olu�abilir. (Kav�aklar caddeleri birbirine ba�lar ve caddeler �ift �eritlidir, bu y�zden arabalar ayn� cadde �zerinden gidi�-geli� yapabilirler.

Size, AOA �lkesindeki baz� �ehirlere ait, kav�aklar ve aralar�ndaki caddenin uzunlu�unu kilometre cinsinden g�steren bir �ehir plan� verilecektir. H�k�metin k�s�tlar�n� da g�z �n�nde bulundurarak, bir g�n i�inde maksimum ka� AOA Liras� tasarruf edilebilir?

### �ehir plan� dosyas� format�:
-------------

Bir �ehir m tane kav�aktan ve n tane caddeden olu�maktad�r. Size �cityplan.txt� ad�nda bir giri� dosyas� verilecektir. Giri� dosyas�n�n ilk sat�r� s�ras�yla m ve n de�erlerini g�stermektedir. Sonraki sat�rlar ise mi. ve mj. kav�aklar�n� ve bu kav�aklar aras�ndaki caddenin uzunlu�unu g�sterir (i != j).

��kt� olarak, ���kl� caddeleri ba�land�klar� kav�aklarla temsil edecek �ekilde yazd�r�n�z. Ayr�ca toplama maliyeti ve toplam ka� AOA liras� tasarruf edildi�ini yazd�r�n�z.

(Tab ile ay�r�lm��t�r)
Giri� dosyas� format�: 
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

��kt� format�: 
0 1 
0 3 
1 4 
2 4 
3 5
4 6
Toplam maliyet = 39 AOA Liras�
Toplam kazan� = 50 AOA Liras�