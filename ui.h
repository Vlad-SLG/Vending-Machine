

#ifndef UI_H
#define UI_H

#include "service.h"

class UI{
private:
    Service service;
public:
    UI(){
        service=Service();
    }

    UI(const Service& serv){
        service=serv;
    }

    void menu(){
        cout<<"1.Afisare tonomat"
              "\n2.Adauga bancnota"
              "\n3.Adauga produs in tonomat"
              "\n4.Cumpara produs"
              "\n0.Inchidere";
    }

    void run(){
        int k;
        while(true){
            menu();
            cout<<"\nAlege optiunea:";
            int option;
            cin>>option;
            if(option==1)
                afisare_atm();
            if(option==2)
                adauga_banc();
            if(option==3)
                adauga_produs(k);
            if(option==4)
                plata_produs();
            if(option==0)
                break;
        }
    }
    void afisare_produse(){
        for (int i = 0; i < service.prod_size(); ++i) {
            cout<<i<<"."<<service.getprod(i)<<endl;
        }
    }

    void plata_produs(){
        afisare_produse();
        int option,suma;
        cout<<"Alege produsul:";
        cin>>option;
        cout<<"Introduceti suma:";
        cin>>suma;
        int rest=suma-service.getprod(option).getPret();
        int rezultat=service.plata(option,suma);
        if(rest==rezultat)
            cout<<"Restul de plata este:"<<rest<<endl;
        if(rezultat==1)
            cout<<"Produsul a fost platit"<<endl;
        if(rezultat==0)
            cout<<"Produsul nu a putut fi platit!"<<endl;

    }

    void afisare_atm(){
        cout<<service.getall();
    }
    void adauga_banc(){
        cout<<"Bancnota:";
        int value;
        cin>>value;
        service.add_moneda(value);
    }
    void adauga_produs(int &k){
        string nume;
        int pret;
        cout<<"Nume:";
        cin>>nume;
        cout<<"Pret:";
        cin>>pret;
        string cod= to_string(k);
        Produs p(cod,nume,pret);
        service.add_produs(p);

    }
};
#endif
