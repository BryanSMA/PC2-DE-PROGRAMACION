/*Desarrolle un programa en C++ que gestione el registro, consulta y cálculo de datos académicos de alumnos,
permitiendo ingresar información como el código, nombre, género, edad y notas de diversas asignaturas (curso 1, curso 2 y curso 3), 
calcular el promedio de notas de cada alumno y 
presentar un menú con opciones para registrar datos, ver la lista de alumnos, ver Notas por Asignatura, 
Calcular el promedio y Mostrar Primero y Ultimo.*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct Alumno {
    int codigo;
    string nombre;
    char genero;
    int edad;
    vector<float> notas;
    float promedio;
};
void registrarAlumno(vector<Alumno>& alumnos) {
    Alumno nuevoAlumno;
    cout<<"Ingrese el codigo del alumno: "; cin>>nuevoAlumno.codigo;
    cout<<"Ingrese el nombre del alumno: ";
    cin.ignore();
    getline(cin, nuevoAlumno.nombre);
    cout<<"Ingrese el genero del alumno (M/F): ";
    cin>>nuevoAlumno.genero;
    cout<<"Ingrese la edad del alumno: ";
    cin>>nuevoAlumno.edad;
    cout<<"Ingrese las notas del alumno para los tres cursos (curso 1, curso 2 y curso 3): ";
    for(int i=0; i<3; i++){
        float nota;
        cin>>nota;
        nuevoAlumno.notas.push_back(nota);
    }
    float suma=0;
    for (size_t i=0; i<nuevoAlumno.notas.size(); i++) {
        suma+=nuevoAlumno.notas[i];
    }
    nuevoAlumno.promedio=suma/nuevoAlumno.notas.size();
    alumnos.push_back(nuevoAlumno);
}
void mostrarAlumnos(const vector<Alumno>& alumnos) {
    cout<<"Lista de Alumnos: "<< endl;
    for (size_t i=0; i<alumnos.size(); ++i) {
        cout << "Codigo: "<<alumnos[i].codigo<<", Nombre: "<<alumnos[i].nombre<< ", Genero: "<<alumnos[i].genero<<", Edad: "<<alumnos[i].edad<< ", Promedio: "<<fixed<< setprecision(2) << alumnos[i].promedio << endl;
    }
}
void mostrarNotasPorAsignatura(const vector<Alumno>& alumnos, int curso) {
    cout<<"Notas para el Curso "<<curso<<":"<<endl;
    for (size_t i=0; i<alumnos.size(); ++i) {
        cout<<"Codigo: "<<alumnos[i].codigo<<", Nota: "<<alumnos[i].notas[curso - 1]<<endl;
    }
}
void calcularPromedioGeneral(const vector<Alumno>& alumnos){
    float suma=0;
    int totalAlumnos=0;
    for (size_t i=0; i<alumnos.size(); i++) {
        suma+=alumnos[i].promedio;
        totalAlumnos++;
    }
    float promedioGeneral=suma/totalAlumnos;
    cout<<"Promedio General de Notas: "<<fixed<<setprecision(2)<<promedioGeneral<<endl;
}
void mostrarPrimeroUltimo(const vector<Alumno>& alumnos){
    if (alumnos.empty()) {
        cout<<"No hay alumnos registrados."<<endl;
        return;
    }
    cout<<"Primer Alumno: "<<alumnos.front().nombre<<endl;
    cout<<"Ultimo Alumno: "<<alumnos.back().nombre<<endl;
}

int main() {
    vector<Alumno> alumnos;
    int opcion;
    do {
        cout<<"\t\tMenu:\n";
        cout<<"1. Registrar Alumno\n";
        cout<<"2. Ver Lista de Alumnos\n";
        cout<<"3. Ver Notas por Asignatura\n";
        cout<<"4. Calcular Promedio General\n";
        cout<<"5. Mostrar Primer y Ultimo Alumno\n";
        cout<<"0. Salir\n";
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch (opcion){
            case 1:
                registrarAlumno(alumnos);
                break;
            case 2:
                mostrarAlumnos(alumnos);
                break;
            case 3:
                int curso;
                cout<<"Ingrese el numero del curso (1, 2 o 3): ";
                cin>>curso;
                mostrarNotasPorAsignatura(alumnos, curso);
                break;
            case 4:
                calcularPromedioGeneral(alumnos);
                break;
            case 5:
                mostrarPrimeroUltimo(alumnos);
                break;
            case 0:
                cout<<"Saliendo del programa..."<<endl;
                break;
            default:
                cout<<"Opcion no valida. Intente de nuevo."<<endl;
        }
    } while(opcion!=0);
    return 0;
}
