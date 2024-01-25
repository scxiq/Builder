#include <iostream>
#include <string>

// Клас продукту, який будується
class Product {
public:
    void setPartA(const std::string& partA) {
        partA_ = partA;
    }

    void setPartB(const std::string& partB) {
        partB_ = partB;
    }

    void setPartC(const std::string& partC) {
        partC_ = partC;
    }

    void show() const {
        std::cout << "Product Parts: " << partA_ << ", " << partB_ << ", " << partC_ << std::endl;
    }

private:
    std::string partA_;
    std::string partB_;
    std::string partC_;
};

// Абстрактний клас будівельника
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product getResult() const = 0;
};

// Конкретний будівельник
class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder() : product_(new Product()) {}

    void buildPartA() override {
        product_->setPartA("Part A");
    }

    void buildPartB() override {
        product_->setPartB("Part B");
    }

    void buildPartC() override {
        product_->setPartC("Part C");
    }

    Product getResult() const override {
        return *product_;
    }

private:
    Product* product_;
};

// Директор, який визначає порядок будівництва
class Director {
public:
    Director(Builder* builder) : builder_(builder) {}

    void construct() {
        builder_->buildPartA();
        builder_->buildPartB();
        builder_->buildPartC();
    }

private:
    Builder* builder_;
};

int main() {
    // Використання паттерна "Будівельник"
    ConcreteBuilder builder;
    Director director(&builder);

    director.construct();
    Product result = builder.getResult();

    result.show();

    return 0;
}
