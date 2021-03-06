#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <degaFormat.h>
#include <degaPredefine.h>
#include <cDegaException.h>

namespace degawong {

class cDemoSize {
public:
	cDemoSize() : width(0), height(0) {}
	cDemoSize(int _height, int _width) : width(_width), height(_height) {}
	virtual ~cDemoSize() {}
public:
	int width;
	int height;
public:
	DEGA_FORCE_INLINE void clear() { width = 0; height = 0; }
};

template <typename _T>
class cDemoPoint {
public:
	cDemoPoint() { clear(); }
	cDemoPoint(const cDemoPoint<_T> &_point) {
		x = _point.x;
		y = _point.y;
		z = _point.z;
		w = _point.w;
	}
	cDemoPoint(_T _x, _T _y, int _pointFlag) : x(_x), y(_y), z(0), w(0), pointFlag(_pointFlag) {}
	cDemoPoint(_T _x, _T _y, _T _X, int _pointFlag) : pointFlag(_pointFlag) {
		switch (pointFlag) {
		case DEGA_3_POINT:
		{
			x = _x;
			y = _y;
			z = _X;
			w = 0;
			break;
		}
		case DEGA_2_HOMO_POINT:
		{
			x = _x;
			y = _y;
			z = 0;
			w = _X;
			break;
		}
		default:
			break;
		}
	}	
	cDemoPoint(_T _x, _T _y, _T _z, _T _w, int _pointFlag) : x(_x), y(_y), z(_z), w(_w), pointFlag(_pointFlag) {}
	virtual ~cDemoPoint() {}
public:
	_T x;
	_T y;
	_T z;
	_T w;
public:
	int pointFlag;
public:
	void clear() { x = 0; y = 0; z = 0; w = 0; }
};

class iScreenNorm {
public:
	iScreenNorm() : width(0), height(0) {}
	iScreenNorm(int _width, int _height) : width(_width), height(_height) {}
	~iScreenNorm() {};
public:
	int width;
	int height;
};

class cDemoPara {
public:
	cDemoPara() { bMenuDownFlag = nullptr; fStyleIntensity = nullptr; };
	cDemoPara(int _iParaNumbers) : iParaNumbers(_iParaNumbers) {
		setParameter(iParaNumbers);
	};
	~cDemoPara() {
		if (nullptr != bMenuDownFlag) { delete bMenuDownFlag; }
		if (nullptr != fStyleIntensity) { delete fStyleIntensity; }
	};
public:
	cDemoPara & operator=(const int value) {
		iImageFormat = 0;
		iParaNumbers = 0;
		iAlgorithmModel = 0;
		iAlgorithmStyle = 0;
		bMenuDownFlag = nullptr;
		fStyleIntensity = nullptr;
		return *this;
	}
	void operator=(const cDemoPara _arcParameter) {
		iImageFormat = _arcParameter.iImageFormat;
		iParaNumbers = _arcParameter.iParaNumbers;
		iAlgorithmModel = _arcParameter.iAlgorithmModel;
		iAlgorithmStyle = _arcParameter.iAlgorithmStyle;
		for (size_t i = 0; i < 3; i++) { bMenuDownFlag[i] = _arcParameter.bMenuDownFlag[i]; }
		for (size_t i = 0; i < _arcParameter.iParaNumbers; i++) { fStyleIntensity[i] = _arcParameter.fStyleIntensity[i]; }
	}
public:
	DEGA_FORCE_INLINE void setParameter(int _iParaNumbers) {
		iAlgorithmModel = 0;
		iAlgorithmStyle = 0;
		iParaNumbers = _iParaNumbers;
		bMenuDownFlag = new bool[3]{ 0 };
		fStyleIntensity = new float[iParaNumbers] {0};
	}
public:
	int iImageFormat;
	int iParaNumbers;	
	int iAlgorithmModel;
	int iAlgorithmStyle;
	bool *bMenuDownFlag;
	float *fStyleIntensity;
	std::vector<std::string> vPortraitList;
};

}

