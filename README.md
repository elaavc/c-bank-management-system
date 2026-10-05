# 🏦 Banka Yönetim Sistemi | Bank Management System

---

# 🇹🇷 Türkçe

C programlama dili kullanılarak geliştirilmiş, temel bankacılık işlemlerini gerçekleştirebilen **konsol tabanlı Banka Yönetim Sistemi** projesidir.

Bu proje ile C dilinde **struct, pointer, dinamik bellek yönetimi, fonksiyonlar, dosya işlemleri ve diziler** gibi temel programlama konularının birlikte kullanılması amaçlanmıştır.

---

## 🚀 Projenin Özellikleri

Program üzerinden:

* 🏦 **Yeni banka hesabı oluşturma**
* 📋 **Aktif hesapları listeleme**
* 🔎 **Hesap numarasına göre hesap arama**
* 💰 **Para yatırma**
* 💸 **Para çekme**
* 🔄 **Hesaplar arası para transferi**
* ❌ **Hesap kapatma**
* 📊 **Hesapları bakiyeye göre sıralama**
* 🔐 **İşlem sırasında şifre doğrulama**
* 💾 **Hesap bilgilerini dosyaya kaydetme**
* 📂 **Daha önce kaydedilmiş hesap bilgilerini program açılışında yükleme**

işlemleri gerçekleştirilebilir.

---

## 🛠️ Kullanılan C Konuları

Projede aşağıdaki C programlama konularından yararlanılmıştır:

* **Struct yapıları**
* **Pointer kullanımı**
* **Pointer to Pointer (`**`)**
* **Dinamik bellek yönetimi:** `malloc()`, `realloc()`, `free()`
* **Fonksiyonlar ve fonksiyon prototipleri**
* **Diziler ve karakter dizileri (string):** `strcmp()`
* **Kontrol yapıları:** `switch-case`, döngüler, koşullu ifadeler
* **Dosya işlemleri:** `FILE` yapısı
* **Binary dosya işlemleri:** `fwrite()`, `fread()`, `fopen()`, `fclose()`

---

