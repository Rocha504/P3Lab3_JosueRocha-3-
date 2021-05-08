#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <stdlib.h>   
#include <time.h>

int menu(){
	
	int op;
	cout<<"          MENU            "<<endl;
	cout<<"1-Descomprimir una cadena"<<endl;
	cout<<"2-Crear Matriz con obstaculos"<<endl;
	cout<<"3-Hacer un recorrido"<<endl;
	cout<<"4-SALIR"<<endl<<endl;
	cout<<"Porfavor ingrese una opcion: ";
	cin>>op;
	
	return op;
}
char * descomprimir(char * arreglo,int size){
	
	char * descomprimido;
	int num,acum=0;
	descomprimido=new char[acum];
	char caracter;
	for(int i=0;i<size;i++){
		num = arreglo[i] - '0';
		i++;
		caracter = arreglo[i];
		int aux=acum;	
		for(int x=0;x<num;x++){
			descomprimido[aux]=caracter;	 
			aux++;	
		} 
		acum=acum+num;			
	}
	cout<<"[";
	for(int y=0;y<acum;y++){
		cout<<descomprimido[y]<<",";
	}
	cout<<"]"<<endl;
	 
	return descomprimido;

}


char** matrix(int n,int m,int k){
	srand (time(NULL));
	char** matriz=0;
	
	matriz=new char*[n*m];
	for(int y=0;y<n*m;y++){
		matriz[y]=new char[n*m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			matriz[i][j]='_';
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			matriz[rand()%m+1][rand()%n+1]='#';
		}
	}
	
	for(int i=0;i<n;i++){
	
		for(int j=0;j<m;j++){
			cout<<" "<<matriz[i][j];
		}
		cout<<endl;
	}
	return matriz;
}
	
int main(int argc, char** argv) {
	
	int op=0;
	
	while (op!= 4){
    	op=menu();
    	switch(op){
    		case 1:{
    			char* arreglo;
				int size;
				char entry;
				cout<<"Ingrese el size de la cadena"<<endl;
				cin>>size;	
				arreglo=new char[size];			
				cout<<"A continuacion debera de llenar el arreglo con los Caracteres siguientes: "<<endl;
				cout<<"D-Down"<<endl;
				cout<<"U-Up"<<endl;
				cout<<"L-Left"<<endl;
				cout<<"R-Right"<<endl;
				for(int i=0;i<size;i++){
					cout<<"Ingrese un numero"<<endl;
					cin>>entry;
					if(isdigit(entry)){
						arreglo[i]=entry;
					}
					else{
						cout<<"Ingrese un numero"<<endl;
						cin>>entry;	
					}
					i++;
					cout<<"Ingrese uno de los caracteres permitidos"<<endl;
					cin>>entry;
					if(entry=='D'||entry=='U'||entry=='L'||entry=='R'){
						arreglo[i]=entry;
					}
					else{
						cout<<"caracter invalido vuelva a ingresar uno valido (D,U,L,R)"<<endl;
						cin>>entry;
					}
				}
				descomprimir(arreglo,size);			
			}
			break;
			case 2:{
				int n,m,k;
				cout<<"Ingrese la cantidad de filas para su matriz ";
				cin>>n;
				cout<<"Ingrese la cantidad de columnas para su matriz ";
				cin>>m;
				cout<<"Ingrese la cantidad de obstaculos para su matriz ";
				cin>>k;
				matrix(n,m,k);
				
				 
			}
			break;
				return 0;
	}
	}
}
