//
// Created by magol on 05/12/2023.
//

#ifndef PARTE2_VARIANT_H
#define PARTE2_VARIANT_H

#endif //PARTE2_VARIANT_H

#include <iostream>
#include <variant>

class Variant {
public:
    // Constructores
    Variant() : data(0) {}
    Variant(int intValue) : data(intValue) {}
    Variant(float floatValue) : data(floatValue) {}
    Variant(const std::string& stringValue) : data(stringValue) {}
    Variant(bool boolValue) : data(boolValue) {}

    // Obtener el valor como int
    int getInt() const {
        return std::get<int>(data);
    }

    // Obtener el valor como float
    float getFloat() const {
        return std::get<float>(data);
    }

    // Obtener el valor como string
    std::string getString() const {
        return std::get<std::string>(data);
    }

private:
    std::variant<int, float, std::string> data;
};