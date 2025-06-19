#include <iostream>
#include <string>
using namespace std;
/*

If they exceed their base packages and did not buy any additional packages; or
they exceed the additional packages as well, the cost of their usage will be calculated using the standard
rates

*/

bool inputcheck(int number){
    if(number>=0){
        return true;

    }

    return false; // içerden herhangi bir değer döndürülmez ise en sonunda false döndürülcek.

}


double costCalculate(int min, int sms, int mbs, int addcallpackages,int addsmspackages,int addintpackages,int price,int providedmin,int providedsms, int providedmb,int price2, int aprovidedmin, int aprovidedsms,int aprovidedmb,int standardratecalls,int standardratesms, int standardrateinternet){
    int costminutes,costsms;
    double costinternet;
    double num = 0.09765625; 

    if(min<=providedmin){
        costminutes =0;

    }

    if(sms<=providedsms){
        costsms =0;

    }

    if(mbs<=providedmb){
        costinternet =0;

    }


    //if( min<=250 && sms<=1000 && mbs<= 5120 ){
      //  return price;
    //}

    if(min>providedmin){  // providedmin = 250

        if(addcallpackages == 0){
            costminutes =  (min - providedmin)*standardratecalls;  // standardratecalls = 2  costminutes ekstradan package fiyatın üzerine eklenecek.
        }
        else{  // ifli bir durum getirmek gerekiyor gibi. Çünkü additionların hiçbiri çalışmıyor. 
            if(min>(addcallpackages*aprovidedmin)+providedmin){
                costminutes= (addcallpackages*price2) + ((min - providedmin - (aprovidedmin * addcallpackages))*standardratecalls) ;


            }
            else{
                costminutes= (addcallpackages*price2);  // aprovidedmin = 250.
            }
               

        }
    }



    if(sms>providedsms){
        if(addsmspackages == 0){    // addsmspackages = kaç tane ekstra aldığını gösterir.
            costsms = (sms - providedsms)*standardratesms;  // provided sms = 1000

        }

        else{
            if(sms>(addsmspackages*aprovidedsms) + providedsms){

                costsms = (addsmspackages * price2) + ((sms - providedsms - (aprovidedsms*addsmspackages))*standardratesms) ;

            }

            else{
                costsms = (addsmspackages * price2);
            }


        }

    }



    if (mbs > providedmb){     
        if(addintpackages == 0){
            costinternet = (mbs - providedmb) *(standardrateinternet/num); // çarpım buraya da eklenilcek muhtemelen.

        }

        else{
            // çarpma işlemim hata veriyor. double)1048576/100. Hata bundan kaynaklanıyor gibi.
            if(mbs > (addintpackages*aprovidedmb) + providedmb){
                costinternet= (addintpackages*price2) + ((mbs - providedmb - (aprovidedmb*addintpackages))*(standardrateinternet/num)) ;
                //costinternet= (addintpackages*price2) + ((mbs - providedmb - (aprovidedmb*addintpackages))*(standardrateinternet*(double)1048576/100)) ;

            }

            else {

                costinternet = (addintpackages*price2);  // else if eşittir diyebilirsin.
            }
            
        }


    }




    return price + costminutes + costsms + costinternet;
    


}



void displayresults(string phoneusage, int packageprice, int totalcost ){


    if(phoneusage== "in Turkey"){


        if(totalcost > packageprice && totalcost<packageprice*2){
            cout <<"Total cost of your phone usage in Turkey is "<< totalcost << " TL. You exceeded your package." << endl;
        }

        else if(totalcost == packageprice){
            cout << "Total cost of your phone usage in Turkey is "<< totalcost << " TL. You did not exceed your package." << endl;


        }

        else if(totalcost >= packageprice*2){
            cout << "Total cost of your phone usage in Turkey is " << totalcost << " TL. You exceeded your package too much. We suggest you to change your package. " << endl;
            

        }
    }

    else{


        if(totalcost > packageprice && totalcost<packageprice*2){
        cout <<"Total cost of your phone usage Internationally is "<< totalcost << " TL. You exceeded your package." << endl;
        }

        else if(totalcost == packageprice){
            cout << "Total cost of your phone usage Internationally is "<< totalcost << " TL. You did not exceed your package." << endl;


        }

        else if(totalcost >= packageprice*2){

            cout << "Total cost of your phone usage Internationally is "<< totalcost << " TL. You exceeded your package too much. We suggest you to change your package." << endl;
        }
    }


    }








