/**
 * @file    reymond_labo3.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Convert MN03 coordinates to WGS84 coordinates
 * @version 1.0
 * @date    08.10.2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

using namespace std;

struct CoordinatesMN03
{
    double x; // in meters
    double y; // in meters
};

struct CoordinatesWGS84
{
    double longitude; // in degrees
    double latitude;  // in degrees
};

CoordinatesWGS84 convertMN03ToWGS84(const CoordinatesMN03 &mn03)
{
    // Convert meters to kilometers
    const double METERS_TO_KILOMETERS = 1000.0;
    double x_km = mn03.x / METERS_TO_KILOMETERS;
    double y_km = mn03.y / METERS_TO_KILOMETERS;

    // Calculate longitude (lambda) and latitude (phi)
    double lambda = 7.4386372 + 13.13606 * x_km + 2.19856 * x_km * y_km + 0.3628 * x_km * y_km * y_km - 0.121 * (x_km * x_km * x_km);
    double phi = 46.9510811 + 8.9952 * y_km - 0.75272 * (x_km * x_km) - 0.00702 * (y_km * y_km) - 0.1242 * (x_km * x_km) * y_km - 0.0389 * (y_km * y_km * y_km);

    return {lambda, phi};
}

int main()
{
    CoordinatesMN03 mn03;
    cout << "Enter x coordinate in meters: ";
    cin >> mn03.x;
    cout << "Enter y coordinate in meters: ";
    cin >> mn03.y;

    CoordinatesWGS84 wgs84 = convertMN03ToWGS84(mn03);

    cout << "Longitude: " << wgs84.longitude << "°E" << endl;
    cout << "Latitude: " << wgs84.latitude << "°N" << endl;

    return 0;
}
