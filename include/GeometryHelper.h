/*

    Geometry Helper Lib

    Copyright 2018 Università della Campania Luigi Vanvitelli

    Author: Marco Costanzo <marco.costanzo@unicampania.it>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef GEOMETRY_HELPER_H
#define GEOMETRY_HELPER_H

#include "TooN/TooN.h"
#include "TooN/SVD.h"

#define GEOMETRY_HELPER_EPSILON 1.0E-5

/*
norm(M) is the norm of the Matrix M computed as the 
higer singular value
*/
double norm(const TooN::Matrix<3> &M);

/*
abs(V) return the vector composed by the absolute values of 
the elements of V
*/
TooN::Vector<> abs(const TooN::Vector<> &v);

/*
max(V) return the maximun element of V
*/
double max(const TooN::Vector<> &v );

/*
min(V) return the minimum element of V
*/
double min(const TooN::Vector<> &v );

/*
sum(V) is the sum of all the elements of a V
*/
double sum(const TooN::Vector<> &v);

/*
rotx(angle) is the SO(3) matrix transformation that rotates
a point around the x-axis for an angle
*/
TooN::Matrix<3,3> rotx( double angle );
/*
roty(angle) is the SO(3) matrix transformation that rotates
a point around the y-axis for an angle
*/
TooN::Matrix<3,3> roty( double angle );
/*
rotz(angle) is the SO(3) matrix transformation that rotates
a point around the z-axis for an angle
*/
TooN::Matrix<3,3> rotz( double angle );

/*
SIGN   Signum function.
   sign(n, zero_out) returns 1 if n
   is greater than zero, zero_out if it equals zero and -1 if it is
   less than zero.
*/
double sign( double n, int zero_out );
/*
SIGN   Signum function.
   sign(n) returns 1 if n
   is greater than zero, 0 if it equals zero and -1 if it is
   less than zero.
*/
double sign( double n );

/*
index_max( vector ) return the index (0-based) of 
the first occurrence of the greather element in the vector
*/
int index_max( const TooN::Vector<>& v );

/*
    Compute pinv as Damped Least Square (DLS)
*/
TooN::Matrix<> pinv_DLS( const TooN::Matrix<>& M, double damping);

/*
    Compute a Projector in the null space of M
*/
TooN::Matrix<> nullSpaceProj( const TooN::Matrix<>& M , const TooN::Matrix<>& M_pinv );

TooN::Matrix<> nullSpaceProj( const TooN::Matrix<>& M, double condition_number = 20.0 );

/*
    Compute the derivate of a poly
    coeff = [a_n a_n_1 a_n_2 ... a_0]
    p = a_n*x^n + a_n_1*x^n_1 + ... + a_1*x + a_0  
*/
TooN::Vector<> polydiff( const TooN::Vector<>& coeff );

/*
    Evaluate the poly in the point x
    coeff = [a_n a_n_1 a_n_2 ... a_0]
    p = a_n*x^n + a_n_1*x^n_1 + ... + a_1*x + a_0  
*/
double polyval( const TooN::Vector<>& coeff , double x );

#endif