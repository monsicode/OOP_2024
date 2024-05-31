#include "Conteiner.h"


CollectionFunctions::CollectionFunctions() : capacity(0), size(0) {}

CollectionFunctions::CollectionFunctions(const CollectionFunctions& other) {
    copyFrom(other);
}

CollectionFunctions::CollectionFunctions(CollectionFunctions&& other) noexcept {
    moveFrom(std::move(other));
}

CollectionFunctions& CollectionFunctions::operator=(const CollectionFunctions& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

CollectionFunctions& CollectionFunctions::operator=(CollectionFunctions&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}


CollectionFunctions::~CollectionFunctions() noexcept {
    free();
}


void CollectionFunctions::addFunction(const polymorphic_ptr<PartialFunction>& func) {
    functions.pushBack(func);
    ++size;
}

const PartialFunction* CollectionFunctions::operator[](unsigned index) const {
    if (index < size) {
        return functions[index].get();
    } else {
        return nullptr;
    }
}

unsigned CollectionFunctions::getSize() const {
    return size;
}

bool CollectionFunctions::isDefined(uint32_t number) const {
    for (size_t i = 0; i < size; ++i) {
        if (!functions[i]->isDefined(number)) {
            return false;
        }
    }
    return true;
}

uint32_t CollectionFunctions::calculate(uint32_t number) const {
    uint32_t sum = 0;
    unsigned count = 0;
    for (size_t i = 0; i < size; ++i) {
        const PartialFunction* func = functions[i].get();
        if (func->isDefined(number)) {
            sum += func->calculate(number);
            ++count;
        }
    }
    return count > 0 ? sum / count : 0;
}


void CollectionFunctions::free() {
    functions.clear();
    capacity = 0;
    size = 0;
}

void CollectionFunctions::copyFrom(const CollectionFunctions& other) {
    functions.clear();

    for (size_t i = 0; i < other.size; ++i) {
        addFunction(other.functions[i]);
    }

    capacity = other.capacity;
    size = other.size;
}


void CollectionFunctions::moveFrom(CollectionFunctions&& other) {
    functions = std::move(other.functions);
    capacity = other.capacity;
    size = other.size;
    other.free();
}