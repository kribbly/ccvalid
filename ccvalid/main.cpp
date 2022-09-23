//
//  main.cpp
//  kredikartikontrol
//
//  Created by Mithatcan Bursalı on 8.02.2022.
//

#include <iostream>
#include <string>

using namespace std;



int main(){
    
    long long int creditcartnumber;
    long long int creditcartnumberlist[16];
    int runntotal = 0;
    
    cout << "Kredi Kartı Kontrol Programı" << endl << endl;
    
    cout << "Lütfen kontrol etmek istediğiniz kredi kartı numarasını giriniz:";
    
    
    cin >> creditcartnumber;

    long long int intcclenght = creditcartnumber;
    string cclenght = to_string(intcclenght);
    int lenghtcheck = cclenght.length();
    
    if ((cclenght.length() < 13) || (cclenght.length() > 17)){
        cout << "Kredi kartı numarası geçerli değil!" << endl;
    }
    
    else{
    
    
   // SAYIYI BASAMAKLARA AYIRMA
    
    
    creditcartnumberlist[lenghtcheck-1] = creditcartnumber % 10;
    creditcartnumberlist[lenghtcheck-2] = (creditcartnumber / 10) % 10;
    creditcartnumberlist[lenghtcheck-3] = (creditcartnumber / 100) % 10;
    creditcartnumberlist[lenghtcheck-4] = (creditcartnumber / 1000) % 10;
    creditcartnumberlist[lenghtcheck-5] = (creditcartnumber / 10000) % 10;
    creditcartnumberlist[lenghtcheck-6] = (creditcartnumber / 100000) % 10;
    creditcartnumberlist[lenghtcheck-7] = (creditcartnumber / 1000000) % 10;
    creditcartnumberlist[lenghtcheck-8] = (creditcartnumber / 10000000) % 10;
    creditcartnumberlist[lenghtcheck-9] = (creditcartnumber / 100000000) % 10;
    creditcartnumberlist[lenghtcheck-10] = (creditcartnumber / 1000000000) % 10;
    creditcartnumberlist[lenghtcheck-11] = (creditcartnumber / 10000000000) % 10;
    creditcartnumberlist[lenghtcheck-12] = (creditcartnumber / 100000000000) % 10;
    creditcartnumberlist[lenghtcheck-13] = (creditcartnumber / 1000000000000) % 10;

    if (lenghtcheck - 13 == 1){
        creditcartnumberlist[lenghtcheck-14] = (creditcartnumber / 10000000000000) % 10;
    }
    
    else if (lenghtcheck - 13 == 2){
        creditcartnumberlist[lenghtcheck-14] = (creditcartnumber / 10000000000000) % 10;
        creditcartnumberlist[lenghtcheck-15] = (creditcartnumber / 100000000000000) % 10;
    }

    else if (lenghtcheck - 13 == 3){
        creditcartnumberlist[lenghtcheck-14] = (creditcartnumber / 10000000000000) % 10;
        creditcartnumberlist[lenghtcheck-15] = (creditcartnumber / 100000000000000) % 10;
        creditcartnumberlist[lenghtcheck-16] = (creditcartnumber / 1000000000000000) % 10;
    }

   // BASAMAKLARA AYIRMA SON
        
    
    
    
  // LUHN ALGORITMASI
    
    if (lenghtcheck - 13 == 0){
    
        for (int i = 0; i < 13; i += 2){
                        
            if (creditcartnumberlist[i] * 2 > 9){
                long long int easier1 = (creditcartnumberlist[i] * 2) / 10;
                long long int easier2 = (creditcartnumberlist[i] * 2) % 10;
            runntotal += easier1 + easier2;
            }
            
            else {
                runntotal += (creditcartnumberlist[i] * 2);
            }
        }
        
        
        for (int k = 1; k < 13; k += 2){
            runntotal += creditcartnumberlist[k];
        }
    }
    
    
   else if (lenghtcheck - 13 == 1){
    
        for (int i = 0; i < 14; i += 2){
                        
            if (creditcartnumberlist[i] * 2 > 9){
                long long int easier1 = (creditcartnumberlist[i] * 2) / 10;
                long long int easier2 = (creditcartnumberlist[i] * 2) % 10;
            runntotal += easier1 + easier2;
            }
            
            else {
                runntotal += (creditcartnumberlist[i] * 2);
            }
        }
        
        
        for (int k = 1; k < 14; k += 2){
            runntotal += creditcartnumberlist[k];
        }
    }

    
   else if (lenghtcheck - 13 == 2){
    
        for (int i = 0; i < 15; i += 2){
                        
            if (creditcartnumberlist[i] * 2 > 9){
                long long int easier1 = (creditcartnumberlist[i] * 2) / 10;
                long long int easier2 = (creditcartnumberlist[i] * 2) % 10;
            runntotal += easier1 + easier2;
            }
            
            else {
                runntotal += (creditcartnumberlist[i] * 2);
            }
        }
        
        
        for (int k = 1; k < 15; k += 2){
            runntotal += creditcartnumberlist[k];
        }
    }

    
    else if (lenghtcheck - 13 == 3){
    
        for (int i = 0; i < 16; i += 2){
                        
            if (creditcartnumberlist[i] * 2 > 9){
                long long int easier1 = (creditcartnumberlist[i] * 2) / 10;
                long long int easier2 = (creditcartnumberlist[i] * 2) % 10;
            runntotal += easier1 + easier2;
            }
            
            else {
                runntotal += (creditcartnumberlist[i] * 2);
            }
        }
        
        
        for (int k = 1; k < 16; k += 2){
            runntotal += creditcartnumberlist[k];
        }
    }

    
    
    
if (runntotal % 10 == 0){
    
    if (creditcartnumberlist[0] == 4){
        cout << "Bu kredi kartı numarası Visa'ya ait ve geçerli!" << endl;
    }
    
    else if (creditcartnumberlist[0] == 5){
        cout << "Bu kredi kartı numarası Mastercard'a ait ve geçerli!" << endl;
    }
    
    else if (creditcartnumberlist[0] == 3 && creditcartnumberlist[1] == 7){
        cout << "Bu kredi kartı numarası American Express'e ait ve geçerli!" << endl;
    }
    
    else if (creditcartnumberlist[0] == 6){
        cout << "Bu kredi kartı numarası Discovery'e ait ve geçerli!" << endl;
    }
    
    else {
        cout << "Kredi kartı tanımlanmayan bir yere ait ve numara olarak geçerli!" << endl;
    }

    
}
    

else{
    cout << "Kredi kartı geçerli değil!" << endl;
}
    
            
    
    
}
    
    
    
    
}
