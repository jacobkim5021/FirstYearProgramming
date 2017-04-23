#ifndef LAKETAHOE_H
#define LAKETAHOE_H

bool readTahoeData(char* filename, float lake[420][210]);

void cleanData(float lake[420][210]);

float area(float lake[420][210]);

float volume(float lake[420][210]);

#endif
