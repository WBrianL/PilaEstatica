#include <iostream>
#include <string>
#include <conio.h>

//Pila Estatica

using namespace std;

const int TAM=5;

class empleado{
private:
	int ClaveEmpleado;
	string nombre;
	string domicilio;
	float sueldo;
	string reporta;
	public:
//metos costructores
	empleado(){
		ClaveEmpleado=0;
		nombre=" ";
		domicilio=" ";
		sueldo=0;
		reporta=" ";
	}
	empleado(int clave, string nom, string dom, float suel, string report){
    ClaveEmpleado=clave;
	 nombre=nom;
	 domicilio=dom;
	 sueldo=suel;
	 reporta=report;
	}
	friend ostream& operator<<(ostream& o, empleado& e){
	    o<<"Codigo: "<<e.ClaveEmpleado<<endl;
	    o<<"Nombre: "<<e.nombre<<endl;
	    o<<"Domicilio: "<<e.domicilio<<endl;
	    o<<"Sueldo: "<<e.sueldo<<endl;
	    o<<"Reporta: "<<e.reporta<<endl;
	}
	friend istream& operator>>(istream& in, empleado& e){
	    cout<<"Dame el codigo: ";
	    in>>e.ClaveEmpleado;
	    cout<<"Dame el nombre: ";
	    in>>e.nombre;
	    cout<<"Dame el domicilio: ";
	    in>>e.domicilio;
	    cout<<"Dame el sueldo: ";
	    in>>e.sueldo;
	    cout<<"Dame a quien reporta: ";
	    in>>e.reporta;
	    return in;
	}

	int insertarclave(int clave){
	    ClaveEmpleado=clave;
	}
	bool operator==(empleado& p){
	    return(ClaveEmpleado==p.ClaveEmpleado);
	}
};

class Pila{
private:
    empleado datos[TAM];
    int ult;

        bool elimina(int pos){
        if(vacia() || pos<0 || pos>ult){
            cout<<"Error de eliminacion";
            return true;
        }
        int i=pos;
        while(i<ult){
            datos[i]=datos[i+1];
            i++;
        }
        ult--;
        return false;
    }

    int inserta(empleado elem, int pos){
        if(llena()|| pos<0 || pos>ult+1){
            cout<<"Error de insercion";
            return 0;
        }
        int i=ult+1;
        while(i>pos){
            datos[i]=datos[i-1];
            i--;
        }
        datos[pos]=elem;
        ult++;
        return 1;
    }
public:
    Pila():ult(-1){}

    bool vacia()const{
        if(ult==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool llena()const{
        if(ult==TAM-1)
            return true;
        return false;
    }

    int ultimo()const{
        return ult;
    }

    /*int agrega(empleado elem){
        int i=ult+1;
        if(llena()){
            cout<<"Erros al insertar :(";
        }
        else{
            datos[i]=elem;
            ult++;
        }
    }

    int buscar(empleado elem){
        for(int i=0;i<=ult;i++){
            if(elem==datos[i]){
                cout<<"------------------"<<endl;
                cout<<datos[i];
            }
            else{
                cout<<"------------------"<<endl;
                cout<<"No hay resultados :(";
            }
        }
    }*/

    int muestra(){
        if(vacia()){
            cout<<"La pila esta vacia :("<<endl;
            cout<<"-------------------------"<<endl;
        }
        else{
            int i=ultimo();
            cout<<datos[i];
        }
    }

    void apilar(empleado& elem){
        inserta(elem,ultimo()+1);
        cout<<"Se desapilo correctamente :)";
    }

    /*empleado& desapilar(){
        ult--;
        cout<<"Se desapilo correctamente :)";
    }*/
    void desapilar(){
        elimina(ult);
    }

//Sobre Carga
    friend ostream& operator<<(ostream& o, Pila& P){
        int i=0;
        cout<<"\n";
        while(i<=P.ultimo()){
            o<<P.datos[i];
            i++;
        }
        return o;
    }
    bool operator ==(Pila& P){
        for(int i=0;i<=ult;i++){
            if(datos[i]==P.datos[i]);
        }
    }

};

int main()
{
    Pila pilita;
    empleado empleadito;
    int opcion;

    do {
        cout << "---Menu---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1:
                cout<<"---Apilar---"<<endl;
                cin>>empleadito;
                pilita.apilar(empleadito);
                system("cls");
                break;
            case 2:
                cout<<"---Desapilar---"<<endl;
                pilita.desapilar();
                getch();
                system("cls");
                break;
            case 3:
                cout<<"---Mostrar---"<<endl;
                cout<<"\n";
                pilita.muestra();
                getch();
                system("cls");
                break;
            case 4:
                cout << "Adios c:" << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcion != 4);
    return 0;
}
