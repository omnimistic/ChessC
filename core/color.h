#pragma once
#include <string>

namespace Color {

    inline const std::string Reset = "\033[0m";
    inline const std::string Bold  = "\033[1m";
    
    inline const std::string BlackText = "\033[30m";
    inline const std::string WhiteText = "\033[37m";
    
    inline const std::string Black    = "\033[40m";
    inline const std::string Red      = "\033[41m";
    inline const std::string Green    = "\033[42m";
    inline const std::string Yellow   = "\033[43m";
    inline const std::string Blue     = "\033[44m";
    inline const std::string Cyan     = "\033[46m";
    inline const std::string White    = "\033[47m";
    inline const std::string DarkGray = "\033[100m";
    
    inline const std::string Magenta = "\033[45m";
}