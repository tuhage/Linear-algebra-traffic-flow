# Programlama-Lab.-Proje-1

KOCAELİ ÜNİVERSİTESİ 
BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
BLM210 PROGRAMLAMA LAB. I, 2018-2019
PROJE 1

PROJE TESLİM TARİHİ: 26.10.2018

TRAFİK AKIŞININ MODELLENMESİ
Bu laboratuvarın amacı, trafik akışını modellemek için doğrusal denklem sistemlerinin nasıl kullanılabileceğini göstermektir.
Problem: her cadde üzerinden geçen araçların akış oranını hesaplayınız. Örnek olarak verilen şekil 1 incelendiğinde bazı caddeler üzerinden geçen ortalama araç sayısı belirli iken x1, x2, x3, x4 ve x5 üzerinden geçen araç sayısı bilinmemektedir. Sizden istenen buradan geçen ortalama araç sayısını Gauss Jordan yok etme yöntemi ile çözmenizdir. Not: girişler çıkışlara eşit olmalıdır. 
 
Şekil 1. Örnek Yol Gösterim1



Programlama Dili: Proje C dili kullanılarak gerçekleştirilecektir. 
    1. İsterler
Bir arayüz tasarlamanız beklenmektedir. Şekil 2’de verilen haritalar kullanıcıya sunulacak ve ve kullanıcıdan seçim yapılması istenilecek, bunun için grafik kütüphanelerinden yararlanabilirsiniz. 


Şekil 2. Kullanıcıya Sunulacak İki Farklı Yol Haritası
Harita seçimi yapıldıktan sonra kullanıcıdan cadde yönleri istenecek. x, y, z ve t ana yollar ve bu yollardan ikisi giriş ikisi çıkış olmalı, eğer kullanıcı ikiden fazla giriş ya da çıkış verisi girerse program kontrolünü yaparak kullanıcıdan tekrar veri girmesini isteyecek. a, b, c, d ve e yollarının yön bilgisi için x, y, z ve t yollarından yararlanılmalı. Örneğin şekil 3’te gösterildiği gibi a caddesinin yönü belirlenmek isteniyorsa “Başlangıç Noktası=t, Yönü=x” bilgileri kullanıcı tarafından girilmelidir. Bu bilgiler tüm a, b, c, d ve e yolları için kullanıcıdan alınacaktır. 
Yön bilgileri, harita üzerinde şekiller ile hareketli olarak gösterilecek. Bunun için graphics.h veya allegro.h kütüphanelerinden faydalanabilirsiniz.

 
Şekil 3. Örnek Yön Ataması
Yolların yönünün belirlenmesinin ardından kullanıcıdan caddeler üzerinden geçen araç yoğunluğunun girilmesi istenecek.  Kullanıcı istediği cadde için saatte geçen ortalama araç sayısını girebilmeli eğer bilgi yoksa o cadde için “-1” değeri girilecek. En az bir cadde bilgisi -1 olarak girilecek ve bilinmeyen değer Gauss-Jordan eleme yöntemi ile çözülecektir.  Çözümler matris (iki boyutlu diziler) üzerinden gerçekleştirilecektir. Her işlem adımı ekranda kullanıcıya verilecek ve sonuç yazdırılacaktır. 
İstenilenler:
    • Kullanıcıya iki farklı yol haritası verilecek ve seçim yapılması istenecek
    • Kullanıcı seçim yaptığı harita üzerinde yolların yönünü belirtecek
    • Yönler hareketli şekiller ile harita üzerinde gösterilecek.
    • Kullanıcı caddeler için ortalama araç sayısını girecek, bilgi olmayan cadde için -1 değeri girilecek
    • Bilinmeyen caddeler üzerinde araç akış yoğunluğunun ölçülmesi için Gauss-Jordan eleme yöntemi kullanılacaktır. 
    •  Gauss-Jordan eleme yöntemi sırasında yapılan her işlem ekrana yazdırılacaktır. 

    2. Ödev Teslimi
    • Proje sunum gününde rapor (hard copy) teslim edilmesi gerekmektedir. 
    • Rapor ieee formatında (önceki yıllarda verilen formatta) 4 sayfa, akış diyagramı veya yalancı kod içeren, özet, giriş, yöntem, deneysel sonuçlar, sonuç ve kaynakça bölümünden oluşmalıdır. 
    • Dersin takibi projenin teslimi dahil edestek.kocaeli.edu.tr sistemi üzerinden yapılacaktır. edestek.kocaeli.edu.tr sitesinde belirtilen tarihten sonra getirilen projeler kabul edilmeyecektir. 
    • Proje ile ilgili sorular edestek.kocaeli.edu.tr sitesindeki forum üzerinden Arş. Gör. Seda Kul veya Arş. Gör. Fulya Akdeniz’e sorulabilir. 
    • Demo tarihleri daha sonra duyurulacaktır. 
    • Demo sırasında algoritma, geliştirdiğiniz kodun çeşitli kısımlarının ne amaçla yazıldığı ve geliştirme ortamı hakkında sorular sorulabilir. 
    • Kullandığınız herhangi bir satır kodu açıklamanız istenebilir. 




KOPYA ÇEKTİĞİ YA DA KOPYA VERDİĞİ TESPİT EDİLEN ÖĞRENCİLER İÇİN KOPYA İŞLEMİ UYGULANACAKTIR. 

PROJE EN FAZLA İKİ KİŞİLİK GRUPLAR HALİNDE YAPILACAKTIR.
