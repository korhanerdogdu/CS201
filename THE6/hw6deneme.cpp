#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <string>
#include <sstream> // string değerini integer'a dönüştürmemizi sağlar.


/*
STOI nin görevi:
Eğer başında 0 veya 00 olan bir saat değeri varsa, bu değerler sayıya dönüştürüldüğünde otomatik olarak atılır.
Bu nedenle, stringi sayıya dönüştürmeden önce başındaki sıfırları kaldırmaya gerek yoktur.
*/
using namespace std;

bool isValidTimeFormat(string time) {
    if (time.length() != 5){
        return false;
    }   { 

    }
        
    
    if (time[2] != ':'){  // time[2] gibi ifadeler karakter yani char türnden değer döndürmeyi sağlar.
        return false;
    }
        
    
    if (!isdigit(time[0]) || !isdigit(time[1]) || !isdigit(time[3]) || !isdigit(time[4])){  // isdigit bir C++ karakter fonksiyonudur ve karakterin bir rakam (0-9 aralığında) olup olmadığını kontrol eder.

        return false;
    }
        
    
    return true;
}

bool isValidTimeRange(string time) {
    int hours = stoi(time.substr(0, 2)); //stoi fonksiyonu dönüşüm işlemini gerçekleştirirken, stringin başındaki sıfırları atlar. Örneğin, "01" ifadesini std::stoi ile dönüştürdüğünüzde sonuç olarak 1 elde edersiniz.
    int minutes = stoi(time.substr(3, 2));
    
    return (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59);
}

bool sayiyacevirkarsilastir(string inputcikarilmiszaman, string cikarilmiszaman){ 
    
    int yenizaman = stoi(inputcikarilmiszaman);
    int yenizaman2 = stoi(cikarilmiszaman); 
    

    //return inputcikarilmiszaman <= cikarilmiszaman;
    return yenizaman <= yenizaman2;

} 


int main() {
    string saat;
    bool isValidFormat = false;
    bool isValidRange = false;

    string departurelocation;
    string routedatabase;
    string timedatabase;
    string starttimeoftravel;
    string line;
    string line2;
    ifstream routes;
    ifstream times;

    vector<string> sehirler;
    vector<string> zamanlar;
    vector<string> birlesim;

    do{
        cout << "Please enter a filename for route database: ";
        cin >> routedatabase;
        routes.open(routedatabase.c_str());
        if(routes.fail()){

            cout << "cannot open routes database file" << endl;
        }
    }while(routes.fail());

    do{

        cout << "Please enter a filename for time database: ";
        cin >> timedatabase;
        times.open(timedatabase.c_str());

        if(times.fail()){

            cout << "cannot open times database file" << endl;
        }

    }while(times.fail());



    do{

        cout << "Please enter departure location: ";
        cin >> departurelocation;
        if(departurelocation == "EXIT"){
            break;

        }

        do{


            cout << "Please enter start time of travel: ";
            cin >> saat;

            isValidFormat = isValidTimeFormat(saat);
            if (isValidFormat == false) {  // format doğru olduktan sonra range' e bakıyor. Continue sayesinde alttakiler çalışmayacak.
                cout << "Time is not in correct format" << endl;
                continue; // Eğer kullanıcı geçersiz bir saat formatı girerse (isValidFormat false ise), continue ifadesi kullanılarak döngünün geri kalan kısmı atlanır ve bir sonraki döngü adımına geçilir. Böylece, hata mesajı ekrana yazdırılır ve kullanıcıdan tekrar bir saat girmesi istenir.
            }

            isValidRange = isValidTimeRange(saat);
            if (isValidRange == false) {
                cout << "Time is not in correct format" << endl;
            }

        }while (isValidFormat == false || isValidRange == false);



// tüm satırları okur ve bize hersatırdaki cümleyi döndürür. Boşluk olup olmaması fark etmez.
        
        while(getline(routes,line)){ 
            vector<string> tempwords;
            istringstream iss(line);
            string word;
            while (iss >> word) {
                tempwords.push_back(word); // Her kelime vektöre ekleniyor
            }

            string newline;
            for (size_t i = 0; i < tempwords.size(); i++) {
                newline += tempwords[i];
                if (i != tempwords.size() - 1) {
                    newline += " ";
                }
            }

            int bosluk = newline.find(" ");
            string sehir = newline.substr(bosluk + 1,departurelocation.length());
            if(sehir == departurelocation){
                sehirler.push_back(newline);  // line i düzeltip yollamak lazım içine.
            }

            tempwords.clear();
        }

 

        string inputcikarilmiszaman = saat.erase(2,1); // saat içinden de ":" gidecek erase yüzünden.
  // tüm satırları okur ve bize hersatırdaki cümleyi döndürür. Boşluk olup olmaması fark etmez.

        while(getline(times,line2)){ 
            vector<string> temptimes;
            istringstream iss(line2);
            string timeword;

            while (iss >> timeword) {
                temptimes.push_back(timeword); // Her kelime vektöre ekleniyor
            }

            string newline2;
            for (size_t i = 0; i < temptimes.size(); i++) {
                newline2 += temptimes[i];
                if (i != temptimes.size() - 1) {
                    newline2 += " ";
                }
            }

            


            int bosluk2 = newline2.find(" ");
            string zaman = newline2.substr(bosluk2 + 1,5); //saat
            
            string cikarilmiszaman = zaman.erase(2,1);  // 2. indeksten başlayacak ve 1 karakteri silecektir. "12:23" ----> "1223" oldu.

            

            if(sayiyacevirkarsilastir(inputcikarilmiszaman,cikarilmiszaman) == true){
                zamanlar.push_back(newline2);
            }

            temptimes.clear();
            
            
        }



        cout << "The search results are:" << endl;
        for(int i =0;i <sehirler.size();i++){
            for(int j =0;j <zamanlar.size();j++){
                int boslukk1=sehirler[i].find(" ");
                int boslukk2= zamanlar[j].find(" ");
                
                if(sehirler[i].substr(0,boslukk1 - 0) == zamanlar[j].substr(0,boslukk2-0)){
                    string birlesmek = sehirler[i].substr(boslukk1 + 1) + " " + zamanlar[j].substr(boslukk2 + 1);
                    birlesim.push_back(birlesmek); // içini temizlemek lazım.
                    
                }  
            }
        }

        for(int i =0;i<birlesim.size();i++){
            cout << birlesim[i] << endl;
        }

        birlesim.clear();


        sehirler.clear();
        routes.clear(); // Dosya hatalarını temizle 

        if (!routes.eof()) { // eğer sona gelmiş ise.
            routes.seekg(0); // Dosyanın başına dön // İkinci işlemleri burada yapabilirsiniz
        }

        zamanlar.clear();
        times.clear();

        if (!times.eof()) { // eğer sona gelmiş ise.
            times.seekg(0); // Dosyanın başına dön // İkinci işlemleri burada yapabilirsiniz
        }





        
        

    }while(departurelocation !="EXIT");  // asıl kodu bunun içine döşeyeceksin.




}
