#include <iostream>
#include <vector>
#include<string> // getline
#include <conio.h>  //. Esta función se utiliza para leer un carácter del teclado sin que se muestre en la consola.
using namespace std;
struct Usuario
{
	int 	codUsu;
	string 	nomUsu;
	string 	passUsu;
	int	   	tipUsu;
};
struct Producto
{
	int		codProducto;
	string	nomProducto;
	float	preProducto;
	int		stkProducto;
};

struct Venta {
	string producto;
	int cantidad;
	float total;
};

struct RVenta {
	string nombreCliente;
	string nombreProducto;
	int cantidad;
	float montoTotal;
};

vector<RVenta> registroVentas;
vector<Usuario> vecUsuario;   
vector<Producto> vecProducto;

void 	add();
void	validarUsuario();
string leerContrasena();
void  mostrarMenuAdmin();
void agregarvendedor();
void listarvendedores();
void eliminarVendedor();
void modificarVendedor();
void buscarVendedor();
void opcionesproductos();
void addVector();
int getCorrelativo();
void removeVector();
void modifyVector();
void listOfItems();
void buscarPorCodigo();
void mostrarMenuVendedor();
void registrarventa();
bool seguirEjecutando = true; 
void listarVentas();
void eliminarVenta();
void consultarVentaPorCliente();
void modificarVenta();
int main(int argc, char *argv[]) {
	
	
	
	add();	//mis usuarios predeterminados
	while(seguirEjecutando){
		validarUsuario();
		system("pause");
		system("cls");
	}
	
	return 0;
}


// Función para agregar un vendedor
void agregarVendedor() {
	int codVendedor, tipVendedor = 2;
	string nomVendedor, passVendedor;
	
	cout << "Ingrese el nombre de usuario del vendedor a agregar\n";
	cin >> nomVendedor;
	cout << "Ingrese la contraseña del vendedor a agregar\n";
	cin >> passVendedor;
	
	codVendedor = vecUsuario.size()+1;
	cout << "El codigo del vendedor es: " << codVendedor << endl;
	
	Usuario usuario;
	usuario.nomUsu = nomVendedor;
	usuario.passUsu = passVendedor;
	usuario.codUsu = codVendedor;
	usuario.tipUsu = tipVendedor;
	
	vecUsuario.push_back(usuario);
}

void listarVendedores() {
	cout << "Listado de Vendedores:\n";
	for (int i = 0; i < vecUsuario.size(); i++) {
		if (vecUsuario[i].tipUsu == 2) { // Comprobar si el usuario actual es un vendedor
			cout << "-----------------------------------\n";
			cout << "Usuario: " << vecUsuario[i].nomUsu << endl;
			cout << "Contraseña: " << vecUsuario[i].passUsu << endl;
			cout << "Codigo de usuario: " << vecUsuario[i].codUsu << endl;
		}
	}
}


void eliminarVendedor()
{
	int cod;
	bool verificacion= false;
	cout << "Ingrese el código de usuario del vendedor a eliminar \n";
	cin >> cod;
	
	for (int i = 0; i < vecUsuario.size(); i++) {
		if(cod == vecUsuario[i].codUsu)
		{
			vecUsuario.erase(vecUsuario.begin() + i);
			verificacion = true;
			break;
		}
		
	}
	if(verificacion == true)
	{
		cout<<"Vendedor eliminado satisfactoriamente!!!\n";
	}
	else
	{
		cout<<"Codigo ingresado no existe!!!\n";
	}
}
void modificarVendedor() {
	int cod;
	bool encontrado = false;
	cout << "Ingrese el código del vendedor a modificar: ";
	cin >> cod;
	
	for (int i = 0; i < vecUsuario.size(); i++) {
		if (vecUsuario[i].codUsu == cod && vecUsuario[i].tipUsu == 2) { // Asegurarse de que es un vendedor
			encontrado = true;
			
			// Solicitar nuevos datos
			cout << "Ingrese el nuevo nombre de usuario para " << vecUsuario[i].nomUsu << ": ";
			cin >> vecUsuario[i].nomUsu;
			cout << "Ingrese la nueva contraseña: ";
			cin >> vecUsuario[i].passUsu;
			cout << "Ingrese el nuevo codigo de usuario: ";
			cin >> vecUsuario[i].codUsu;
			cout << "Datos del vendedor actualizados correctamente.\n";
			break;
		}
	}
	
	if (!encontrado) {
		cout << "No se encontró un vendedor con el código proporcionado.\n";
	}
}

