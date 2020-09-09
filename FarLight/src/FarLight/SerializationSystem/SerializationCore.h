#pragma once

#include <cereal\archives\binary.hpp>
#include <cereal\types\memory.hpp>
#include <cereal\types\vector.hpp>
#include <cereal\types\polymorphic.hpp>
#include <cereal\types\base_class.hpp>

#define FL_SERIALIZE(FIELD)             CEREAL_NVP(FIELD)
#define FL_SERIALIZE_NAMED(NAME, FIELD) cereal::make_nvp(NAME, FIELD)
#define FL_SERIALIZE_BASE(CLASS)        SERIALIZE_NAMED(std::string("__base_") + #CLASS, cereal::base_class<CLASS>( this ))

#define FL_REGISTER_SERIALIZED_TYPE(CLASS, VERSION) CEREAL_REGISTER_TYPE(CLASS);\
                                                    CEREAL_CLASS_VERSION(CLASS, VERSION);
