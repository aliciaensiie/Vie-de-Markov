#if __linux__

#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#include "../SFML-2.5.1/include/SFML/Audio.hpp"

#else   /*I didn't bother adding support for MAC OS*/
# error "Unknown compiler"
#endif