void buscarVendedor()
{
	int codigovendedor;
	bool verif=false;
	cout << "Ingrese el código del vendedor a buscar\n";
	cin >> codigovendedor;
	for (int i = 0; i < vecUsuario.size(); i++)
	{
		if(codigovendedor == vecUsuario[i].codUsu)
		{
			cout << "Nombre de usuario: " << vecUsuario[i].nomUsu<<endl;
			cout << "Contraseña de usuario: " << vecUsuario[i].passUsu<<endl;
			verif = true;
			break;
		}
	}
	
	if (verif == true)
	{
		cout << "Vendedor encontrado " ;
	}
	else
	{
		cout<<"El codigo ingresado no existe!!!\n";
	}
}

void add()
{
	vecUsuario.push_back({1,"jeferson","123",1});
	vecUsuario.push_back({2,"jeferson1","123",2});
	
	Usuario usuario;
	usuario.codUsu =3;
	usuario.nomUsu = "jperez";
	usuario.passUsu = "91011";
	usuario.tipUsu = 2;
	vecUsuario.push_back(usuario);
}
void	validarUsuario()
{
	string nomUsuario,passUsuario;
	bool flag = false;
	int pos;
	cout<<"ACCESO AL SISTEMA\n";
	cout<<"Usuario:";
	cin>>nomUsuario;
	passUsuario = leerContrasena();
	
	for(int i=0;i<vecUsuario.size();i++)
	{
		if(nomUsuario == vecUsuario[i].nomUsu && 
		   passUsuario == vecUsuario[i].passUsu)
		{
			flag = true;		
			pos = i;
		}
	}
	if(flag == true)
	{
		cout<<"Acceso correcto\n";
		system("pause"); //hace que el programa se detenga hasta que el usuario presione cualquier tecla.
		system("cls");  //borra la pantalla de la consola.
		switch(vecUsuario[pos].tipUsu)
		{
		case 1:
			cout<<"MENU DE OPCIONES GENERAL\n";
			cout<<"------------------------\n";
			cout<<"Admin:\n";
			mostrarMenuAdmin();
			break;
		case 2:	
			cout<<"MENU DE VENTAS\n";
			cout<<"------------------------\n";
			cout<<"Vendedor:\n";	
			mostrarMenuVendedor();
			break;		
		}				
	}
	else
	{
		cout<<"Acceso denegado\n";
	}
}
void mostrarMenuAdmin() {
	int opcion;
	do {
		cout << "MENU DE OPCIONES DEL ADMINISTRADOR\n";
		cout << "1. Agregar Vendedor\n";
		cout << "2. Listar Vendedores\n";
		cout << "3. Eliminar Vendedor\n";
		cout << "4. Modificar Vendedor\n";
		cout << "5. Buscar Vendedor\n";
		cout << "6. Salir\n";
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			agregarVendedor();
			break;
		case 2:
			listarVendedores();
			break;
		case 3:
			eliminarVendedor();
			break;
		case 4:
			modificarVendedor();
			break;
		case 5:
			buscarVendedor();
			break;
		case 6:
			cout << "Saliendo del menú del administrador...\n";
			seguirEjecutando = true; // Establecer la variable en false para salir del bucle
			system("cls");
			return; // Retornar para salir de la función
			
		default:
			cout << "Opción no válida. Intente de nuevo.\n";
		}
	} while (opcion != 6 && seguirEjecutando);
}
string leerContrasena() {
	string contrasena;
	char ch;
	cout << "Ingrese su contraseña: ";
	ch = _getch();
	while (ch != 13) { // (enter)
		if (ch != 8) { // No es un space
			contrasena.push_back(ch);
			cout << '*';
		}
		else if (!contrasena.empty()) { // Es un backspace y la contraseña no est
			contrasena.pop_back();
			cout << "\b \b"; // Retrocede un carácter, escribe espacio (para borrar
		}		
		ch = _getch();
	}
	cout << endl;
	return contrasena;
}

