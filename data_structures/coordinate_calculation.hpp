/*

Copyright (c) 2015, Project OSRM, Dennis Luxen, others
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list
of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef COORDINATE_CALCULATION
#define COORDINATE_CALCULATION

#include <osrm/coordinate.hpp>

#include <iosfwd> //for std::ostream
#include <string>
#include <utility>

struct coordinate_calculation
{
    static double
    ApproximateDistance(const int lat1, const int lon1, const int lat2, const int lon2);

    static double ApproximateDistance(const FixedPointCoordinate &first_coordinate,
                                      const FixedPointCoordinate &second_coordinate);

    static float approx_euclidean_distance(const FixedPointCoordinate &first_coordinate,
                                              const FixedPointCoordinate &second_coordinate);

    static float
    approx_euclidean_distance(const int lat1, const int lon1, const int lat2, const int lon2);

    static float ApproximateSquaredEuclideanDistance(const FixedPointCoordinate &first_coordinate,
                                                     const FixedPointCoordinate &second_coordinate);

    static void lat_or_lon_to_string(const int value, std::string &output);

    static void convertInternalCoordinateToString(const FixedPointCoordinate &coordinate,
                                                  std::string &output);

    static void convertInternalReversedCoordinateToString(const FixedPointCoordinate &coordinate,
                                                          std::string &output);

    static float ComputePerpendicularDistance(const FixedPointCoordinate &segment_source,
                                              const FixedPointCoordinate &segment_target,
                                              const FixedPointCoordinate &query_location);

    static float ComputePerpendicularDistance(const FixedPointCoordinate &segment_source,
                                              const FixedPointCoordinate &segment_target,
                                              const FixedPointCoordinate &query_location,
                                              FixedPointCoordinate &nearest_location,
                                              float &ratio);

    static float perpendicular_distance_from_projected_coordinate(
                                              const FixedPointCoordinate &segment_source,
                                              const FixedPointCoordinate &segment_target,
                                              const FixedPointCoordinate &query_location,
                                              const std::pair<double, double> &projected_coordinate);

    static float perpendicular_distance_from_projected_coordinate(
                                              const FixedPointCoordinate &segment_source,
                                              const FixedPointCoordinate &segment_target,
                                              const FixedPointCoordinate &query_location,
                                              const std::pair<double, double> &projected_coordinate,
                                              FixedPointCoordinate &nearest_location,
                                              float &ratio);

    static int
    OrderedPerpendicularDistanceApproximation(const FixedPointCoordinate &segment_source,
                                              const FixedPointCoordinate &segment_target,
                                              const FixedPointCoordinate &query_location);

    static float GetBearing(const FixedPointCoordinate &A, const FixedPointCoordinate &B);

    static float deg_to_rad(const float degree);
    static float rad_to_deg(const float radian);
};

#endif //COORDINATE_CALCULATION
