#pragma once

#include "FarLight/MathSystem/Vector.h"
#include "FarLight/MathSystem/Matrix.h"

#include "FarLight/SerializationSystem/SerializationCore.h"

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
        void Load(Archive& archive, BVec1& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Load(Archive& archive, BVec2& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Load(Archive& archive, BVec3& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Load(Archive& archive, BVec4& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        template<class Archive>
        void Save(Archive& archive, BVec1 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Save(Archive& archive, BVec2 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Save(Archive& archive, BVec3 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Save(Archive& archive, BVec4 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        // IVecX Load and Save
        template<class Archive>
        void Load(Archive& archive, IVec1& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Load(Archive& archive, IVec2& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Load(Archive& archive, IVec3& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Load(Archive& archive, IVec4& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        template<class Archive>
        void Save(Archive& archive, IVec1 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Save(Archive& archive, IVec2 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Save(Archive& archive, IVec3 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Save(Archive& archive, IVec4 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        // UVecX Load and Save
        template<class Archive>
        void Load(Archive& archive, FVec1& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Load(Archive& archive, UVec2& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Load(Archive& archive, UVec3& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Load(Archive& archive, UVec4& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        template<class Archive>
        void Save(Archive& archive, UVec1 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Save(Archive& archive, UVec2 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Save(Archive& archive, UVec3 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Save(Archive& archive, UVec4 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        // FVecX Load and Save
        template<class Archive>
        void Load(Archive& archive, FVec1& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Load(Archive& archive, FVec2& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Load(Archive& archive, FVec3& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Load(Archive& archive, FVec4& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        template<class Archive>
        void Save(Archive& archive, FVec1 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Save(Archive& archive, FVec2 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Save(Archive& archive, FVec3 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Save(Archive& archive, FVec4 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        // DVecX Load and Save
        template<class Archive>
        void Load(Archive& archive, DVec1& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Load(Archive& archive, DVec2& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Load(Archive& archive, DVec3& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Load(Archive& archive, DVec4& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }

        template<class Archive>
        void Save(Archive& archive, DVec1 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x)
            );
        }
        template<class Archive>
        void Save(Archive& archive, DVec2 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y)
            );
        }
        template<class Archive>
        void Save(Archive& archive, DVec3 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z)
            );
        }
        template<class Archive>
        void Save(Archive& archive, DVec4 const& v)
        {
            archive(
                FL_SERIALIZE_NAMED("x", v.x),
                FL_SERIALIZE_NAMED("y", v.y),
                FL_SERIALIZE_NAMED("z", v.z),
                FL_SERIALIZE_NAMED("w", v.w)
            );
        }


        // IMatX Load and Save
        template<class Archive>
        void Load(Archive& archive, IMat2& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Load(Archive& archive, IMat3& m)
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
        void Load(Archive& archive, IMat4& m)
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
        void Save(Archive& archive, IMat2 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Save(Archive& archive, IMat3 const& m)
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
        void Save(Archive& archive, IMat4 const& m)
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

        // UMatX Load and Save
        template<class Archive>
        void Load(Archive& archive, UMat2& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Load(Archive& archive, UMat3& m)
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
        void Load(Archive& archive, UMat4& m)
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
        void Save(Archive& archive, UMat2 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Save(Archive& archive, UMat3 const& m)
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
        void Save(Archive& archive, UMat4 const& m)
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

        // FMatX Load and Save
        template<class Archive>
        void Load(Archive& archive, FMat2& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Load(Archive& archive, FMat3& m)
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
        void Load(Archive& archive, FMat4& m)
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
        void Save(Archive& archive, FMat2 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Save(Archive& archive, FMat3 const& m)
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
        void Save(Archive& archive, FMat4 const& m)
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

        // DMatX Load and Save
        template<class Archive>
        void Load(Archive& archive, DMat2& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Load(Archive& archive, DMat3& m)
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
        void Load(Archive& archive, DMat4& m)
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
        void Save(Archive& archive, DMat2 const& m)
        {
            archive(
                FL_SERIALIZE_NAMED("m_00", m[0]),
                FL_SERIALIZE_NAMED("m_01", m[1]),
                FL_SERIALIZE_NAMED("m_10", m[2]),
                FL_SERIALIZE_NAMED("m_11", m[3])
            );
        }
        template<class Archive>
        void Save(Archive& archive, DMat3 const& m)
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
        void Save(Archive& archive, DMat4 const& m)
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
