#include "cCgiccMain.hpp"

int main(int argc, const char** argv, const char** env)
{
    cCgiccMain cgi;
    int err = cgi.Run(argc, argv, env);
    return err;
}

