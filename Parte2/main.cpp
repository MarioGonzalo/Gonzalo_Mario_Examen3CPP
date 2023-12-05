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
            throw runtime_error("Error: variable " + name + " ya definida, no se puede insertar");
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
            throw runtime_error("Error: variable " + name + " no definida, no se puede buscar");
        }
    }
    //Fin apartado 3

    //Inicio apartado 6
    void removeVariable(const string& name){
        auto it = symbolTable.find(name);//Busca la variable en la tabla de símbolos
        //Si se encuentra, se elimina
        if (it != symbolTable.end()) {
            symbolTable.erase(it);
        } else {
            //Si no la encuentra, devuelve un mensaje de error
            throw runtime_error("Error: variable " + name + " no definida, no se puede eliminar");
        }
    }
    void variableExists(const string& name){
        auto it = symbolTable.find(name);//Busca la variable en la tabla de símbolos
        //Si se encuentra, se imprime un mensaje
        if (it != symbolTable.end()) {
            cout << "La variable " << name << " está definida" << endl;
        } else {
            //Si no la encuentra, devuelve un mensaje de error
            cout << "La variable " << name << " no está definida" << endl;
        }
    }



    //Fin apartado 6

private:
    // Tabla de símbolos que asocia nombres de variables con sus valores
    map<string, Variant> symbolTable;
};
// Fin apartado 1




int main() {
    Environment env;

    //Inicio apartado 4
    // Manejo de errores
    //Si se busca una variable que no está definida
    try {
        env.insertVariable("x", Variant(5));
        env.lookup("x");
        env.lookup("y");
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    //Si se busca una variable que no está definida
    try {
        env.removeVariable("x");
        env.lookup("x");
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    //Si se elimina una variable que no está definida
    try {
        env.removeVariable("y");
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    //Si se inserta una variable que ya está definida
    try {
        env.insertVariable("a", Variant(5));
        env.insertVariable("a", Variant(5));
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    //Fin apartado 4
    //Inicio apartado 5
    env.insertVariable("x", Variant(5));
    env.insertVariable("y", Variant(3.14f));
    env.insertVariable("z", Variant("Hola Mundo!"));
    env.lookup("x");
    env.removeVariable("x");
    env.variableExists("x");
    //Fin apartado 5
    return 0;
}
