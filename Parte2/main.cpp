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

    // Función para agregar una variable al entorno
    void addVariable(const string& name, const Variant& value) {
        symbolTable[name] = value;
    }

    // Función para obtener el valor de una variable en el entorno
    Variant getVariable(const string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            // Manejo de error: la variable no está definida en el entorno
            return Variant();
        }
    }

private:
    // Tabla de símbolos que asocia nombres de variables con sus valores
    map<string, Variant> symbolTable;
};





int main() {

    return 0;
}
