#include <map>
#include "Variant.h"
#include <string>

using namespace std; // Se emplea el namespace para no escribir std:: antes de cada función

// Inicio apartado 1
class Environment {
public:
    // Constructor
    Environment() {}

    // Destructor
    ~Environment() {}

    // Función para obtener el valor de una variable en el entorno
    Variant getVariable(const string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            // Manejo de error: la variable no está definida en el entorno
            cerr << "Error: variable " << name << " no definida" << endl;
            return Variant();
        }
    }
    //Inicio apartado 2
    // Función para insertar una variable en el entorno
    void insertVariable(const string& name, const Variant& value){
        auto insert = symbolTable.insert(pair<string, Variant>(name, value));
        // Manejo de error: la variable ya está definida en el entorno
        if (!insert.second){
            cerr << "Error: variable " << name << " ya definida" << endl;
        }
    }
    //Fin apartado 2

    //Inicio apartado 3
    // Función para modificar el valor de una variable en el entorno
    Variant lookup(const string& name){
        auto it = symbolTable.find(name);//Busca la variable en la tabla de símbolos
        //Si la encuentra, devuelve el valor de la variable
        if (it != symbolTable.end()) {
            return it->second;

        } else {
            //Si no la encuentra, devuelve un mensaje de error
            cerr << "Variable " << name << " no definida" << endl;
            return Variant();
        }
    }
    //Fin apartado 3

private:
    // Tabla de símbolos que asocia nombres de variables con sus valores
    map<string, Variant> symbolTable;
};
// Fin apartado 1




int main() {
    Environment env;

    //Ejemplo de uso
    env.insertVariable("x", Variant(5));
    env.insertVariable("y", Variant(3.14f));
    env.insertVariable("z", Variant("Hola mundo"));
    env.lookup("x").getInt();//Devuelve el valor de la variable x
    env.lookup("arbol").getInt();//Devuelve un mensaje de error

    cout << env.getVariable("x").getInt() << endl;
    return 0;
}
