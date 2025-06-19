#include <iostream> // referans koymadan tolower?
#include <vector>
#include <string>  // bianry/linear search
using namespace std;



/*
 
 void changeBookTitleToUppercase(Book& book) {
     for (char& c : book.Title) {
         c = toupper(c);
     }
 }

 bool karsilastir(const Book& book1, const Book& book2) {
     // book1.Title'i büyük harfe çevir
     changeBookTitleToUppercase(book1);BÖYLELİKLE ORJİNAL LİSTEDEKİ HARF BOYUTUNU DEĞİŞTİREBİLİYORUZ

     // book2.Title'ı büyük harfe çevir
     changeBookTitleToUppercase(book2);

     // Diğer karşılaştırma işlemleri...
 }

 
 
 
 Eğer karsilastir fonksiyonu içinde referans parametrelerini kullanmazsanız, changeBookTitleToUppercase fonksiyonu kitap nesnelerinin kopyaları üzerinde çalışacaktır. Bu durumda, karsilastir fonksiyonu orijinal kitap nesnelerini değiştirmeyecektir. Yani, karsilastir fonksiyonu çağrıldığında, kitap nesnelerinin kopyaları üzerinde büyük harf dönüşümü yapılacak ancak orijinal kitap nesneleri değişmeyecektir.


 Eğer changeBookTitleToUppercase fonksiyonu olmazsa ve karsilastir fonksiyonunun başına referans parametreleri (const Book& book1, const Book& book2) koyarsanız, karsilastir fonksiyonu içinde kitap nesnelerinin Title alanları üzerinde herhangi bir değişiklik yapamazsınız. Bu durumda, karsilastir fonksiyonu sadece kitap nesnelerini okuyabilir ve karşılaştırma işlemlerini gerçekleştirebilir.

 Referans parametreleri, verilere erişmek ve onları okumak için kullanılır. Eğer karsilastir fonksiyonu içinde kitap nesnelerinin Title alanları üzerinde değişiklik yapmanız gerekiyorsa, changeBookTitleToUppercase veya benzer bir fonksiyon kullanmanız gerekir. Referans parametreleri, fonksiyon içinde verilere erişmek için kullanılırken, bu tür yardımcı fonksiyonlarla birlikte kullanılarak veriler üzerinde değişiklik yapılabilir.
 
 
 */

struct Book { // bu sıraya göre ayarlama yapıyor.
    std::string Title;
    std::string Author;
    int PublicationYear;
    };

void insertbook(vector<Book> & books, string title, string author, int publicationyear){
    Book bbok;
    bbok.Title = title;
    bbok.Author = author;
    bbok.PublicationYear=publicationyear;
    books.push_back(bbok); // fonkisyon sonrası books değişeceği için referans koymak zorundayım.
}

bool karsilastir( const Book book1, const Book book2) { // referansa gerek yok orjinal listede değişiklik yapmayacağım. Performans,fonksiyon içinde verilere erişmek amacıyla ekleyebilirsin. Eğer referans kullansaydım burda,veriye erişmek amacıyla kullanmış olurdum, veriyi değiştirmek amacıyla değil. Zaten orjinalini değiştirecek bir fonksiyon yok içerde.
    string surname;
    string surname2;
    
    int index1 =book1.Author.find(' ');
    int possibleindex1=book1.Author.find(' ',index1 + 1) ;
    if(possibleindex1 != string::npos){
        
        surname = book1.Author.substr(book1.Author.find(' ',index1 + 1) + 1);
    }
    
    else{
        surname = book1.Author.substr(book1.Author.find(' ') + 1);

    }
    
    int index2 =book2.Author.find(' ');
    int possibleindex2=book2.Author.find(' ',index2 + 1);
    
    if(possibleindex2 != string::npos){
        
        surname2 = book2.Author.substr(book2.Author.find(' ',index2 + 1) + 1); // burada
    }
    
    else{
        surname2 = book2.Author.substr(book2.Author.find(' ') + 1);

    }
    //string temp1 = surname;
    //string temp2 = surname;
    
    
    /*
     
     if(surname.at(0) <= 'z' && surname.at(0) >='a'){
         for(int i =0;i<surname.size();i++){
             char c = surname.at(i);
             buyuk(&c);
         }
     }
     
     bu yöntem de olurdu.
     */
    
    for (char &c : surname) { // referans kullanmasaydık kopya oluşacaktı ve surname aynı kalacaktı. burda yapılan değişiklik orjinal listeyi etkilemiyor.
        
        c = tolower(c);
    }
    for (char &c : surname2) {
        c = tolower(c);
    }
    
    
    if (surname == surname2) {
        string title1 = book1.Title;
        string title2 = book2.Title;

        // Eser adlarını karşılaştırıyoruz burada
        return title1 < title2;
    }
    
    

    return surname < surname2;  // sadece true mu false mu bunu belirleyecek,surname orjinal kalacak, fonksiyon içi değişecek.
    
    // Alfabetik olarak sorgulluyoruz. ASCI Table' a göre sorguluyoruz. ASCI Table' da büyük harflerin karşılığına gelen sayı küçük harflere göre daha küçük. İçeriden bir return ifadesi gelmez ise bu returnlenecek.
    
    
}
// substr içine tek parametre koyduğunda kaçıncı indeksten başladığını belirtir ve bundan sonraki tüm karakterleri yazdırır.


