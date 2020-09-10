#pragma once

#include "FarLight/SerializationSystem/SerializationCore.h"

#include <glm/glm.hpp>

namespace FarLight
{
    class Serializator
    {
    public:
        Serializator(const Serializator&) = delete;
        Serializator(Serializator&&) = delete;
        Serializator& operator=(const Serializator&) = delete;
        Serializator& operator=(Serializator&&) = delete;

        static Serializator& GetInstance() noexcept
        {
            static Serializator s_Instance;
            return s_Instance;
        }

        // BVecX Load and Save
        template<class Archive>
        void Load(Archive& archive, glm::bvec1& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::bvec2& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::bvec3& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::bvec4& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        template<class Archive>
        void Save(Archive& archive, glm::bvec1 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::bvec2 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::bvec3 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::bvec4 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        // glm::ivecX Load and Save
        template<class Archive>
        void Load(Archive& archive, glm::ivec1& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::ivec2& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::ivec3& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::ivec4& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        template<class Archive>
        void Save(Archive& archive, glm::ivec1 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::ivec2 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::ivec3 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::ivec4 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        // glm::uvecX Load and Save
        template<class Archive>
        void Load(Archive& archive, glm::uvec1& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::uvec2& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::uvec3& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::uvec4& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        template<class Archive>
        void Save(Archive& archive, glm::uvec1 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::uvec2 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::uvec3 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::uvec4 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        // glm::vecX Load and Save
        template<class Archive>
        void Load(Archive& archive, glm::vec1& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::vec2& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::vec3& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::vec4& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        template<class Archive>
        void Save(Archive& archive, glm::vec1 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::vec2 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::vec3 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::vec4 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        // glm::dvecX Load and Save
        template<class Archive>
        void Load(Archive& archive, glm::dvec1& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::dvec2& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::dvec3& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::dvec4& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        template<class Archive>
        void Save(Archive& archive, glm::dvec1 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::dvec2 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::dvec3 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::dvec4 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }


        // glm::imatX Load and Save
        template<class Archive>
        void Load(Archive& archive, glm::imat2x2& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::imat3x3& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_10", m[3]),
                FL_SERIALIZE_NAMED("m_11", m[4]),
                FL_SERIALIZE_NAMED("m_12", m[5]),
                FL_SERIALIZE_NAMED("m_20", m[6]),
                FL_SERIALIZE_NAMED("m_21", m[7]),
                FL_SERIALIZE_NAMED("m_22", m[8])
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::imat4x4& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_03", m[3]),
                FL_SERIALIZE_NAMED("m_10", m[4]),
                FL_SERIALIZE_NAMED("m_11", m[5]),
                FL_SERIALIZE_NAMED("m_12", m[6]),
                FL_SERIALIZE_NAMED("m_13", m[7]),
                FL_SERIALIZE_NAMED("m_20", m[8]),
                FL_SERIALIZE_NAMED("m_21", m[9]),
                FL_SERIALIZE_NAMED("m_22", m[10]),
                FL_SERIALIZE_NAMED("m_23", m[11]),
                FL_SERIALIZE_NAMED("m_30", m[12]),
                FL_SERIALIZE_NAMED("m_31", m[13]),
                FL_SERIALIZE_NAMED("m_32", m[14]),
                FL_SERIALIZE_NAMED("m_33", m[15])
            );
        }

        template<class Archive>
        void Save(Archive& archive, glm::imat2x2 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::imat3x3 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_10", m[3]),
                FL_SERIALIZE_NAMED("m_11", m[4]),
                FL_SERIALIZE_NAMED("m_12", m[5]),
                FL_SERIALIZE_NAMED("m_20", m[6]),
                FL_SERIALIZE_NAMED("m_21", m[7]),
                FL_SERIALIZE_NAMED("m_22", m[8])
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::imat4x4 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_03", m[3]),
                FL_SERIALIZE_NAMED("m_10", m[4]),
                FL_SERIALIZE_NAMED("m_11", m[5]),
                FL_SERIALIZE_NAMED("m_12", m[6]),
                FL_SERIALIZE_NAMED("m_13", m[7]),
                FL_SERIALIZE_NAMED("m_20", m[8]),
                FL_SERIALIZE_NAMED("m_21", m[9]),
                FL_SERIALIZE_NAMED("m_22", m[10]),
                FL_SERIALIZE_NAMED("m_23", m[11]),
                FL_SERIALIZE_NAMED("m_30", m[12]),
                FL_SERIALIZE_NAMED("m_31", m[13]),
                FL_SERIALIZE_NAMED("m_32", m[14]),
                FL_SERIALIZE_NAMED("m_33", m[15])
            );
        }

        // glm::umatX Load and Save
        template<class Archive>
        void Load(Archive& archive, glm::umat2x2& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::umat3x3& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_10", m[3]),
                FL_SERIALIZE_NAMED("m_11", m[4]),
                FL_SERIALIZE_NAMED("m_12", m[5]),
                FL_SERIALIZE_NAMED("m_20", m[6]),
                FL_SERIALIZE_NAMED("m_21", m[7]),
                FL_SERIALIZE_NAMED("m_22", m[8])
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::umat4x4& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_03", m[3]),
                FL_SERIALIZE_NAMED("m_10", m[4]),
                FL_SERIALIZE_NAMED("m_11", m[5]),
                FL_SERIALIZE_NAMED("m_12", m[6]),
                FL_SERIALIZE_NAMED("m_13", m[7]),
                FL_SERIALIZE_NAMED("m_20", m[8]),
                FL_SERIALIZE_NAMED("m_21", m[9]),
                FL_SERIALIZE_NAMED("m_22", m[10]),
                FL_SERIALIZE_NAMED("m_23", m[11]),
                FL_SERIALIZE_NAMED("m_30", m[12]),
                FL_SERIALIZE_NAMED("m_31", m[13]),
                FL_SERIALIZE_NAMED("m_32", m[14]),
                FL_SERIALIZE_NAMED("m_33", m[15])
            );
        }

        template<class Archive>
        void Save(Archive& archive, glm::umat2x2 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::umat3x3 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_10", m[3]),
                FL_SERIALIZE_NAMED("m_11", m[4]),
                FL_SERIALIZE_NAMED("m_12", m[5]),
                FL_SERIALIZE_NAMED("m_20", m[6]),
                FL_SERIALIZE_NAMED("m_21", m[7]),
                FL_SERIALIZE_NAMED("m_22", m[8])
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::umat4x4 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_03", m[3]),
                FL_SERIALIZE_NAMED("m_10", m[4]),
                FL_SERIALIZE_NAMED("m_11", m[5]),
                FL_SERIALIZE_NAMED("m_12", m[6]),
                FL_SERIALIZE_NAMED("m_13", m[7]),
                FL_SERIALIZE_NAMED("m_20", m[8]),
                FL_SERIALIZE_NAMED("m_21", m[9]),
                FL_SERIALIZE_NAMED("m_22", m[10]),
                FL_SERIALIZE_NAMED("m_23", m[11]),
                FL_SERIALIZE_NAMED("m_30", m[12]),
                FL_SERIALIZE_NAMED("m_31", m[13]),
                FL_SERIALIZE_NAMED("m_32", m[14]),
                FL_SERIALIZE_NAMED("m_33", m[15])
            );
        }

        // glm::matX Load and Save
        template<class Archive>
        void Load(Archive& archive, glm::mat2& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::mat3& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_10", m[3]),
                FL_SERIALIZE_NAMED("m_11", m[4]),
                FL_SERIALIZE_NAMED("m_12", m[5]),
                FL_SERIALIZE_NAMED("m_20", m[6]),
                FL_SERIALIZE_NAMED("m_21", m[7]),
                FL_SERIALIZE_NAMED("m_22", m[8])
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::mat4& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_03", m[3]),
                FL_SERIALIZE_NAMED("m_10", m[4]),
                FL_SERIALIZE_NAMED("m_11", m[5]),
                FL_SERIALIZE_NAMED("m_12", m[6]),
                FL_SERIALIZE_NAMED("m_13", m[7]),
                FL_SERIALIZE_NAMED("m_20", m[8]),
                FL_SERIALIZE_NAMED("m_21", m[9]),
                FL_SERIALIZE_NAMED("m_22", m[10]),
                FL_SERIALIZE_NAMED("m_23", m[11]),
                FL_SERIALIZE_NAMED("m_30", m[12]),
                FL_SERIALIZE_NAMED("m_31", m[13]),
                FL_SERIALIZE_NAMED("m_32", m[14]),
                FL_SERIALIZE_NAMED("m_33", m[15])
            );
        }

        template<class Archive>
        void Save(Archive& archive, glm::mat2 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::mat3 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_10", m[3]),
                FL_SERIALIZE_NAMED("m_11", m[4]),
                FL_SERIALIZE_NAMED("m_12", m[5]),
                FL_SERIALIZE_NAMED("m_20", m[6]),
                FL_SERIALIZE_NAMED("m_21", m[7]),
                FL_SERIALIZE_NAMED("m_22", m[8])
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::mat4 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_03", m[3]),
                FL_SERIALIZE_NAMED("m_10", m[4]),
                FL_SERIALIZE_NAMED("m_11", m[5]),
                FL_SERIALIZE_NAMED("m_12", m[6]),
                FL_SERIALIZE_NAMED("m_13", m[7]),
                FL_SERIALIZE_NAMED("m_20", m[8]),
                FL_SERIALIZE_NAMED("m_21", m[9]),
                FL_SERIALIZE_NAMED("m_22", m[10]),
                FL_SERIALIZE_NAMED("m_23", m[11]),
                FL_SERIALIZE_NAMED("m_30", m[12]),
                FL_SERIALIZE_NAMED("m_31", m[13]),
                FL_SERIALIZE_NAMED("m_32", m[14]),
                FL_SERIALIZE_NAMED("m_33", m[15])
            );
        }

        // glm::dmatX Load and Save
        template<class Archive>
        void Load(Archive& archive, glm::dmat2& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::dmat3& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_10", m[3]),
                FL_SERIALIZE_NAMED("m_11", m[4]),
                FL_SERIALIZE_NAMED("m_12", m[5]),
                FL_SERIALIZE_NAMED("m_20", m[6]),
                FL_SERIALIZE_NAMED("m_21", m[7]),
                FL_SERIALIZE_NAMED("m_22", m[8])
            );
        }
        template<class Archive>
        void Load(Archive& archive, glm::dmat4& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_03", m[3]),
                FL_SERIALIZE_NAMED("m_10", m[4]),
                FL_SERIALIZE_NAMED("m_11", m[5]),
                FL_SERIALIZE_NAMED("m_12", m[6]),
                FL_SERIALIZE_NAMED("m_13", m[7]),
                FL_SERIALIZE_NAMED("m_20", m[8]),
                FL_SERIALIZE_NAMED("m_21", m[9]),
                FL_SERIALIZE_NAMED("m_22", m[10]),
                FL_SERIALIZE_NAMED("m_23", m[11]),
                FL_SERIALIZE_NAMED("m_30", m[12]),
                FL_SERIALIZE_NAMED("m_31", m[13]),
                FL_SERIALIZE_NAMED("m_32", m[14]),
                FL_SERIALIZE_NAMED("m_33", m[15])
            );
        }

        template<class Archive>
        void Save(Archive& archive, glm::dmat2 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::dmat3 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_10", m[3]),
                FL_SERIALIZE_NAMED("m_11", m[4]),
                FL_SERIALIZE_NAMED("m_12", m[5]),
                FL_SERIALIZE_NAMED("m_20", m[6]),
                FL_SERIALIZE_NAMED("m_21", m[7]),
                FL_SERIALIZE_NAMED("m_22", m[8])
            );
        }
        template<class Archive>
        void Save(Archive& archive, glm::dmat4 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_02", m[2]),
                FL_SERIALIZE_NAMED("m_03", m[3]),
                FL_SERIALIZE_NAMED("m_10", m[4]),
                FL_SERIALIZE_NAMED("m_11", m[5]),
                FL_SERIALIZE_NAMED("m_12", m[6]),
                FL_SERIALIZE_NAMED("m_13", m[7]),
                FL_SERIALIZE_NAMED("m_20", m[8]),
                FL_SERIALIZE_NAMED("m_21", m[9]),
                FL_SERIALIZE_NAMED("m_22", m[10]),
                FL_SERIALIZE_NAMED("m_23", m[11]),
                FL_SERIALIZE_NAMED("m_30", m[12]),
                FL_SERIALIZE_NAMED("m_31", m[13]),
                FL_SERIALIZE_NAMED("m_32", m[14]),
                FL_SERIALIZE_NAMED("m_33", m[15])
            );
        }

    private:
        explicit Serializator() noexcept = default;
    };
}
