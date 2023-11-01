#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Gamepad
{
public:
    Gamepad();
    ~Gamepad();

    void read_data();
    float get_inputLX() const;
    float get_inputRY() const;
    bool get_inputL1() const;

private:
    PyObject *pGModule, *pGClass, *pGInstance;
    PyObject *pInput, *pInputL, *pInputR, *pInputLX, *pInputRY, *pInputL1;
    float gamepad_inputLX, gamepad_inputRY;
    bool gamepad_inputL1;
};