void mostrarMenuVendedor() {
	int opcion;
	do {
		cout << "MENU DE OPCIONES DEL VENDEDOR\n";
		cout << "1. Productos\n";
		cout << "2. Registrar Venta\n";
		cout << "3. Ver ventas realizadas\n";
		cout << "4. Eliminar Venta\n";
		cout << "5. Buscar Venta\n";
		cout << "6. Modificar Venta\n";
		cout << "7. Salir\n";
		cout << "SELECCIONE UNA OPCION: [1-6] ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			opcionesproductos();
			break;
		case 2:
			registrarventa();
			break;
		case 3:
			listarVentas();
			break;
		case 4:
			eliminarVenta();
			break;
		case 5:
			consultarVentaPorCliente();
			break;
			
		case 6:
			modificarVenta();
			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Opción no válida. Intente de nuevo.\n";
		}
		
	} while
		 (opcion != 7);
}

void opcionesproductos()
{
	int opcion;
	do
	{
		cout << "MENU DE OPCIONES\n";
		cout << "Agregar Productos__________[1]\n";
		cout << "Buscar Producto____________[2]\n";
		cout << "Eliminar Producto__________[3]\n";
		cout << "Modificar Producto_________[4]\n";
		cout << "Listar producto____________[5]\n";
		cout << "Salir______________________[6]\n";
		cout << "Ingrese una opcion[1-6]: ";
		cin >> opcion;
		
		switch (opcion)
		{
		case 1: 
			system("cls"); 
			addVector(); 
			break;
		case 2:	
			system("cls"); 
			buscarPorCodigo(); 
			system("pause");
			system("cls"); 
			break;
		case 3:	
			system("cls"); 
			removeVector();
			system("pause");
			system("cls"); 
			break;
		case 4:	
			system("cls");
			modifyVector();
			system("pause");
			system("cls"); 
			break;
		case 5:	
			system("cls"); 
			listOfItems(); 
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls"); 
			return;
		default:cout << "Ingrese una opcion correcta[1-6]\n";
		}

	} while (opcion!=6);
}

int getCorrelativo()
{
	if (vecProducto.size() == 0)//Esta vacio
	{
		return 1;
	}
	else
	{
		return vecProducto[vecProducto.size()-1].codProducto + 1;
	}
}
void addVector()
{ 
	string	rpta,
		nomPro;
	int		cod,
		stkPro;
	float	prePro;
	/*Agregando datos al arreglo*/
	do
	{
		cod = getCorrelativo();
		cout << "Codigo:"<<cod<<endl;
		//cin >> cod;
		cin.ignore();//limpiar el buffer
		cout << "Nombre:"; 
		getline(cin,nomPro);
		//cin >> nomPro;
		cout << "Precio:"; cin >> prePro;
		cout << "Stock:"; cin >> stkPro;
		
		/*declarar un tipo de dato para la estructura*/
		Producto producto;
		producto.codProducto = cod; //lleno datos de la estructura
		producto.nomProducto = nomPro;
		producto.preProducto = prePro;
		producto.stkProducto = stkPro;
		
		/*Agregar el registro al arreglo*/
		vecProducto.push_back(producto);
		
		cout << "Deseas continuar registrando productos...(S/s):";
		cin >> rpta;
		
		system("cls");
	} while (rpta == "S" || rpta == "s");

}

void listOfItems()
{
	for (int i = 0; i < vecProducto.size(); i++)
	{
		cout << "-----------------------------------\n";
		cout << "Codigo:" << vecProducto[i].codProducto << endl;
		cout << "Nombre:" << vecProducto[i].nomProducto << endl;
		cout << "Precio:" << vecProducto[i].preProducto << endl;
		cout << "Stock:" << vecProducto[i].stkProducto << endl;
		cout << "-----------------------------------\n";
	}
}

