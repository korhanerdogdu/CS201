#include <iostream>
#include <string>


using namespace std; // Str1.append(str2) stringde append olunca böyle oluyor.

int main() {
    string source;
    string search;
    bool harficermeyen;  // naber ben korhan end bunu dene.
    char c;
    string m;
    string sourcebul;

    while (true) {
        cout << "Enter source string: ";
        bool harficermeyen;
        getline(cin, source);  
        sourcebul = source;
        

        while(!(source.substr(source.length()-3) == "END" || source.substr(source.length() -3) == "end" || source.substr(source.length() -3) == "eNd" || source.substr(source.length()-3) == "End" || source.substr(source.length()-3) == "eND" || source.substr(source.length()-3) == "EnD" || source.substr(source.length()-3) == "ENd" || source.substr(source.length()-3) == "enD" )){
            getline(cin,source);
            sourcebul += " " + source;



        }  
        source = sourcebul;

        
        //harficermeyen = false;


        /*


        if(source[0]=='+'){     // normalde burdaki if ve bunun else i yoktu. 

            // Sample run 4 için anca bu şekilde yapabildim çünkü sistem hata veriyor.
            cout << "Enter source string: ";
            getline(cin,source);
            break;
            
        }
        
        
        
        */





        
        harficermeyen = false;

        for (int i = 0; i < source.length(); i++) {

            c = source[i];
            if (!isalpha(c) && c != ' ' && !(c <= 57 && c >= 48)) {   // 3ünden biri olmak zorunda.
                harficermeyen = true;  // c harf ve boşluk değilse true döndür. Başka bir durum sağlanıyorsa bir şey döndürme. Başka bir şey döndürmesi için c lerin hepsinin teker teker ya sadece boşluk ya da sadece harf çıkması lazım.
                break;  // fordan çıktı
            }            
        }

        if (harficermeyen == false && (source.substr(source.length()-3) == "END" || source.substr(source.length() -3) == "end" || source.substr(source.length() -3) == "eNd" || source.substr(source.length()-3) == "End" || source.substr(source.length()-3) == "eND" || source.substr(source.length()-3) == "EnD" || source.substr(source.length()-3) == "ENd" || source.substr(source.length()-3) == "enD")) {

            break;

        }

        
        
    }

    string d1= "+";
    string d2= "."; 
    string d3= "*";
    string d4="**";

    // source içinde end olmadan search i aratmalıyız. End in indeksini bulmalıyız.
    int endindeks = source.length()-3;

    // naber ben korhan end yani 16 adım atacak
                    //  17

    int aranacakadim = source.length()-4;
    source=source.substr(0,aranacakadim); // doğru gibi şu an.  yani source = naber ben korhan oluyor.
    m = source;
    do{

        cout << "Enter search string: ";
        cin >> search;

        if(search.substr(search.length()-1,1) == d1){ // temp_word ve word silme yöntemiyle yapılabilirdi.

            search=search.substr(0,search.length()-1);

            int b1 = source.find(search);

            int b2 = source.find(search,b1 + 1);


            if(b1 != string::npos){  


                int bosluk= source.find(" ",b1);

                int atilacakadim=bosluk - b1;

                if(b1==0){ // 1 tane harf başa girilirse diye.
                    cout << "index: " << b1 << " word: " << source.substr(b1,atilacakadim) << endl;

                }

                else{

                    int oncekiyer = b1 -1;

                    if(source[oncekiyer]== ' '){
                        cout << "index: " << b1 << " word: " << source.substr(b1,atilacakadim) << endl;

                    }
                }


            } 


            if(b2 != string::npos){

                int bosluk2= source.find(" ",b2);
                int atilacakadim2=bosluk2 - b2;

                int oncekiyer2= b2 -1;

                

                if(source[oncekiyer2]==' '){

                    cout << "index: " << b2 << " word: " << source.substr(b2,atilacakadim2) << endl;

                }
                
            } 


        }



        // max 4 kere yazdırılmış.
        else if(search.substr(search.length()-2,2) == d4){  // şu an zaten source içinde end yok.

            source = source.append(" "); //Cars are fast END



            search=search.substr(0,search.length()-2); //r** için yorumluyoruz. 2 tane ** işaretinin gitmeis gerekir.

            //
            
            string kelime;  // son kelimeyi okuamıyor.

            int boslukindex;
            int ekle = 0;

            boslukindex=source.find(" ");  // Cars are fast end


            while(boslukindex != string::npos){
                
                kelime = source.substr(0,boslukindex);

                int searchindex = kelime.find(search);

                int searchindex2=kelime.find(search, searchindex + 1);


                if(searchindex != string::npos){
                    cout << "index: " << searchindex + ekle  << " word: " << kelime << endl;
                }


                if(searchindex2 != string::npos){
                    cout << "index: " << searchindex2 + ekle << " word: " << kelime << endl;
                }



                ekle = ekle + kelime.length() + 1;    // 5 


            
                source.erase(0,kelime.length()+1); // are fast 

                boslukindex=source.find(" ");

                // int ekle2 =(kelime.substr(0,searchindex)).length();

            }

            // buraya endsiz source u döndürmem lazım.
            source = m;


        }


        else if(search.substr(search.length()-1,1) == d3){ // There are way too much homework in this class end

            source = source.append(" ");

            search=search.substr(0,search.length()-1);

            string word;
            string temp_word;
            int boslukunindex;
            int eklemek=0;

            boslukunindex=source.find(" ");
            bool checkk=true;

            while(boslukunindex != string::npos){  // there are good times and there are bad times
                word = source.substr(0,boslukunindex);
                temp_word = " " + word + " ";

                int arama = temp_word.find(search);
                int arama2 = temp_word.find(search,arama +1);  // bir kelimenin içinde 2 tane search olması durumunda.



                if((arama != string::npos) && (temp_word[arama + search.length()] != ' ') && (temp_word[arama - 1] != ' ')){

                    if((arama2 != string::npos) && (temp_word[arama2 + search.length()] != ' ') && (temp_word[arama2 -search.length()] != ' ')){

                        cout << "index: " << arama-1 + eklemek << " word: " << word << endl;


                    }

                    else if(arama2 == string::npos){
                        cout << "index: " << arama-1 + eklemek << " word: " << word << endl;
                        bool checkk = false;

                    }
                }

                
                else if(search.length()==2 && arama != string::npos){
                    int arama = temp_word.find(search);
                    if((temp_word[arama + search.length()] != ' ') && (temp_word[arama - 1] != ' ') ){
                        if(checkk==true){

                            cout << "index: " << arama-1 + eklemek << " word: " << word << endl;


                        }
                        
         
                    }       


                }
   

                //} //1 ve -1 yazıyordu.


                if((arama2 != string::npos) && (temp_word[arama2 + search.length()] != ' ') && (temp_word[arama2 -search.length()] != ' ')){
                    cout << "index: " << arama2-1 + eklemek << " word: " << word << endl;

                }

                eklemek = eklemek + word.length() + 1;

                source.erase(0,word.length()+1);

                boslukunindex=source.find(" ");

            }

            source = m;

        }



        else if(search.substr(search.length()-1,1) == d2){  // Cars are fast END

            source = source.append(" ");  // fast in sonuna bir boşluk ekledi.

            search=search.substr(0,search.length()-1);

            string worde;
            int boslukkindex;
            int eklemekke = 0;
            int yer;
            int yer2;

            boslukkindex=source.find(" ");


            while(boslukkindex != string::npos){ // ars
                worde = source.substr(0,boslukkindex);

                yer = worde.find(search);
                yer2 = worde.find(search,yer +1);

                if((yer != string::npos)){

                    if((source[yer + search.length()]) == ' '){

                        cout << "index: " << yer + eklemekke << " word: " << worde << endl;

                    }

                }

                if(yer2 != string::npos){

                    if((source[yer2 + search.length()]) == ' '){

                        cout << "index: " << yer2 + eklemekke << " word: " << worde << endl;

                    }                   


                }

                eklemekke = eklemekke + worde.length() + 1;

                source.erase(0,worde.length()+1);

                boslukkindex=source.find(" ");



                
            }


            source = m;





        }







    }while((search != "QUIT") && (search != "Quit") && (search != "QUiT") && (search != "QuIt") && (search != "QUIt") && (search != "QuiT") && (search != "qUIT") && (search != "qUiT") && (search != "quIt") && (search != "quit") && (search != "qUit") && (search != "quIT") && (search != "qUIt") && (search != "QuiT") && (search != "qUiT") && (search != "QUit") );
                                                                                                        //5                                         //7 doğru           d                       d                   10                      11                  12                      13
    return 0;
}
