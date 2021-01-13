//
// Created by brayden on 1/11/21.
//

#ifndef NVIDIA_OOP_EXAMPLE_H
#define NVIDIA_OOP_EXAMPLE_H


class Quote {
public:
    std::string isbn() const;
    virtual double net_price(std::size_t n) const;
};




#endif //NVIDIA_OOP_EXAMPLE_H
