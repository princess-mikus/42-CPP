#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);