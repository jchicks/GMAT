//$Id: ManeuverFrame.hpp 9513 2011-04-30 21:23:06Z djcinsb $
//------------------------------------------------------------------------------
//                              ManeuverFrame
//------------------------------------------------------------------------------
// GMAT: General Mission Analysis Tool
//
// Copyright (c) 2002-2011 United States Government as represented by the
// Administrator of The National Aeronautics and Space Administration.
// All Other Rights Reserved.
//
// Developed jointly by NASA/GSFC and Thinking Systems, Inc. under contract
// number NNG04CC06P
//
// Author: Darrel J. Conway, Thinking Systems, Inc.
// Created: 2003/12/17
//
/**
 * Defines the base class for maneuver reference frames. 
 */
//------------------------------------------------------------------------------


#ifndef ManeuverFrame_hpp
#define ManeuverFrame_hpp


#include "gmatdefs.hpp"
#include "BurnException.hpp"


class GMAT_API ManeuverFrame
{
public:
	ManeuverFrame();
	virtual ~ManeuverFrame();
   ManeuverFrame(const ManeuverFrame& mf);
   ManeuverFrame& operator=(const ManeuverFrame& mf);

   void                SetState(Real *pos, Real *vel = NULL);
   void                CalculateBasis(Real basis[3][3]);
   virtual std::string GetFrameLabel(Integer id);

protected:
   /// Matrix of the basis vectors -- Internal buffer used for efficiency
   Real                basisMatrix[3][3];

   /// Central body for the frame
   std::string         centralBody;
   /// Reference body for the frame
   std::string         referenceBody;
   /// Position vector used to calculate the basis
   Real                *position;
   /// Velocity vector used to calculate the basis
   Real                *velocity;

   /// @todo Determine if basisMatrix can be replaced with an Rmatrix33, and if
   ///       position and velocity can be replaced with Rvector3's

   //---------------------------------------------------------------------------
   //  void CalculateBasis()
   //---------------------------------------------------------------------------
   /**
    * Calculates the principal directions for the maneuver frame.
    *
    * This method calculates the principal directions and stores them in the
    * basisMatrix member.  Derived classes need to implement this method, along
    * with the default methods.
    */
   //---------------------------------------------------------------------------
   virtual void        CalculateBasis() = 0;
};


#endif // ManeuverFrame_hpp
