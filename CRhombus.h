/*! \file Rhombus.h
    \brief Declaration of the class Rhombus
    \author Alessandro Passaggio - Gregorio Bertelli
*/

#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "CShape.h"


/// @class Rhombus
/// @brief to manage an object with the shape of a Rhombus
class Rhombus : public Shape
{
public:

    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    Rhombus();
    Rhombus(float px, float py, float w, float h);
    Rhombus(const Rhombus &r);

    ~Rhombus();
    /// @}

    /// @name OPERATORS
    /// @{
    Rhombus& operator=(const Rhombus &r);
    bool operator==(const Rhombus &r);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const Rhombus &r);
    void Reset();
    /// @}

    /// @name GETTERS
    /// @{
	float Get1Diagonal();
	float Get2Diagonal();
    float GetSide();
    float GetArea();
    float GetPerimeter();
    /// @}

    /// @name DEBUG and SERIALIZATION
    /// @{
    void Dump();
    /// @}
};

#endif