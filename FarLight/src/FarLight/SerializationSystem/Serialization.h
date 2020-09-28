#pragma once

// serialization input/output streams
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

// polymorphis
#include <boost/serialization/base_object.hpp>

// std types
#include <boost/serialization/array.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <boost/serialization/set.hpp>

// non-standat types
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_serialize.hpp>

#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/nvp.hpp>

#define FL_SERIALIZE_DATA(OFSTREAM, DATA) boost::archive::xml_oarchive oa(OFSTREAM);\
                                          oa << FL_SERIALIZE(DATA)

#define FL_DESERIALIZE_DATA(IFSTREAM, DATA) boost::archive::xml_iarchive ia(IFSTREAM);\
                                            ia >> FL_SERIALIZE(DATA)

#define FL_SERIALIZE_DATA_NAMED(OFSTREAM, NAME, DATA) boost::archive::xml_oarchive oa(OFSTREAM);\
                                                      oa << FL_SERIALIZE_NAMED(NAME, DATA)

#define FL_DESERIALIZE_DATA_NAMED(IFSTREAM, NAME, DATA) boost::archive::xml_iarchive ia(IFSTREAM);\
                                                        ia >> FL_SERIALIZE_NAMED(NAME, DATA)


#define FL_REGISTER_SERIALIZABLE friend class boost::serialization::access;\
                                 BOOST_SERIALIZATION_SPLIT_MEMBER()

#define FL_REGISTER_CLASS_VERSION(CLASS, VERSION) BOOST_CLASS_VERSION(CLASS, VERSION)

#define FL_SERIALIZE(FIELD)             BOOST_SERIALIZATION_NVP(FIELD)
#define FL_SERIALIZE_NAMED(NAME, FIELD) boost::serialization::make_nvp(NAME, FIELD)

#define FL_SERIALIZE_DERIVED(BASE_CLASS) BOOST_SERIALIZATION_BASE_OBJECT_NVP(BASE_CLASS)

namespace FarLight
{
    class Serializer
    {
    public:
        template<typename T>
        static bool Serialize(T& obj, const std::string& filePath) noexcept
        {
            FL_PROFILE_FUNCTION();

            bool result = true;
            try
            {
                std::ofstream fs(filePath);
                FL_SERIALIZE_DATA(fs, obj);
            }
            catch (const std::exception& e)
            {
                result = false;
                FL_CORE_ERROR("An error occurred while attempting to serialize an object to disk.\nPath: {0}\nError: {1}", filePath, e.what());
            }
            return result;
        }

        template<typename T>
        static T Deserialize(const std::string& filePath) noexcept
        {
            FL_PROFILE_FUNCTION();

            T data;
            try
            {
                std::ifstream fs(filePath);
                FL_DESERIALIZE_DATA(fs, data);
            }
            catch (std::exception& e)
            {
                FL_CORE_ERROR("An error occurred while attempting to deserialize an object from disk.\nPath: {0}\nError: {1}", filePath, e.what());
            }
            return data;
        }
    };
}
