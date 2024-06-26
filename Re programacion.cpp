#include <iostream>
#include <string>

using namespace std;
// se usa para ahorrarnos trabajo 

void agregar_empleado(string nombres[], int cedulas[], int tipos_empleados[], double precios_x_hora[], int horas_trabajadas[], int& count);
void consultar_empleado(const string nombres[], const int cedulas[], const int tipos_empleados[], const double precios_x_hora[], const int horas_trabajadas[], int count);
void modificar_empleado(string nombres[], int cedulas[], int tipos_empleados[], double precios_x_hora[], int horas_trabajadas[], int count);
void borrar_empleado(string nombres[], int cedulas[], int tipos_empleados[], double precios_x_hora[], int horas_trabajadas[], int& count);

int main() {
    // se crea un maximo de 10 empleados para no alargar la tarea
    const int max_empleados = 10;
    string nombres[max_empleados];
    int cedulas[max_empleados];
    int tipos_empleados[max_empleados];
    double precios_x_hora[max_empleados];
    int horas_trabajadas[max_empleados];
    int count = 0;

    int menu = 0;
    // se crea el while para agregar la cantidad de empleados que el usuario quiera 
    while (menu != 5) {
        cout << "1. Agregar empleado\n2. Consultar empleado\n3. Modificar empleado\n4. Borrar empleado\n5. Salir\n\nDigite su opcion: ";
        cin >> menu;
        switch (menu) {
        case 1:
            agregar_empleado(nombres, cedulas, tipos_empleados, precios_x_hora, horas_trabajadas, count);
            break;
        case 2:
            consultar_empleado(nombres, cedulas, tipos_empleados, precios_x_hora, horas_trabajadas, count);
            break;
        case 3:
            modificar_empleado(nombres, cedulas, tipos_empleados, precios_x_hora, horas_trabajadas, count);
            break;
        case 4:
            borrar_empleado(nombres, cedulas, tipos_empleados, precios_x_hora, horas_trabajadas, count);
            break;
        case 5:
            cout << "Vuelva pronto, Gracias!" << endl;
            break;
        default:
            cout << "Opcion invalida, digite de nuevo\n" << endl;
        }
    }
    return 0;
}

void agregar_empleado(string nombres[], int cedulas[], int tipos_empleados[], double precios_x_hora[], int horas_trabajadas[], int& count) {
    if (count >= 10) {
        cout << "No se pueden meter mas empleados." << endl;
        // si pasa el maximo de empleados tirara el mensaje 
        return;
    }

    string nombre;
    int cedula = 0;
    int tipo_empleado = 0;
    double precio_x_hora = 0;
    int cant_horas = 0;

    cout << "Digite el nombre del empleado: ";
    cin >> nombre;
    cout << "Digite cedula: ";
    cin >> cedula;
    cout << "Digite precio por hora de " << nombre << ": ";
    cin >> precio_x_hora;
    cout << "Digite la cantidad de horas que trabajo " << nombre << ": ";
    cin >> cant_horas;
    cout << "Digite el tipo de empleado (1: Operario 2: Tecnico 3: Profesional): ";
    cin >> tipo_empleado;

    nombres[count] = nombre;
    cedulas[count] = cedula;
    tipos_empleados[count] = tipo_empleado;
    precios_x_hora[count] = precio_x_hora;
    horas_trabajadas[count] = cant_horas;
    count++;
    // se agrega un empleado mas al contador 
    cout << "Empleado agregado correctamente ." << endl << endl;
}
// se traen los datos para poder consultar por el empleado 
void consultar_empleado(const string nombres[], const int cedulas[], const int tipos_empleados[], const double precios_x_hora[], const int horas_trabajadas[], int count) {
    int cedula;
    cout << "Digite la cedula del empleado que desea consultar: ";
    cin >> cedula;

    for (int i = 0; i < count; i++) {
        if (cedulas[i] == cedula) {
            string tipo_empleado_string;
            double salario_ordinario = precios_x_hora[i] * horas_trabajadas[i];
            double aumento = 0;
            if (tipos_empleados[i] == 1) {
                tipo_empleado_string = "Operario";
                aumento = 0.15;
            }
            else if (tipos_empleados[i] == 2) {
                tipo_empleado_string = "Tecnico";
                aumento = 0.10;
            }
            else {
                tipo_empleado_string = "Profesional";
                aumento = 0.05;
                // aumentos depende del tipo de trabajador 
            }
            double salario_bruto = salario_ordinario + (salario_ordinario * aumento);
            double deduccion_caja = salario_bruto * (9.17 / 100);
            double salario_neto = salario_bruto - deduccion_caja;

            cout << "Nombre del empleado (" << tipo_empleado_string << "): " << nombres[i] << endl;
            cout << "Cedula de " << nombres[i] << ": " << cedulas[i] << endl;
            cout << "Precio por hora: " << precios_x_hora[i] << endl;
            cout << "Cantidad de horas trabajadas: " << horas_trabajadas[i] << endl;
            cout << "Salario ordinario de " << nombres[i] << ": " << salario_ordinario << endl;
            cout << "Aumento del empleado: " << aumento * 100 << "%" << endl;
            cout << "Salario bruto: " << salario_bruto << endl;
            cout << "Deduccion CCSS: " << deduccion_caja << endl;
            cout << "Salario neto de " << nombres[i] << ": " << salario_neto << endl << endl;

            return;
        }
    }
    cout << "Empleado no encontrado, digite bien la cedula" << endl << endl;
}			// si la cedula del empleado no se encuentra tirara error 

    // se traen los datos para poder modificar el empleado 