int main(){

    int minL;
    int smsL;
    int mbL;
    int mini;
    int smsi;
    int mbi;
    int additionalpackageminL,additionalpackagesmsL,additionalpackagembL,additionalpackagemini,additionalpackagesmsi,additionalpackagembi;
    string a = "in Turkey";
    string b = "Internationally";


    cout << "Please enter how many minutes you used this month in Turkey: ";
    cin >> minL; 
    if(!inputcheck(minL)){
        cout << "Number of minutes cannot be smaller than 0";

    }
    else{

        cout << "Please enter how many SMSs you sent this month in Turkey: ";
        cin >> smsL;
        if(!inputcheck(smsL)){
            cout << "Number of SMSs cannot be smaller than 0.";
        }
        else{

            cout << "Please enter how many MBs you used this month in Turkey: ";
            cin >> mbL;
            if(!inputcheck(mbL)){
                cout << "Number of SMSs cannot be smaller than 0.";
            }
            else{

                cout << "Please specify how many additional packages you bought for calls, SMS and internet in this order: ";
                cin >> additionalpackageminL >> additionalpackagesmsL >> additionalpackagembL;
                if(!inputcheck(additionalpackageminL) || !inputcheck(additionalpackagesmsL) || !inputcheck(additionalpackagembL)){
                    cout << "Number of additional minutes packages cannot be smaller than 0.";

                }

            }

        }

    }

    if(inputcheck(minL) && inputcheck(smsL) && inputcheck(mbL) && inputcheck(additionalpackageminL) && inputcheck(additionalpackagesmsL) && inputcheck(additionalpackagembL)){

        int x = costCalculate(minL,smsL,mbL,additionalpackageminL,additionalpackagesmsL,additionalpackagembL,120,250,1000,5120,30,250,250,1024,2,1,2);
        displayresults(a,120,x);

        cout << "Please enter how many minutes you used this month Internationally: ";
        cin >> mini; 
        if(!inputcheck(mini)){
        cout << "Number of minutes cannot be smaller than 0";
        }

        else{



            cout << "Please enter how many SMSs you sent this month Internationally: ";
            cin >> smsi;
            if(!inputcheck(smsi)){
                cout << "Number of SMSs cannot be smaller than 0.";
            }
        else{



            cout << "Please enter how many MBs you used this month Internationally: ";
            cin >> mbi;
            if(!inputcheck(mbi)){

                cout << "Number of SMSs cannot be smaller than 0.";
            }
            else{

                cout << "Please specify how many additional packages you bought for calls, SMS and internet in this order: ";
                cin >> additionalpackagemini >> additionalpackagesmsi >> additionalpackagembi;
                if(!inputcheck(additionalpackagemini) || !inputcheck(additionalpackagesmsi) || !inputcheck(additionalpackagembi)){
                    cout << "Number of additional internet packages cannot be smaller than 0.";

                }


            }

            
        }

    }


    }

    if(inputcheck(minL) && inputcheck(smsL) && inputcheck(mbL) && inputcheck(additionalpackageminL) && inputcheck(additionalpackagesmsL) && inputcheck(additionalpackagembL) && inputcheck(mini) && inputcheck(smsi) && inputcheck(mbi) && inputcheck(additionalpackagemini) && inputcheck(additionalpackagesmsi) && inputcheck(additionalpackagembi)){
        int m = costCalculate(mini,smsi,mbi,additionalpackagemini,additionalpackagesmsi,additionalpackagembi,300,100,200,2048,100,50,100,1024,15,3,5);
        displayresults(b,300,m);



    } 




}



 








   


        




  




    




