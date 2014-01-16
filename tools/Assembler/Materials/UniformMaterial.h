#pragma once
#include "Material.h"

class UniformMaterial : public Material {
    public:
        /**
         * Material tensor is represented by dim^2 x dim^2 matrix.
         * Its format is dim x dim arrays of dim x dim matrices.
         */
        UniformMaterial(Float density, const MatrixF& material_tensor);

        virtual Float get_material_tensor(
                size_t i, size_t j, size_t k, size_t l) const;

        virtual MatrixF strain_to_stress(const MatrixF& strain) const;

        virtual Float get_density() const {
            return m_density;
        }

    protected:
        UniformMaterial() {}

    protected:
        size_t m_dim;
        Float m_density;
        MatrixF m_material_tensor;
};
