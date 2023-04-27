#include <iostream>
#include <string>

using namespace std;

// Declaram clasa Student
class Student
{
private:
    string nume;
    string prenume;
    int varsta;
    string specializare;
    int nota[2];

public:
    Student (string n,string pr, int v,string s,int n1,int n2)
    {
        nume = n;
        prenume=pr;
        varsta = v;
        specializare=s;
        nota[0]=n1;
        nota[1]=n2;
    }
    /*am construit constructorul care are 6 parametri de intrare:
        n-un string reprezentând numele studentului
        pr-un string reprezentând prenumele studentului
        v-un intreg reprezentând vârsta studentului
        s-un string reprezentând specializarea studentului
        n1-un intreg reprezentând nota de la examen a studentului
        n2-un intreg reprezentând nota de la laborator/seminar a studentului
    Acest constructor inițializează membrii unei instanțe a clasei "Student" cu valorile specificate în parametrii constructorului.*/

float media_semestriala()
{
    int suma=nota[0]+nota[1];
    return suma/2.0;
}
/*am alcatuit o metoda clasei Student pentru a calcula media semetriala a studentului pe baza celor doua note ale sale introduse de la tastautura.
Media este calculata prin insumarea celor doua note,apoi impartind suma la 2.0*/

void afiseaza_detalile_studentului()
{
    cout<<"Nume: "<<nume<<endl;
    cout<<"Prenume: "<<prenume<<endl;
    cout<<"Varsta: "<<varsta<<endl;
    cout<<"Specializare: "<<specializare<<endl;
    cout<<"Note: "<<nota[0]<<","<<nota[1]<<endl;
    cout<<"Media: "<<media_semestriala()<<endl;
    if(media_semestriala()<5)
    {
        cout<<"NEPROMOVAT";
    }
    else
    {
        cout<<"PROMOVAT";

    }
    cout<<endl;
}
/*am construit o alta metoda a clasei Student care afiseaza toate detalile studentului.
Si la media am folosit o conditie aceea daca media semestriala a studentului este mai mica decat 5 sa se afiseze ca este NEPROMOVAT astfel se va afisa PROMOVAT.*/
    ~Student()
    {
        cout<<"Destructor apelat"<<endl;
    }
    /*Am declarat un destructor cu un compartiment simplu care afiseaza mesajul "Destructor apelat" atunci cand un obiect acelei clase este distrus.
      Astfel cand un obiect de tip Student este creat si apoi distrus se va afisa mesajul respectiv indicand ca memoria alocata a fost eliberata corect*/
};
int main()
{
    string nume, prenume, specializare;
    int varsta,n1,n2;
   // Introducem detaliile pentru primul student
    cout<<"Introduceti detaliile pentru primul student:"<<endl;
    cout<<"Nume: ";
    cin>>nume;
    cout<<"Prenume: ";
    cin>>prenume;
    cout<< "Varsta: ";
    cin>>varsta;
    cout<<"Specializarea: ";
    cin>>specializare;
    cout<<"Introduceti cele 2 note:"<<endl;
    cout<<"nota examenului:";cin>>n1;
    cout<<"nota laborator/seminar:";cin>>n2;
    Student student1(nume, prenume, varsta, specializare,n1,n2);// Creăm primul obiect de tip Student
    cout<<endl;

    // Introducem detaliile pentru al doilea student
    cout<<"Introduceti detaliile pentru al doilea student:"<<endl;
    cout<<"Nume: ";
    cin>>nume;
    cout<<"Prenume: ";
    cin>>prenume;
    cout<<"Varsta: ";
    cin>>varsta;
    cout<<"Specializarea: ";
    cin>>specializare;
     cout<<"Introduceti cele 2 note:"<<endl;
    cout<<"nota examenului:";cin>>n1;
    cout<<"nota laborator/seminar:";cin>>n2;
    Student student2(nume, prenume, varsta, specializare,n1,n2);// Creăm al doilea obiect de tip Student
    cout<<endl;

    //Introducem detaliile pentru al treilea student
    cout<<"Introduceti detaliile pentru al treilea student:" << endl;
    cout<<"Nume: ";
    cin>>nume;
    cout<<"Prenume: ";
    cin>>prenume;
    cout<<"Varsta: ";
    cin>>varsta;
    cout<<"Specializarea: ";
    cin>>specializare;
    cout<<"Introduceti cele 2 note:"<<endl;
    cout<<"nota examenului:";cin>>n1;
    cout<<"nota laborator/seminar:";cin>>n2;
    Student student3(nume, prenume, varsta, specializare,n1,n2);
    cout<<endl; // Creăm al treilea obiect de tip Student

    cout<<"Detaliile si media pentru primul student:"<<endl;
    student1.afiseaza_detalile_studentului();
    cout<<endl;
    cout<<"Detaliile si media pentru al doilea student:"<<endl;
    student2.afiseaza_detalile_studentului();
    cout<<endl;
    cout<<"Detaliile si media pentru al treilea student:"<<endl;
    student3.afiseaza_detalile_studentului();
    return 0;
}