void	buscarPorCodigo()
{
	int codigo;
	bool flag = false;
	cout << "Ingrese el codigo a buscar:";
	cin >> codigo;
	for (int i = 0; i < vecProducto.size(); i++)
	{
		if (codigo == vecProducto[i].codProducto)
		{
			cout << "Codigo:" << vecProducto[i].codProducto << endl;
			cout << "Nombre:" << vecProducto[i].nomProducto << endl;
			cout << "Precio:" << vecProducto[i].preProducto << endl;
			cout << "Stock:" << vecProducto[i].stkProducto << endl;
			flag = true;
			break;//Salir del ciclo
		}
	}
	if(flag == false)
	{
		cout<<"El codigo ingresado no existe!!!\n";
	}
}
void removeVector()
{
	int  cod;
	bool flag = false;
	cout<<"Ingrese el codigo del producto a eliminar:";
	cin>>cod;
	for(int i=0;i<vecProducto.size();i++)
	{
		if(cod == vecProducto[i].codProducto)	
		{
			vecProducto.erase(vecProducto.begin() + i);
			flag = true;
			break;
		}
	}
}

void modifyVector()
{
	int cod,
		opcion;
	string 	_nombre;
	float	_precio;
	int		_stock;
	
	cout<<"Ingrese el codigo del producto a modificar:";			
	cin>>cod;
	for (int i = 0; i < vecProducto.size(); i++) {

		if(cod == vecProducto[i].codProducto)
		{
			cout<<"--------------------\n";
			cout<<"Registro encontrado\n";
			cout<<"--------------------\n";
			cout<<"Codigo:"<<vecProducto[i].codProducto<<endl;				
			cout<<"Nombre:"<<vecProducto[i].nomProducto<<endl;				
			cout<<"Precio:"<<vecProducto[i].preProducto<<endl;				
			cout<<"Stock:"<<vecProducto[i].stkProducto<<endl;				
			cout<<"--------------------\n";
			cout<<"MINI MENU\n";
			cout<<"Nombre\t\t[1]\n";
			cout<<"Precio\t\t[2]\n";
			cout<<"Stock\t\t[3]\n";
			cout<<"Salir\t\t[4]\n";
			cout<<"Seleccionar una opcion[1-4]:";
			cin>>opcion;
			cin.ignore();
			switch(opcion)
			{
			case 1: cout<<"Cambiar nombre:";
			getline(cin,_nombre);
			vecProducto[i].nomProducto = _nombre; 
			break;
			case 2:	cout<<"Cambiar precio:";
			cin>>_precio;	
			vecProducto[i].preProducto = _precio;
			break;
			case 3:	cout<<"Cambiar stock:";
			cin>>_stock;	
			vecProducto[i].stkProducto = _stock;
			break;
			case 4:break;
			default:cout<<"Ingrese una opcion correcta[1-4]\n";
		}
		}
		else
		{
			cout<<"El codigo ingreado no existe!!!\n";
		}
	}
}

void registrarventa() {
	int idProducto, cantidad;
	string nombreCliente, nombreProducto;
	float montoTotal = 0.0;
	bool productoEncontrado = false;
	
	cout << "Ingrese el nombre del cliente: ";
	cin.ignore(); // Limpia el buffer antes de leer una cadena de texto
	getline(cin, nombreCliente);
	
	cout << "Ingrese el nombre del producto a comprar: ";
	getline(cin, nombreProducto);
	
	for (int i = 0; i < vecProducto.size(); i++) {
		if (vecProducto[i].nomProducto == nombreProducto) {
			if (vecProducto[i].stkProducto > 0) {
				cout << "Ingrese la cantidad que desea llevar: ";
				cin >> cantidad;
				
				if (cantidad <= vecProducto[i].stkProducto) {
					montoTotal = cantidad * vecProducto[i].preProducto;
					vecProducto[i].stkProducto -= cantidad; // Disminuir el stock del producto
					productoEncontrado = true;
					
					// Registrar la venta
					RVenta nuevaVenta;
					nuevaVenta.nombreCliente = nombreCliente;
					nuevaVenta.nombreProducto = nombreProducto;
					nuevaVenta.cantidad = cantidad;
					nuevaVenta.montoTotal = montoTotal;
					
					registroVentas.push_back(nuevaVenta);
					
				} else {
					cout << "No hay suficiente stock del producto.\n";
				}
			} else {
				cout << "Producto sin stock.\n";
			}
			break; // Salir del bucle una vez que se encuentra el producto
		}
	}
	
	if (!productoEncontrado) {
		cout << "Producto no encontrado.\n";
		system("pause");
		cout << "Para comprar otro producto seleccione enter .... ";
		system("cls"); 
	} else {
		cout << "Monto total a pagar: " << montoTotal << endl;
		cout << "VENTA REGISTRADA\n";
		system("pause");
		system("cls");
	}
}

