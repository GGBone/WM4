// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef PHYSICSMODULE_H
#define PHYSICSMODULE_H

#include "Wm4OdeSolver.h"

class PhysicsModule
{
public:
    // construction and destruction
    PhysicsModule ();
    ~PhysicsModule ();

    // initialize the differential equation solver
    void Initialize (double dTime, double dDeltaTime, double dTheta1,
        double dTheta2, double dTheta1Dot, double dTheta2Dot);

    // access the current state
    double GetTime () const;
    double GetDeltaTime () const;
    double GetTheta1 () const;
    double GetTheta1Dot () const;
    double GetTheta2 () const;
    double GetTheta2Dot () const;
    void GetPositions (double& rdX1, double& rdY1, double& rdX2,
        double& rdY2) const;

    // take a single step of the solver
    void Update ();

    // physical constants
    double Gravity;
    double Mass1, Mass2;
    double Length1, Length2;
    double JointX, JointY;

protected:
    // state and auxiliary variables
    double m_dTime, m_dDeltaTime;
    double m_adState[4], m_adAux[4];

    // ODE solver (specific solver assigned in the cpp file)
    Wm4::OdeSolverd* m_pkSolver;
    static void OdeFunction (double dTime, const double* adState,
        void* pvData, double* adFValue);
};

#include "PhysicsModule.inl"

#endif

