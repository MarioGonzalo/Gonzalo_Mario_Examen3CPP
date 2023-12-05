#include <map>
#include "Variant.h"
#include <string>

using namespace std; // Se emplea el namespace para no escribir std:: antes de cada función


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
        }
    }
    void insertVariable(const string& name, const Variant& value){
        auto insert = symbolTable.insert(pair<string, Variant>(name, value));
        if (!insert.second){
            cerr << "Error: variable " << name << " ya definida" << endl;
        }
    }
private:
    // Tabla de símbolos que asocia nombres de variables con sus valores
    map<string, Variant> symbolTable;
};





int main() {
    Environment env;

    env.insertVariable("x", Variant(5));
    env.insertVariable("y", Variant(3.14f));
    env.insertVariable("z", Variant("Hola mundo"));

    cout << env.getVariable("x").getInt() << endl;
    return 0;
}
