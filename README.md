# 🏦 Banka Yönetim Sistemi | Bank Management System

![C Language](https://img.shields.io/badge/Language-C-blue.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)

[🇹🇷 Türkçe](#türkçe) | [🇬🇧 English](#english)

---

## 🇹🇷 Türkçe

C programlama dili kullanılarak geliştirilmiş, temel bankacılık işlemlerini gerçekleştirebilen konsol tabanlı Banka Yönetim Sistemi projesidir.

Bu proje ile C dilinde struct, pointer, dinamik bellek yönetimi, fonksiyonlar, dosya işlemleri ve diziler gibi temel programlama konularının birlikte kullanılması amaçlanmıştır.

### 🚀 Projenin Özellikleri

Program üzerinden:
- 🏦 **Yeni banka hesabı oluşturma**
- 📋 **Aktif hesapları listeleme**
- 🔎 **Hesap numarasına göre hesap arama**
- 💰 **Para yatırma**
- 💸 **Para çekme**
- 🔄 **Hesaplar arası para transferi**
- ❌ **Hesap kapatma**
- 📊 **Hesapları bakiyeye göre sıralama**
- 🔐 **İşlem sırasında şifre doğrulama**
- 💾 **Hesap bilgilerini dosyaya kaydetme**
- 📂 **Daha önce kaydedilmiş hesap bilgilerini program açılışında yükleme**

işlemleri gerçekleştirilebilir.

---

### 🛠️ Kullanılan C Konuları

Projede aşağıdaki C programlama konularından yararlanılmıştır:
- **Struct Yapıları**
- **Pointer Kullanımı & Pointer to Pointer (`**`)**
- **Dinamik Bellek Yönetimi:** `malloc()`, `realloc()`, `free()`
- **Fonksiyonlar ve Fonksiyon Prototipleri**
- **Diziler ve Karakter Dizileri (Strings):** `strcmp()` ile metin karşılaştırma
- **Kontrol Yapıları:** `switch-case`, döngüler, koşullu ifadeler
- **Dosya İşlemleri:** `FILE` yapısı ve Binary dosya işlemleri (`fwrite()`, `fread()`, `fopen()`, `fclose()`)

---

### 📌 Hesap Yapısı

Her hesap aşağıdaki bilgileri içeren bir `struct` yapısı ile tutulmaktadır:

```c
struct hesap {
    char hesapNumarasi[20];
    char isim[15];
    char soyad[15];
    char sifre[7];
    double bakiye;
    int aktifMi;
};
