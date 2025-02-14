#include <Functions/FunctionFactory.h>
#include <Functions/FunctionsExternalDictionaries.h>


namespace DB
{

REGISTER_FUNCTION(ExternalDictionaries)
{
    const std::string dict_get_description { R"(
Retrieves values from a dictionary.

Accepts 3 parameters:
-- name of the dictionary;
-- name of the column of the dictionary or tuple of column names;
-- key value - expression returning dictionary key-type value or tuple-type value - depending on the dictionary configuration;

Returned value: value of the dictionary attribute parsed in the {} if key is found, otherwise <null_value> element specified in the dictionary configuration.

Throws an exception if cannot parse the value of the attribute or the value does not match the attribute data type.
)" };

    const std::string dict_get_or_default_description { R"(
Retrieves values from a dictionary.

Accepts 4 parameters:
-- name of the dictionary;
-- name of the column of the dictionary or tuple of column names;
-- key value - expression returning dictionary key-type value or tuple-type value - depending on the dictionary configuration;
-- default values returned if the dictionary does not contain a row with the key value;

Returned value: value of the dictionary attribute parsed in the {} if key is found, otherwise default value.

Throws an exception if cannot parse the value of the attribute or the value does not match the attribute data type.
)" };

    const std::string dict_get_or_null_description { R"(
Retrieves values from a dictionary.

Accepts 3 parameters:
-- name of the dictionary;
-- name of the column of the dictionary or tuple of column names;
-- key value - expression returning dictionary key-type value or tuple-type value - depending on the dictionary configuration;

Returned value: value of the dictionary attribute parsed in the attribute’s data type if key is found, otherwise NULL.

Throws an exception if cannot parse the value of the attribute or the value does not match the attribute data type.
)" };

    factory.registerFunction<FunctionDictGetNoType<DictionaryGetFunctionType::get>>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "attribute’s data type") });
    factory.registerFunction<FunctionDictGetNoType<DictionaryGetFunctionType::getOrDefault>>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "attribute’s data type") });
    factory.registerFunction<FunctionDictGetOrNull>(Documentation{ dict_get_or_null_description });

    factory.registerFunction<FunctionDictGetUInt8>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "UInt8") });
    factory.registerFunction<FunctionDictGetUInt16>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "UInt16") });
    factory.registerFunction<FunctionDictGetUInt32>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "UInt32") });
    factory.registerFunction<FunctionDictGetUInt64>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "UInt64") });
    factory.registerFunction<FunctionDictGetInt8>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "Int8") });
    factory.registerFunction<FunctionDictGetInt16>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "Int16") });
    factory.registerFunction<FunctionDictGetInt32>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "Int32") });
    factory.registerFunction<FunctionDictGetInt64>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "Int64") });
    factory.registerFunction<FunctionDictGetFloat32>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "Float32") });
    factory.registerFunction<FunctionDictGetFloat64>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "Float64") });
    factory.registerFunction<FunctionDictGetDate>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "Date") });
    factory.registerFunction<FunctionDictGetDateTime>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "DateTime") });
    factory.registerFunction<FunctionDictGetUUID>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "UUID") });
    factory.registerFunction<FunctionDictGetIPv4>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "IPv4") });
    factory.registerFunction<FunctionDictGetIPv6>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "IPv6") });
    factory.registerFunction<FunctionDictGetString>(Documentation{ fmt::format(fmt::runtime(dict_get_description), "String") });

    factory.registerFunction<FunctionDictGetUInt8OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "UInt8") });
    factory.registerFunction<FunctionDictGetUInt16OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "UInt16") });
    factory.registerFunction<FunctionDictGetUInt32OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "UInt32") });
    factory.registerFunction<FunctionDictGetUInt64OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "UInt64") });
    factory.registerFunction<FunctionDictGetInt8OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "Int8") });
    factory.registerFunction<FunctionDictGetInt16OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "Int16") });
    factory.registerFunction<FunctionDictGetInt32OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "Int32") });
    factory.registerFunction<FunctionDictGetInt64OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "Int64") });
    factory.registerFunction<FunctionDictGetFloat32OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "Float32") });
    factory.registerFunction<FunctionDictGetFloat64OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "Float64") });
    factory.registerFunction<FunctionDictGetDateOrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "Date") });
    factory.registerFunction<FunctionDictGetDateTimeOrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "DateTime") });
    factory.registerFunction<FunctionDictGetUUIDOrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "UUID") });
    factory.registerFunction<FunctionDictGetIPv4OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "IPv4") });
    factory.registerFunction<FunctionDictGetIPv6OrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "IPv6") });
    factory.registerFunction<FunctionDictGetStringOrDefault>(Documentation{ fmt::format(fmt::runtime(dict_get_or_default_description), "String") });

    factory.registerFunction<FunctionDictHas>(Documentation{ R"(
Checks whether a key is present in a dictionary.
Accepts 2 parameters: name of the dictionary, key value - expression returning dictionary key-type value or tuple-type value - depending on the dictionary configuration.
Returned value: 0 if there is no key, 1 if there is a key, type of UInt8
)"});

    factory.registerFunction<FunctionDictGetHierarchy>(Documentation{ R"(
Creates an array, containing all the parents of a key in the hierarchical dictionary.
Accepts 2 parameters: name of the dictionary, key value - expression returning a UInt64-type value.
Returned value: parents for the key, type of Array(UInt64)
)"});

    factory.registerFunction<FunctionDictIsIn>(Documentation{ R"(
Checks the ancestor of a key through the whole hierarchical chain in the dictionary.
Accepts 3 parameters: name of the dictionary, key to be checked - expression returning a UInt64-type value, alleged ancestor of the key - expression returning a UInt64-type.
Returned value: 0 if key is not a child of the ancestor, 1 if key is a child of the ancestor or if key is the ancestor, type of UInt8
)"});

    factory.registerFunction<FunctionDictGetChildrenOverloadResolver>(Documentation{ R"(
Returns first-level children as an array of indexes. It is the inverse transformation for dictGetHierarchy.
Accepts 2 parameters: name of the dictionary, key value - expression returning a UInt64-type value.
Returned value: first-level descendants for the key, type of Array(UInt64)
)"});

    factory.registerFunction<FunctionDictGetDescendantsOverloadResolver>(Documentation{ R"(
Returns all descendants as if dictGetChildren function was applied level times recursively.
Accepts 3 parameters: name of the dictionary, key value - expression returning a UInt64-type value, level — hierarchy level - If level = 0 returns all descendants to the end - UInt8
Returned value: descendants for the key, type of Array(UInt64)
)"});
}

}
