#pragma once

#include "matrix.h"

template<typename T>
class TArrayMatrix: public TMatrix<T> {
public:
    TArrayMatrix(size_t rows = 0, size_t columns = 0) : Rows_(rows), Columns_(columns) {
        Data_ = new T[Rows_ * Columns_];
    }
    
    ~TArrayMatrix() {
        delete[] Data_;
    }
    
    T* GetRawData() {
        return Data_;
    }

    const T* GetRawData() const {
        return Data_;
    }
    
    size_t GetRows() const override {
        return Rows_;
    }

    size_t GetColumns() const override {
        return Columns_;
    }

    T GetValue(size_t row, size_t column) const override {
        return Data_[Columns_ * row + column];
    }
    
    void SetValue(size_t row, size_t column, T value) override {
        Data_[Columns_ * row + column] = value;
    }
    
    T* GetCellRef(size_t row, size_t column) {
        return Data_ + Columns_ * row + column;
    }
    
    const T* GetCellRef(size_t row, size_t column) const {
        return Data_ + Columns_ * row + column;
    }

private:
    size_t Rows_;
    size_t Columns_;
    T* Data_;
};
