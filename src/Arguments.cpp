#include "Arguments.hpp"


Arguments::Arguments(std::vector<std::string> const& args) : args_{} {
    BuildMap(args);
}

Arguments::~Arguments() {}

bool Arguments::CheckArgument(std::string const& key) const {
    return args_.find(key) != args_.end();
}

std::ostream & operator<<(std::ostream& out, Arguments const& c) {
    for(auto const& element : c.args_) {
        if(element.second.size()) {
            out << element.first << ":" << element.second << std::endl;
        }
        else {
            out << element.first << std::endl;
        }
    }
    return out;
}

void Arguments::BuildMap(std::vector<std::string> const& args) {
    std::size_t i{ 0 };
    while(i < args.size()) {
        if(CheckValidArgument(args.at(i)) && !CheckSimpleArgument(args, i)) {
            std::string key{ GetArgumentID(args.at(i)) };
            std::string value{ args.at(i + 1) };
            // Add the argument with the correspondig value to the map
            args_.insert(std::make_pair(key, value));
            ++i;
        }
        else if(CheckValidArgument(args.at(i))) {
            std::string key{ GetArgumentID(args.at(i)) };
            // Add the argument with an empty value to the map
            args_.insert(std::make_pair(key, ""));
        }
        i++;
    }
}

std::string Arguments::GetArgumentID(std::string const& arg) const {
    return arg.substr(1, arg.size() - 1);
}

bool Arguments::CheckValidArgument(std::string const& arg) const {
    return (arg.at(0) == '-') && (arg.size() > 1);
}

bool Arguments::CheckSimpleArgument(std::vector<std::string> const& args, std::size_t pos) const {
    auto simple_argument{ true };
    if((pos + 1) < args.size() && (args.at(pos + 1).at(0) != '-')) {
        simple_argument = false;
    }
    return simple_argument;
}
