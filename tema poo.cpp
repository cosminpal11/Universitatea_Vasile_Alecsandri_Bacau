//Aceasta tema a fost facuta dupa ce s-a prezentat proiectul.

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Produs
{
public:
    string denumire;
    float pret;
    int unitMasura;
    float stocMagazin;

    void citireProduse()
    {
        system("cls");
        int x = 0;
        cin.get();
        cout << "Denumire: ";
        getline(cin, denumire);

        cout << "Pret: ";
        if (!(cin >> pret))
            while (x == 0)
            {
                if (!(cin >> pret))
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Pret invalid! Introduceti un alt pret: ";
                }
                else if (pret < 0)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Pret invalid! Introduceti un alt pret: ";
                }
                else x = 1;
             }
        x = 0;
        cout << "Daca produsul se cumpara pe bucata, introduceti un numar par." << endl;
        cout << "Daca produsul se cumpara la kilogram, introduceti un numar impar." << endl;
        if (!(cin >> unitMasura))
            while (x == 0)
            {
                if (!(cin >> unitMasura))
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Valoare invalida! Introduceti o valoare valida: ";
                }
                else if (unitMasura < 0)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Valoare invalida! Introduceti o valoare valida: ";
                }
                else x = 1;
            }
        x = 0;
        cout << "Stoc magazin: ";
        if (!(cin >> stocMagazin))
            while (x == 0)
            {
                if (!(cin >> stocMagazin))
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Valoare invalida! Introduceti o valoare valida: ";
                }
                else if (stocMagazin < 0)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Valoare invalida! Introduceti o valoare valida: ";
                }
                else x = 1;
            }
    }

    void afiseazaProdus()
    {
        cout << "Denumire: " << denumire << endl;
        cout << "Pret: " << pret;
        if (unitMasura % 2 == 0)
            cout << "/bucata" << endl;
            else cout << "/kg" << endl;
        cout << "Cantitate magazin: " << stocMagazin << endl;
    }
};

