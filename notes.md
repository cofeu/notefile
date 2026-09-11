# C DİLİ DERS NOTLARI

## Veri Tipleri & Format Belirleyiciler (Format Specifiers)

| Belirleyici | Veri Tipi | Açıklama | Örnek |
|---|---|---|---|
| `%c` | char | Tek karakter | `'A'` |
| `%d` | int | Tam sayı | `10` |
| `%f` | float | Ondalık sayı | `3.14f` |
| `%lf` | double | Hassas ondalık sayı | `3.141592` |
| `%s` | string (char dizisi) | Karakter dizisi | `"Merhaba"` |
| `%p` | pointer | Bellek adresi | `0x7ffe...` |
| `%u` | unsigned int | Pozitif tam sayı | — |
| `%x` | — | 16'lık taban (hexadecimal) | — |

---

## Bellek Boyutları ve `sizeof` Operatörü

`sizeof(tip)` → bir değişkenin bellekte kaç Byte yer kapladığını döner.

| Tip | Boyut | Aralık / Not |
|---|---|---|
| char | 1 Byte (8-bit) | -128 ile 127 arası |
| int | 4 Byte (32-bit) | -2,147,483,648 ile 2,147,483,647 |
| float | 4 Byte (32-bit) | 6-7 basamak hassasiyet |
| double | 8 Byte (64-bit) | 15-17 basamak hassasiyet |
| pointer | 8 Byte | 64-bit sistemlerde adres boyutu sabittir |

> Not: Pointer'ın boyutu, gösterdiği veri tipinden **bağımsızdır**. `int *p` de `char *p` de `double *p` de 64-bit sistemde 8 Byte'tır — çünkü pointer sadece bir **adres** tutar, adresin kendisi her zaman aynı uzunluktadır.

---

## Aritmetik Operatörler

| Operatör | Anlamı |
|---|---|
| `+` | Toplama |
| `-` | Çıkarma |
| `*` | Çarpma |
| `/` | Bölme (İki int bölünürse sonuç tam sayı çıkar: `5 / 2 = 2`) |
| `%` | Modül (Bölümünden kalanı verir: `5 % 2 = 1`) |
| `++` | Artırma (`a++` veya `++a`) |
| `--` | Azaltma (`a--` veya `--a`) |

---

## Karşılaştırma (İlişkisel) Operatörleri

Sonuç: `1` (Doğru) veya `0` (Yanlış)

| Operatör | Anlamı |
|---|---|
| `==` | Eşit mi? |
| `!=` | Eşit değil mi? |
| `>` | Büyük mü? |
| `<` | Küçük mü? |
| `>=` | Büyük veya eşit |
| `<=` | Küçük veya eşit |

---

## Mantıksal Operatörler (Koşulları Birleştirme)

| Operatör | Anlamı |
|---|---|
| `&&` | VE (AND) — her iki koşul da doğruysa 1 döner |
| `\|\|` | VEYA (OR) — koşullardan en az biri doğruysa 1 döner |
| `!` | DEĞİL (NOT) — koşulun tersini alır (`!1 = 0`, `!0 = 1`) |

> **Dikkat:** Mantıksal (`&&`, `||`) ile Bitwise (`&`, `|`) operatörleri karıştırılmamalı. Mantıksal olanlar koşulları (true/false) birleştirir, bitwise olanlar sayıların bit'leri üzerinde işlem yapar.

---

## Atama Operatörleri

| Operatör | Açıklamı |
|---|---|
| `=` | Atama |
| `+=` | Toplama ve atama (`x += 5` → `x = x + 5`) |
| `-=` | Çıkarma ve atama |
| `*=` | Çarpma ve atama |
| `/=` | Bölme ve atama |
| `%=` | Modül ve atama |
| `&=` | Bitwise AND ve atama |
| `\|=` | Bitwise OR ve atama |
| `^=` | Bitwise XOR ve atama |
| `>>=` | Bitwise Right Shift ve atama |
| `<<=` | Bitwise Left Shift ve atama |

---

## Bit Tabanlı Mantıksal Tablolar

### 1. AND (`&`) Operatörü (VE Kapısı)
Sadece iki bit de 1 (doğru) olduğunda sonuç 1 olur.

| X | Y | X & Y |
|---|---|---|
| 1 | 1 | 1 |
| 1 | 0 | 0 |
| 0 | 1 | 0 |
| 0 | 0 | 0 |

### 2. OR (`\|`) Operatörü (VEYA Kapısı)
Girişlerden en az bir tanesi 1 ise sonuç 1 olur.

| X | Y | X \| Y |
|---|---|---|
| 1 | 1 | 1 |
| 1 | 0 | 1 |
| 0 | 1 | 1 |
| 0 | 0 | 0 |

### 3. XOR (`^`) Operatörü (Özel VEYA Kapısı)
Girişler birbirinden farklı olduğunda sonuç 1 olur.

| X | Y | X ^ Y |
|---|---|---|
| 1 | 1 | 0 |
| 1 | 0 | 1 |
| 0 | 1 | 1 |
| 0 | 0 | 0 |

### 4. NOT (`~`) Operatörü (Tümleyen / Invert)
Bitleri tersine çevirir (1'i 0, 0'ı 1 yapar).

### 5. Bit Shift (Kaydırma) Operatörleri
- `<<` Sola kaydırma: bitleri sola kaydırır (`x << n` → `x * 2^n` ile çarpar)
- `>>` Sağa kaydırma: bitleri sağa kaydırır (`x >> n` → `x / 2^n` ile böler)
- Örn: `5 (00000101) << 1 → 10 (00001010)`

### Binary (İkili Sistem) Mantığı

```
0 0 0 0 0 1 1 1 = 7   çünkü 1 + 2 + 4 = 7   | 8-bit
        2^2 2^1 2^0
0 0 0 0 0 0 1 1 = 3   çünkü 1 + 2 = 3       | 8-bit
```

---

## Kontrol Akışı (Akış Kontrolü)

| Yapı | Açıklama |
|---|---|
| `if` | Belirtilen koşul doğruysa çalışır |
| `else if` | İlk koşul yanlışsa yeni koşul test eder |
| `else` | Hiçbir koşul uymazsa çalışacak varsayılan blok |
| `switch` | Tek bir değişkenin sabit değerlerine (`case`) göre dallanma sağlar |

---

## Döngüler (Loops)

| Yapı | Açıklama |
|---|---|
| `for` | Adım sayısı belli olan döngüler için: `for(int i=0; i<10; i++)` |
| `while` | Koşul sağlandığı sürece dönen döngü: `while(kosul)` |
| `do..while` | En az 1 kez çalışması garanti olan döngü |
| `break` | Döngüyü anında sonlandırır ve dışarı çıkar |
| `continue` | Döngünün o anki adımını atlar, bir sonraki adıma geçer |

---

## POINTER (İŞARETÇİ) — DETAYLI KONU

Pointer'lar, C'de en kritik ve genellikle en çok zorlanılan konudur. Ama mantığı aslında basittir: **her değişkenin bellekte bir adresi vardır**, ve pointer bu adresi tutan özel bir değişkendir.

### Temel Operatörler

