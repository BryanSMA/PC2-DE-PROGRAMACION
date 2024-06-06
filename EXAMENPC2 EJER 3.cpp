/*Desarrollar  un  programa  en  C++  que  permita  ingresar  y  almacenar  el  código,  el  nombre, nota 1, nota 2 y nota 3 de un curso. 
Mostrar el promedio de cada estudiante y la cantidad de estudiantes desaprobados. 
Finalmente, ordene los datos en base de los promedios. Muestre los datos ordenados. */
#include <iostream>
#include <string>
using namespace std;
struct Estudiante{
    string cod;
    string nom;
    float nota1,nota2,nota3,prom=0;
};
int main() {
    Estudiante estud[100];
    int n,desap=0;
    cout<<"Ingrese la cantidad de estudiantes : ";
    cin>>n;
    for(int i=0 ; i<n; i++) {
        cout<<"Codigo, nombre y notas del estudiante "<<i+1<<": "<<endl;
        cout<<"Ingrese el codigo de estudiante: "<<endl;
        cin>>estud[i].cod;
        cout<<"Ingrese el nombre del estudiante: "<<endl;
		cin>>estud[i].nom;
		cout<<"Ingrese nota 1: "; cin>>estud[i].nota1;
		cout<<"Ingrese nota 2: "; cin>>estud[i].nota2;
		cout<<"Ingrese nota 3: "; cin>>estud[i].nota3;
        estud[i].prom=(estud[i].nota1+estud[i].nota2+estud[i].nota3)/3.0;
        if (estud[i].prom<=10.0) {
			desap++;
		}
    }
    for (int i=0; i<n-1; i++) {
        for (int j = 0; j<n-i-1; ++j) {
            if (estud[j].prom<estud[j+1].prom) {
                Estudiante temp=estud[j];
                estud[j]=estud[j+1];
                estud[j+1]=temp;
            }
        }
    }
    cout<<"\nPromedio y cantidad de estudiantes desaprobados:\n";
    for (int i=0; i<n; i++){
        cout<<"Estudiante "<<i+1<<": "<<estud[i].nom<<" - Promedio: "<<estud[i].prom<<endl;
    }
    cout<<"Desaprobados: "<<desap<<endl;
    return 0;
}
