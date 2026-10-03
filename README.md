🏦 Banka Yönetim Sistemi

C programlama dili kullanılarak geliştirilmiş, temel bankacılık işlemlerini gerçekleştirebilen konsol tabanlı Banka Yönetim Sistemi projesidir.

Bu proje ile C dilinde struct, pointer, dinamik bellek yönetimi, fonksiyonlar, dosya işlemleri ve diziler gibi temel programlama konularının birlikte kullanılması amaçlanmıştır.

🚀 Projenin Özellikleri

Program üzerinden:

🏦 Yeni banka hesabı oluşturma

📋 Aktif hesapları listeleme

🔎 Hesap numarasına göre hesap arama

💰 Para yatırma

💸 Para çekme

🔄 Hesaplar arası para transferi

❌ Hesap kapatma

📊 Hesapları bakiyeye göre sıralama

🔐 İşlem sırasında şifre doğrulama

💾 Hesap bilgilerini dosyaya kaydetme

📂 Daha önce kaydedilmiş hesap bilgilerini program açılışında yükleme

işlemleri gerçekleştirilebilir.

🛠️ Kullanılan C Konuları

Projede aşağıdaki C programlama konularından yararlanılmıştır:

struct yapıları
Pointer kullanımı
Pointer to pointer (**)
Dinamik bellek yönetimi
malloc()
realloc()
free()
Fonksiyonlar
Fonksiyon prototipleri
Diziler ve karakter dizileri
strcmp() ile string karşılaştırma
switch-case
Döngüler
Koşullu ifadeler
Dosya işlemleri
FILE yapısı
Binary dosya işlemleri
fwrite()
fread()
fopen() / fclose()
📌 Hesap Yapısı

Her hesap aşağıdaki bilgileri içeren bir struct yapısı ile tutulmaktadır:

struct hesap {
    char hesapNumarasi[20];
    char isim[15];
    char soyad[15];
    char sifre[7];
    double bakiye;
    int aktifMi;
};

aktifMi değişkeni sayesinde kapatılan hesapların sistemden tamamen silinmesi yerine pasif hale getirilmesi sağlanmıştır.

💳 Bankacılık İşlemleri
Para Yatırma

Kullanıcı hesap numarasını ve yatırmak istediği tutarı girer. İşlem öncesinde hesap sahibinin şifresi doğrulanır ve bakiye güncellenir.

Para Çekme

Para çekme işleminden önce hesap ve şifre kontrolü yapılır. Hesapta yeterli bakiye bulunmuyorsa işlem gerçekleştirilmez.

Para Transferi

Bir hesaptan başka bir hesaba para transferi yapılabilir.

Transfer sırasında:

Gönderen hesabın mevcut olması
Alıcı hesabın mevcut olması
Hesapların aktif olması
Gönderen hesabın şifre doğrulaması
Yeterli bakiye bulunması
Kişinin kendisine transfer yapmaması
Transfer tutarının 0'dan büyük olması

kontrol edilir.

💾 Veri Saklama

Programda hesap bilgileri binary dosya kullanılarak hesaplar.bin dosyasına kaydedilir.

Program kapatılırken hesap bilgileri dosyaya yazılır:

fwrite()

Program tekrar çalıştırıldığında daha önce kaydedilen bilgiler:

fread()

kullanılarak tekrar belleğe yüklenir.

Bu sayede program kapatıldıktan sonra hesap bilgileri kaybolmaz.

🧠 Dinamik Bellek Yönetimi

Başlangıçta hesaplar için belirli bir kapasite ayrılır. Hesap sayısı kapasiteye ulaştığında realloc() kullanılarak bellekte ayrılan alan genişletilir.

Bu sayede programın sabit sayıda hesapla sınırlandırılması yerine, ihtiyaç oldukça yeni hesapların eklenebilmesi sağlanmıştır.

📊 Hesapları Sıralama

Hesaplar mevcut bakiyelerine göre yüksekten düşüğe sıralanabilir.

Sıralama işleminde Bubble Sort algoritmasından yararlanılmıştır.

🔐 Şifre Doğrulama

Para yatırma, para çekme ve para transferi gibi işlemlerde işlem yapılmadan önce hesap sahibinin şifresi kontrol edilir.

Yanlış şifre girildiğinde işlem iptal edilir.

▶️ Programı Çalıştırma

Projeyi bilgisayarınıza indirdikten sonra herhangi bir C derleyicisi veya IDE kullanarak çalıştırabilirsiniz.

Örneğin GCC kullanıyorsanız:

gcc main.c -o banka
./banka

Program ilk çalıştırıldığında hesaplar.bin dosyası bulunmuyorsa yeni hesaplarla başlanır. Daha önce oluşturulmuş bir hesaplar.bin dosyası varsa kayıtlı hesaplar otomatik olarak yüklenir.

🎯 Projenin Amacı

Bu proje, C programlama dilinde öğrendiğim temel konuları daha kapsamlı bir uygulama üzerinde birleştirmek amacıyla geliştirilmiştir.

Özellikle struct yapıları, pointer kullanımı, dinamik bellek yönetimi, fonksiyonlar ve dosya işlemleri konularında pratik yapmayı hedefledim.

👩‍💻 Geliştirici

Elanur Avcı

Computer Engineering Student
Mersin University

⭐ Projeyi faydalı bulduysanız inceleyebilir ve geliştirme önerilerinizi paylaşabilirsiniz.
