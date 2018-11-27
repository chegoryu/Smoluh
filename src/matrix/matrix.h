#pragma once

#include <cstddef>

template<typename T>
class TMatrix {
public:
    TMatrix() = default;
    virtual ~TMatrix() = default;
    
    virtual size_t GetRows() const = 0;
    virtual size_t GetColumns() const = 0;
    
    virtual T GetValue(size_t row, size_t column) const = 0;
    virtual void SetValue(size_t row, size_t column, T value) = 0;
    
    virtual T& GetCellRef(size_t row, size_t column) = 0;
    virtual const T& GetCellRef(size_t row, size_t column) const = 0;
};
