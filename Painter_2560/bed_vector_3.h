
/**
  vector_3.cpp - Vector library for bed leveling
  Copyright (c) 2012 Lars Brubaker.  All right reserved.
*/
#ifndef VECTOR_3_H
#define VECTOR_3_H

#if ENABLED(AUTO_BED_LEVELING_FEATURE)
class matrix_3x3;

struct vector_3 {
  float x, y, z;

  vector_3();
  vector_3(float x, float y, float z);

  static vector_3 cross(vector_3 a, vector_3 b);

  vector_3 operator+(vector_3 v);
  vector_3 operator-(vector_3 v);
  void normalize();
  float get_length();
  vector_3 get_normal();

  void debug(const char title[]);

  void apply_rotation(matrix_3x3 matrix);
};

struct matrix_3x3 {
  float matrix[9];

  static matrix_3x3 create_from_rows(vector_3 row_0, vector_3 row_1, vector_3 row_2);
  static matrix_3x3 create_look_at(vector_3 target);
  static matrix_3x3 transpose(matrix_3x3 original);

  void set_to_identity();

  void debug(const char title[]);
};


void apply_rotation_xyz(matrix_3x3 rotationMatrix, float& x, float& y, float& z);
#endif // AUTO_BED_LEVELING_FEATURE

#endif // VECTOR_3_H