void Swap(Book &book1info, Book &book2info) { // fonksiyonun içine struct yollayacaksan parametrenin başına struct yapısının ismini yazman gerekiyor (Book).Vektörün her bir indeksi struct yapısındadır. Biz vektörün içindeki herhangi bir indeksi fonksiyonun içine yolluyoruz, o indeks de struct yapısı olduğu için fonksiyon tanımlarken struct' ın ismini yazmamız gerekiyor.
    Book temp = book1info;
    book1info = book2info;
    book2info = temp;
}

void sirala(vector<Book> &books) {
    for (int i = 0; i < books.size() - 1; ++i) {
        for (int j = i + 1; j < books.size(); ++j) {
            if (karsilastir(books[j], books[i])) {
                swap(books[i], books[j]);
            }
        }
    }// fonkisyon sonrası books değişeceği için referans koymak zorundayım.
    
    

    
}
// soyisimler aynı ise kitabın ismine göre, bir de birden fazla isim söz konusu.





int main() {  // vs code da bu şekil yazamıyorsun.
    
    
    int choice;
    string intitle;
    string inauthor;
    int inyear;
    
    // vektörün içersine struct atıyoruz. Vektörün her bir indeksi struct yapısındadır.
    vector<Book> books = {
        {"The Great Gatsby", "F Scott Fitzgerald", 1925},
        {"Moby Dick", "Herman Melville", 1851},
        {"To Kill a Mockingbird", "Harper Lee", 1960},
        {"Pride and Prejudice", "Jane Austen", 1813},
        {"Burmese Days", "George Orwell", 1934},
        {"Brave New World", "Aldous Huxley", 1932},
        {"Animal Farm", "George Orwell", 1945}
    };
    
    
    do{
        
        cout << "Library System Menu:" << endl;
        cout << "1. Add books" << endl;
        cout << "2. Search for an author" << endl;
        cout << "3. Search for by book title" << endl;
        cout << "4. Display books" << endl;
        cout << "5. Quit" << endl;
        
        
        cout << "Enter your choice: ";
        cin >> choice;
        
        if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 ){
            cout << "Invalid choice, please try again." << endl;
            
        }
        else{
            
            if(choice == 1){
                // yazarın soyadını büyüğe çevirip hesaplaman gerekiyor.
                
                cout << "Enter the new book details:" << endl;
                
                
                cout << "Enter book's title: " ;
                getline(cin >> ws,intitle); // getline in düzgün biçimde çalışmasını sağlar. Bu düzeltmeyi yapmasaydım kod çıktısı --> Enter book's title: Enter book's author: şeklinde oluyordu. Bunu önlemiş olduk.
                
                
                cout << "Enter book's author: ";
                getline(cin >> ws,inauthor);
                
                
                cout << "Enter book's publication year: " ;
                cin >> inyear;
                
                insertbook(books, intitle, inauthor, inyear);
                
                
            }
            
            
            else if(choice == 2){ // George Orwell
                bool found = false;
                sirala(books);
                cout << "Enter the author of the book you want to search for: ";
                getline(cin >> ws,inauthor);
                string soyat;
                int indeks=inauthor.find(' ');
                int indeks2=inauthor.find(' ',indeks + 1);
                if(indeks2 != string::npos){
                    
                    soyat=inauthor.substr(indeks2 + 1);
                }
                else{
                    
                    soyat=inauthor.substr(indeks + 1);

                }
                
                for (char &c : inauthor) {
                    c = tolower(c);
                }
                string kopya;
                
                for(int i =0;i<books.size();i++){
                    kopya = books[i].Author;
                    
                    for (char &c : kopya) {
                        c = tolower(c); // Arada boşuk olması bir problem yaratmıyor.
                    }
                    if(inauthor == kopya){ // struct ın içinde bir değişiklik yapmıyorum. Değişkeni alıp ayrı bir şekilde üzerinde oynadım. Orjinal yapı değişmez.
                        
                        if (found==false) {
                            std::cout << "Books by " << soyat << ":" << std::endl;
                            found = true;
                        }
                        
                        cout << "Title: " << books[i].Title  <<", Publication Year: " << books[i].PublicationYear << ", Position: " << i+1 << endl;
                    }
                    
                }
 
                if(found==false){
                    cout << "No books were found." << endl;
                    
                }
                
            }
            
            
            else if(choice == 3){
                bool foundd = false;
                sirala(books);
                cout << "Enter the title of the book you want to search for: ";
                getline(cin >> ws,intitle);
                string eklenmis = '"'+intitle+'"';
                
                cout << "Books matching the title " << eklenmis << ":" << endl;

                
                for (char &c : intitle) {
                    c = tolower(c);
                }
                string kopya2;
                for(int i =0;i<books.size();i++){
                    kopya2 = books[i].Title;

                    for (char &c : kopya2) {
                        c = tolower(c); // Arada boşuk olması bir problem yaratmıyor.
                    }
                    if(intitle == kopya2){ // struct ın içinde bir değişiklik yapmıyorum. Değişkeni alıp ayrı bir şekilde üzerinde oynadım. Orjinal yapı değişmez.
                        
                 
                        foundd = true;
                        cout << "Title: " << books[i].Title  <<", Author: " << books[i].Author << ", Publication Year: " << books[i].PublicationYear << ", Position: "<< i+1 << endl;
                        
                        
                    }
                    
  
                    
                }
                if(foundd == false){
                    cout << "No books were found." << endl;
                    
                    
                }
                
                
                
            }
            
            else if(choice == 4){
                
                cout << "Sorted books by author's last name:" << endl;
                sirala(books);
                for(int i =0;i<books.size();i++){
                    cout << i + 1 <<". " <<  books[i].Title << ", " << books[i].Author << ", " << books[i].PublicationYear << endl;
                    
                }
                cout << endl;
                
            }
            
            
            
            
            
            
        }
        
        
        
    }while(choice!=5);
    cout << "Goodbye!";
    

    return 0;
    
    
}

/*
 
 for (char &c : books[i].Author) {
     c = tolower(c); // Arada boşuk olması bir problem yaratmıyor.
}
 
 böyle yapılıırsa orjinal satır listedeki yazar isminin harflerinin büyüklüğünde değişikliğe neden olursun
 
 
 
 */








/*
 struct ın vektör ile birlikte kullanışını daha iyi anlaman için örnek;
 
 
 #include <iostream>
 #include <vector>
 #include <string>

 struct Person {
     std::string name;
     int age;
 };

 int main() {
     std::vector<Person> people;

     Person person1 = {"John", 30};
     Person person2 = {"Alice", 25};
     Person person3 = {"Michael", 40};

     people.push_back(person1);
     people.push_back(person2);
     people.push_back(person3);

     std::cout << "People:" << std::endl;
     for (int i = 0; i < people.size(); ++i) {
         std::cout << "Name: " << people[i].name << ", Age: " << people[i].age << std::endl;
     }

     return 0;
 }

 
 
 */