void modificar_empleado(string nombres[], int cedulas[], int tipos_empleados[], double precios_x_hora[], int horas_trabajadas[], int count) {
    int cedula;
    cout << "Digite la cedula del empleado que desea modificar: ";
    cin >> cedula;

    for (int i = 0; i < count; i++) {
        if (cedulas[i] == cedula) {
            string nombre;
            int tipo_empleado = 0;
            double precio_x_hora = 0;
            int cant_horas = 0;

            cout << "Digite el nuevo nombre del empleado (actual: " << nombres[i] << "): ";
            cin >> nombre;
            cout << "Digite la nueva cedula (actual: " << cedulas[i] << "): ";
            cin >> cedulas[i];
            cout << "Digite el nuevo precio por hora de " << nombre << " (actual: " << precios_x_hora[i] << "): ";
            cin >> precio_x_hora;
            cout << "Digite la nueva cantidad de horas que trabajo " << nombre << " (actual: " << horas_trabajadas[i] << "): ";
            cin >> cant_horas;
            cout << "Digite el nuevo tipo de empleado (1: Operario 2: Tecnico 3: Profesional) (actual: " << tipos_empleados[i] << "): ";
            cin >> tipo_empleado;

            nombres[i] = nombre;
            precios_x_hora[i] = precio_x_hora;
            horas_trabajadas[i] = cant_horas;
            tipos_empleados[i] = tipo_empleado;

            cout << "Empleado modificado exitosamente." << endl << endl;
            return;
        }
    }
    cout << "Empleado no encontrado." << endl << endl;
}
// se traen los datos para borrar el emplado 
void borrar_empleado(string nombres[], int cedulas[], int tipos_empleados[], double precios_x_hora[], int horas_trabajadas[], int& count) {
    int cedula;
    cout << "Digite la cedula del empleado que desea borrar: ";
    cin >> cedula;

    for (int i = 0; i < count; i++) {
        if (cedulas[i] == cedula) {
            for (int j = i; j < count - 1; j++) {
                nombres[j] = nombres[j + 1];
                cedulas[j] = cedulas[j + 1];
                tipos_empleados[j] = tipos_empleados[j + 1];
                precios_x_hora[j] = precios_x_hora[j + 1];
                horas_trabajadas[j] = horas_trabajadas[j + 1];
                // se borran los datos 
            }
            count--;
            // se agrega -- para el contador  
            cout << "Empleado borrado exitosamente." << endl << endl;
            return;
        }
    }
    cout << "Empleado no encontrado." << endl << endl;
}