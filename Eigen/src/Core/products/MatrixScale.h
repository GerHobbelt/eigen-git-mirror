#ifndef EIGEN_MATRIX_SCALE_H
#define EIGEN_MATRIX_SCALE_H

namespace Eigen { 
namespace internal {

template<typename Scalar, typename Index>
struct matrix_scale_add_imp;

template<typename Scalar, typename Index>
struct matrix_scale_add_imp
{
	static void run(Index size, Scalar *dest, const Scalar alpha){

		typedef Map<Matrix<Scalar,Dynamic,1> > ResMap;
		ResMap dest_map = ResMap(dest, size);
		dest_map = alpha*dest_map; 
	}
};

}

template<typename MatrixType>
struct matrix_scale_add
{
	typedef typename MatrixType::Scalar Scalar;
	static void run(MatrixType& dest, const Scalar& alpha)
	{
		internal::matrix_scale_add_imp<Scalar, Index>::run(dest.size(),dest.data(),alpha);
	}
};
}
#endif