void listarVentas() {
	if (registroVentas.empty()) {
		cout << "No hay ventas registradas.\n";
		return;
	}
	
	cout << "Listado de Ventas:\n";
	for (int i = 0; i < registroVentas.size(); i++) {
		cout << "-----------------------------------\n";
		cout << "Nombre del Cliente: " << registroVentas[i].nombreCliente << endl;
		cout << "Producto Vendido: " << registroVentas[i].nombreProducto << endl;
		cout << "Cantidad: " << registroVentas[i].cantidad << endl;
		cout << "Monto Total: S/. " << registroVentas[i].montoTotal << endl;
	}
	cout << "-----------------------------------\n";
	system("pause");
	system("cls");
}

void eliminarVenta(){
	bool confirmado = false;
	string nombreClienteDELETED;
	cout << "Ingrese el nombre del cliente que desea borrar la compra\n";
	cin >> nombreClienteDELETED;
	for(int i=0 ; i< registroVentas.size();i++){
		if(registroVentas[i].nombreCliente == nombreClienteDELETED)
		{
			registroVentas.erase(registroVentas.begin() + i);
			confirmado = true;
			break;
			
		}
	}
	if(confirmado == true)
	{
		cout << "VENTA ELIMINADA \n";
		system("pause");
		system("cls"); 
	}
	else
	{
		cout << "NO SE ENCONTRO NINGUNA VENTA PARA EL CLIENTE INDICADO \n";
		system("pause");
		system("cls"); 
	}
}
	
void consultarVentaPorCliente() {
		string nombreCliente;
		cout << "Ingrese el nombre del cliente para buscar sus ventas: ";
		cin >> nombreCliente;
		
		bool ventaEncontrada = false;
		for (int i = 0; i < registroVentas.size(); i++) {
			if (registroVentas[i].nombreCliente == nombreCliente) {
				cout << "-----------------------------------\n";
				cout << "Producto Vendido: " << registroVentas[i].nombreProducto << endl;
				cout << "Cantidad: " << registroVentas[i].cantidad << endl;
				cout << "Monto Total: S/. " << registroVentas[i].montoTotal << endl;
				ventaEncontrada = true;
			}
		}
		
		if (!ventaEncontrada) {
			cout << "No se encontraron ventas para el cliente: " << nombreCliente << ".\n";
		}
	system("pause");
	system("cls");
}
	
void modificarVenta() {
	if (registroVentas.empty()) {
		cout << "No hay ventas para modificar.\n";
		return;
	}
	
	string nombreCliente, nombreProducto;
	int nuevaCantidad;
	float nuevoMontoTotal;
	cout << "Ingrese el nombre del cliente de la venta a modificar: ";
	cin >> nombreCliente;
	cout << "Ingrese el nombre del producto de la venta a modificar: ";
	cin >> nombreProducto;
	
	for (int i = 0; i < registroVentas.size(); i++) {
		if (registroVentas[i].nombreCliente == nombreCliente && registroVentas[i].nombreProducto == nombreProducto) {
			cout << "Ingrese la nueva cantidad: ";
			cin >> nuevaCantidad;
			
			// Verificar existencia del producto y calcular el nuevo monto
			for (int j = 0; j < vecProducto.size(); j++) {
				if (vecProducto[j].nomProducto == nombreProducto) {
					nuevoMontoTotal = nuevaCantidad * vecProducto[j].preProducto;
					registroVentas[i].cantidad = nuevaCantidad;
					registroVentas[i].montoTotal = nuevoMontoTotal;
					cout << "Venta modificada correctamente.\n";
					cout << "Nuevo monto total: S/. " << nuevoMontoTotal << endl;
					system("pause");
					system("cls");
					return;
				}
			}
			
			cout << "Producto no encontrado en el inventario.\n";
			return;
		}
	}
	
	cout << "Venta no encontrada.\n";
	system("pause");
	system("cls");
}
