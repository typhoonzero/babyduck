#include <unsupported/Eigen/CXX11/Tensor>

int main() {
  const int tmpd = 3;
Eigen::Tensor<double, tmpd> epsilon(3,3,3);
epsilon.setZero();
epsilon(0,1,2) = 1;
epsilon(1,2,0) = 1;
epsilon(2,0,1) = 1;
epsilon(1,0,2) = -1;
epsilon(2,1,0) = -1;
epsilon(0,2,1) = -1;
Eigen::Tensor<double, 4> grassmannIdentity(3,3,3,3);
grassmannIdentity.setZero();
// this is not the most efficient way to write such a product,
// but is the only way possible with the current feature set
for (int i = 0; i < 3; i++) {
  for (int j = 0; j < 3; j++) {
    for (int k = 0; k < 3; k++) {
      for (int l = 0; l < 3; l++) {
        for (int m = 0; m < 3; m++) {
          grassmannIdentity(i,j,l,m) += epsilon(i,j,k) * epsilon(k,l,m);
        }
      }
    }
  }
}

// verify
for (int i = 0; i < 3; i++) {
  for (int j = 0; j < 3; j++) {
    for (int l = 0; l < 3; l++) {
      for (int m = 0; m < 3; m++) {
        assert(grassmannIdentity(i,j,l,m) == (int(i == l) * int(j == m) - int(i == m) * int(j == l)));
      }
    }
  }
}

// dimensionalities
assert(epsilon.dimension(0) == 3);
assert(epsilon.dimension(1) == 3);
assert(epsilon.dimension(2) == 3);
auto dims = epsilon.dimensions();
assert(dims[0] == 3);
assert(dims[1] == 3);
assert(dims[2] == 3);

}