| Operatör | Anlamı |
|---|---|
| `&` (Adres Operatörü) | Değişkenin bellekteki adresini verir (`&a` → `a`'nın adresi) |
| `*` (Dereference / Değer) | Adresteki değeri okur veya değiştirir (`*p` → `p` adresindeki değer) |

> Dikkat: `*` iki farklı bağlamda iki farklı anlama gelir:
> - **Tanımlarken:** `int *p;` → "p bir pointer'dır" demektir
> - **Kullanırken:** `*p` → "p'nin gösterdiği adresteki değer" demektir

### Temel Örnek

```c
int a = 10;
int *p = &a;   // p, a'nın adresini tutuyor
*p = 20;       // a'nın değeri artık 20 oldu!
```

### Bellek Üzerinde Görselleştirme

```
Bellek:
┌─────────┐
│ a = 10  │  ← adresi: 0x7ffc...387c
└─────────┘

┌──────────────────┐
│ p = 0x7ffc...387c │  ← p bu adresi TUTUYOR
└──────────────────┘
```

`*p = 20` dediğinde: "p'nin tuttuğu adrese git, oradaki kutuyu 20 yap" demek olur. O adresteki kutu zaten `a` olduğu için, `a` da 20 olur.

### Pass by Value vs Pass by Reference (Pointer ile)

C'de bir fonksiyona normal bir değişken gönderildiğinde, fonksiyon o değişkenin **kopyasıyla** çalışır. Orijinal değişkeni değiştiremez:

```c
void degistir(int sayi) {
    sayi = 100;   // sadece kopyayı değiştirir
}

int main() {
    int x = 5;
    degistir(x);
    printf("%d\n", x);  // 5 yazdırır — x değişmedi!
}
```

Ama fonksiyona değişkenin **adresini** (pointer) gönderirsek, fonksiyon gerçek değişkeni değiştirebilir:

```c
void degistir(int *p) {
    *p = 100;   // p'nin gösterdiği gerçek değeri değiştirir
}

int main() {
    int x = 5;
    degistir(&x);        // dikkat: x değil, &x gönderiyoruz
    printf("%d\n", x);   // 100 yazdırır — x gerçekten değişti!
}
```

| Versiyon | Fonksiyona ne gönderilir | Ne değişir | Sonuç |
|---|---|---|---|
| `degistir(int sayi)` | x'in **kopyası** | sadece kopya | main'deki x değişmez |
| `degistir(int *p)` | x'in **adresi** | gerçek x | main'deki x değişir |

Bu ayrım C'de **pass by value** (değere göre geçiş) ve **pass by reference** (pointer ile taklit edilen referansa göre geçiş) olarak adlandırılır. C'de gerçek "reference" tipi yoktur; pointer ile aynı etki elde edilir.

### Pratik Örnek: Swap (Takas) Fonksiyonu

İki değişkenin değerini takas etmek, pointer kullanmadan **imkansızdır** — çünkü fonksiyonlar kopyalarla çalışır. Pointer ile çözümü:

```c
void takas(int *a, int *b) {
    int temp = *a;   // 1) temp = a'nın değeri (geçici sakla)
    *a = *b;         // 2) a'nın yerine b'nin değerini yaz
    *b = temp;       // 3) b'nin yerine temp'i (eski a'yı) yaz
}

int main() {
    int x = 5, y = 10;
    takas(&x, &y);
    printf("x = %d, y = %d\n", x, y);  // x = 10, y = 5
}
```

`temp` burada geçici bir "tutucu" görevi görür — çünkü `*a = *b` yapıldığı an `a`'nın eski değeri kaybolur; `temp` olmasaydı bu değeri `b`'ye aktaramazdık. (İki bardaktaki suyu değiştirmek için üçüncü boş bir bardağa ihtiyaç duyulması gibi.)

### Pointer'ın Gösterdiği Yer Değişebilir

Bir pointer sabit bir değişkene "mahkum" değildir — istediğin zaman başka bir adrese yönlendirebilirsin:

```c
int a = 5, b = 20;
int *p = &a;

p = &b;      // p artık a'yı değil, b'yi gösteriyor!
*p = 50;     // b'nin değeri değişir, a'ya hiç dokunulmaz

printf("a = %d, b = %d\n", a, b);  // a = 5, b = 50
```

> **Altın kural:** `p = &b` → p'nin **kendisi** değişir (artık nereyi gösterdiği değişir). `*p = 50` → p'nin **gösterdiği yerdeki değer** değişir. İkisi tamamen farklı işlemlerdir.

### Pointer Kullanırken Yaygın Hata: `*` Unutmak

```c
int tutanAdres = 10;
int *p = &tutanAdres;

p = 50;      // YANLIŞ! p'nin kendisini (adresini) 50 yapar — tehlikeli
*p = 50;     // DOĞRU! p'nin gösterdiği yerdeki değeri 50 yapar
```

`p = 50` dersen, `tutanAdres`'e hiç dokunmazsın — bunun yerine `p`'yi geçersiz bir adrese (`0x32`) yönlendirmiş olursun. Derleyici genelde şöyle bir uyarı verir:

```
warning: assignment to 'int *' from 'int' makes pointer from integer without a cast
```

Bu satırdan sonra `*p` kullanmaya kalkarsan (örn. `*p = 99`), program büyük ihtimalle **çöker** (segmentation fault) çünkü 50 numaralı bellek adresine erişim/yazma iznin yok.

> **Kısaca:** `p`'nin kendisiyle (nereyi gösterdiğiyle) ilgileniyorsan `p = ...` yaz, ama sağ tarafa mutlaka bir **adres** ver (`&x` gibi), düz sayı değil. `p`'nin gösterdiği yerdeki **değeri** değiştirmek istiyorsan `*p = ...` yaz.

### Pointer'a Pointer (Double Pointer — `**`)

Bir pointer'ın adresini tutan pointer'a "pointer'a pointer" denir. `**` demek, iki kat pointer'ın içinden geçip en sonunda gerçek değere ulaşmak demektir.

```c
int a = 3;
int *p = &a;     // p, a'nın adresini tutuyor
int **pp = &p;   // pp, p'nin adresini tutuyor

**pp = 99;       // pp'den p'ye, p'den a'ya git, a'yı 99 yap

printf("%d\n", a);  // 99
```

| İfade | Ne verir |
|---|---|
| `p` | a'nın adresi |
| `pp` | p'nin adresi ("p'nin evinin adresi") |
| `*pp` | pp'nin gösterdiği yerdeki değer = p'nin içindeki değer = a'nın adresi |
| `**pp` | iki kat dereference → a'nın kendisi |

```
pp ──► p ──► a
```

`p` ve `pp`'nin kendi içerikleri (hangi adresleri tuttukları) hiç değişmez — sadece zincirin sonundaki `a` değişir. `*` sayısı, "kaç kat pointer'ın içinden geçtiğini" gösterir.

### Pointer Pratiğinde Altın Kurallar

- **`X = Y` her zaman:** Y'yi oku (değiştirme), X'e yaz. `*q = *p` → `*p`'yi oku, `*q`'ya yaz. Sağ taraf hep okunur, sol taraf hep yazılır.
- **Bir kod satırından sonra kendine sor:** "şu an p neyi gösteriyor, q neyi gösteriyor?" — değerleri değil, **okları** takip et. Pointer'ın kendisi (p=...) mi değişti, yoksa gösterdiği yerdeki değer (*p=...) mi değişti, bunu ayırt et.

### void Pointer (Genel Amaçlı İşaretçi)

`void *` herhangi bir tipteki veriye işaret edebilen, tip bilgisi taşımayan bir pointer'dır. Kullanmadan önce doğru tipe **cast** edilmesi gerekir:

```c
int sayi = 10;
void *ptr = &sayi;
printf("%d", *(int*)ptr);  // int'e cast edip değeri okuyoruz
```

`malloc` gibi fonksiyonlar her zaman `void*` döndürür, çünkü hangi tip için bellek ayırdıklarını bilmezler:

```c
int *dizi = (int*) malloc(5 * sizeof(int));
```

---

## Diziler (Arrays) ve String Kavramı

- **Dizi:** Aynı tipteki verilerin bellekte ardışık dizilmesidir.
  ```c
  int sayilar[5] = {10, 20, 30, 40, 50}; // sayilar[0] ilk elemandır (10)
  ```
- **String:** C'de string diye ayrı bir tip yoktur, char dizisidir.
  ```c
  char isim[] = "Yustea";
  ```
  > Not: C string'lerinin sonuna otomatik olarak `'\0'` (Null Terminator) eklenir! Yani `"Yustea"` 6 harf görünse de bellekte 7 Byte kaplar.

> **Bağlantı noktası:** Dizi isimleri aslında C'de ilk elemanın adresine "çürüyerek" (decay) dönüşür — yani `sayilar` neredeyse `&sayilar[0]` gibi davranır. Bu yüzden diziler ve pointer'lar C'de çok yakından ilişkilidir; dizi öğrenirken pointer bilgisi doğrudan işine yarayacak.

---

## Yapılar (Structs) ve typedef

Farklı veri tiplerini tek bir çatı altında toplamak için kullanılır.

```c
struct Ogrenci {
    char isim[50];
    int no;
};

typedef struct Ogrenci Ogrenci; // Ogrenci tip adı oluşturur
```

---

## Kütüphaneler

| Kütüphane | Sağladığı |
|---|---|
| `#include <stdbool.h>` | `true` / `false` (bool) desteği |
| `#include <stdio.h>` | `printf`, `scanf`, `fopen` gibi I/O işlemleri |
| `#include <stdlib.h>` | `malloc`, `free`, `exit` gibi sistem işlemleri |
| `#include <string.h>` | `strlen`, `strcpy`, `strcmp` gibi string fonksiyonları |

---

## FONKSİYONLAR — DETAYLI KONU

Bir işi yapan, tekrar tekrar çağırabilen kod bloğudur. Amaç: aynı kodu defalarca yazmamak.

### Temel Yapı

```c
donusTipi fonksiyonAdi(parametreler) {
    // kod
    return deger;  // (void değilse)
}
```

```c
int topla(int a, int b) {
    return a + b;
}

int main() {
    int sonuc = topla(3, 5);
    printf("%d\n", sonuc);  // 8
}
```

- `int` → fonksiyonun **döndürdüğü** değerin tipi
- `topla` → fonksiyonun adı
- `(int a, int b)` → **parametreler**
- `return a+b;` → sonuç, çağrıldığı yere geri gönderilir

### Scope (Kapsam)

Bir fonksiyon içinde tanımlanan değişkenler **sadece o fonksiyona özeldir**, dışarıdan görünmez:

```c
int carp(int x, int y) {
    int sonuc = x * y;   // sonuc sadece carp() içinde var
    return sonuc;
}

int main() {
    printf("%d\n", sonuc);  // HATA! sonuc burada tanımlı değil
}
```

**Aynı isimli değişken, farklı kapsam (shadowing):**

```c
int x = 10;   // global x

void fonksiyon() {
    int x = 99;   // bu, global x'i "gölgeler" ama ona dokunmaz — ayrı bir kutu
    printf("%d\n", x);   // 99
}

int main() {
    fonksiyon();
    printf("%d\n", x);   // 10 — hiç değişmedi
}
```

> Bir fonksiyon içinde aynı isimde yeni bir değişken tanımlarsan (`int x = ...`), bu her zaman **yeni, ayrı bir kutu** yaratır — dış kapsamdaki aynı isimli değişkene asla dokunmaz.

### Pass by Value — Fonksiyon Parametreleri Kopyadır

```c
int x = 5;

void degistir(int x) {
    x = 100;    // bu, dışarıdaki x'in KOPYASINI değiştirir
}

int main() {
    degistir(x);
    printf("%d\n", x);   // 5 — hiç değişmedi
}
```

`degistir(x)` çağrıldığında fonksiyon, dışarıdaki `x`'in değerini kendi parametresine **kopyalar**. İkisi aynı isme sahip olsa da tamamen ayrı iki kutudur.

> **Dikkat:** Bu davranış `void` ile ilgili değildir! `void` sadece "fonksiyon değer döndürmüyor" demektir. Fonksiyon `int` döndürse ve `return x;` yapsa bile (`return`'lenen değer `main`'e taşınsa bile), dışarıdaki orijinal `x` yine değişmez — çünkü mesele hep **pass by value**'dur, `void`/`int` farkı değil.

**Orijinal değişkeni gerçekten değiştirmenin tek yolu: pointer**

| Fonksiyon | x (main'de) | Neden |
|---|---|---|
| `void degistir(int x) { x=100; }` | 5 kalır | kopya değişti, orijinal etkilenmedi |
| `int degistir(int x) { x=100; return x; }` | 5 kalır | kopya değişti, `return` sadece sonucu dışarı taşıdı |
| `void degistir(int *p) { *p=100; }` | **100 olur** | pointer ile gerçek adrese ulaşıldı |

```c
void ikiKatiYap(int *p) {
    *p = *p * 2;
}

int main() {
    int x = 7;
    ikiKatiYap(&x);   // x = 14
    ikiKatiYap(&x);   // x = 28
    printf("%d\n", x);
}
```

### İşlem Önceliği (Operatör Precedence)

Matematikteki gibi bir öncelik sırası var — C bu konuda farklı davranmaz:

```
1. Parantez ()
2. Çarpma *, Bölme /, Modül %   (soldan sağa)
3. Toplama +, Çıkarma -          (soldan sağa)
```

```c
int sonuc = 10 + 2 * 3;   // önce 2*3=6, sonra 10+6=16
```

> Emin olamadığında parantez kullanmak her zaman güvenlidir: `10 + (2 * 3)`.

### İç İçe Fonksiyon Çağrıları

**Kural:** En içteki fonksiyon her zaman önce çalışır, sonucu dışarıdaki fonksiyona parametre olarak gider — soğan gibi dıştan içe değil, **içten dışa** çözülür.

```c
int ikiEkle(int x) {
    return x + 2;
}

int main() {
    int sonuc = ikiEkle(ikiEkle(3));
    // Adım 1: ikiEkle(3) = 5
    // Adım 2: ikiEkle(5) = 7
    printf("%d\n", sonuc);  // 7
}
```

### Sıralı İşlemler — Satırlar Yukarıdan Aşağıya Çalışır

```c
int islem(int a, int b) {
    int sonuc = a * b;   // sonuc, a ve b DEĞİŞMEDEN ÖNCE hesaplanır
    a = 0;                // sadece kopya a'yı etkiler
    b = 0;                // sadece kopya b'yi etkiler
    return sonuc;
}

int main() {
    int x = 4, y = 5;
    int sonuc = islem(x, y);
    printf("x=%d y=%d sonuc=%d\n", x, y, sonuc);
    // x=4 y=5 sonuc=20
}
```

`sonuc` satırı çalıştığında `a` ve `b` henüz orijinal değerlerindeydi (4 ve 5), o yüzden `sonuc = 20` olarak sabitlendi. Sonraki `a=0; b=0;` satırları hem geç kaldı hem de sadece kopyaları etkiledi — `sonuc`'u da `x, y`'yi de değiştiremedi.

### `static` Anahtar Kelimesi

`static`'in anlamı, **nerede kullanıldığına göre değişir:**

| Kullanım yeri | `static` ne yapar |
|---|---|
| Fonksiyon önünde | Fonksiyonu sadece bulunduğu `.c` dosyasına hapseder — başka dosyalardan çağrılamaz |
| Değişken önünde (fonksiyon içi) | Değişkenin değerini fonksiyon çağrıları arasında **korur**, her çağrıda sıfırlanmaz |

```c
// static fonksiyon örneği
static void logHata(char *mesaj) {
    printf("HATA: %s\n", mesaj);
}
// Bu fonksiyon sadece bulunduğu dosyada çağrılabilir.
```

```c
// static değişken örneği
void sayac() {
    static int kacKere = 0;   // sadece İLK çağrıda 0'a atanır
    kacKere++;
    printf("%d\n", kacKere);
}

int main() {
    sayac();  // 1
    sayac();  // 2
    sayac();  // 3
}
```

> **Not (C# / Java'dan gelenler için):** `public`, `private`, `protected` gibi erişim belirleyiciler C'de **yoktur** — bunlar nesne yönelimli dillere (OOP) özgüdür. C'de `static` fonksiyon, kabaca C#'taki `private`'a benzer bir amaca hizmet eder (görünürlüğü kısıtlamak), ama **sınıf** seviyesinde değil **dosya** seviyesinde çalışır, çünkü C'de "sınıf" kavramı yoktur.

### Fonksiyon Pratiğinde Sık Yapılan Hatalar

- İşlem önceliğini unutup soldan sağa düz toplama yapmak (`a + b * c` → önce `b*c`, sonra toplama)
- Pointer olmayan parametrelerde orijinal değişkenin değişeceğini sanmak (pass by value unutmak)
- İç içe çağrılarda dıştan içe değil, **içten dışa** çözülmesi gerektiğini unutmak
- Sıralı işlemlerde bir değişkenin sonradan değişmesinin, önceki satırlarda zaten hesaplanmış bir değeri etkilemeyeceğini unutmak

---

## int/int Bölme Tuzağı (Çok Sık Yapılan Hata)

C'de **iki int'i böldüğünde sonuç her zaman int'tir**, ondalık kısım atılır (kesme, yuvarlama değil):

```c
int a = 405 / 5;      // 81      (tam bölünüyor, sorun yok)
int b = 9 / 4;         // 2       (9/4=2.25 ama ondalık atılır!)
float c = 9 / 4;       // 2.00 !! (float'a atasan bile bölme İNT olarak yapıldı, sonra çevrildi)
```

**Sonucu `float` bir değişkene atman, bölmenin ondalıklı yapılacağı anlamına GELMEZ.** Önemli olan, bölme işlemine giren sayıların kendi tipi.

**Ondalıklı bölme istiyorsan**, bölmeye giren sayılardan **en az biri** `float`/`double` olmalı:

```c
float d = 9 / 4.0;        // 2.25  (4.0 float olduğu için ondalıklı bölme)
float e = (float)9 / 4;   // 2.25  (cast ile 9'u float'a çevirdik)
```

> **Altın kural:** Ondalıklı bölme için bölme **anındaki** tipler önemli, sonucu koyduğun değişkenin tipi değil.

---

## DİZİLER (Arrays) — DETAYLI KONU

### 1D Dizi — Bir Kutu Sırası

```c
int a[5] = {10, 20, 30, 40, 50};
```

```
 [0]  [1]  [2]  [3]  [4]
┌────┬────┬────┬────┬────┐
│ 10 │ 20 │ 30 │ 40 │ 50 │
└────┴────┴────┴────┴────┘
```

- İndeksler **0'dan başlar**: ilk eleman `a[0]`, son eleman `a[4]` (yani `boyut - 1`).
- `a[2]` demek: "0'dan başlayarak 2 kutu say, oradaki değeri al" → **30** (üçüncü eleman, 2. eleman değil!).
- N elemanlı bir dizide geçerli indeksler her zaman `0`'dan `N-1`'e kadardır.

### Python List ile Farkları

| Özellik | Python `list` | C `array` |
|---|---|---|
| Boyut | Dinamik, büyütülebilir | **Sabit** — tanımlandığında kilitlenir |
| Tip | Karışık tip tutabilir | **Tek tip** (`int a[5]` sadece int) |
| `.append()`, `.pop()` | Var | **Yok** — C dizisi ham bellek, metodu yok |
| Sınır kontrolü | Aşarsan hata verir (`IndexError`) | **Kontrol YOK** — sınırı aşarsan program sessizce bozulur veya çöker |

```c
int a[3] = {1, 2, 3};
printf("%d\n", a[5]);  // ÇALIŞABİLİR ama anlamsız/çöp değer verir — C seni KORUMAZ
```

### Döngü ile Dizide Gezinmek

```c
int notlar[5] = {70, 85, 90, 60, 100};
int toplam = 0;

for (int i = 0; i < 5; i++) {
    toplam += notlar[i];
}
// toplam = 70+85+90+60+100 = 405
```

`i < 5` şartı yüzünden `i` değerleri `0,1,2,3,4` olur — **5 tane** değer, tüm dizi bir kez, eksiksiz gezilir.

### 2D Dizi — Kutu Sıralarının Üst Üste Dizilmesi

```c
int m[2][3] = {
    {10, 20, 30},
    {40, 50, 60}
};
```

```
satır 0:  [0][0]  [0][1]  [0][2]
          ┌────┬────┬────┐
          │ 10 │ 20 │ 30 │
          └────┴────┴────┘

satır 1:  [1][0]  [1][1]  [1][2]
          ┌────┬────┬────┐
          │ 40 │ 50 │ 60 │
          └────┴────┴────┘
```

`m[satır][sütun]` demek: **önce hangi satıra ineceğini söyle, sonra o satırın içinde hangi sütuna bakacağını söyle.**

```c
m[0][0] = 10   // satır 0 → sütun 0
m[0][2] = 30   // satır 0 → sütun 2
m[1][0] = 40   // satır 1 → sütun 0
m[1][1] = 50   // satır 1 → sütun 1
```

> **Hatırlatma tekniği:** "Önce aşağı in (satır), sonra sağa git (sütun)." İlk indeks satır, ikinci indeks sütun.

### İç İçe (Nested) Döngü ile 2D Diziyi Gezmek

```c
int tahta[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

for (int i = 0; i < 3; i++) {           // dış döngü: satırlar
    for (int j = 0; j < 3; j++) {       // iç döngü: sütunlar
        printf("%d ", tahta[i][j]);
    }
    printf("\n");   // her satır bitince alt satıra geç
}
```

Çıktı:
```
1 2 3
4 5 6
7 8 9
```

Bu yapı, oyun tahtası (tic-tac-toe, mayın tarlası gibi) ekrana basmanın temel yöntemidir — dış döngü satırları, iç döngü her satırın sütunlarını gezer.

### Char Dizisiyle Tahta Örneği (Tic-Tac-Toe için)

```c
char tahta[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
```

> **Dikkat:** `''` (içi boş tek tırnak) **geçersizdir** — bir `char` her zaman tam olarak bir karakter içermelidir. Boşluk karakteri için `' '` yazılır (içinde bir boşluk var).

Bir hücreye hamle yazmak:
```c
int satir, sutun;
scanf("%d %d", &satir, &sutun);   // scanf her zaman ADRES ister (&)
tahta[satir][sutun] = 'X';
```

### Diziler ve Pointer İlişkisi (İpucu)

Dizi isimleri C'de neredeyse ilk elemanın adresine "çürüyerek" (decay) dönüşür — yani `a` neredeyse `&a[0]` gibi davranır. Bu yüzden diziler ve pointer'lar C'de çok yakından ilişkilidir (ileride pointer aritmetiği konusunda detaylandırılacak).

---

## scanf Kullanırken Sık Yapılan Hatalar

### 1. `&` Unutmak

```c
scanf("%d", sayi);    // YANLIŞ! scanf her zaman ADRES ister
scanf("%d", &sayi);   // DOĞRU
```

### 2. `%c` ile Char Okurken Boşluk Unutmak

```c
scanf("%d%d", &sayi1, &sayi2);
scanf("%c", &islem);     // YANLIŞ! Önceki scanf'ten kalan Enter (\n) karakterini okur
scanf(" %c", &islem);    // DOĞRU! Baştaki boşluk, bekleyen boşluk/enter karakterlerini atlar
```

Bir `%d` ile sayı okuduktan sonra, kullanıcının bastığı **Enter tuşu** (`\n`) hâlâ giriş kuyruğunda bekler. Bir sonraki `%c` bu `\n`'i gerçek karakter olarak okuyabilir. `%c`'den **önce bir boşluk** koymak bu sorunu çözer.

---

## 0'a Bölme (Division by Zero)

C'de int/int'i `0`'a bölmek **tanımsızdır** ve programı çökertir:

```
Floating point exception (core dumped)
```

Python'daki gibi düzgün bir hata (`ZeroDivisionError`) vermez — program aniden sonlanır. Bu yüzden bölme işleminden **önce** her zaman kontrol etmek gerekir:

```c
if (sayi2 == 0) {
    printf("Hata: 0'a bolme yapilamaz!\n");
} else {
    printf("Sonuc: %d\n", bol(sayi1, sayi2));
}
```

> **Dikkat:** Bu kontrolü sadece **bölme işleminin içine** koy — `sayi2 == 0` genel bir kontrolmüş gibi tüm işlemlerin (toplama, çıkarma, çarpma) önüne koyarsan, `5 + 0` gibi tamamen geçerli işlemleri de yanlışlıkla engellemiş olursun. `0` sadece **bölme** için sorunludur.

> **Genel prensip:** Kullanıcı girdisine asla güvenme — olası hataları (0'a bölme, dizi sınırı aşma, geçersiz karakter) önceden kontrol et.

---

## Uygulama: Basit Hesap Makinesi Projesi

Öğrenilen konuları (fonksiyon, switch/case, scanf, hata kontrolü) birleştiren tam bir örnek:

```c
#include <stdio.h>

int topla(int x, int y) { return x + y; }
int cikar(int x, int y) { return x - y; }
int carp(int x, int y) { return x * y; }
int bol(int x, int y)  { return x / y; }

int main() {
    printf("HESAP MAKINESI\n");
    int sayi1, sayi2;
    char islem;

    printf("Sayilari girin: ");
    scanf("%d%d", &sayi1, &sayi2);

    printf("Yapacaginiz islem (+, -, /, *): ");
    scanf(" %c", &islem);   // basindaki bosluga dikkat

    switch(islem) {
        case '+':
            printf("Sonuc: %d\n", topla(sayi1, sayi2));
            break;
        case '-':
            printf("Sonuc: %d\n", cikar(sayi1, sayi2));
            break;
        case '*':
            printf("Sonuc: %d\n", carp(sayi1, sayi2));
            break;
        case '/':
            if (sayi2 == 0) {
                printf("HATA: 0'a bolme yapilamaz!\n");
            } else {
                printf("Sonuc: %d\n", bol(sayi1, sayi2));
            }
            break;
        default:
            printf("Boyle bir islem bulunamadi..\n");
            break;
    }
    return 0;
}
```

Bu projede kullanılan konular: fonksiyon tanımlama/return, `switch/case` + `break`, `scanf` ile sayı/char okuma, `0`'a bölme kontrolü, `default` ile geçersiz girdi kontrolü.

---

## Devam Eden Proje: Tic-Tac-Toe (XOX)

**Tamamlanan adımlar:**
1. ✅ Tahtayı 2D dizi (`char tahta[3][3]`) olarak oluşturma, `' '` ile başlatma
2. ✅ Tahtayı iç içe döngü ile ekrana bastırma
3. ✅ Kullanıcıdan satır/sütun alma (`scanf("%d %d", &satir, &sutun)`)
4. ✅ Seçilen hücreye işaret koyma (`tahta[satir][sutun] = 'X'`)
5. ✅ Sonsuz döngü (`while(10)`) yerine kontrollü döngü (`for (int hamle=0; hamle<9; hamle++)`) kullanma

**Kalan adımlar:**
- X ve O'yu sırayla koymak (`char oyuncu = 'X'`, her turdan sonra `if/else` ile değiştirmek)
- Aynı hücreye ikinci kez basmayı engellemek (hücre doluysa uyarı verip tekrar sormak)
- Kazananı kontrol etmek (satır/sütun/çapraz aynı harften oluşunca oyunu bitirmek) — projenin en öğretici kısmı
- Geçersiz satır/sütun girişini (0-2 dışı) kontrol etmek

---

## STRING'LER (Char Dizileri) — DETAYLI KONU

C'de ayrı bir "string" tipi **yoktur** — string dediğimiz şey aslında bir `char` dizisidir:

```c
char isim[] = "Yusuf";
```

### En Kritik Kavram: `'\0'` (Null Terminator)

C, bir string'in **nerede bittiğini** bilmek için özel bir işaretçi karaktere ihtiyaç duyar — bu karakter `'\0'` (null terminator, değeri 0 olan bir karakter).

```c
char isim[] = "Yusuf";
```

Bellekte şöyle durur:

```
 [0]  [1]  [2]  [3]  [4]  [5]
┌────┬────┬────┬────┬────┬────┐
│ Y  │ u  │ s  │ u  │ f  │ \0 │
└────┴────┴────┴────┴────┴────┘
```

`"Yusuf"` **5 harf** görünse de, bellekte **6 byte** kaplar — C, string'in sonuna otomatik olarak `'\0'` ekler. Bu olmasaydı `printf` gibi fonksiyonlar string'in nerede bittiğini bilemez, belleği okumaya devam eder, çöp karakterler yazdırırdı.

### `%s` ile Yazdırma

```c
char isim[] = "Yusuf";
printf("%s\n", isim);   // Yusuf
```

Dikkat: `%s` ile yazdırırken `&isim` değil **`isim`** yazılır — dizi ismi zaten neredeyse bir adrese "çürüdüğü" için (bkz. Diziler bölümü), `printf` bu adresten başlayıp `'\0'`'a kadar okur.

### `strlen`'in Arka Planda Yaptığı (Elle Yazılmış Hâli)

`strlen`, dizide gezip `'\0'`'a rastlayana kadar sayar:

```c
char kelime[] = "Merhaba";
int i = 0;

while (kelime[i] != '\0') {
    i++;
}
// i artık uzunluğu tutuyor (7)
```

### `string.h` Kütüphanesi — Hazır Fonksiyonlar

| Fonksiyon | Ne yapar | Örnek |
|---|---|---|
| `strlen(s)` | String uzunluğunu döner (`'\0'` sayılmaz) | `strlen("Kod")` → 3 |
| `strcmp(a, b)` | İki string'i karşılaştırır | aşağıda detaylı |
| `strcpy(hedef, kaynak)` | String kopyalar | aşağıda detaylı |

```c
#include <string.h>

char kelime[] = "Merhaba";
printf("%d\n", strlen(kelime));   // 7
```

### `strcmp` — String Karşılaştırma (== KULLANMA!)

**String'leri `==` ile karşılaştıramazsın!** Bu çok sık yapılan bir hata:

```c
char a[] = "kedi";
char b[] = "kedi";

if (a == b) {   // YANLIŞ! İçeriği değil, ADRESLERİ karşılaştırır — her zaman false
```

`a` ve `b` farklı bellek adreslerinde olduğu için, içerikleri aynı olsa bile `a == b` her zaman **false** döner. Doğrusu `strcmp`:

```c
if (strcmp(a, b) == 0) {   // 0 dönerse, string'ler AYNI demektir
    printf("Ayni\n");
}
```

> **Dikkat, kontra-entüitif nokta:** `strcmp`, string'ler **aynıysa 0** döner (true/1 değil!). "0 = eşit" mantığını aklında tut.

### `strcpy` — String Kopyalama

```c
char kaynak[] = "Merhaba";
char hedef[20];   // yeterince büyük olmalı!

strcpy(hedef, kaynak);   // kaynak'ı hedef'e kopyalar
printf("%s\n", hedef);   // Merhaba
```

### `scanf` ile String Okumak

```c
char isim[20];
scanf("%s", isim);   // dikkat: & YOK! Dizi ismi zaten adrese çürüyor
```

`%d` ile sayı okurken `&sayi` gerekiyordu, ama string için `&` **gerekmez** — `isim` zaten `&isim[0]` gibi davranır.

**Önemli sınırlama:** `scanf("%s", ...)` **boşlukta durur**. Kullanıcı `"Ahmet Yilmaz"` girerse, `scanf("%s", isim)` sadece `"Ahmet"`'i okur, `"Yilmaz"` giriş kuyruğunda kalır. Boşluklu tam metin okumak için `fgets()` gibi farklı bir fonksiyon gerekir (ileri seviye konu).

---

## STRUCT'LAR (Yapılar) — DETAYLI KONU

Farklı veri tiplerini tek bir çatı altında toplamak için kullanılır. Örneğin bir "öğrenci" kavramı: isim (string), yaş (int), not ortalaması (float) — bunları ayrı ayrı değişkenler yerine **tek bir birim** hâlinde tutabilirsin.

### Tanımlama ve Kullanma

```c
struct Ogrenci {
    char isim[20];
    int yas;
    float ortalama;
};

int main() {
    struct Ogrenci ogr1;
    strcpy(ogr1.isim, "Yusuf");
    ogr1.yas = 20;
    ogr1.ortalama = 85.5;

    printf("Isim: %s, Yas: %d, Ortalama: %.1f\n", ogr1.isim, ogr1.yas, ogr1.ortalama);
}
```

### `.` (Nokta) Operatörü

Bir struct değişkeninin içindeki bir alana (üyeye) erişmek için kullanılır. `ogr1.yas` → "ogr1'in içindeki yas alanına git" demek.

### Struct Pointer ve `->` Operatörü

Bir struct'a da pointer ile işaret edilebilir, tıpkı `int *p` gibi:

```c
struct Ogrenci ogr1 = {"Ahmet", 20};
struct Ogrenci *p = &ogr1;   // p, ogr1'in ADRESİNİ tutuyor
```

**Sorun:** `p.yas` çalışmaz, çünkü `p` bir struct değil, bir **adres**. `.` operatörü sadece gerçek struct'lar üzerinde çalışır.

**Çözüm 1 (uzun yol):**
```c
(*p).yas = 20;   // önce *p ile struct'a ulaş, sonra .yas ile alana eriş
```

**Çözüm 2 — `->` operatörü (kısayol, tercih edilen):**
```c
p->yas = 20;   // (*p).yas ile TAMAMEN AYNI ŞEY, sadece daha kısa
```

> **Kısaca:**
> - `.` → struct'ın **kendisi** üzerinden erişim (`ogr1.yas`)
> - `->` → struct'a **pointer** üzerinden erişim (`p->yas`)
> - `->`, aslında `(*p).` yazmanın kısayoludur

### Struct'ı Fonksiyona Pointer Olarak Geçmek (Pass by Reference)

```c
void yasArttir(struct Ogrenci *p) {
    p->yas = p->yas + 1;
}

int main() {
    struct Ogrenci ogr1 = {"Ahmet", 20};
    yasArttir(&ogr1);
    printf("%d\n", ogr1.yas);   // 21 — gerçek struct değişti!
}
```

`p`, `ogr1`'in adresini tuttuğu için, `p->yas` üzerinden yapılan değişiklik **gerçek `ogr1`'e yansır** — tıpkı `int *p` ile yaptığımız pass-by-reference'ın aynısı, sadece struct için.

### Struct Dizisi

Birden fazla struct'ı bir arada tutmak için (örn. birden fazla öğrenci):

```c
struct Ogrenci sinif[3] = {
    {"Ahmet", 20},
    {"Ayse", 22},
    {"Mehmet", 21}
};

printf("%s\n", sinif[1].isim);   // Ayse
printf("%d\n", sinif[2].yas);    // 21
```

İndeksleme, normal `int` dizisiyle **aynı mantık** (`[0], [1], [2]`, 0'dan başlar) — sadece her "kutu" artık bir struct, içine `.` ile erişiliyor.

---

## Kendi Yazdığın String Fonksiyonları (Pratik Örnekler)

`strcmp` ve `strcpy`'nin arka planda nasıl çalıştığını gösteren, kendi yazdığın implementasyonlar:

### Kendi `strcmp`'in

```c
void karsilatirStr(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0') {
        if (a[i] != b[i]) {
            printf("%d harf uyusmuyor\n", i);
            return;
        }
        i++;
    }
    printf("Kelimeler ayni\n");
}
```

Mantık: harf harf gez, bir farka rastlarsan hemen bildirip çık (`return`); döngü sonuna kadar hiç fark çıkmazsa "aynı" de.

### Kendi `strcpy`'in

```c
void kopyaStr(char x[], char y[]) {
    int i = 0;
    while (y[i] != '\0') {
        x[i] = y[i];
        i++;
    }
    x[i] = '\0';   // KRİTİK: null terminator'ı elle eklemeyi unutma!
}
```

Mantık: kaynağın (`y`) her karakterini hedefe (`x`) kopyala; döngü `'\0'`'da durduğu için, `'\0'`'ı ayrıca elle eklemek gerekir — aksi hâlde hedef string düzgün "bitmez".

---

## Uygulama: Öğrenci Not Sistemi Projesi (Struct Dizisi + Döngü)

Struct, struct dizisi, scanf/& kuralları, scope ve int/float bölmeyi bir araya getiren tam bir örnek:

```c
#include <stdio.h>

typedef struct Ogrenci {
    char isim[20];
    int yas;
    int not;
} Ogrenci;

int main() {
    Ogrenci sinif[3];
    int toplam = 0;

    // 1. Veri toplama döngüsü
    for (int i = 0; i < 3; i++) {
        printf("Isim: ");
        scanf("%s", sinif[i].isim);        // isim bir DİZİ, & yok

        printf("Yas: ");
        scanf("%d", &sinif[i].yas);        // yas bir INT, & var

        printf("Not: ");
        scanf("%d", &sinif[i].not);        // not bir INT, & var
    }

    // 2. Yazdırma + toplama döngüsü
    for (int i = 0; i < 3; i++) {
        printf("Isim: %s, Yas: %d, Not: %d\n", sinif[i].isim, sinif[i].yas, sinif[i].not);
        toplam = toplam + sinif[i].not;
    }

    // 3. Ortalama - DÖNGÜLERİN DIŞINDA, tek seferlik hesaplanır
    float ortalama = toplam / 3.0;   // 3.0 dikkat: int/int bölme tuzağı!
    printf("Sinif ortalamasi: %.2f\n", ortalama);

    return 0;
}
```

### Bu Projede Öğrenilen Kritik Noktalar

**1. `&` kuralı struct alanlarında da geçerli:**
```c
scanf("%s", sinif[i].isim);   // dizi → & YOK
scanf("%d", &sinif[i].yas);   // int → & VAR
```

**2. "Biriktirici" değişken (`toplam`) döngünün DIŞINDA, sadece bir kere tanımlanmalı:**
```c
int toplam = 0;              // DÖNGÜLERDEN ÖNCE, bir kere
for (...) {
    toplam = toplam + ...;   // döngü içinde İÇİNDE "int" YOK, sadece GÜNCELLENİYOR
}
```
Eğer `int toplam = ...` döngü **içine** konursa, her adımda yeniden sıfırdan tanımlanır — bir önceki adımın toplamı kaybolur.

**3. Ortalama gibi "tüm veri toplandıktan sonra" hesaplanması gereken işlemler, döngünün DIŞINDA (kapanış `}`'inden sonra) yapılmalı:**
```c
for (...) {
    toplam = toplam + sinif[i].not;
}
// döngü BİTTİ, toplam artık TAM — ortalama burada hesaplanır
float ortalama = toplam / 3.0;
```
Eğer bu döngünün içinde yapılırsa, ortalama her öğrenciden sonra (henüz eksik bir toplamla) hatalı şekilde tekrar tekrar hesaplanır.

**4. `typedef struct` kullanımı:**
```c
typedef struct Ogrenci {
    ...
} Ogrenci;   // artık "struct Ogrenci" yerine sadece "Ogrenci" yazılabilir
```

---

## MALLOC (Dinamik Bellek Yönetimi) — DETAYLI KONU

`malloc` (memory allocate = "bellek ayır"), C'de **çalışma anında** (programın çalıştığı sırada, kod yazarken değil) bellekten yer istemeni sağlayan bir fonksiyondur. `stdlib.h` kütüphanesinde bulunur.

### Neden Gerekli?

Normal diziler (`int a[5]`) boyutu **kod yazarken** (derleme anında) sabitlenir. Ama gerçek hayatta, "kaç eleman gerekecek" genelde **kullanıcının girdiği bir sayıya** bağlıdır — bu, kod yazarken bilinemez. `malloc`, boyutu **çalışma anında** belirlemeni sağlar.

### Temel Kullanım

```c
#include <stdlib.h>

int *dizi = malloc(n * sizeof(int));
```

- `sizeof(int)` → bir `int`'in kaç byte olduğunu verir (genelde 4)
- `n * sizeof(int)` → n tane int için toplam kaç byte gerektiğini hesaplar
- `malloc(...)` → bu kadar byte'lık boş bellek ayırır, başlangıç **adresini** (pointer) döndürür
- Ayrılan bellek, normal bir dizi gibi `dizi[0]`, `dizi[1]` şeklinde kullanılabilir

> **Önemli:** `malloc`, bir **pointer** döndürür — sayı değil. Bu yüzden sonucu her zaman bir pointer değişkenine atarız (`int *dizi = ...`).

### `free()` — Belleği Geri Vermek

```c
free(dizi);   // artık kullanmadığın belleği geri ver
```

`malloc` ile aldığın bellek, sen `free` etmedikçe **program bitene kadar** senin elinde kalır. `free` etmezsen buna **bellek sızıntısı (memory leak)** denir — program uzun süre çalıştıkça (özellikle döngü içinde tekrar tekrar malloc yapılıp free edilmezse) bellek gitgide tükenir, program yavaşlar ya da çöker. Bu, hemen bir hataya yol açmaz ama sinsi bir sorundur.

### Struct + Malloc Birleşimi (Dinamik Liste)

Sabit boyutlu bir struct dizisini (`Ogrenci sinif[3];`) dinamik hâle getirmek için:

```c
typedef struct Ogrenci {
    char isim[20];
    int not;
} Ogrenci;

int main() {
    int n;
    printf("Kac ogrenci var: ");
    scanf("%d", &n);

    Ogrenci *sinif = malloc(n * sizeof(Ogrenci));   // sizeof(Ogrenci) dikkat!

    int toplam = 0;

    for (int i = 0; i < n; i++) {
        printf("Isim: ");
        scanf("%s", sinif[i].isim);
        printf("Not: ");
        scanf("%d", &sinif[i].not);
    }

    for (int i = 0; i < n; i++) {
        printf("Isim: %s | Not: %d\n", sinif[i].isim, sinif[i].not);
        toplam = toplam + sinif[i].not;
    }

    float ortalama = toplam / (float)n;   // n değişken olduğu için (float) cast gerekli
    printf("Ortalama: %.2f\n", ortalama);

    free(sinif);
    return 0;
}
```

### Dikkat Edilecek Noktalar

- `malloc`'tan dönen pointer de **normal dizi gibi `[]` ile** kullanılır — `->` gerekmez! `sinif[i].isim` doğru, `sinif->isim[i]` **yanlış** bir karışıklıktır.
- `n` bir **değişken** olduğu için `n.0` gibi sabit yazamazsın; ondalık bölme için `(float)n` ile **cast** yapman gerekir.
- `n`'i almadan önce (`scanf("%d", &n);`), kullanıcıya ne istediğini açıklayan bir `printf` koymayı **unutma** — yoksa kullanıcı ne gireceğini bilemez, yanlış bir şey girerse `n` tanımsız/çöp bir değer alır (bu da örneğin `toplam / (float)n` işleminde `-nan` gibi geçersiz sonuçlara yol açabilir).
- `malloc` ile ayrılan bellek işin sonunda mutlaka `free()` ile geri verilmeli.

---

## RASTGELE SAYI ÜRETME (rand) — DETAYLI KONU

C'de Python'daki `random` modülünün karşılığı `stdlib.h` (ve zaman tabanlı "tohum" için `time.h`) içindedir.

### Temel Kullanım

```c
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));   // "tohum" (seed) ayarla — SADECE BİR KERE, main'in başında

    int sayi = rand();          // 0 ile RAND_MAX arası rastgele bir sayı
    int zar = rand() % 6 + 1;   // 1-6 arası rastgele sayı (zar atma gibi)
}
```

| Fonksiyon | Ne yapar |
|---|---|
| `srand(seed)` | Rastgele sayı üretecini "tohumlar" — bunu yapmazsan her çalıştırmada **aynı** sayılar çıkar |
| `srand(time(NULL))` | Tohum olarak şu anki zamanı kullanır — bu yüzden her çalıştırmada farklı sonuç alınır |
| `rand()` | `0` ile `RAND_MAX` (çok büyük bir sayı) arası rastgele bir `int` döner |
| `rand() % n` | `0` ile `n-1` arası bir sayı üretir (n farklı olası sonuç) |

> **Kritik nokta — `srand` kaç kere çağrılmalı?** `srand(time(NULL))` sadece **bir kere**, programın en başında çağrılmalı. Döngü içine konursa, aynı saniye içinde birden fazla çağrıldığında hep **aynı** sayıyı üretmeye başlar (çünkü `time(NULL)` saniye hassasiyetinde çalışır) — bu bir hataya yol açar.

### `rand() % n` ile Kaç Farklı Sonuç Üretilir?

`rand() % n` ifadesi, tam olarak **`0`'dan `n-1`'e kadar** (n tane) farklı sonuç üretir — `n`'in kendisi **asla** çıkmaz.

```c
int olasilik = rand() % 4;   // olası değerler: 0, 1, 2, 3  (4 ASLA ÇIKMAZ!)
```

> **Sık yapılan hata:** `rand() % 4` kullanıp, kontrol ederken `if (olasilik == 4)` yazmak — bu satır **hiçbir zaman** çalışmaz, çünkü `% 4` en fazla `3` üretir. Kontrol şartların, üretilen aralıkla (`0` ile `n-1` arası) birebir örtüşmeli.

### Rastgele Olaya Göre Dallanma (if/else if ile)

```c
int olasilik = rand() % 4;   // 0,1,2,3 arası

if (olasilik == 0) {
    // 1. olay
} else if (olasilik == 1) {
    // 2. olay
} else if (olasilik == 2) {
    // 3. olay
} else if (olasilik == 3) {
    // 4. olay
}
```

Her `olasilik` değeri için bir dal yazarak, "hangi rastgele olayın gerçekleştiğine" karar verilir.

---

## sleep() — Programı Duraklatma

`unistd.h` kütüphanesinde bulunur (Linux/Mac için).

```c
#include <unistd.h>

sleep(1);   // programı 1 SANİYE durdurur, sonra kaldığı yerden devam eder
```

Bir döngüde "her turdan sonra biraz bekle" gibi bir efekt (örneğin metin tabanlı bir oyunda "gün" hissi vermek) için kullanılır. Test ederken uzun süreler (`sleep(60)` gibi) yerine kısa süreler (`sleep(1)`) kullanmak, geliştirme sürecini hızlandırır.

---

## Uygulama: Zombi Hayatta Kalma Simülatörü (rand + struct + döngü)

`struct`, `rand()`, `sleep()`, çok dallı `if/else if` ve döngü çıkış şartını bir araya getiren örnek proje:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct Karakter {
    int can;
    int aclik;
    int mermi;
    int gun;
} Karakter;

int main() {
    srand(time(NULL));   // BİR KERE, en başta

    Karakter insan;
    insan.can = 100;
    insan.aclik = 100;
    insan.mermi = 1000;
    insan.gun = 0;

    while (1) {
        sleep(1);   // test için kısa; gerçek oyunda daha uzun tutulabilir
        insan.gun++;
        printf("Gun: %d\n", insan.gun);

        int olasilik = rand() % 4;   // 0,1,2,3 - kontroller bu aralıkla eşleşmeli

        if (olasilik == 0) {
            printf("Zombi saldirdi! Caniniz azaldi\n");
            insan.can -= 90;
        } else if (olasilik == 1) {
            printf("Zombiyi yendiniz\n");
        } else if (olasilik == 2) {
            printf("Kactiniz, ama actiniz\n");
            insan.aclik -= 80;
        } else if (olasilik == 3) {
            printf("Zombi sizden kacti, bir sey olmadi\n");
        }

        if (insan.can <= 0) {
            break;   // can bitince döngüden çık
        }
    }

    printf("Oldunuz! %d gun hayatta kaldiniz\n", insan.gun);
    return 0;
}
```

### Bu Projede Öğrenilen Kritik Noktalar

- **`rand() % n` aralığı ile kontrol şartları birebir örtüşmeli** — `% 4` kullanıyorsan kontroller `0,1,2,3` olmalı, `4` asla eklenmemeli
- **Başlangıç değerleri döngünün dışında, bir kere** atanmalı — döngü içine konursa her turda sıfırlanır/resetlenir
- **`srand(time(NULL))` sadece bir kere**, döngü dışında çağrılmalı
- **`while(1)` + `break`** kalıbı, "kaç kere tekrar edeceği önceden bilinmeyen" döngüler için kullanılır (burada: karakter ne zaman öleceği belli değil)
- Döngüden çıktıktan sonra (dışında), final/sonuç mesajı yazdırılabilir

---

## 4 HAFTALIK ÖĞRENME PLANI

Hedef: C'nin temellerini derinlemesine tamamlamak, ardından Assembly'e geçiş yapmak.

### Hafta 1 — Bellek Yönetimi (✅ malloc/free tamamlandı)
- `malloc`, `free` — tamamlandı
- `calloc`, `realloc` — henüz görülmedi
- Bellek sızıntısı, dangling pointer, double free hataları
- Struct + malloc birleşimi (dinamik liste) — tamamlandı (öğrenci sistemi, telefon rehberi, market projesi)

### Hafta 2 — Veri Yapıları ve Dosya İşlemleri
- Pointer aritmetiği (`p++`, dizi-pointer ilişkisinin derinleşmesi)
- Bağlı liste (linked list) — malloc'un asıl kullanım alanı
- Dosya işlemleri: `fopen`, `fread`, `fwrite`, `fclose`, `fprintf`, `fscanf`
- Proje fikri: Rehber/market projelerini dosyaya kaydedip okuma ile kalıcı hale getirmek

### Hafta 3 — Organizasyon ve Orta Seviye Kavramlar
- Header dosyaları, çoklu dosya organizasyonu (`.h`/`.c` ayrımı)
- Fonksiyon pointer'ları (GTK gibi kütüphanelerin "callback" sisteminin temeli)
- Recursive (özyinelemeli) fonksiyonlar
- `enum` kullanımı

### Hafta 4 — Pekiştirme ve Bitirme Projesi
- Önceki 3 haftanın konularını birleştiren orta-büyük bir proje
- Kod okunabilirliği, fonksiyonlara ayırma alışkanlıkları
- Temel debug alışkanlıkları


## Sıradaki Konular (Öneri Sırası)

1. **Recursive (özyinelemeli) fonksiyonlar** — bir fonksiyonun kendini çağırması (faktöriyel, fibonacci gibi klasik örnekler)
2. **Diziler** — tek/çok boyutlu diziler, dizi-pointer ilişkisi, diziyi fonksiyona parametre geçmek
3. **Pointer aritmetiği** — `p++`, dizilerle pointer kullanımı
4. **String fonksiyonları** — `strlen`, `strcpy`, `strcmp` uygulamaları
5. **Struct'lar** — kendi veri tiplerini oluşturma, struct pointer'ları
6. **Dinamik bellek yönetimi** — `malloc`, `calloc`, `free`, bellek sızıntıları
7. **Dosya işlemleri (File I/O)** — `fopen`, `fread`, `fwrite`, `fclose`
8. **Fonksiyon prototipleri** — `main`'den önce/sonra tanımlama, header dosyaları
