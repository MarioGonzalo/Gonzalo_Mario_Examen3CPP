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

    //Inicio apartado 2
    // Función para insertar una variable en el entorno
    void insertVariable(const string& name, const Variant& value){
        auto insert = symbolTable.insert(pair<string, Variant>(name, value));
        // Manejo de error: la variable ya está definida en el entorno
        if (!insert.second){
            throw runtime_error("Error: variable " + name + " ya definida");
        }
    }
    //Fin apartado 2

    //Inicio apartado 3
    // Función para buscar una variable en el entorno
    Variant lookup(const string& name){
        auto it = symbolTable.find(name);//Busca la variable en la tabla de símbolos
        //Si la encuentra, devuelve el valor de la variable
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            //Si no la encuentra, devuelve un mensaje de error
            throw runtime_error("Error: variable " + name + " no definida");
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
    //Inicio apartado 5
    env.insertVariable("x", Variant(5));
    env.insertVariable("y", Variant(3.14f));
    env.insertVariable("z", Variant("Hola Mundo!"));
    env.lookup("x");
    //Fin apartado 5
    //Inicio apartado 4
    try {
        env.insertVariable("x", Variant(5));
        env.lookup("x");
        env.lookup("y");
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    //Fin apartado 4
    return 0;
}
