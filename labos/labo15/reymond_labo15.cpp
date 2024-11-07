/**
 * @file    reymond_labo3.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Convert CH1903 coordinates to WGS84 and write a KML file
 * @version 1.0
 * @date    04.11.2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>


using namespace std;

struct Coordinate {
    double x;
    double y;
};

Coordinate CH1903toWGS84(const Coordinate& chCoord) {
    // Convert CH1903 to WGS84
    double x = ((chCoord.x / 100) - 600000) / 1000000;
    double y = ((chCoord.y / 100) - 200000) / 1000000;

    double lambda = 2.6779094 + 4.728982 * x + 0.791484 * x * y + 0.1306 * x * pow(y, 2) - 0.0436 * pow(x, 3);
    double phi = 16.9023892 + 3.238272 * y - 0.270978 * pow(x, 2) - 0.002528 * pow(y, 2) - 0.0447 * pow(x, 2) * y - 0.0140 * pow(y, 3);

    lambda = lambda * 100 / 36;
    phi = phi * 100 / 36;

    return {phi, lambda};
}

Coordinate* readCoordinates(const string& filename, int& count) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << endl;
        return nullptr;
    }

    count = 0;
    double x, y;
    while (infile >> x >> y) {
        count++;
    }

    infile.clear();
    infile.seekg(0, ios::beg);

    Coordinate* coordinates = new Coordinate[count];
    int index = 0;
    while (infile >> x >> y) {
        coordinates[index++] = {x, y};
    }

    cout << "Read " << count << " coordinates from file: " << filename << endl;
    return coordinates;
}

void writeKML(const string& filename, const Coordinate* coordinates, int count) {
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    outfile << R"(<kml xmlns="http://www.opengis.net/kml/2.2">)" << endl;
    outfile << "<Document>" << endl;
    outfile << "<name>Marathon HEIG</name>" << endl;
    outfile << "<Placemark>" << endl;
    outfile << "<Style>" << endl;
    outfile << "<LineStyle>" << endl;
    outfile << "<color>FF0000cc</color>" << endl;
    outfile << "<width>5</width>" << endl;
    outfile << "</LineStyle>" << endl;
    outfile << "</Style>" << endl;
    outfile << "<LineString>" << endl;
    outfile << "<altitudeMode>clampToGround</altitudeMode>" << endl;
    outfile << "<coordinates>" << endl;

    for (int i = 0; i < count; ++i) {
        Coordinate wgsCoord = CH1903toWGS84(coordinates[i]);
        outfile << wgsCoord.y << "," << wgsCoord.x << " ";
    }

    outfile << "</coordinates>" << endl;
    outfile << "</LineString>" << endl;
    outfile << "</Placemark>" << endl;
    outfile << "</Document>" << endl;
    outfile << "</kml>" << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <source file> <destination file>" << endl;
        return 1;
    }

    string sourceFile = argv[1];
    string destFile = argv[2];

    int count = 0;
    Coordinate* coordinates = readCoordinates(sourceFile, count);
    if (coordinates == nullptr || count == 0) {
        cerr << "No coordinates read from file: " << sourceFile << endl;
        delete[] coordinates;
        return 1;
    }

    ifstream outfileCheck(destFile);
    if (outfileCheck.good()) {
        outfileCheck.seekg(0, ios::end);
        long fileSize = outfileCheck.tellg();
        outfileCheck.seekg(0, ios::beg);
        cout << "File " << destFile << " already exists with size " << fileSize << " bytes." << endl;
        cout << "Do you want to overwrite it? (y/n): ";
        char response;
        cin >> response;
        if (response != 'y' && response != 'Y') {
            cout << "Enter a new filename: ";
            cin >> destFile;
        }
    }
    outfileCheck.close();

    writeKML(destFile, coordinates, count);
    cout << "KML file written to " << destFile << endl;

    delete[] coordinates;
    return 0;
}