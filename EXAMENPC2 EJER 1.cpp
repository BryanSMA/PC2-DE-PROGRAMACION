/*Dise�a un programa de ayuda al diagn�stico de enfermedades. 
En nuestra base de datos hemos registrado 10 enfermedades y 10 s�ntomas:
Char enfermedades(10)(20) = {�gripe�,�indigesti�n�,�catarro�, ...}
Char s�ntomas(10)(20) = {�fiebre�,�tos�,�dolor de cabeza�, ...}
Almacenamos en una matriz de 10 � 10 valores booleanos (1 o 0) los s�ntomas quepresenta cada enfermedad:
bool s�ntomtologias(10)(20) = {{1,0,1, ...},              {0,0,0, ...},.... }; 
La celda sintomatologia [i ] [j]vale 1 si la enfermedad i presenta el s�ntoma j,
y 0 encaso contrario.
Dise�a un programa que pregunte al paciente si sufre cada uno de los 10 s�ntomas y,
en funci�n de las respuestas dadas, determine la enfermedad que padece. 
Si la descripci�n de sus s�ntomas no coincide exactamente con la de alguna de las enfermedades,
el sistema indicar� que no se puede emitir un diagn�stico fiable.*/
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char enfermedades[10][20]= {"gripe", "indigestion", "catarro", "bronquitis", "alergia", "migra�a", "gastritis", "amigdalitis", "sinusitis", "covid"};
	string sintomas[10] = {"fiebre", "tos", "dolor de cabeza", "nausea", "dolor de garganta", "congestion", "dificultad para respirar", "fatiga", "dolor muscular", "perdida de apetito"};
	bool sintomatologias[10][10]={
	{1, 1, 1, 0, 1, 0, 0, 1, 0, 0},//gripe
	{0, 0, 1, 1, 0, 0, 0, 1, 1, 0},//indigestion
	{0, 1, 1, 0, 1, 1, 0, 1, 0, 0},//catarro
	{1, 1, 0, 0, 1, 1, 1, 1, 0, 0},//bronquitis
	{0, 1, 1, 0, 1, 1, 0, 1, 0, 1},//alergia
	{0, 0, 1, 1, 0, 1, 0, 1, 0, 0},//migra�a
	{1, 0, 1, 1, 0, 1, 0, 1, 1, 0},//gastritis
	{0, 1, 1, 0, 1, 1, 0, 1, 0, 1},//amigdalitis
	{0, 1, 1, 0, 1, 1, 0, 1, 0, 0},//sinusitis
	{1, 1, 1, 0, 1, 1, 1, 1, 1, 1},//covid
	};
	bool sintomas_persona[10];
	cout<<"Indique si presente alguno de los siguientes sintomas(1 para si, 0 para no):"<<endl;
	for(int i=0; i<10;i++){
		cout<<sintomas[i]<<": "<<endl;
		cin>>sintomas_persona[i];
	}
	bool encontrado;
    for(int i = 0; i < 10; ++i){
        encontrado=true;
        for(int j = 0; j < 10; ++j){
            if(sintomas_persona[j]!=sintomatologias[i][j]){
                encontrado=false;
                break;
            }
        }
        if(encontrado){
            cout<<"Usted puede tener: "<<enfermedades[i]<<endl;
            return 0;
        }
    }
    cout<<"No se puede emitir un diagn�stico fiable."<<endl;
	return 0;
}
