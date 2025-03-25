#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);