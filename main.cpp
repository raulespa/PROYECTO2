#include <iostream>
#include <mysql.h>

using namespace std;

char serverdb[] = "localhost";
char userdb[] = "umg";
char passworddb[] = "Umg$2019";
char database[] = "proyecto2";

int main() {
	MYSQL* connection;
	string ALUMNO_ID;
	string NOMBRE_COMPLETO;
	string CORREO;
	string CARNE;
	string FECHA_NACIMIENTO;
	string GRADO_NOMBRE;
	string GRADO_ID;
	string PROMEDIO;
	string SECCION;
	string sql;
	const char* query;
	int result;
	int op; 
	float num1, num2, num3, num4;
	connection = mysql_init(0);
	if (connection)
	{
		cout << "BIENVENIDO AL PROYECTO 2 / RAUL GONZALEZ / FERDINAND REYNA / *PROGRAMACION 1*\n\n" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection)
		{
			cout << "conexion exitosa con la base de datos" << endl;
			
			int op;
			
		    while(op != 10)
			{
				cout <<"\n\n";
				cout << "1) Igresar Alumnos"<< endl;
				cout << "2) Ingresar Grados"<< endl;
				cout << "3) Borrar Alumno" << endl;
				cout << "4) Borrar Grado"<< endl;
				cout << "5) Ver listado de Alumnos"<< endl;
				cout << "6) Ver Listado de Grados"<< endl;
				cout << "7) Buscar Grado" << endl;
				cout << "8) Buscar Alumno"<< endl;
				cout << "SELECCIONE UNA OPCION\n" << endl;
				cin>> op;
				
				switch(op)
				{
					case 1: 
					
					cout << "ingrese el nombre del alumno: "<<endl;
					cin.ignore();
					getline(cin, NOMBRE_COMPLETO);
					cout << "ingrese el correo del alumno: "<<endl;
					getline(cin, CORREO);
					cout << "ingrese el carne del alumno: "<<endl;
					getline(cin, CARNE);
					cout << "ingrese la fecha de nacimiento del alumno (YY-MM-DD): "<<endl;
					getline(cin, FECHA_NACIMIENTO);
					cout << "ingrese el grado del alumno: "<<endl;
					getline(cin, GRADO_NOMBRE);
					cout << "ingrese la seccion del alumno: "<<endl;
					getline(cin, SECCION);
					cout << "ingrese la primer nota del alumno: ";
					cin >> num1;
					cout << "ingrese la segunda nota del alumno: "<<endl;
					cin >> num2;
					cout << "ingrese la tercera nota del alumno: "<<endl;
					cin >> num3;
					cout << "ingrese la cuarta nota del alumno: "<<endl;
					cin >> num4;
					cout << "el promedio del estudiante es de: " << (num1 + num2 + num3 + num4) / 4;
					cin.ignore();
					cout << "\n ingrese el promedio del estudiante: "<<endl;
					getline(cin, PROMEDIO);
					sql = "insert into alumno(NOMBRE_COMPLETO, CORREO, CARNE, FECHA_NACIMIENTO, PROMEDIO, GRADO_NOMBRE, SECCION)  VALUES ( '" + NOMBRE_COMPLETO +"' , '" + CORREO +"'  , '" + CARNE +"' ,  '" + FECHA_NACIMIENTO + "' , '" + PROMEDIO + "' ,'" + GRADO_NOMBRE +"' , '" + SECCION +"' )";
					query = sql.c_str();
					result = mysql_query(connection, query);
					if (result == 0)
					{
					cout << "se ha registrado al alumno\n\n";
					}		 
					else
					{
			   	    cout << "no se ha podido registrar al alumno " << mysql_error(connection) << endl; 
					}
					break;
					
					
					case 2:
					cout << "ingrese el Grado: "<<endl;
					cin.ignore();
					getline(cin, GRADO_NOMBRE);
					cout << "ingrese la seccion: "<<endl;
					getline(cin, SECCION);
					sql = "insert into grado(GRADO_NOMBRE, SECCION)  VALUES ( '" + GRADO_NOMBRE +"' , '" + SECCION +"')";
					query = sql.c_str();
					result = mysql_query(connection, query);
					if (result == 0)
					{
					cout << "se ha registrado el grado\n\n";
					}		
					else
					{
			   	    cout << "no se ha podido registrar el grado " << mysql_error(connection) << endl; 
					}
					break;
					
					
					case 3:
					cout << "ingrese el ID del alumno que desea eliminar\n " <<endl;
					cin.ignore();
					getline(cin, ALUMNO_ID);
					sql = "delete from alumno where ALUMNO_ID = ( '" + ALUMNO_ID +"')";
					query = sql.c_str();
					result = mysql_query(connection, query);
					if (result == 0)
					{
					cout << "se ha eliminado al alumno\n\n";
					}		
					else
					{
			   	    cout << "no se ha podido eliminar al alumno " << mysql_error(connection) << endl; 
					}	
					break;
					
					case 4:
					cout << "ingrese el ID del grado que desea eliminar\n " <<endl;
					cin.ignore();
					getline(cin, GRADO_ID);
					sql = "delete from grado where GRADO_ID = ( '" + GRADO_ID +"')";
					query = sql.c_str();
					result = mysql_query(connection, query);
					if (result == 0)
					{
					cout << "se ha eliminado el grado\n\n";
					}		
					else
					{
			   	    cout << "no se ha podido eliminar el grado " << mysql_error(connection) << endl; 
					}	
					break;
					
					case 5: 
					MYSQL_ROW row;
					MYSQL_RES* data;
					sql = "SELECT * FROM ALUMNO";
					query = sql.c_str();
					result = mysql_query(connection, query);
					if (result == 0)
					{  
						cout << "el listado de alumnos es: \n" <<endl;
						data = mysql_store_result(connection);
						int countColumns = mysql_num_fields(data);
						while(row = mysql_fetch_row(data))
						{
								for (int i = 0; i < countColumns; i++)
								{
									cout << row[i] << "\t";
								}
								cout <<endl;
						}
					}
					break;
					
					case 6: 
					sql = "SELECT * FROM GRADO";
					query = sql.c_str();
					result = mysql_query(connection, query);
					if (result == 0)
					{  
						cout << "el listado de grados es: \n" <<endl;
						data = mysql_store_result(connection);
						int countColumns = mysql_num_fields(data);
						while(row = mysql_fetch_row(data))
						{
								for (int i = 0; i < countColumns; i++)
								{
									cout << row[i] << "\t";
								}
								cout <<endl;
						}
					}
					break;
					
					case 7:
					cout << "ingrese el ID del GRADO que desea  buscar " <<endl;
					cin.ignore();
					getline(cin, GRADO_ID);
					sql = "select GRADO_ID, GRADO_NOMBRE, SECCION from GRADO where GRADO_ID  = ( '" + GRADO_ID +"')";
					query = sql.c_str();
					result = mysql_query(connection, query);
						{  
						cout << "EL GRADO QUE USTED BUSCA ES: " <<endl;
						data = mysql_store_result(connection);
						int countColumns = mysql_num_fields(data);
						while(row = mysql_fetch_row(data))
						{
								for (int i = 0; i < countColumns; i++)
								{
									cout << row[i] << "\t";
								}
								cout <<endl;
						}
					}
					break;
					
					case 8:
					cout << "ingrese el ID del alumno que desea  buscar " <<endl;
					cin.ignore();
					getline(cin, ALUMNO_ID);
					sql = "select ALUMNO_ID, NOMBRE_COMPLETO, CORREO, CARNE, FECHA_NACIMIENTO, PROMEDIO, GRADO_NOMBRE, SECCION from ALUMNO where ALUMNO_ID  = ( '" + ALUMNO_ID +"')";
					query = sql.c_str();
					result = mysql_query(connection, query);
						{  
						cout << "EL ALUMNO QUE USTED BUSCA ES: " <<endl;
						data = mysql_store_result(connection);
						int countColumns = mysql_num_fields(data);
						while(row = mysql_fetch_row(data))
						{
								for (int i = 0; i < countColumns; i++)
								{
									cout << row[i] << "\t";
								}
								cout <<endl;
						}
					}
					break;
						
			    }
			    
			    	
				
							
			 } 
		
			
		}	
		else 
		{
			cout << "no fue posible conectar con la base de datos" << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "no sirve la conexion" << endl; 
	}
	
	return 0;
}


