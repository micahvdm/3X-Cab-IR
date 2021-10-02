#include "../std.h"

#include "AudioFilter.h"
#include <complex>
#include <math.h>
#include <cmath>
#include <cstring>
#include <memory>

using namespace std;

using namespace TwoPlay;

AudioFilter::~AudioFilter()
{
	delete[] x;
	delete[] y;
	delete[] xR;
	delete[] yR;
}
void AudioFilter::Initialize(size_t length)
{
	this->length = length;
	x = new double[length];
	y = new double[length];
	xR = new double[length];
	yR = new double[length];

#if JUNK
	bilinearTransformCoefficients.resize(length);
	for (size_t i = 0; i < length; ++i)
	{
		bilinearTransformCoefficients[i].Resize(length);

	}

	Polynomial minusOne = Polynomial(-1.0,1); // z-1
	Polynomial plusOne = Polynomial(1.0,1); // z-1

	for (size_t i = 0; i < length; ++i)
	{
		Polynomial x = Polynomial::ONE;
		for (size_t j = 0; j < i; ++j)
		{
			x = x * minusOne;
		}
		for (size_t j = i; j < length; ++j)
		{
			x = x * plusOne;
		}


		for (size_t k = 0; k < length; ++k)
		{
			bilinearTransformCoefficients[k][i] += x[k];
		}
	}
	#endif
}


void AudioFilter::Reset()
{
	memset(x, 0, sizeof(double)*length);
	memset(y, 0, sizeof(double)*length);
	memset(xR, 0, sizeof(double)*length);
	memset(yR, 0, sizeof(double)*length);
}

void AudioFilter::Disable()
{
	// set to identity IIF.
	this->zTransformCoefficients.Disable();

}

static constexpr double PI = M_PI;
static constexpr double TWO_PI = M_PI*2;

void AudioFilter::BilinearTransform(float frequency, const FilterCoefficients& prototype, FilterCoefficients* result)
{
	double w0 = frequency * TWO_PI;
	double k = 1 / std::tan(w0 * T * 0.5);

	for (size_t outputIndex = 0; outputIndex < length; ++outputIndex)
	{
		result->a[outputIndex] = 0;
		result->b[outputIndex] = 0;
	}

	size_t outIx = length-1;
	for (size_t outputIndex = 0; outputIndex < length; ++outputIndex)
	{
		double x = 1;
		double sumB = 0;
		double sumA = 0;
		Polynomial& p = bilinearTransformCoefficients[outputIndex];
		for (size_t inputIndex = 0; inputIndex < length; ++inputIndex)
		{
			double scale = p[inputIndex]*x;
			sumB += prototype.b[inputIndex] * scale;
			sumA += prototype.a[inputIndex] * scale;
		}
		x *= k;
		// write in causitive order.
		result->b[outIx] = sumB;
		result->a[outIx] = sumA;
		--outIx;
	}
	
	// ... and normalize.
	double scale = 1.0 / result->a[0];
	for (size_t i = 0; i < length; ++i)
	{
		result->a[i] *= scale;
		result->b[i] *= scale;
	}

}

double AudioFilter::GetFrequencyResponse(float frequency)
{
	double w0 = frequency *T *TWO_PI;

	complex<double> ejw = std::exp(complex<double>(0.0, w0));

	complex<double> numSum = complex<double>(0,0);
	complex<double> denomSum = complex<double>(0,0);

	complex<double> x = complex<double>(1,0);

	for (size_t i = 0; i <= length; ++i)
	{
		denomSum += zTransformCoefficients.b[i]*x;
		numSum += zTransformCoefficients.a[i]*x;
		x *= ejw;
	}
	return std::abs(numSum/denomSum);
}