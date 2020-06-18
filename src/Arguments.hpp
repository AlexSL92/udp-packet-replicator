#pragma once

#include <cstdint>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>


/**
*   @brief Manager of the main arguments
*/
class Arguments {

public:

    /**
    *   @brief Construct a new Arguments object
    *   
    *   @param args Vector of arguments
    */
    Arguments(std::vector<std::string> const& args);

    /**
    *   @brief Check if a certain argument exists in the map
    *   
    *   @param key Argument to search
    *   @return true Argument found
    *   @return false Argument missing
    */
    bool CheckArgument(std::string const& key) const;

    /**
    *   @brief Get the Argument Specifier value
    *   
    *   @tparam T Convert value to this type
    *   @param key Name of the argument
    *   @return T Converted value
    */
    template<typename T>
    T GetArgumentSpecifier(std::string const& key) const {
        if(args_.find(key) == args_.end()) {
            throw std::runtime_error("Required argument '-" + key + "' not specified");
        }
        std::istringstream ss{ args_.at(key) };
        T value;
        ss >> value;
        return value;
    }

    /**
    *   @brief Overload of << ostream operator
    *   
    *   @param out Stream object
    *   @param c Arguments class
    *   @return std::ostream& serialized class
    */
    friend std::ostream & operator<<(std::ostream& out, Arguments const& c);

private:

    std::unordered_map<std::string, std::string> args_; //!< Map of arguments

    /**
    *   @brief Build private map of the class
    *   
    *   @param args Vector of arguments
    */
    void BuildMap(std::vector<std::string> const& args);

    /**
    *   @brief Get the argument ID
    *   
    *   @param arg Argument
    *   @return std::string ID of the argument 
    */
    std::string GetArgumentID(std::string const& arg) const;

    /**
    *   @brief Check if the argument has the correct format
    *   
    *   @param arg Argument to be checked
    *   @return true Argument with a valid format
    *   @return false Argument with an invalid format
    */
    bool CheckValidArgument(std::string const& arg) const;

    /**
    *   @brief Check if the argument does not need an specifier
    *   
    *   @param args Vector of arguments
    *   @param pos Position of the argument to check
    *   @return true Simple argument
    *   @return false Complex argument
    */
    bool CheckSimpleArgument(std::vector<std::string> const& args, std::size_t pos) const;

};
