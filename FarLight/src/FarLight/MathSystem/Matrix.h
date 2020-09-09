#pragma once

#include <glm/glm.hpp>

namespace FarLight
{
    // Integer matrix
    using IMat2 = glm::imat2x2;
    using IMat3 = glm::imat3x3;
    using IMat4 = glm::imat4x4;

    // Unsigned integer matrix
    using UMat2 = glm::umat2x2;
    using UMat3 = glm::umat3x3;
    using UMat4 = glm::umat4x4;

    // Float matrix
    using FMat2 = glm::mat2;
    using FMat3 = glm::mat3;
    using FMat4 = glm::mat4;

    // Double matrix
    using DMat2 = glm::dmat2;
    using DMat3 = glm::dmat3;
    using DMat4 = glm::dmat4;
}
