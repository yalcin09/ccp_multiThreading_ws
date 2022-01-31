/*************************************************************************************************************
 * 
 * Multithread Yapısı
 * 
 * --> Thread nedir?
 * Thread'in türkçedeki anlamı iş parçacığıdır.
 * Ram içerisinide spesifik adreslerimiz vardır.
 * 
 * Bilgisayarda bil kod çalışmaya başladığında ona bir başlangıç adresi verilir. Buna;
 * starting point/address denir.
 * 
 * Ve program tanımlanan başlangıç adresinden bir sonraki adrese doğru ilerleyerek işlemini bitirir.
 * Buna up to down rule denir.
 * Örnek:
 *   0x001000000 -> int main()              : Bu bizim başlangıç adresimiz.
 *   0x002000000 -> cout << "Hello World";  : Bu bir sonraki adres değerindeki işlem
 *   0x003000000 -> ....
 *   0x004000000 -> ....
 *   0x005000000 -> return 0                : Program sonu adresi
 * 
 * 
 * Eğer biz up to down rule yapısını kırmak istiyorsak,
 * another starting point/address verebiliriz.
 * 
 * Burada yapılan işlem asıl başlama adresi olan main fonksiyonunun kod akışı devam ederken,
 * belirlediğimiz başka bir fonksiyonun adresi ikinci bir main olarak (misal) algılanır.
 * Main fonksiyonu işlerken rassal olarak veya kendimizin belirlediği sürede main fonksiyonuna ara
 * verilir ve tanımlanan diğer fonksiyona geçirilir. Burada yine rassal olarak veya belrilenen süre
 * boyunca kodlar işlenir ve daha sonra main fonksiyonuna geçirilir. Bu döngü proğram bitene kadar
 * veya proğramcının istediği süre/koşula kadar devam eder.
 * 
 * Burada aynı anda iki veya daha fazla fonksiyon çalıştırılmaz (Tek çekirdekli bir işlemci için),
 * fonksiyonlar belirli bir süre çalıştırıldıktan sonra diğer fonksiyona geçiş yapılır. Ve bu döngüsel
 * olarak devam eder.
 * 
 * Kısacası thread, birden fazla fonksiyonu rassal veya sıralı olarak belirlenen kurallar neticesinde
 * fonksiyonlar arası geçiş yapmaya yaramaktadır.
 * 
 *************************************************************************************************************/