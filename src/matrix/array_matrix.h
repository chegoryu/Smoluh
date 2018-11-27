#pragma once

#include "matrix.h"

#include <algorithm>
#include <new>

template<typename T>
class TArrayMatrix: public TMatrix<T> {
private:
    void swap(TArrayMatrix& other) {
        std::swap(Rows_, other.Rows_);
        std::swap(Columns_, other.Columns_);
        std::swap(Data_, other.Data_);
    }

public:
    TArrayMatrix(size_t rows = 0, size_t columns = 0) : Rows_(rows), Columns_(columns) {
        if (Rows_ != 0 && Columns_ != 0) {
            Data_ = new T[Rows_ * Columns_];
            std::fill(Data_, Data_ + Rows_ * Columns_, T());
        } else {
            Data_ = nullptr;
        }
    }
    
    TArrayMatrix(const TArrayMatrix& other) {
        new(this) TArrayMatrix(other.Rows_, other.Columns_);
        if (Data_ != nullptr && other.Data_ != nullptr) {
            std::copy(other.Data_, other.Data_ + other.Rows_ * other.Columns_, Data_);
        }
    }
    
    TArrayMatrix& operator=(const TArrayMatrix& other) {
        TArrayMatrix copy(other);
        this->swap(copy);
        return *this;
    }

    ~TArrayMatrix() {
        if (Data_ != nullptr) {
            delete[] Data_;
        }
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
    
    T& GetCellRef(size_t row, size_t column) {
        return Data_[Columns_ * row + column];
    }
    
    const T& GetCellRef(size_t row, size_t column) const {
        return Data_[Columns_ * row + column];
    }

private:
    size_t Rows_;
    size_t Columns_;
    T* Data_;
};