int main()
{
    Produs produse[100];
    int nrProduse = 0;
    int optiune;
    float buget;
    system("Color 02");
    cout << "Care e bugetul dumneavoastra?" << endl;
    cin >> buget;
    system("cls");
    do 
    {
        system("Color 07");
        cout << "BANK: " << buget << endl;
        cout << "----------- Meniu -------------" << endl;
        cout << "1. Adauga produs" << endl;
        cout << "2. Elimina produs" << endl;
        cout << "3. Editeaza pret produs" << endl;
        cout << "4. Afiseaza lista de produse" << endl;
        cout << "5. Cumpara!!!" << endl;
        cout << "0. Iesire" << endl;
        cout << "-------------------------------" << endl;
        cout << "Alegeti o optiune: ";
        cin >> optiune;

        switch (optiune)
        {
            case 1:
            {
                if (nrProduse >= 100)
                {
                    system("cls");
                    system("Color E7");
                    cout << "Lista de produse este plina!" << endl;
                    Sleep(3000);
                    system("cls");
                    break;
                }
                system("cls");
                Produs produsNou;
                produsNou.citireProduse();
                int gasit = 0;
                for (int i = 0; i < nrProduse; i++)
                {
                    if (produsNou.denumire == produse[i].denumire)
                    {
                        gasit = 1;
                        int raspuns;
                        cout << "Produsul deja se afla in stocul nostru. Doriti sa adaugati in stocul deja existent?" << endl;
                        cout << "Daca <DA>, introduceti <1>. In caz contrar introduceti alt carecter:" << endl;
                        cin >> raspuns;
                        switch (raspuns)
                        {
                            case 1:
                            {
                                produse[i].stocMagazin += produsNou.stocMagazin;
                                system("Color A0");
                                cout << "Stoc completat!";
                                Sleep(3000);
                                system("cls");
                                break;
                            }
                            default:
                            {
                                system("Color C0");
                                cout << "Operatiune anulata";
                                Sleep(3000);
                                system("cls");
                                break;
                            }
                        }
                        break;
                    }
                }
                if (gasit == 0)
                {
                    produse[nrProduse++] = produsNou;
                    system("cls");
                    system("Color 20");
                    cout << "Produsul a fost adaugat cu succes!" << endl;
                    Sleep(3000);
                    system("cls");
                    break;
                }
                break;
            }
            case 2:
            {
                if (nrProduse == 0)
                {
                    system("cls");
                    system("Color E0");
                    cout << "Lista de produse este goala!" << endl;
                    Sleep(3000);
                    system("cls");
                    break;
                }
                system("cls");
                int gasit = 0;
                cout << "Introduceti produsul pe care vreti sa-l eliminati: ";
                string prodElim;
                cin.get();
                getline(cin, prodElim);
                for (int i = 0; i < nrProduse;i++)
                {
                    if (prodElim == produse[i].denumire)
                    {
                        gasit = 1;
                        for (int j = i; j < nrProduse - 1; j++)
                        {
                            produse[j] = produse[j + 1];
                        }
                        nrProduse--;
                        break;
                    }
                }
                system("cls");
                if (gasit == 1)
                {
                    system("Color 20");
                    cout << "Produsul a fost eliminat cu succes!" << endl;
                }
                else
                {
                    system("Color 40");
                    cout << "Produsul nu a fost gasit." << endl;
                }
                Sleep(3000);
                system("cls");
                cout << endl;
                break;
            }
            case 3:
            {
                if (nrProduse == 0)
                {
                    system("Color E0");
                    system("cls");
                    cout << "Lista de produse este goala!" << endl;
                    Sleep(3000);
                    system("cls");
                    break;
                }
                system("cls");
                int gasit = 0;
                cout << "Introduceti produsul caruia doriti sa editati pretul: ";
                string prodSchimbPret;
                cin.get();
                getline(cin, prodSchimbPret);
                for (int i = 0; i < nrProduse; i++)
                {
                    if (prodSchimbPret == produse[i].denumire)
                    {
                        gasit = 1;
                        cout << "Introduceti pretul nou al produsului: ";
                        cin >> produse[i].pret;
                    }
                }
                system("cls");
                if (gasit == 1)
                {
                    system("Color 20");
                    cout << "Pretul a fost schimbat cu succes!" << endl;
                }
                else
                {
                    system("Color 40");
                    cout << "Nu s-a gasit produsul. Nu s-a modificat niciun pret." << endl;
                }
                Sleep(3000);
                system("cls");
                break;
            }
            case 4:
            {
                if (nrProduse == 0)
                {
                    system("Color E0");
                    system("cls");
                    cout << "Lista de produse este goala!" << endl;
                    Sleep(3000);
                    system("cls");
                    break;
                }
                system("cls");
                cout << "Lista de produse:" << endl;
                cout << endl;
                for (int i = 0; i < nrProduse; i++) {
                    produse[i].afiseazaProdus();
                cout << "------------------------------" << endl;
                }
                cout << endl;
                break;
            }
            case 5:
            {
                if (nrProduse == 0)
                {
                    system("cls");
                    system("Color E0");
                    cout << "Lista de produse este goala!" << endl;
                    Sleep(3000);
                    system("cls");
                    break;
                }
                system("cls");
                string cumpProd;
                int gasit = 0;
                float copBuget;
                copBuget = buget;
                cout << "Ce doriti sa cumparati?" << endl;
                cin.get();
                getline(cin, cumpProd);
                float cantCump;
                for (int i = 0; i < nrProduse; i++)
                {
                    if (cumpProd == produse[i].denumire)
                    {
                        gasit = 1;
                        int x = 0;
                        if (produse[i].unitMasura % 2 == 0)
                        {
                            cout << "Cate bucati doriti sa cumparati?" << endl;
                            cin >> cantCump;
                            while (x == 0)
                            {
                                if (!(cantCump))
                                {
                                    cin.clear();
                                    cin.ignore();
                                    cout << "Introduceti o valoare numerica: ";
                                    cin >> cantCump;
                                }
                                else x = 1;
                            }
                        }
                        else
                        {
                            cout << "Cate kilograme doriti sa cumparati?" << endl;
                            cin >> cantCump;
                            while (x == 0)
                            {
                                if (!(cantCump))
                                {
                                    cin.clear();
                                    cin.ignore();
                                    cout << "Introduceti o valoare numerica: ";
                                    cin >> cantCump;
                                }
                                else x = 1;
                            }
                        }
                        if (cantCump > produse[i].stocMagazin)
                        {
                            system("Color 04");
                            cout << "Stoc insuficient!" << endl;
                            Sleep(2000);
                            system("Color 07");
                            int raspuns;
                            cout << "Doriti sa cumparati o alta cantitate, mai mica sau egala decat " << produse[i].stocMagazin << " ?" << endl;
                            cout << "Daca <DA>, introduceti 1. In caz contrar introduceti orice valoare" << endl;
                            cin >> raspuns;
                            switch (raspuns)
                            {
                                case 1:
                                {
                                    if (produse[i].unitMasura % 2 == 0)
                                    {
                                        int x = 0;
                                        cout << "Cate bucati doriti sa cumparati?" << endl;
                                        cin >> cantCump;
                                        while (x == 0)
                                        {
                                            if (!(cantCump))
                                            {
                                                cin.clear();
                                                cin.ignore();
                                                cout << "Introduceti o valoare numerica: ";
                                                cin >> cantCump;
                                            }
                                            else x = 1;
                                        }
                                    }
                                    else
                                    {
                                        int x = 0;
                                        cout << "Cate kilograme doriti sa cumparati?" << endl;
                                        cin >> cantCump;
                                        while (x == 0)
                                        {
                                            if (!(cantCump))
                                            {
                                                cin.clear();
                                                cin.ignore();
                                                cout << "Introduceti o valoare numerica: ";
                                                cin >> cantCump;
                                            }
                                            else x = 1;
                                        }
                                    }
                                    break;
                                }
                                default:
                                {
                                    system("Color E0");
                                    cout << "Tranzactie anulata!";
                                    Sleep(3000);
                                    system("cls");
                                    break;
                                }
                            }
                        }
                        float plata;
                        plata = cantCump * produse[i].pret;
                        if (plata > buget)
                        {
                            system("Color 40");
                            cout << "Fonduri insuficiente! Achizitia a fost anulata!";
                            Sleep(3000);
                            system("cls");
                            break;
                        }
                        else
                        {
                            produse[i].stocMagazin -= cantCump;
                            buget -= plata;
                            if (produse[i].stocMagazin == 0)
                            {
                                for (int j = i; j < nrProduse - 1; j++)
                                {
                                    produse[j] = produse[j + 1];
                                }
                                nrProduse--;
                            }
                        }
                    }
                }
                if ((gasit == 1)&&(copBuget !=buget))
                {
                    system("Color 20");
                    cout << "Multumim ca ati cumparat de la noi";
                    Sleep(2000);
                    system("cls");
                }
                else if(gasit ==0)
                {
                    system("Color E0");
                    cout << "Din pacate produsul nu este in stocul nostru...";
                    Sleep(3000);
                    system("cls");
                }
                break;
            }
            case 0:
                system("cls");
                system("Color 50");
                cout << "La revedere!" << endl;
                break;
            default:
                system("cls");
                system("Color 04");
                cout << "Optiune invalida!" << endl;
                Sleep(3000);
                system("cls");
        }
    } while (optiune != 0);
    return 0;
}