## 📌 Hesap Yapısı

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
```

`aktifMi` değişkeni sayesinde kapatılan hesapların sistemden tamamen silinmesi yerine **pasif hale getirilmesi** sağlanmıştır.

---

## 💳 Bankacılık İşlemleri

### 💰 Para Yatırma

Kullanıcı hesap numarasını ve yatırmak istediği tutarı girer. İşlem öncesinde hesap sahibinin şifresi doğrulanır ve bakiye güncellenir.

### 💸 Para Çekme

Para çekme işleminden önce hesap ve şifre kontrolü yapılır. Hesapta yeterli bakiye bulunmuyorsa işlem gerçekleştirilmez.

### 🔄 Para Transferi

Bir hesaptan başka bir hesaba para transferi yapılabilir.

Transfer sırasında:

* Gönderen hesabın mevcut olması
* Alıcı hesabın mevcut olması
* Hesapların aktif olması
* Gönderen hesabın şifre doğrulaması
* Yeterli bakiye bulunması
* Kişinin kendisine transfer yapmaması
* Transfer tutarının `0`'dan büyük olması

kontrol edilir.

---

## 💾 Veri Saklama

Programda hesap bilgileri binary dosya kullanılarak `hesaplar.bin` dosyasına kaydedilir.

Program kapatılırken hesap bilgileri:

```c
fwrite()
```

kullanılarak dosyaya yazılır.

Program tekrar çalıştırıldığında daha önce kaydedilmiş bilgiler:

```c
fread()
```

kullanılarak tekrar belleğe yüklenir.

Bu sayede program kapatıldıktan sonra hesap bilgileri kaybolmaz.

---

## 🧠 Dinamik Bellek Yönetimi

Başlangıçta hesaplar için belirli bir kapasite ayrılır.

Hesap sayısı mevcut kapasiteye ulaştığında `realloc()` kullanılarak bellekte ayrılan alan genişletilir.

Bu sayede programın sabit sayıda hesapla sınırlandırılması yerine, **ihtiyaç oldukça yeni hesapların eklenebilmesi** sağlanmıştır.

---

## 📊 Hesapları Sıralama

Hesaplar mevcut bakiyelerine göre **yüksekten düşüğe** sıralanabilir.

Sıralama işleminde **Bubble Sort algoritmasından** yararlanılmıştır.

---

## 🔐 Şifre Doğrulama

Para yatırma, para çekme ve para transferi gibi işlemlerde işlem yapılmadan önce hesap sahibinin şifresi kontrol edilir.

Yanlış şifre girildiğinde işlem iptal edilir.

---

## ▶️ Programı Çalıştırma

Projeyi bilgisayarınıza indirdikten sonra herhangi bir C derleyicisi veya IDE kullanarak çalıştırabilirsiniz.

Örneğin GCC kullanıyorsanız:

```bash
gcc main.c -o banka
./banka
```

Program ilk çalıştırıldığında `hesaplar.bin` dosyası bulunmuyorsa yeni hesaplarla başlanır.

Daha önce oluşturulmuş bir `hesaplar.bin` dosyası varsa kayıtlı hesaplar otomatik olarak yüklenir.

---

## 🎯 Projenin Amacı

Bu proje, C programlama dilinde öğrendiğim temel konuları daha kapsamlı bir uygulama üzerinde birleştirmek amacıyla geliştirilmiştir.

Özellikle **struct yapıları, pointer kullanımı, dinamik bellek yönetimi, fonksiyonlar ve dosya işlemleri** konularında pratik yapmayı hedefledim.

---

## 👩‍💻 Geliştirici

**Elanur Avcı**

Computer Engineering Student
Mersin University

⭐ Projeyi faydalı bulduysanız inceleyebilir ve geliştirme önerilerinizi paylaşabilirsiniz.

---

# 🇬🇧 English

A **console-based Bank Management System** developed in the C programming language that performs basic banking operations.

The main goal of this project is to practice and combine fundamental C programming concepts—such as **structs, pointers, dynamic memory management, functions, file handling, and arrays**—in a comprehensive application.

---

## 🚀 Project Features

The program allows users to:

* 🏦 **Create** a new bank account
* 📋 **List** active accounts
* 🔎 **Search** for an account by account number
* 💰 **Deposit** money
* 💸 **Withdraw** money
* 🔄 **Transfer** money between accounts
* ❌ **Close** an account
* 📊 **Sort** accounts by balance
* 🔐 **Verify** passwords during transactions
* 💾 **Save** account information to a file
* 📂 **Load** previously saved account information automatically on application startup

---

## 🛠️ C Concepts Used

The following C programming concepts and functions are utilized in this project:

* **Structures (`struct`)**
* **Pointers**
* **Pointer to Pointer (`**`)**
* **Dynamic Memory Management:** `malloc()`, `realloc()`, `free()`
* **Functions & Function Prototypes**
* **Arrays & Character Arrays (Strings):** `strcmp()`
* **Control Flow:** `switch-case`, loops, conditional statements
* **File Handling:** `FILE` structure
* **Binary File Operations:** `fwrite()`, `fread()`, `fopen()`, `fclose()`

---

## 📌 Account Structure

Each account is stored using a `struct` containing the following attributes:

```c
struct hesap {
    char hesapNumarasi[20];
    char isim[15];
    char soyad[15];
    char sifre[7];
    double bakiye;
    int aktifMi;
};
```

The `aktifMi` variable is used to mark closed accounts as **inactive** instead of completely removing them from the system.

---

## 💳 Banking Operations

### 💰 Deposit Money

The user enters the account number and the amount to deposit. Before the transaction is completed, the account owner's password is verified and the balance is updated.

### 💸 Withdraw Money

The account and password are checked before a withdrawal is performed. If the account does not have sufficient funds, the transaction is not completed.

### 🔄 Money Transfer

The system allows users to transfer money from one account to another.

The following conditions are checked during a transfer:

* The sender's account exists
* The recipient's account exists
* Both accounts are active
* The sender's password is verified
* The sender has sufficient balance
* The sender cannot transfer money to their own account
* The transfer amount must be greater than `0`

---

## 💾 Data Storage

Account information is stored in a binary file named `hesaplar.bin`.

When the program is closed, account information is written to the file using:

```c
fwrite()
```

When the program starts again, previously saved account information is loaded into memory using:

```c
fread()
```

This allows account information to be preserved even after the program is closed.

---

## 🧠 Dynamic Memory Management

The program initially allocates a specific capacity for storing accounts.

When the number of accounts reaches the current capacity, `realloc()` is used to expand the allocated memory.

This allows the program to dynamically support additional accounts instead of being limited to a fixed number of accounts.

---

## 📊 Account Sorting

Accounts can be sorted according to their balance from **highest to lowest**.

The **Bubble Sort algorithm** is used for the sorting operation.

---

## 🔐 Password Verification

Before performing operations such as depositing, withdrawing, or transferring money, the account owner's password is verified.

If an incorrect password is entered, the transaction is cancelled.

---

## ▶️ How to Run

After downloading the project, it can be compiled and executed using any C compiler or IDE.

For example, using GCC:

```bash
gcc main.c -o banka
./banka
```

When the program is run for the first time, if the `hesaplar.bin` file does not exist, the system starts without any previously saved accounts.

If a previously created `hesaplar.bin` file exists, the saved account information is automatically loaded.

---

## 🎯 Project Purpose

This project was developed to combine the fundamental C programming concepts I have learned into a more comprehensive application.

In particular, I aimed to gain practical experience with **structs, pointers, dynamic memory management, functions, and file handling**.

---

## 👩‍💻 Developer

**Elanur Avcı**

Computer Engineering Student
Mersin University

⭐ If you find this project useful, feel free to explore the code and share your suggestions for improvement.
